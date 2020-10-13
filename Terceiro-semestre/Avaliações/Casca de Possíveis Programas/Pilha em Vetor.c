/*Síntese
	Objetivo: 
	Autora: Layla Emanuele.
	Data: 17/06/2020
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 4

//Pilha ultimo a entra é o primeiro a sair 
struct tProduto {
	int codigo;
	char descricao[30];
};


int menu(void);
void push(struct tProduto[], int, char[], int);
void pop(struct tProduto [], int , int );
void listar(struct tProduto[], int );


int main(void) {
	struct tProduto pilha[TAM_VET];
	int opcao, cod=0, i=0, cont=0;
	char desc[30];

	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Empilhar ***\n\n");

				if(cont<TAM_VET) {
					do {
						printf("Digite o codigo...: ");
						scanf("%d", &cod);
						if(cod == 0)
							printf("O codigo não pode ser 0\n");
					} while(cod == 0);

					printf("Digite a descricao: ");
					fflush(stdin);
					gets(desc);
					push(pilha, cod, desc, i);
					i++;
					cont++;
				} else
					printf("A pilha está cheia");
				break;

			case 2:
				printf("\n\n*** Desempilhar ***\n\n");

				if(cont != 0) {
					
					printf("Desempilhou:  %d\n", pilha[i-1].codigo);
					printf("Desempilhou:  %s\n", pilha[i-1].descricao);
					pop(pilha, i);
					i--;
					cont--;
				} else
					printf("Pilha estava vazia!\n");
				getch();
				
				break;

			case 3:
				printf("\n\n*** Listagem ***\n\n");
				listar(pilha, cont);
				break;
		}
	} while (opcao != 0);

	return 0;
}


int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Empilhar\n");
	printf("2. Desempilhar\n");
	printf("3. Listagem\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}


void push(struct tProduto pilha[], int cod, char desc[], int i) {
	strcpy(pilha[i].descricao, desc);
	pilha[i].codigo = cod;
}


void pop(struct tProduto pilha[], int i) {
	pilha[i-1].codigo = 0;
	strcpy(pilha[i-1].descricao, "");
}

void listar(struct tProduto pilha[], int cont) {
	int i;
	for(i=0; i<cont; i++)
		printf("%d - %s\n", pilha[i].codigo, pilha[i].descricao);
	getch();
}
