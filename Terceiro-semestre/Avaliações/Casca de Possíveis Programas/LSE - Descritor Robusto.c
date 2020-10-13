/*Síntese:
	Objetivo:
	Autora: Layla Emanuele
	Data: 17/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Tipos de variáveis
struct tLista {
	int
	char
};

struct tNo {
	struct tLista dado;
	struct tNo *prox;
};

struct tDescritor{
	struct tNo *ini;
	struct tNo *fim;
};

//Protótipos das Funções
void inicializar(struct tNo **lst);
int menu();
void incluir(struct tNo **lst, struct tNo *novo);

//Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	struct tDescritor lista, *no;
	int opcao

	inicializar(&lista);

	do {
		system("cls");
		opcao = menu();
		system("cls");

		switch(opcao) {
			case 1:
				printf("----Inclusão----");
				no = malloc(sizeof(struct tNo));
				printf("Qual.....?");
				scanf("%d", & no->);
				incluir(&lista,no);

				break;

			case 2:
				printf("----Listagem----");
				break;

			case 3:
				printf("----Consulta----");
				break;

			case 4:
				printf("----Alteração----");
				break;

			case 5:
				printf("----Exclusão----");
				break;
		}

	} while(opcao != 0);




	return 0;
}

void inicializar(struct tDescritor *lst) {
	(*lst)->ini = 	(*lst)->fim = NULL;
}

int menu() {
	int op;

	printf("----MENU----\n");
	printf("1. Inclusão\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alteração\n");
	printf("5. Exclusão\n");
	printf("0. Sair\n");

	scanf("%d", &op);

	return op;
}

void incluir(struct tDescritor *desc, struct tNo *novo) {
	struct tNo *p = (*desc).ini, *q;
	if (((*desc).ini == NULL) || (novo->dado.codigo < (*desc).ini->dado.codigo)) { // Lista vazia OU inicio
		if ((*desc).ini == NULL) // lista vazia
			(*desc).fim = novo;
		novo->prox = (*desc).ini;
		(*desc).ini = novo;
	}
	else { // fim ou meio
		if (novo->dado.codigo > (*desc).fim->dado.codigo) { // fim
			(*desc).fim->prox = novo;
			novo->prox = NULL;
			(*desc).fim = novo;
		}
		else { // meio
			while (p->dado.codigo < novo->dado.codigo) {
				q = p;
				p = p->prox;
			}
			q->prox = novo;
			novo->prox = p;
		}
	}

}

void excluir(struct tDescritor *desc, struct tNo *vitima) {
	struct tNo *p = (*desc).ini, *q;
	
	if ((*desc).qtd == 0) // unico
		(*desc).ini = (*desc).fim = NULL;
	else { // Inicio ou fim ou meio
		if ((*desc).ini == vitima) // Inicio
			(*desc).ini = vitima->prox;
		else { // fim e meio
			while (p != vitima) {
				q = p;
				p = p->prox;
			}
			q->prox = vitima->prox;
			if (vitima->prox == NULL)
				(*desc).fim = q;
		}
	}
	free(vitima);
	(*desc).qtd--;
}

struct tNo *consultar(struct tDescritor lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}
