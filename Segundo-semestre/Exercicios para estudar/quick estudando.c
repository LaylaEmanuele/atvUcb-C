#include <stdlib.h>
#include <stdio.h>

void quick(int vet[], int ini, int fim){
	int recebeI=ini, recebeF=fim, pivo=vet[(ini+fim)/2];
	int aux;
	
	while(recebeI<recebeF){
		
		while(pivo>vet[recebeI] && recebeI<recebeF)
			recebeI++;
		while(pivo<vet[recebeF] && recebeF>recebeI)
			recebeF--;
		if(recebeI<=recebeF){
			aux=vet[recebeI];
			vet[recebeI]=vet[recebeF];
			vet[recebeF]=aux;
			
			recebeI++;
			recebeF--;
		}
	}
	
	if(recebeF>ini)
		quick(vet, ini, recebeF);
	
	if(recebeI<fim)	
		quick(vet, recebeI, fim);	
	
}



int main(void){
	int vet[30], i, j, ini=0, fim=30;

	for(i=0,j=30;i<30;i++,j--){
        vet[i]=j;
    }
    
   for(i=0;i<30;i++){
     	printf("%d\n", vet[i]);  		//desordenado
	}
   
   
   quick(vet, ini, fim);
   
   for(i=0;i<30;i++){
     	printf("%d\n", vet[i]);  		//ordenado
	}
}
