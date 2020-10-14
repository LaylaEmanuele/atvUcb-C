/*Síntese:
	Objetivo: Realizar uma pesquisa(binária e sequencial) por funções(recursiva e iterativa), analisar quantas vezes realizou a leitura de cada posição e apresentar em um gráfico.
	Data: 10/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void pesquisarBI(int vet[], int chave){     //função iterativa pesquisa binária
	int meio, inicio=0, fim=1023, achou=0;
	
	do{
		meio=(inicio+fim)/2;
		
		if(chave == vet[meio]){
			printf("O nº foi encontrado!");
			achou = 1;
		}	
		else if(chave > vet[meio])
			inicio = meio+1;
		else if(chave < vet[meio])
			fim = meio-1;
	}while(inicio<=fim && achou!=1);
	
	if(achou == 0)
		printf("O nº não foi encontrado!");
}

void pesquisarBR(int vet[], int chave, int meio, int inicio, int fim, int qtdPesquisaB[]){ //função recursiva pesquisa binária
	int achou=0; 
	qtdPesquisaB[chave]++;
	
	meio=(inicio+fim)/2;
	if(chave == vet[meio]){
		printf("O nº foi encontrado!");
		achou = 1;
	}	
	else if(chave > vet[meio])
		inicio = meio+1;
	else if(chave < vet[meio])
		fim = meio-1;
			
	if(inicio>fim ||  achou==1){
		if(achou==0)
			printf("O nº não foi encontrado!");
		return;
	}
	
	pesquisarBR(vet, chave, meio, inicio, fim, qtdPesquisaB);
}

void pesquisarSI(int vet[], int chave, int fim){ //função iterativa pesquisa sequencial 
	int i=0, achou=0;
	
	do{
		if(chave==vet[i]){
			printf("O nº foi encontrado!");
			achou=1;
		}
		else if(chave!=vet[i])
			i++;	
	}while(achou!=1 && i<=fim);
	
	if(achou==0)
		printf("O nº não foi encontrado!");
}

void pesquisarSR(int vet[], int i, int chave, int fim){ //função recursisa pesquisa sequencial 
	if(chave == vet[i] || i > fim){
		if(chave == vet[i])
			printf("O nº foi encontrado!");
		else
			printf("O n° não foi encontrado!");			
		return;
	}
	pesquisarSR(vet, i+1, chave, fim);

}

int main(void){
	int vetor[1024], i, chave, qtdPesquisaB[1024];
	int meio=0, inicio=0, fim=1023;
	setlocale(LC_ALL,"Portuguese");

	for(i=0;i<1024;i++)
		vetor[i]=i; 
	printf("Digite o nº a ser pesquisado:");
	scanf("%d", &chave);
	for(i=0;i<1024;i++)
		qtdPesquisaB[i]=0;
	i=0;
	
//	pesquisarBI(vetor, chave);
//	pesquisarBR(vetor, chave, meio, inicio, fim);
	
	for(chave=0;chave<1024;chave++)
		pesquisarBR(vetor, chave, meio, inicio, fim, qtdPesquisaB);
		
	system("cls");
		
	for(i=0;i<1024;i++)
		printf("%d\n",qtdPesquisaB[i]);
//	pesquisarSI(vetor, chave, fim);
//	pesquisarSR(vetor, i, chave, fim);
	
	return 0;
}
