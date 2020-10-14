// Sintese
//   objetivo "AA01 - CRUD (inclus?o, listagem, consulta, altera??o e exclus?o) de produtos (c?digo, descri??o e valor) com VETOR de registro (struct)"
//   data "13/08/2019"
//   autor "Edson F. da Fonseca & Turma de Programacao Estruturada de 2019/2"
#include <stdio.h>
#include <stdlib.h>

#define TAM 50

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

void listar(struct tProduto[], int);

int main(void) {
	struct tProduto produtos[TAM];
	int qtd=0, opcao, i, codigo, achei;
	
	do {
		printf("\n\n*** MENU ***\n\n");
		printf("1. Inclusao\n");
		printf("2. Listagem\n");
		printf("3. Consulta\n");
		printf("4. Alteracao\n");
		printf("5. Exclusao\n");
		printf("0. Sair\n\n");
		printf("Digite sua opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				if (qtd < TAM) {
					printf("Digite o codigo do produto...: ");
					scanf("%d", &produtos[qtd].codigo);
					printf("Digite a descricao do produto: ");
					fflush(stdin);
					gets(produtos[qtd].descricao);
					printf("Digite o valor do produto: ");
					scanf("%f", &produtos[qtd].valor);
					qtd++;
				}
				else
					printf("Encheu!!!");
				break;
			case 2:
				printf("\n\n*** Listagem ***\n");
				listar(produtos, qtd);
				break;
			case 3:
				printf("\n\n*** Consulta ***\n");
				printf("Digite o codigo: ");
				scanf("%d", &codigo);
				achei = 0;
				for (i=0; i<qtd; i++) {
					if (codigo == produtos[i].codigo) {
						printf("%3d - %20s - R$ %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
						achei = 1;
					}
				}
				if (!achei)
					printf("Codigo nao encontrado!!!");
				break;
			case 4:
				printf("\n\n*** Alteracao ***\n");
				printf("Digite o codigo: ");
				scanf("%d", &codigo);
				achei = 0;
				for (i=0; i<qtd; i++) {
					if (codigo == produtos[i].codigo) {
						printf("%3d - %20s - R$ %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
						printf("Digite a descricao do produto: ");
						fflush(stdin);
						gets(produtos[i].descricao);
						printf("Digite o valor do produto: ");
						scanf("%f", &produtos[i].valor);
						achei = 1;
					}
				}
				if (!achei)
					printf("Codigo nao encontrado!!!");
				break;
			case 5:
				printf("\n\n*** Exclusao ***\n");
				printf("Digite o codigo: ");
				scanf("%d", &codigo);
				achei = 0;
				for (i=0; i<qtd; i++) {
					if (codigo == produtos[i].codigo) {
						printf("%3d - %20s - R$ %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
						produtos[i] = produtos[qtd-1];
						qtd--;
						achei = 1;
					}
				}
				if (!achei)
					printf("Codigo nao encontrado!!!");
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

void listar(struct tProduto prods[], int qt) {
	int i;
	for (i=0; i<qt; i++)
		printf("%3d - %20s - R$ %.2f\n", prods[i].codigo, prods[i].descricao, prods[i].valor);
}


