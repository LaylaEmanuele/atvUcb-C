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

//Protótipos das Funções
void inicializar(struct tNo **lst);
int menu();
void incluir(struct tNo **lst, struct tNo *novo);

//Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	struct tNo *lista, *no;
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

void inicializar(struct tNo **lst) {
	(*lst) = NULL;
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

void incluir(struct tNo **lst, struct tNo *novo) {
	struct tNo *p = (*lst), *q;

	if(((*lst) == NULL) || (comparo o novo < com o que tem na lista) { //inicio e vazia
	novo->prox = (*lst);
		(*lst) = novo;
	} else {
		while(p != NULL && (comparo o p < com o que tem no novo)){ //meio e fim
			q = p;
			p = p->prox;
		}
		q->prox = novo;
		novo->prox = p;
	}
}

void excluir(struct tNo **lst, struct tNo *vitima) {
	struct tNo *p = (*lst), *q;
	if ((*lst) == vitima) // Unico OU Inicio
		(*lst) = vitima->prox;
	else { // fim e meio
		while (p != vitima) {
			q = p;
			p = p->prox;
		}
		q->prox = vitima->prox;
	}
	free(vitima);
}

struct tNo *consultar(struct tNo *lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}
