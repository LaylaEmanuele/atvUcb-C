/*Síntese
	Objetivo: Ler e imprimir o maior elemento da matriz 50x20.
	Data: 28/08/2019
	Autores: Gabriel Raposo e Layla Emnanuele.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void){
	int posL=0, posC=0, matriz[50][20], maiorV=0, maiorL=0, maiorC=0;
	
	setlocale(LC_ALL,"Portuguese");
	for(posL=0; posL<50;posL++){
		for(posC=0; posC<20;posC++){
			printf("Insira o valor da %dº linha %dº coluna:", posL+1, posC+1);
			scanf("%d", &matriz[posL][posC]);
		}
	}
	
	system("cls");
	
	for(posL=0; posL<50;posL++){
		for(posC=0; posC<20;posC++){
			if(matriz[posL][posC] > maiorV){
				maiorV = matriz[posL][posC];
				maiorL = posL;
				maiorC = posC;
			}
		}
	}
	printf("O maior valor da matriz é: %d e ele se encontra na %dº linha %dº coluna.", maiorV, maiorL+1, maiorC+1);
	return 0;
}



