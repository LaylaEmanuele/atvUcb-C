/*Síntese:
   Objetivo: Criar uma lista de produtos com seus dados podendo se fazer alteração da lista. 
   Data: 08/08/2019
   Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define TAM 100

int main(void){
	setlocale(LC_ALL,"Portuguese");
	int codigo[TAM], escolha, i=0, j, pesquisa, flag;
	float valor[TAM];
	char nome[TAM][100];
	
	do{
		system("cls");
		printf("1 - Para adicionar produto.\n");
		printf("2 - Para ver os produtos já adicionados.\n");
		printf("3 - Para consultar\n");
		printf("4 - Para alterar\n");
		printf("0 - Para sair.\n");
		scanf("%i",&escolha);
		switch(escolha){
			case 1 :
				
				if(i<TAM){
					system("cls");
					printf("Insira o nome do produto:");
					fflush(stdin);
					gets(nome[i]);
					system("cls");
					printf("Informe o código do produto:");
					scanf("%i",&codigo[i]);
					system("cls");
					printf("Informe o valor do produto:");
					scanf("%f",&valor[i]);
					i++;
				}
				else
					printf("A quantidade de produtos permitidas foi excedido!");
				break;			
						
			case 2 :
				
				system("cls");
				
				for(j = 0; j<i; j++)
					printf("%10s - %10i - %1.2f \n", nome[j], codigo[j], valor[j]);
					
				getch();
				break;
				
			case 3 :
				system("cls");
				flag=0;
				
				printf("Digite o código do produto que você deseja procurar:");
				scanf("%i",&pesquisa);
				
				for(j=0; j<i; j++){
					if(pesquisa == codigo[j]){
						printf("O seu produto foi encontrado!\n");
						printf("%10s - %3.2f", nome[j], valor[j]);
						flag=1;
					}						
				}
				
				if(flag==0)
					printf("O seu produto não foi encontrado!");
				getch();					
				break;	
									
		case 4 :
			system("cls");
			flag=0;
			
			printf("Digite o código do produto que você deseja alterar os dados:");
			scanf("%i",&pesquisa);
				
			for(j=0; j<i; j++){
				if(pesquisa == codigo[j]){
					printf("Digite os novos dados do produto\n");
					printf("Descrição: ");
					fflush(stdin);
					gets(nome[j]);
					printf("Valor:");
					scanf("%f",&valor[j]);
					printf("\nAlteração feita com sucesso!");
					flag=1;
				}						
			}
			
			if(flag==0)
				printf("O produto que você deseja alterar não foi encontrado!");
			getch();					
			break;	
		} 	
				
	}while(escolha!=0);
	
	return 0;
}



