/*Síntese:
	Objetivo: LSE de produtos
	Data: 16/10/2019
	Autores: Gabriel Raposo e Layla Emanuele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

// Prototipos de funcao
int menu(void);

//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	struct tNo *lista=NULL;
	struct tNo *p;
	int opcao, pesqCod, encontrou;
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				p = malloc(sizeof(struct tNo));

				printf("Digite o codigo do produto...: ");
				scanf("%d", &( (*p).dado.codigo ));
				printf("Digite a descricao do produto: ");
				fflush(stdin);
				gets( (*p).dado.descricao );
				printf("Digite o valor do produto....: ");
				scanf("%f", &((*p).dado.valor) );

				if (lista == NULL) // lista vazia
					(*p).prox = NULL;
				else  // lista NAO vazia
					(*p).prox = lista;
				lista = p;
				break;
			case 2:
				printf("\n\n*** Listagem ***\n");
				p = lista;
				while (p != NULL) {
					printf("--> %s\n", (*p).dado.descricao);
					p = (*p).prox;
				}
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;

			case 3:
				printf("\n\n*** Consulta ***\n");

				p = lista;
				encontrou=0;

				printf("Qual o código do produto que deseja encontrar?");
				scanf("%d",&pesqCod);

				while (p != NULL && encontrou == 0) {
					if((*p).dado.codigo == pesqCod) {
						encontrou = 1;
						printf("Produto encontrado!");
						printf("--> %s\n", (*p).dado.descricao);
					}
					p = (*p).prox;
				}

				if(encontrou != 1)
					printf("Produto não encontrado!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;

			case 4:

				printf("\n\n*** Consulta ***\n");

				p = lista;
				encontrou=0;

				printf("Qual o código do produto que deseja alterar as informações?");
				scanf("%d",&pesqCod);

				while (p != NULL && encontrou == 0) {
					if((*p).dado.codigo == pesqCod) {
						encontrou = 1;
						printf("Digite a nova descricao do produto: ");
						fflush(stdin);
						gets( (*p).dado.descricao );
						printf("Digite o novo valor do produto....: ");
						scanf("%f", &((*p).dado.valor) );
					}
					p = (*p).prox;
				}

				if(encontrou != 1)
					printf("Produto não encontrado!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alteração\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//------------------------------------------------------------------------
