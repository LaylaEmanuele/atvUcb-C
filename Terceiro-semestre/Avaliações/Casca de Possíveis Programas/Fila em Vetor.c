/*Síntese
	Objetivo: 
	Autora: Layla Emanuele.
	Data: 17/06/2020
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 4

// Fila é primeiro que entra é o primeiro que saí

struct tProduto {
	int codigo;
	char descricao[30];
};



int menu(void);
void enqueue(struct tProduto[], int, char[], int);
void dequeue(struct tProduto [], int , int );
void listar(struct tProduto[], int cont);


int main(void) {
	struct tProduto fila[TAM_VET];
	int opcao, cod=0, i=0, cont=0;
	char desc[30];

	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Enfileirar ***\n\n");

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
					enqueue(fila, cod, desc, i);
					i++;
					cont++;
				} else
					printf("A fila está cheia");

				break;
			case 2:
				printf("\n\n*** Desinfileirar ***\n\n");
				if(cont != 0) {
					i=0;
					
					printf("Desinfileirou: %d\n", fila[i].codigo);
					printf("Desinfileirou: %s\n", fila[i].descricao);
					dequeue(fila, i, cont);
					i++;
					cont--;
				} else
					printf("A fila está vazia");

				break;
			case 3:
				printf("\n\n*** Listagem ***\n\n");
				listar(fila, cont);
				
		}
	} while (opcao != 0);

	return 0;
}


int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Enfileirar\n");
	printf("2. Desinfileirar\n");
	printf("3. Listagem\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}


void enqueue(struct tProduto fila[], int cod, char desc[], int i) {
	strcpy(fila[i].descricao, desc);
	fila[i].codigo = cod;
}


void dequeue(struct tProduto fila[], int i, int cont) {
	int aux=0;

	while(aux<cont){
		strcpy(fila[i].descricao,fila[i+1].descricao);
		fila[i].codigo = fila[i+1].codigo;
		aux++;
		i++;
	}
}


void listar(struct tProduto fila[], int cont) {
	int i;
	for(i=0; i<cont; i++)
		printf("%d - %s\n", fila[i].codigo, fila[i].descricao);
	getch();	
}


