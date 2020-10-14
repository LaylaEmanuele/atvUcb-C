/*Síntese
	Objetivo: Criar os métodos de ordenação bubble e select para medir as performances individuais.
	Data: 17/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM 10000

int contador;

int bubble(int teste[]){
	int i,j,aux;
	
	contador=0;
	
	for(i=0;i<TAM-1;i++){
		for(j=i+1;j<TAM;j++){
			if(teste[j]<teste[i]){
				aux=teste[j];
				teste[j]=teste[i];
				teste[i]=aux;
				
				contador++;
			}
		}
	}
		
}

int select(int teste[]){
	int i,j,indice_menor,aux;
	
	contador=0;
	
	for(i=0;i<TAM-1;i++){
		indice_menor=i;
		for(j=i+1;j<TAM;j++){
			if(teste[j]<teste[indice_menor]){				
				indice_menor=j;
				
				contador++;
			}
		}
		aux=teste[indice_menor];
		teste[indice_menor]=teste[i];
		teste[i]=aux;
	}
	
}

int main (void){
	int i, teste1[TAM], teste2[TAM], teste3[TAM], teste4[TAM], teste5[TAM], teste1C[TAM], teste2C[TAM], teste3C[TAM], teste4C[TAM], teste5C[TAM], mediaB=0, mediaS=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	srand(time(NULL));
	
	for(i=0;i<TAM;i++){
		teste1[i]=(rand() % 1000000);
		teste1C[i]=teste1[i];
		teste2[i]=(rand() % 1000000);
		teste2C[i]=teste2[i];
		teste3[i]=(rand() % 1000000);
		teste3C[i]=teste3[i];
		teste4[i]=(rand() % 1000000);
		teste4C[i]=teste4[i];
		teste5[i]=(rand() % 1000000);
		teste5C[i]=teste5[i];
	}
	
	bubble(teste1);
	mediaB+=contador;
	printf("%d\n",contador);
	bubble(teste2);
	mediaB+=contador;
	printf("%d\n",contador);
	bubble(teste3);
	mediaB+=contador;
	printf("%d\n",contador);
	bubble(teste4);
	mediaB+=contador;
	printf("%d\n",contador);
	bubble(teste5);
	mediaB+=contador;
	printf("%d\n",contador);
	
	mediaB=mediaB/5;
	
	select(teste1C);
	mediaS+=contador;
	printf("%d\n",contador);
	select(teste2C);
	mediaS+=contador;
	printf("%d\n",contador);
	select(teste3C);
	mediaS+=contador;
	printf("%d\n",contador);
	select(teste4C);
	mediaS+=contador;
	printf("%d\n",contador);
	select(teste5C);
	mediaS+=contador;
	printf("%d\n",contador);
	
	mediaS=mediaS/5;
	
	
	printf("A média da quantidade de trocas ocorridas no bubble foi de: %d\n", mediaB);
	printf("A média da quantidade de trocas ocorridas no select foi de: %d\n", mediaS);
	
	
	
	return 0;
}
