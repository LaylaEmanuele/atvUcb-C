#include <stdlib.h>
#include <stdio.h>

int buscar(int vet[], int ini, int fim, int chave){
	int meio=(ini+fim)/2;
	
	if(chave==vet[meio])
		return meio;
	else if(chave>vet[meio])
		ini=meio+1;
	else if(chave<vet[meio])
		fim=meio-1;
	if(ini>fim)
		return -1;
	buscar(vet, ini, fim, chave);
}

int main (void){
	int vet [100], i, inicio=0, fim=99, chave, buscaB;
	
	for(i=0;i<100;i++)
		vet[i]=i;	
	printf("Digite o valor a ser pesquisado:");
	scanf("%d",&chave);
		
	buscaB = buscar(vet, inicio, fim, chave);
	
	if(buscaB==-1)
		printf("O número não foi encontrado");
	else
		printf("O número foi encontrado na posição %d", buscaB);
	return 0;
}
