/*Síntese
	Objetivo: Ler e imprimir em forma de tabela uma matriz 20x20.
	Data: 28/08/2019
	Autores: Gabriel Raposo e Layla Emnanuele.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM 2

int main(void){
	int posL=0, posC=0, matriz[TAM][TAM];
	
	setlocale(LC_ALL,"Portuguese");
	for(posL=0; posL<TAM;posL++){
		for(posC=0; posC<TAM;posC++){
			printf("Insira o valor da %dº linha %dº coluna:", posL+1, posC+1);
			scanf("%d", &matriz[posL][posC]);
		}
	}
	
	system("cls");
	
	for(posL=0; posL<TAM;posL++){
		for(posC=0; posC<TAM;posC++){
			printf("%d ", matriz[posL][posC]);
		}
		printf("\n");		
	}
	return 0;
}



