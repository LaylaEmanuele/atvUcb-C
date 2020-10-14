// Sintese
//   objetivo "CRUD (inclusao e listagem) de produtos (cod, descricao e valor)"
//   data "08/08/2019"
//   autor "Edson F. da Fonseca & Turma de Programacao Estruturada de 2019/2"
#include <stdio.h>
#include <stdlib.h>

#define TAM 50

int main(void) {
	int codigos[TAM];
	char descricoes[TAM][20];
	float valores[TAM];
	
	int qtd=0, opcao, i;
	
	do {
		printf("\n\n*** MENU ***\n\n");
		printf("1. Inclusao\n");
		printf("2. Listagem\n");
		printf("0. Sair\n\n");
		printf("Digite sua opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");

				if (qtd < TAM) {
					printf("Digite o codigo do produto...: ");
					scanf("%d", &codigos[qtd]);
					printf("Digite a descricao do produto: ");
					fflush(stdin);
					gets(descricoes[qtd]);
					printf("Digite o valor do produto: ");
					scanf("%f", &valores[qtd]);
					qtd++;
				}
				else
					printf("Encheu!!!");
				break;
			case 2:
				printf("\n\n*** Listagem ***\n");
				for (i=0; i<qtd; i++)
					printf("%3d - %20s - R$ %.2f\n", codigos[i], descricoes[i], valores[i]);
				break;
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}
