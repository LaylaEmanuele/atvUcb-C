/*Síntese
	Objetivo: Receber uma frase e uma palavra do usuário e verifique se a palavra aparece na frase.
	Data: 25-08-2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void) {
	char palavra[50], frase[100];
	int achei=0, i=0, j=0, aux=0, tamanhoPalavra;

	setlocale(LC_ALL,"Portuguese");

	printf("Digite uma palavra:\n");
	gets(palavra);
	strupr(palavra);
	tamanhoPalavra = strlen(palavra);
	printf("Digite uma frase:\n");
	gets(frase);
	strupr(frase);

	while(frase[i]!='\0') {
		if(frase[i]==palavra[j]) {
			aux++;
			j++;
		} else {
			aux=0;
			j=0;
		}

		i++;

		if((aux==tamanhoPalavra && tamanhoPalavra > 1 && (frase[i]==' ' || frase[i]=='\0')))
			achei=1;
		else if(tamanhoPalavra==1 && frase[i-2]==' ' && frase[i]==' ')
			achei=1;
	}
	if(achei==1)
		printf("A palavra está contida na frase.");
	else
		printf("A palavra não aparece na frase.");
	return 0;
}


