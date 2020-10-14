/*Síntese 
	Objetivo: Ler uma matriz 10x5 e contar quantos números pares e ímpares existe na matriz.
	Data: 29/08/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define TAML 10
#define TAMC 5

int main(void){
	int matriz[TAML][TAMC], qtdImp=0, qtdPar=0, lin, col; 
	
	setlocale(LC_ALL,"Portuguese");
	
	for(lin=0; lin<TAML;lin++){
		for(col=0;col<TAMC; col++){
			printf("Insira o valor na %dº linha e na %dº coluna:\n", lin+1, col+1);
			scanf("%d",&matriz[lin][col]);
		}
	}
	
	for(lin=0; lin<TAML;lin++){
		for(col=0;col<TAMC; col++){
			if(matriz[lin][col]%2==0)
				qtdPar++;
			else 
				qtdImp++;			
		}
	}
	
	system("cls");
	
	printf("A quantidade de números pares é %d e de números ímpares %d.", qtdPar, qtdImp);
	
	
}





