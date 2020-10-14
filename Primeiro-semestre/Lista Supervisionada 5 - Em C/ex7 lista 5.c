/* Algoritmo 
Síntese: 
 Objetivo: Mostrar alfabeto.
 Entrada: Letra do alfabeto.
 Saída: O alfabeto a partir da letra inserida.
*/
#include <stdio.h>
#include <stdlib.h>
void mostraAlfabeto(char letraC);

main(){
	char letra;
	printf("Insira uma letra do alfabeto:");
	letra = getche();
	mostraAlfabeto(letra);
	getch();
}

void mostraAlfabeto(char letraC){
	char letraD;
	if (letraC >= 'a'){
		for(letraD = letraC; letraD <= 'z'; letraD++){
			printf("\n %c",letraD);		
		}
	}
	else if(letraC >= 'A') {
		for(letraD = letraC; letraD <= 'Z'; letraD++){
			printf("\n %c",letraD);		
		}
	}
	else {
		printf("Não foi inserido nenhuma letra do alfabeto.");
	}
	
}

