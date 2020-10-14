#include <stdlib.h>
#include <stdio.h>

int buscar(int vet[], int chave){
	int inicio=0, fim=99, meio=(inicio+fim)/2;
	
	while(chave!=vet[meio] && inicio<=fim){
		meio=(inicio+fim)/2;
		if(chave==vet[meio])
			return meio;
		else if(chave>vet[meio])
			inicio=meio+1;
		else if(chave<vet[meio])
			fim=meio-1;		
	}
	
	if(inicio>fim)
		return -1;

}

int main (void){
	int vet [100], i, chave, buscaB;
	
	for(i=0;i<100;i++)
		vet[i]=i;	
	printf("Digite o valor a ser pesquisado:");
	scanf("%d",&chave);
		
	buscaB = buscar(vet, chave);
	
	if(buscaB==-1)
		printf("O número não foi encontrado");
	else
		printf("O número foi encontrado na posição %d", buscaB);
	return 0;
}
