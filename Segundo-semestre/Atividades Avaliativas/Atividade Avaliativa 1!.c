/*Síntese:
   Objetivo: Criar uma lista de produtos com seus dados (struct[codigo, valor, nome]) podendo se fazer alteração da lista e deletar os dados inseridos. 
   Data: 13/08/2019
   Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 100

int main(void){
	setlocale(LC_ALL,"Portuguese");
	int escolha, i=0, j, pesquisa, flag, armazena_indice;
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
					
					if(i<TAM){
						system("cls");
						printf("Insira o nome do produto:");
						fflush(stdin);
						gets(produtos[i].nome);
						system("cls");
						printf("Informe o código do produto:");
						scanf("%i",&produtos[i].codigo);
						system("cls");
						printf("Informe o valor do produto:");
						scanf("%f",&produtos[i].valor);
						i++;
					}
					else
						printf("A quantidade de produtos permitidas foi excedido!");
					break;			
							
				case 2 :
					
					system("cls");
					
					for(j = 0; j<i; j++)
						printf("%10s - %10i - %1.2f \n", produtos[j].nome, produtos[j].codigo, produtos[j].valor);
						
					getch();
					break;
					
				case 3 :
					system("cls");
				
					printf("Digite o código do produto que você deseja procurar:");
					scanf("%i",&pesquisa);
					
					for(j=0; j<i; j++){
						if(pesquisa == produtos[j].codigo){
							printf("O seu produto foi encontrado!\n");
							printf("%10s - %3.2f", produtos[j].nome, produtos[j].valor);
							flag=1;
						}						
					}
					
					if(flag==0)
						printf("O seu produto não foi encontrado!");
					getch();					
					break;	
										
			case 4 :
				system("cls");
			
				
				printf("Digite o código do produto que você deseja alterar os dados:");
				scanf("%i",&pesquisa);
					
				for(j=0; j<i; j++){
					if(pesquisa == produtos[j].codigo){
						printf("Digite os novos dados do produto\n");
						printf("Descrição: ");
						fflush(stdin);
						gets(produtos[j].nome);
						printf("Valor:");
						scanf("%f",&produtos[j].valor);
						printf("\nAlteração feita com sucesso!");
						flag=1;
					}						
				}
				
				if(flag==0)
					printf("O produto que você deseja alterar não foi encontrado!");
				getch();					
				break;	
				
			case 5: 
				system("cls");
				printf("Digite o código do produto que deseja excluir:\n");
				scanf("%i",&pesquisa);
				
				for(j=0;j<i; j++){
					if(pesquisa == produtos[j].codigo){
						armazena_indice = j;
						flag = 1;			
					}	
				}
				
				if(flag==1){
					for(j=armazena_indice;j<i;j++){
						produtos[j].codigo = produtos[j+1].codigo;
						produtos[j].valor = produtos[j+1].valor;
						strncpy(produtos[j].nome,produtos[j+1].nome,100);
					}
					i--;
				}
				else 
					printf("Produto não encontrado.");
				getch();
				break;
			} 	
			
					
		}while(escolha!=0);
		return 0;
	}



