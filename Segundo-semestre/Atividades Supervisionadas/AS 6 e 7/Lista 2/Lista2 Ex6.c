/*Síntese 
	Objetivo: Ler as duas primeiras linhas de uma matriz 3x10 e realizar a soma das colunas das duas primeiras linhas e inserir o valor da soma na terceira linha.
	Data: 29/08/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define TAML 3
#define TAMC 10

int main(void){
	int matriz[TAML][TAMC], lin, col;
	
	setlocale(LC_ALL,"Portuguese");
	
	for(lin=0; lin<TAML-1;lin++){
		for(col=0; col<TAMC;col++){
			printf("Insira o valor na %dº linha e na %dº coluna:\n", lin+1, col+1);
			scanf("%d",&matriz[lin][col]);
		}
	}
	
	system("cls");
	
	for(col=0; col<TAMC;col++){
		matriz[2][col]=(matriz[1][col]+matriz[0][col]);		
		printf("%d ",matriz[2][col]);
	}
		
}
