/*Síntese 
	Objetivo: Ler as duas primeiras linhas de uma matriz 3x10 e realizar a soma das colunas das duas primeiras linhas e inserir o valor da soma na terceira linha.
	Data: 29/08/2019.
	Autores: Gabriel Raposo e Layla Emanuele.

*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void){
	int valorDado[100], i, cont1=0, cont2=0, cont3=0, cont4=0, cont5=0, cont6=0;
	
	srand(time(NULL));
	
	for(i=0;i<100;i++)
		valorDado[i]=(rand()%6)+1;
	
	for(i=0;i<100;i++){
		if(valorDado[i] == 1)
			cont1++;
		else if(valorDado[i] == 2)
			cont2++;
		else if(valorDado[i] == 3)
			cont3++;	
		else if(valorDado[i] == 4)
			cont4++;
		else if(valorDado[i] == 5)
			cont5++;
		else
			cont6++;	
	}
	
	printf("A quantidade de dados que obtiveram o valor 1 foi de: %d\n", cont1);	
	printf("A quantidade de dados que obtiveram o valor 2 foi de: %d\n", cont2);	
	printf("A quantidade de dados que obtiveram o valor 3 foi de: %d\n", cont3);	
	printf("A quantidade de dados que obtiveram o valor 4 foi de: %d\n", cont4);	
	printf("A quantidade de dados que obtiveram o valor 5 foi de: %d\n", cont5);	
	printf("A quantidade de dados que obtiveram o valor 6 foi de: %d\n", cont6);	

	return 0;
}

