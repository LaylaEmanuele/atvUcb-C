/*Síntese
	Objetivo: Criar os métodos de ordenação bubble e select para medir as performances individuais.
	Data: 29/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM 10000

int contador;

int bubble(int teste[]) {
	int i,j,aux;

	contador=0;

	for(i=0; i<TAM-1; i++) {
		for(j=i+1; j<TAM; j++) {
			if(teste[j]<teste[i]) {
				aux=teste[j];
				teste[j]=teste[i];
				teste[i]=aux;

				contador++;
			}
		}
	}

}

int select(int teste[]) {
	int i,j,indice_menor,aux;

	contador=0;

	for(i=0; i<TAM-1; i++) {
		indice_menor=i;
		for(j=i+1; j<TAM; j++) {
			if(teste[j]<teste[indice_menor]) {
				indice_menor=j;
				contador++;
			}
		}
		aux=teste[indice_menor];
		teste[indice_menor]=teste[i];
		teste[i]=aux;
	}

}

void quick(int vet[], int inicio, int fim) {
	int i = inicio, j = fim;
	int pivo = vet[(inicio + fim) / 2];
	int aux;

	while (i < j) {
		contador++;
		while(pivo > vet[i] && i < fim) {
			i++;
		}

		while(pivo < vet[j] && j > inicio) {
			j--;
		}

		if (i<=j) {
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;
		}
	}

	if (j > inicio) {
		quick(vet, inicio, j);
	}


	if (i < fim) {
		quick(vet, i, fim);
	}

}

void insertion(int vet[]) {
	int i=0, j=1, k, z, aux;

	contador=0;

	while(j<TAM) {
		if(vet[i]>vet[j]) {
			contador++;
			aux=vet[j];
			vet[j]=vet[i];
			vet[i]=aux;
			
			k=i;
			z=i-1;
			
			while(vet[k]<vet[z] && z>=0) {
				contador++;
				aux=vet[k];
				vet[k]=vet[z];
				vet[z]=aux;

				k--;
				z--;
			}
		}
		
		i++;
		j++;
	}

}

int main (void) {
	int i, teste1[TAM], teste2[TAM], teste3[TAM], teste4[TAM], teste5[TAM], teste1C[TAM], teste2C[TAM], teste3C[TAM], teste4C[TAM], teste5C[TAM], teste1Q[TAM], teste2Q[TAM], teste3Q[TAM], teste4Q[TAM], teste5Q[TAM], teste1I[TAM], teste2I[TAM], teste3I[TAM], teste4I[TAM], teste5I[TAM], mediaB=0, mediaS=0, mediaQ=0, mediaI=0;
	int ini=0, fim=TAM-1;

	setlocale(LC_ALL,"Portuguese");

	srand(time(NULL));

	for(i=0; i<TAM; i++) {
		teste1[i]=(rand() % 1000000);
		teste1C[i]=teste1[i];
		teste1Q[i]=teste1[i];
		teste1I[i]=teste1[i];
		teste2[i]=(rand() % 1000000);
		teste2C[i]=teste2[i];
		teste2Q[i]=teste2[i];
		teste2I[i]=teste2[i];
		teste3[i]=(rand() % 1000000);
		teste3C[i]=teste3[i];
		teste3Q[i]=teste3[i];
		teste3I[i]=teste3[i];
		teste4[i]=(rand() % 1000000);
		teste4C[i]=teste4[i];
		teste4Q[i]=teste4[i];
		teste4I[i]=teste4[i];
		teste5[i]=(rand() % 1000000);
		teste5C[i]=teste5[i];
		teste5Q[i]=teste5[i];
		teste5I[i]=teste5[i];
	}

	printf("Bubble: \n");
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

	printf("Select: \n");
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

	printf("Insertion: \n");
	insertion(teste1I);
	mediaI+=contador;
	printf("%d\n",contador);
	insertion(teste2I);
	mediaI+=contador;
	printf("%d\n",contador);
	insertion(teste3I);
	mediaI+=contador;
	printf("%d\n",contador);
	insertion(teste4I);
	mediaI+=contador;
	printf("%d\n",contador);
	insertion(teste5I);
	mediaI+=contador;
	printf("%d\n",contador);
	
	mediaI=mediaI/5;

	printf("Quick: \n");
	contador = 0;
	quick(teste1Q, ini, fim);
	mediaQ+=contador;
	printf("%d\n",contador);
	contador = 0;
	quick(teste2Q, ini, fim);
	mediaQ+=contador;
	printf("%d\n",contador);
	contador = 0;
	quick(teste3Q, ini, fim);
	mediaQ+=contador;
	printf("%d\n",contador);
	contador = 0;
	quick(teste4Q, ini, fim);
	mediaQ+=contador;
	printf("%d\n",contador);
	contador = 0;
	quick(teste5Q, ini, fim);
	mediaQ+=contador;
	printf("%d\n",contador);

	mediaQ=mediaQ/5;



	printf("A média da quantidade de trocas ocorridas no bubble foi de: %d\n", mediaB);
	printf("A média da quantidade de trocas ocorridas no select foi de: %d\n", mediaS);
	printf("A média da quantidade de trocas ocorridas no insertion foi de: %d\n", mediaI);
	printf("A média da quantidade de trocas ocorridas no quick foi de: %d\n", mediaQ);

	return 0;
}

