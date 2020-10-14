/*Síntese
Objetivo: Armazenar as temperaturas médias de 3 anos, mostrar a maior e menor temperatura de cada ano e a maior e menor dos 3 anos.
Data: 02/09/2019
Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ANOS 3
#define MESES 12

int main(void){

	float temps[ANOS][MESES], maiorTempAno, menorTempAno, maiorT=0, menorT=100;
	int ano, mes; 
	char mesesExt[12][20] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
	  
	setlocale(LC_ALL,"Portuguese");
	
	for(ano=0;ano<ANOS;ano++)
		for(mes=0;mes<MESES;mes++){
			printf("Insira a temperatura do mês de %s do %dº ano: ", mesesExt[mes], ano+1);
			scanf("%f",&temps[ano][mes]);
		}
	for(ano=0;ano<ANOS;ano++){
		maiorTempAno = 0;
		menorTempAno = 100;
		for(mes=0;mes<MESES;mes++){
			if(temps[ano][mes]>maiorTempAno)
				maiorTempAno = temps[ano][mes];
			if(temps[ano][mes]<menorTempAno)
				menorTempAno = temps[ano][mes];	
			if(temps[ano][mes]>maiorT)	
				maiorT = temps[ano][mes];
			if(temps[ano][mes]<menorT)	
				menorT = temps[ano][];
		}		
		printf("A maior temperatura do %dº ano foi de %.1f\n",ano+1, maiorTempAno);
		printf("A menor temperatura do %dº ano foi de %.1f\n",ano+1, menorTempAno);
	}
	printf("A maior temperatura registrada foi de %.1f\n",maiorT);
	printf("A menor temperatura registrada foi de %.1f\n",menorT);
	
	return 0;
}

