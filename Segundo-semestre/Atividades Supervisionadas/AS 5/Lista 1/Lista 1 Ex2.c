/*Síntese
	Objetivo: Contar a quantidade de palavras em uma frase.
	Data: 25-08-2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int qtdPalavras=0, i=0;
	char frase[100];
	
	printf("Digite a sua frase:\n");
	gets(frase);
	
	while(frase[i]!='\0' && frase[0]!= ' '){
		if((frase[i]==' ' && frase[i+1]!=' ') || frase[i+1]=='\0')
			qtdPalavras++;
		i++;	
	}

	printf("A quantidade de palavras na frase é de: %d", qtdPalavras);

	return 0;
}
