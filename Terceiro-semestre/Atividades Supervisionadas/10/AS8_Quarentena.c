/* Síntese
	Objetivo: Fazer uma árvore de produto através da Árvore binária de busca
	Autora: Layla Emanuele
	Data: 19/05/2020
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Declarações de tipo de variáveis
struct tProduto {
	int codigo;
	char descricao[80];
};

struct tNo {
	struct tNo *esq;
	struct tNo *dir;
	struct tProduto dado;
};

//Protótipos das funções
void inicializar(struct tNo **);
int menu();
void incluir(struct tNo **, struct tNo *);
void preordem(struct tNo *);
void emordem(struct tNo *);
void posordem(struct tNo *);
struct tNo *consultar(struct tNo *, int );
int grau(struct tNo *);
struct tNo *menor (struct tNo *);
int excluir(struct tNo **, int );
void destruir (struct tNo *);

//Função Principal
int main(void) {
	int opcao, pesqCod;
	struct tNo *arvore, *no;
	setlocale(LC_ALL,"Portuguese");

	inicializar(&arvore);

	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch(opcao) {
			case 1:
				no = malloc(sizeof(struct tNo));
				printf("-------Inclusão-------\n");
				printf("Qual o código do produto?\n");
				scanf("%d", &(no->dado.codigo));

				printf("Qual a descrição do produto?\n");
				fflush(stdin);
				gets(no->dado.descricao);

				incluir(&arvore, no);
				break;
			case 2:
				printf("-------Listagem Pré Ordem-------\n");
				preordem(arvore);
				getch();
				break;
			case 3:
				printf("-------Listagem Em Ordem-------\n");
				emordem(arvore);
				getch();
				break;
			case 4:
				printf("-------Listagem Pós Ordem-------\n");
				posordem(arvore);
				getch();
				break;
			case 5:
				printf("-------Consultar-------\n");
				printf("Qual o código a ser consultado?\n");
				scanf("%d", &pesqCod);
				if(consultar(arvore, pesqCod) != NULL)
					printf("Encontrou");
				else
					printf("Não encontrou");
				getch();
				break;
			case 6:
				printf("-------Exclusão-------\n");
				printf("Qual código será excluído?\n");
				scanf("%d", &pesqCod);
				if(excluir(&arvore, pesqCod))
					printf("Excluído");
				else
					printf("Não foi encontrado");
				getch();
				break;
		}
	} while(opcao!=0);

	destruir(arvore);

	return 0;
}

//Funções
void inicializar(struct tNo **raiz) {
	(*raiz) = NULL;
}

int menu() {
	int op;
	printf("-------Menu-------\n");
	printf("1 - Inclusão\n");
	printf("2 - Listagem Pré Ordem\n");
	printf("3 - Listagem Em Ordem\n");
	printf("4 - Listagem Pós Ordem\n");
	printf("5 - Consulta\n");
	printf("6 - Exclusão\n");
	printf("0 - Sair\n");
	printf("Digite a opção desejada:\n");
	scanf("%d",&op);
	return op;
}

void incluir(struct tNo **raiz, struct tNo *p) {
	if((*raiz) == NULL) { //sem nós na arvore
		(*raiz) = p;
		p->esq = p->dir = NULL;
	} else {
		if(p->dado.codigo < (*raiz)->dado.codigo) {
			incluir(&((*raiz)->esq), p);
		} else
			incluir(&((*raiz)->dir), p);
	}
}

void preordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
	preordem(raiz->esq);
	preordem(raiz->dir);
}

void emordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	emordem(raiz->esq);
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
	emordem(raiz->dir);

}

void posordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	posordem(raiz->esq);
	posordem(raiz->dir);
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
}

struct tNo *consultar(struct tNo *raiz, int cod) {
	if((raiz == NULL) || (raiz->dado.codigo == cod))
		return raiz;
	if(cod < raiz->dado.codigo) //nao entendi mas sigo compreendendo'
		consultar(raiz->esq, cod);
	return consultar(raiz->dir, cod);
}

int grau(struct tNo *raiz) {
	if((raiz->esq == NULL) && (raiz->dir == NULL))
		return 0;
	if((raiz->esq != NULL) && (raiz->dir != NULL))
		return 2;
	return 1;
}

struct tNo *menor (struct tNo *raiz) {
	if((raiz == NULL) || (raiz->esq == NULL))
		return raiz;
	menor(raiz->esq);

}

int excluir(struct tNo **raiz, int cod) {
	struct tNo *p;
	if((*raiz) == NULL)
		return 0;
	if((*raiz)->dado.codigo == cod) {
		if(grau(*raiz) == 0) { //grau = 0
			free(*raiz);
			*raiz = NULL;
		} else {
			if(grau(*raiz) == 1) { //grau igual a 1
				p = (*raiz);
				if((*raiz)->esq !=NULL)
					(*raiz) = (*raiz)->esq;
				else
					(*raiz) = (*raiz)->dir;
				free(p);
			} else { //grau igual 2
				p = menor((*raiz)->dir);
				(*raiz)->dado.codigo = p->dado.codigo;
				excluir(&((*raiz)->dir), p->dado.codigo);
			}
		}
		return 1;
	}
	if(cod < (*raiz)->dado.codigo)
		return excluir(&((*raiz)->esq), cod);
	return 	excluir(&((*raiz)->dir), cod);
}

void destruir (struct tNo *raiz) {
	if(raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}
