/*Síntese
	Objetivo: Apresentar as iniciais do nome do usuário.
	Data: 25-08-2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

int main(void){
	int i=0;
	char nome[100];
	
	printf("Insira seu nome: \n");
	gets(nome);
	
	while(nome[i]!='\0'){
		if(i==0)
			printf("%c", toupper(nome[i]));
		if(nome[i]==' ' && nome[i+1]!=' ')
			printf("%c",toupper(nome[i+1]));
		i++;	
	}
	printf(".");
	
	return 0;
}

