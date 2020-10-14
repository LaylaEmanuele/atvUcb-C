/*Síntese:
	Objetivo: LSE modularizada de produtos com exclusão, backup, restore.
	Data: 29/10/2019
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


// Prototipos de funcao
int menu(void);
void incluir(struct tProduto prod, FILE *arq);
void listar(FILE *arq, struct tProduto prod);
int consultar(FILE *arq, int cod, struct tProduto *prod) ;


//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	struct tProduto produto;
	FILE *prod;
	int pesqCod, pesquisa, opcao;
	
	
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");

				printf("Digite o código do produto: ");
				scanf("%d", &produto.codigo);
				printf("Digite a descrição do produto: ");
				fflush(stdin);
				gets(produto.descricao);
				printf("Digite o valor do produto: ");
				scanf("%f", &produto.valor);
				incluir(produto, prod);
				printf("Produto adicionado com sucesso!");
				break;
				
			case 2:
				
				printf("\n\n*** Listagem ***\n");
				listar(prod, produto);
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;

			case 3:
				printf("\n\n*** Consulta ***\n");				

				printf("Qual o código do produto que deseja encontrar?\n");
				scanf("%d",&pesqCod);
				pesquisa=consultar(prod, pesqCod, &produto);				

				if(pesquisa == 0)
					printf("Produto não encontrado!");
				else{
					printf("Produto encontrado!\n");	
					printf("Valor: %10f | Descricao: %10s | Codigo: %10d", produto.valor, produto.descricao, produto.codigo);
				}
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;

			
				
		}
	} while (opcao != 0);
	
	return 0; 
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//--- Inclusão -----------------------------------------------------------
void incluir(struct tProduto prod, FILE *arq){
	arq=fopen("produtos.dat","ab");
	fwrite(&prod,sizeof(prod),1,arq);
	fclose(arq);
}

//--- Listagem -----------------------------------------------------------
void listar(FILE *arq, struct tProduto prod){
	arq=fopen("produtos.dat","rb");
	while(fread(&prod,sizeof(prod),1,arq)){
		printf("Valor: %10f | Descricao: %10s | Codigo: %10d\n", prod.valor, prod.descricao, prod.codigo);
	}
	fclose(arq);
}

//--- Consultar -----------------------------------------------------------
int consultar(FILE *arq, int cod, struct tProduto *prod){
	arq=fopen("produtos.dat","rb");
	while(fread(&*prod,sizeof(*prod),1,arq)){
		if(cod==(*prod).codigo)
			return 1;
	}
	fclose(arq);
	return 0;
}
