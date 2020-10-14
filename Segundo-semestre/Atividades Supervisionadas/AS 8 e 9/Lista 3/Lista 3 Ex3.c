/*Síntese
	Objetivo: Realiazar o cálculo de uma potenciação por meio de uma função recursiva.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int potenciar(int k, int n, int j, int mult){
	
	if(j==n)
		return mult;
		
	mult=k*mult;
	j++;
	
	potenciar(k,n,j,mult);
}



int main(void){
	int k, n;	//base e expoente, respectivamente
	int multiplicacao=1, j=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Informe o número que será a base de sua exponenciação:\n");
	scanf("%d",&k);
	printf("Informe o número que será a expoente de sua exponenciação:\n");
	scanf("%d",&n);
	
	multiplicacao = potenciar(k,n,j,multiplicacao);
	printf("O resultado da potenciação é: %d",multiplicacao);
	
	return 0;
}
