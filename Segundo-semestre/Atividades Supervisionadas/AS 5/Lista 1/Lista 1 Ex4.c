/*Síntese
	Objetivo: Apresentar o nome inserido no formato para referencial bibliográfico.
	Data: 25-08-2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(void){
	char nome[100], sobrenome[20];
	int i=0, auxiliarSobrenome, j=0, auxiliarIniciais;
	
	printf("Insira o nome:\n");
	gets(nome);
	
	auxiliarSobrenome=strlen(nome);
	
	while(nome[auxiliarSobrenome]!=' '){
		auxiliarSobrenome--;
	}
	
	auxiliarIniciais=auxiliarSobrenome;
	
	while(nome[auxiliarSobrenome]!='\0'){
		sobrenome[i]=nome[auxiliarSobrenome+1];
		i++;
		auxiliarSobrenome++;
	}
	
	printf("%s,", sobrenome);
	
	for(j=0;j<auxiliarIniciais;j++){
		if(j==0)
			printf("%c.",toupper(nome[j]));
		if(nome[j]==' ' && nome[j+1]!=' ')
			printf("%c.",toupper(nome[j+1]));			
	}
	
	return 0;
}

