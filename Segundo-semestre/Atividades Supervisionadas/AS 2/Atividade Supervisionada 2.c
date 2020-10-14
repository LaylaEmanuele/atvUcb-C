/*Síntese:
   Objetivo: Criar uma lista(modularizada) de produtos com seus dados (struct[codigo, valor, nome]) podendo se fazer alteração da lista e deletar os dados inseridos. 
   Data: 14/08/2019
   Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 100

struct tProdutos{
	int codigo;
	float valor;
	char nome[100];
};

void listar(struct tProdutos[], int);
void adicionar(struct tProdutos[], int);
void consultar(struct tProdutos[], int, int);
void alterar(struct tProdutos[], int, int);
void deletar(struct tProdutos[], int, int);


int main(void){
	setlocale(LC_ALL,"Portuguese");
	int escolha, qtd=0, j, pesquisa, flag, armazena_indice;
	
	struct{
		int codigo;
		float valor;
		char nome[100];
	} produtos[TAM];
	
	
		do{
			flag=0;
			system("cls");
			printf("1 - Para adicionar produto.\n");
			printf("2 - Para ver os produtos já adicionados.\n");
			printf("3 - Para consultar\n");
			printf("4 - Para alterar\n");
			printf("5 - Para deletar um produto adicionado a lista.\n");
			printf("0 - Para sair.\n");
			scanf("%i",&escolha);
			switch(escolha){
				case 1 :
					
					adicionar(produtos, qtd);
					qtd++;
					break;			
							
				case 2 :
					
					listar(produtos, qtd);
					break;
					
				case 3 :
	
					consultar(produtos, qtd, flag);
					break;	
										
				case 4 :
	
					alterar(produtos, qtd, flag);				
					break;	
				
				case 5: 
	
					deletar(produtos, qtd, flag);
					qtd--;			
					break;
			} 
					
		}while(escolha!=0);
		return 0;
	}
	
void adicionar(struct tProdutos aProdutos[], int aQtd){
	if(aQtd<TAM){
		system("cls");
		printf("Insira o nome do produto:");
		fflush(stdin);
		gets(aProdutos[aQtd].nome);
		system("cls");
		printf("Informe o código do produto:");
		scanf("%i",&aProdutos[aQtd].codigo);
		system("cls");
		printf("Informe o valor do produto:");
		scanf("%f",&aProdutos[aQtd].valor);
	}else
		printf("A quantidade de produtos permitidas foi excedido!");
		
	return aProdutos[aQtd];	
}

void listar(struct tProdutos lProdutos[], int lQtd){
		int j;
		system("cls");					
		for(j = 0; j<lQtd; j++)
			printf("%10s - %10i - R$%1.2f \n", lProdutos[j].nome, lProdutos[j].codigo, lProdutos[j].valor);						
		getch();
}

void consultar(struct tProdutos cProdutos[], int cQtd, int cFlag){
	
	int j, pesquisa; 
	
	system("cls");
	printf("Digite o código do produto que você deseja procurar:");
	scanf("%i",&pesquisa);
			
	for(j=0; j<cQtd; j++){
		if(pesquisa == cProdutos[j].codigo){
			printf("O seu produto foi encontrado!\n");
			printf("%10s - R$%3.2f", cProdutos[j].nome, cProdutos[j].valor);	
			cFlag=1;
		}						
	}	
	if(cFlag==0)
		printf("O seu produto não foi encontrado!");
	getch();			
}

void alterar(struct tProdutos alProdutos[], int alQtd, int alFlag){
	int pesquisa, j;	
	system("cls");
			
	printf("Digite o código do produto que você deseja alterar os dados:");
	scanf("%i",&pesquisa);				
	
	for(j=0; j<alQtd; j++){
		if(pesquisa == alProdutos[j].codigo){
			printf("Digite os novos dados do produto\n");
			printf("Descrição: ");
			fflush(stdin);
			gets(alProdutos[j].nome);
			printf("Valor:");
			scanf("%f",&alProdutos[j].valor);
			printf("\nAlteração feita com sucesso!");
			alFlag=1;
		}						
	}
	
	if(alFlag==0)
		printf("O produto que você deseja alterar não foi encontrado!");
	getch();
}

void deletar(struct tProdutos dProdutos[], int dQtd, int dFlag){
	int j, pesquisa;
		
	system("cls");
	printf("Digite o código do produto que deseja excluir:\n");
	scanf("%i",&pesquisa);
				
	for(j=0;j<dQtd; j++){
		if(pesquisa == dProdutos[j].codigo){
			dProdutos[j]=dProdutos[dQtd-1];		
			dFlag=1;		
		}	
	}
	
	if(dFlag==0)
		printf("Produto não encontrado.");
	getch();	
}

