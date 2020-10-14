/*Síntese
	Objetivo: Receber elementos do usuário e soma-los em uma matriz definida pelo usuário de no máximo 100x100.
	Data: 01/09/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	int tamL=0, tamC=0, soma=0, posC=0, posL=0;

	setlocale(LC_ALL,"Portuguese");

	printf("Informe a quantidade de linhas da sua matriz.\n");
	do {
		scanf("%d", &tamL);
		if(tamL>100)
			printf("ERRO! Digite um valor válido menor do que 100.\n");
	} while(tamL>100);

	system("cls");

	printf("Informe a quantidade de colunas da sua matriz.\n");
	do {
		scanf("%d", &tamC);
		if(tamC>100)
			printf("ERRO! Digite um valor válido menor do que 100.\n");
	} while(tamC>100);

	system("cls");

	int matriz[tamL][tamC];

	for(posL=0; posL<tamL; posL++) {
		for(posC=0; posC<tamC; posC++) {
			printf("Insira os dados da matriz na %dº linha e na %d°º coluna: ", posL+1, posC+1);
			scanf("%d", &matriz[posL][posC]);
		}
	}

	system("cls");

	for(posL=0; posL<tamL; posL++) {
		for(posC=0; posC<tamC; posC++)
			soma+=matriz[posL][posC];
	}

	printf("A soma dos elementos da matriz é:%d", soma);
	return 0;
}
