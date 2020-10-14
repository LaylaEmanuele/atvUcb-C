/*Síntese
Objetivo: Receber uma matriz de caracteres e uma palavra e verificar se a palavra aparece na matriz.
Data: 02/09/2019
Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void){
	int i=0, tamanhoP=0, achei=0;
	char cacaPalavras[5][5], palavra[20], posL, posC;
	
	setlocale(LC_ALL,"Portuguese");
	
	for(posL=0;posL<5;posL++)
		for(posC=0;posC<5;posC++){
			printf("Insira as letras do caça palavras:");
			cacaPalavras[posL][posC] = getche();
			printf("\n");
		}
	system("cls");
		
	printf("Insira a palavra que você deseja encontra:");
	gets(palavra);
	tamanhoP=strlen(palavra);
	
	for(posL=0;posL<5;posL++){
		i=0;
		for(posC=0;posC<5;posC++){
			if(cacaPalavras[posL][posC]==palavra[i]) 
				i++;
			else{
				posC-=i;
				i=0;
			}
			if(i==tamanhoP)
				achei = 1;
		}
	}
		
	for(posC=0;posC<5;posC++){
		i=0;
		for(posL=0;posL<5;posL++){
			if(cacaPalavras[posL][posC]==palavra[i]) 
				i++;
			else{
				posL-=i;
				i=0;
			}
			if(i==tamanhoP)
				achei = 1;	
		}
	}
	
	if(achei==1)
		printf("A palavra foi encontrada.");
	else 
		printf("A palavra não foi encontrada.");
		
	return 0;
}
