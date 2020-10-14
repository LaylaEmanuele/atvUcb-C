/*Síntese
	Objetivo: Encontrar o menor elemento de um vetor por meio de uma função recursiva.
	Data: 07/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 5

int menorN(int vet[], int i, int menor){
	
	if(i==TAM)
		return menor;
	if(menor>vet[i])
		menor = vet[i];
		
	menorN(vet, i+1, menor);
}

int main (void){
	int vetor[TAM], i, menor;
	
	setlocale(LC_ALL,"Portuguese");
	
	for(i=0;i<TAM;i++){
		printf("Digite o %dº termo: ",i+1);
		scanf("%d", &vetor[i]);
	}
	
	i=0;
	
	menor=vetor[0];
	
	printf("O menor elemento é:%d ", menorN(vetor, i, menor));
	return 0;
}
