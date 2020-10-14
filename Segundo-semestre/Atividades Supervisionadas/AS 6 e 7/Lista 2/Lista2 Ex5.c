/*Síntese 
	Objetivo: Armazenar o gabarito de uma loteria esportiva e comparar com as respostas do usuário.
	Data: 29/08/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdlib.h>
#include <stdio.h>

int main(void){
	int gabarito[13], resposta[13], i, acertos=0;
	
	printf("Insira o gabarito:\n");
	for(i=0;i<13;i++){
		scanf("%d",&gabarito[i]);
	}
	
	printf("Insira as suas respostas:\n");
	for(i=0;i<13;i++){	
		scanf("%d",&resposta[i]);
	}
	
	for(i=0;i<13;i++){
		if(resposta[i]==gabarito[i])
			acertos++;
	}
	
	system("cls");
	if(acertos==13)
		printf("Ganhador");
	else		
		printf("Infelizmente sua quantidade de acertos %d não foi suficiente para ganhar", acertos);
}
