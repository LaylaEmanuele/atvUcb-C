/*Síntese
	Objetivo: Receber elementos de uma matriz 50x20 e somar os elementos de suas linhas e suas colunas.
	Data: 01/09/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	int matriz[50][20], posL=0, posC=0, soma=0;

	setlocale(LC_ALL,"Portuguese");

	for(posL=0; posL<50; posL++)
		for(posC=0; posC<20; posC++) {
			printf("Insira os dados da matriz na %dº linha e na %d°º coluna: ", posL+1, posC+1);
			scanf("%d", &matriz[posL][posC]);
		}

	for(posL=0; posL<50; posL++) {
		for(posC=0; posC<20; posC++)
			soma+=matriz[posL][posC];

		printf("A soma da %dº linha é: %d\n", posL+1, soma);
		soma=0;
	}

	for(posC=0; posC<20; posC++) {
		for(posL=0; posL<50; posL++)
			soma+=matriz[posL][posC];

		printf("A soma da %dº coluna é: %d\n", posC+1, soma);
		soma=0;
	}

	return 0;
}

