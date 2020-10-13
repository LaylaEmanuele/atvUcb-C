/*Síntese
	Objetivo: Lista de produtos feita através da tabela hash usando endereçamento linear
	Autora: Layla Emanuele.
	Data: 06/05/2020
*/	 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define M 13

//Declaração de tipo de variáveis 
struct tProduto {
	int codigo;
	char descricao[30];
};

//Protótipos funções 
int menu(void);

int hash (int k, int i;){
	return (k + i) % M;
}

void incluir(struct tProduto tabela[], int i, int cod, char desc[]){
	strcpy(tabela[i].descricao, desc);
	tabela[i].codigo = cod;
}

void listar(struct tProduto tabela[]){
	int i;
	for(i=0; i<M;i++){
		if(tabela[i].dado.codigo = -1)
			printf("Deletado");
		printf("%d - %s\n", tabela[i].codigo, tabela[i].descricao);
		
	}
	getch();
}

void consultar(struct tProduto tabela[], int i){
	printf("%d - %s\n", tabela[i].codigo, tabela[i].descricao);
}

void deletar(struct tProduto tabela[], int cod){
	while(i != cod)
		i++;
	tabela[i].dado.codigo = -1;
}

int main(void){
	struct tProduto tabela[M];
	int opcao, cont = 0, i = 0;
	char desc[30];
	
	do{
		system("cls");
		opcao = menu();
		system("cls");
		switch(opcao){
			case 1:
				printf("\n\n*** Inclusao ***\n\n");
				if(cont<M) {
					printf("Digite o codigo...: ");
					scanf("%d", &cod);
					printf("Digite a descricao: ");
					fflush(stdin);
					gets(desc);
					i = hash(cod, i);
					incluir(tabela, i, cod, desc);
					cont++;
				} else
					printf("A tabela está cheia");
				break;
			
			case 2:
				printf("\n\n*** Listagem ***\n\n");
				listar(tabela);
				break;
			
			case 3:
				printf("\n\n*** Consulta ***\n\n");
				printf("Digite o codigo a ser pesquisado...: ");
				scanf("%d", &cod);
				i = hash(cod, i);
				consultar(tabela, i);
				break;
			
			case 4:
				printf("\n\n*** Exclusao ***\n\n");
				printf("Digite o codigo a ser deletado...: ");
				scanf("%d", &cod);
				deletar(tabela, cod);
				break;
		}
	}while(opcao != 0);
	return 0;
}


//Funções 
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Incluir\n");
	printf("2. Listar\n");
	printf("3. Consultar\n");
	printf("4. Deletar\n\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}


