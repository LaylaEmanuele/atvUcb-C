/*Síntese
	Objetivo: Informar a quantidade de consoantes de uma frase.
	Data: 25-08-2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int qtdConsoantes=0, i=0, j;
	char frase[100];
	
	printf("Digite a frase desejada:");
	gets(frase);
	strupr(frase);

	while(frase[i] != '\0'){
		if(((frase[i]>=65 && frase[i]<=90) || frase[i]==128) && frase[i]!='A' && frase[i]!='E' && frase[i]!='I' && frase[i]!='O' && frase[i]!='U')
			qtdConsoantes++;				
		i++;	
	}	
	printf("A quantidade de consoantes é: %d", qtdConsoantes);
	
	return 0;
}


