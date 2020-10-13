/* Síntese
	Objetivo: Apresentar altura de um nó e seu fb de uma Árvore binária de busca
	Autora: Layla Emanuele
	Data: 20/05/2020
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
void rotacaoSD(struct tNo **);
void rotacaoSE(struct tNo **);
void balancearAVL(struct tNo **);
void incluir(struct tNo **, struct tNo *);
void preordem(struct tNo *);
void emordem(struct tNo *);
void posordem(struct tNo *);
void calcH(struct tNo *, int *);
int fb(struct tNo *);
struct tNo *consultar(struct tNo *, int );
void altFB(struct tNo *, int , int );
int grau(struct tNo *);
struct tNo *menor (struct tNo *);
int excluir(struct tNo **, int );
void destruir (struct tNo *);
void representa(struct tNo *); 

//Função Principal
int main(void) {
	int opcao, pesqCod, altura = 0, alturaD = 0, alturaE = 0, valorFB;
	struct tNo *arvore, *no, *p, *q;
	setlocale(LC_ALL,"Portuguese");

	inicializar(&arvore);

	do {
		alturaD = 0;
		alturaE = 0;
		altura = 0;

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
				q = consultar(arvore, pesqCod);

				if(q != NULL) {
					calcH(q->dir, &alturaD);
					calcH(q->esq, &alturaE);

					if(alturaD>alturaE)
						altura = alturaD;
					else
						altura = alturaE;

					valorFB = fb(q);
					altFB(q, valorFB, altura); //função para mostrar em detalhes
				} else
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
			case 7:
				representa(arvore);
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
	printf("7 - Representação\n");
	printf("0 - Sair\n");
	printf("Digite a opção desejada:\n");
	scanf("%d",&op);
	return op;
}

void rotacaoSD(struct tNo **pai) {
	struct tNo *filho = (*pai)->esq;
	(*pai)->esq = filho->dir;
	filho->dir = (*pai);
	(*pai) = filho;
}

void rotacaoSE(struct tNo **pai) {
	struct tNo *filho = (*pai)->dir;
	(*pai)->dir = filho->esq;
	filho->esq = (*pai);
	(*pai) = filho;
}

void balancearAVL(struct tNo **raiz) {
	int fat = fb(*raiz);
	if((fat != 2) && (fat != -2))
		return;
	if((fat == 2) && (fb((*raiz)->dir) == 1))	//simples esquerda
		rotacaoSE(raiz);
	else {
		if((fat == -2) && (fb((*raiz)->esq) == -1))	//simples direita
			rotacaoSD(raiz);
		else {
			if((fat == 2) && (fb((*raiz)->dir) == - 1)) { //dupla esquerda
				rotacaoSD(&((*raiz)->dir));
				rotacaoSE(raiz);
			} else { //dupla direita
				rotacaoSE(&((*raiz)->esq));
				rotacaoSD(raiz);
			}
		}
	}
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
	balancearAVL(raiz);
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

void calcH(struct tNo *raiz, int *altura) {
	if(raiz == NULL)
		return ;
	*altura = *altura + 1;
	if(raiz->esq != NULL)
		calcH(raiz->esq, altura);
	if(raiz->dir != NULL)
		calcH(raiz->dir, altura);
}

int fb(struct tNo *raiz) {
	int alturaD = 0, alturaE = 0;
	if(raiz == NULL)
		return;

	calcH(raiz->dir, &alturaD);
	calcH(raiz->esq, &alturaE);

	return alturaD - alturaE;
}

struct tNo *consultar(struct tNo *raiz, int cod) {
	if((raiz == NULL) || (raiz->dado.codigo == cod))
		return raiz;
	if(cod < raiz->dado.codigo)
		return consultar(raiz->esq, cod);
	return consultar(raiz->dir, cod);
}

void altFB(struct tNo *raiz, int valorFB, int altura) {
	printf("-------------------------\n");
	printf("Código->%d\n", raiz->dado.codigo);
	printf("Descrição->%s\n", raiz->dado.descricao);
	printf("Altura->%d\n", altura);
	printf("Fator de Balanceamento->%d\n", valorFB);
	printf("-------------------------\n");
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
	int resp;
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
		resp = excluir(&((*raiz)->esq), cod);
	resp = excluir(&((*raiz)->dir), cod);
	balancearAVL(raiz);
	return resp;
}

void destruir (struct tNo *raiz) {
	if(raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}

void representa(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	printf("( %d", raiz->dado.codigo);
	representa(raiz->esq);
	representa(raiz->dir);
	printf(")");
}
