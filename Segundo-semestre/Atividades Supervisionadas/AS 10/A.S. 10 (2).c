/*Síntese:
	Objetivo: Realizar uma pesquisa(binária e sequencial) por funções(recursiva e iterativa), analisar quantas vezes realizou a leitura de cada posição e apresentar em um gráfico.
	Data: 10/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pesquisarB_iterativa(int vet[], int chave, int qtd[]) {    //função iterativa pesquisa binária
	int inicio=0, fim=1023, meio=(inicio+fim)/2;

	while(inicio<=fim && chave!=vet[meio]) {
		meio=(inicio+fim)/2;
		if(chave == vet[meio])
			return meio;
		else if(chave > vet[meio])
			inicio = meio+1;
		else if(chave < vet[meio])
			fim = meio-1;
		qtd[chave]++;
	}

	if(inicio>fim)
		return -1;
}

int pesquisarB_recursiva(int vet[], int chave, int meio, int inicio, int fim) { //função m recursiva pesquisa binária

	meio=(inicio+fim)/2;

	if(chave == vet[meio])
		return meio;
	else if(chave > vet[meio])
		inicio = meio+1;
	else if(chave < vet[meio])
		fim = meio-1;

	if(inicio>fim)
		return -1;

	pesquisarB_recursiva(vet, chave, meio, inicio, fim);
}

int pesquisarS_iterativa(int vet[], int chave, int fim, int i) { //função iterativa pesquisa sequencial

	while(i<=fim && chave!=vet[i])
		i++;

	if(i>fim)
		return -1;
	else
		return i;
}

int pesquisarS_recursiva(int vet[], int chave, int fim, int i) { //função recursiva pesquisa sequencial

	i++;
	if(chave == vet[i])
		return i;
	else if (i == fim)
		return -1;

	pesquisarS_recursiva(vet,chave,fim,i);
}

int main(void) {
	int vetor[1024], qtdPbinaria[1024], i=0, chave, meio=0, inicio=0, fim=1023, pos;
	setlocale(LC_ALL,"Portuguese");

	for(i=0; i<1024; i++) {
		vetor[i]=i;
		qtdPbinaria[i]=0;
	}
	i=0;

	printf("Qual a o número que você deseja procurar?\n");
	scanf("%d",&chave);

	printf("\n\nPesquisa binária iterativa: \n\n");
	pos=pesquisarB_iterativa(vetor, chave, qtdPbinaria);
	if(pos!=-1)
		printf("O número %d foi encontrado na posição %d com %d pesquisas",chave ,pos+1, qtdPbinaria[chave]);
	else
		printf("O número não foi encontrado!");

	printf("\n\nPesquisa binária recursiva: \n\n");
	pos=pesquisarB_recursiva(vetor, chave, meio, inicio, fim);
	if(pos!=-1)
		printf("O número %d foi encontrado na posição %d com %d pesquisas",chave ,pos+1, qtdPbinaria[chave]);
	else
		printf("O número não foi encontrado!");


	printf("\n\nPesquisa sequencial iterativa: \n\n");
	pos=pesquisarS_iterativa(vetor, chave, fim, i);
	if(pos!=-1)
		printf("O número %d foi encontrado na posição %d com %d pesquisas",chave ,pos+1, pos);
	else
		printf("O número não foi encontrado!");

	printf("\n\nPesquisa sequencial recursiva: \n\n");
	pos=pesquisarS_recursiva(vetor, chave, fim, i);
	if(pos!=-1)
		printf("O número %d foi encontrado na posição %d com %d pesquisas",chave ,pos+1, pos);
	else
		printf("O número não foi encontrado!");

	/*
	printf("Posição, Valor, Quantidade\n");
	for(i=0; i<1024; i++){
		pesquisarB_iterativa(vetor, i, qtdPbinaria);
		printf("%d, %d, %d\n", i+1, vetor[i], qtdPbinaria[i]);
	}
	*/

	return 0;
}
