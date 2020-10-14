/*Síntese:
   Objetivo: Criar uma lista de produtos com seus dados.
   Entrada: Nome, código e valor do produto.
   Saída: Uma lista com os dados de cada produto inserido.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL,"Portuguese");
	int codigo[100], escolha, i=0, j;
	float valor[100];
	char nome[100][100];
	do{
		escolha = 0;
		system("cls");
		printf("1 - Para adicionar produto.\n");
		printf("2 - Para ver os produtos já adicionados.\n");
		printf("Para sair digite qualquer tecla.\n");
		scanf("%i",&escolha);
		fflush(stdin);
		switch(escolha){
			case 1 :
				system("cls");
				printf("Insira o nome do produto:");
				gets(nome[i]);
				fflush(stdin);
				system("cls");
				printf("Informe o código do produto:");
				scanf("%i",&codigo[i]);
				fflush(stdin);
				system("cls");
				printf("Informe o valor do produto:");
				scanf("%f",&valor[i]);
				fflush(stdin);
				i++;
				break;
			case 2 :
				system("cls");
				for(j = 0; j<i; j++){
					printf("%s %i %.2f \n", nome[j], codigo[j], valor[j]);
				}	
				getch();
				break;		
			default	:
				exit(0);
				break;
		} 
	}while(escolha==1 || escolha==2);
}
