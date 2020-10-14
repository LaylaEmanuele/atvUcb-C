/*Síntese
	Objetivo: Receber elementos de uma matriz 15x12 juntamente de um único caracter e verificar se o mesmo se encontra dentro da matriz.
	Data: 01/09/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

	int posL, posC, achei=0;
	char matriz[15][12], chara;

	setlocale(LC_ALL,"Portuguese");

	for(posL=0; posL<15; posL++)
		for(posC=0; posC<12; posC++) {
			printf("Insira os dados da matriz na %dº linha e na %d°º coluna: ", posL+1, posC+1);
			matriz[posL][posC]=getche();
			printf("\n");
		}
	
	system("cls");	

	printf("Qual o caracter que você deseja procurar na matriz?\n");

	chara=getche();

	for(posL=0; posL<15; posL++)
		for(posC=0; posC<12; posC++)
			if(chara == matriz[posL][posC])
				achei=1;

	system("cls");

	if(achei==1)
		printf("O caracter foi encontrado na matriz");
	else
		printf("O caracter não está na matriz");


	return 0;
}
