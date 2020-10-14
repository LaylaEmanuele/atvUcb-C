/* Algoritmo DDD;
Síntese 
 Objetivo: Informar de qual região é o DDD.
 Entrada: O número de telefone.
 Saída: Qual lugar é o DDD.
*/

#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e saida
#include <stdlib.h> //emulador
#include <math.h> //cálculos
#include <locale.h> //idiomas

main(){
	setlocale(LC_ALL, "Portuguese");
	int ddd, telefone;
	printf("Informe seu DDD: ");
	scanf("%i", &ddd);
	printf("Informe seu número de telefone: ");
	scanf("%i", &telefone);
	
	system("cls");
	
	if(ddd == 61){
		printf("O DDD é de Brasília.");
	}
	if(ddd == 71){
		printf("O DDD é de Salvador.");
	}
	if(ddd == 11){
		printf("O DDD é de São Paulo.");
	}
	if(ddd == 21){
		printf("O DDD é de Rio de Janeiro.");
	}
	if(ddd == 32){
		printf("O DDD é de Juiz de Fora.");
	}
	if(ddd == 19){
		printf("O DDD é de Campinas.");
	}
	if(ddd == 27){
		printf("O DDD é de Campinas.");
	}
	if(ddd == 31){
		printf("O DDD é de Belo Horizonte");
	}
	getch();
}


