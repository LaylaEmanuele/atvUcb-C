/*Síntese
	Objetivo: Inverter a ordem dos elementos presentes em um vetor de tamanho 100 usando recursividade de função
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define QTD 100

void inverter(float numeros[], int i, int j){
	float aux; 
	
	if(i>=j)
	 	return;
	 	
	aux = numeros[i];
	numeros[i]= numeros[j];
	numeros[j] = aux; 
	
	j--;
	i++;
	
	inverter(numeros, i ,j);
}


int main(void){
	float numeros[QTD];
	int i=0, j=QTD-1;
	
	setlocale(LC_ALL,"Portuguese"); 
	
	for(i=0;i<QTD;i++){
		printf("Digite o %dº número: ", i+1);
		scanf("%f", &numeros[i]);
	}
	
	for(i=0;i<QTD;i++){
		printf("%.2f ", numeros[i]);
	}
	
	printf("\n");
	
	i=0;
	inverter(numeros, i ,j);
	
	for(i=0;i<QTD;i++){
		printf("%.2f ", numeros[i]);
	}
	
	return 0;
}
