/*Síntese
	Objetivo: Ler e somar a diagonal principal de uma matriz 50x50.
	Data: 28/08/2019
	Autores: Gabriel Raposo e Layla Emnanuele.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void){
	int matriz[50][50], posL=0, posC = 0, soma = 0;
	
	setlocale(LC_ALL,"Portuguese");
	
	for(posL=0; posL<50; posL++){
		for(posC=0; posC<50; posC++){
			printf("Insira os dados da matriz na %dº linha e na %d°º coluna: ", posL+1, posC+1);
			scanf("%d", &matriz[posL][posC]);
		}
	}
	
	system("cls");
	
	for(posL=0, posC=0; posC<50; posL++, posC++){
		soma+=matriz[posL][posC];
	}
	printf("O resultado da soma da diagonal principal é: %d", soma);	
	return 0;
}

