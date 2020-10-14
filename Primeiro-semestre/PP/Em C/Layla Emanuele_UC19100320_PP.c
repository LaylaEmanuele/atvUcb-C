/* 	Layla Emanuele Efren Costa 
	UC19100320
	21-06-2019	
*/
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
 
 char leValidaNome(char nomeEvento[], int i);
 int leValidaQTDGasto(int gastosQTDEventos);
 float leValidaGasto(float gastosEvento[], int i, int gastosQTDEventos, int j);
 float calculaMedia(int gastosQTDEventos, float somaGastos,float gastosEvento[], int i, int j);
main(){
	setlocale(LC_ALL,"Portuguese");
	int i, j, gastosQTDEventos;
	float gastosEvento[50], somaGastos, mediaGastos;	
	char nomeEvento [100];
	somaGastos = 0;
	leValidaNome(nomeEvento, i); 
	gastosQTDEventos= leValidaQTDGasto(gastosQTDEventos);
	leValidaGasto(gastosEvento, i, gastosQTDEventos, j);
	getche();
	
	system("cls");
	
	printf("Evento: %s",nomeEvento);
	printf("Sequencial          Gastos(R$)  ");
	for(j=0;j<gastosQTDEventos;j++) {
		printf("%i    %f\n",j+1, gastosEvento[j]);
	}
	mediaGastos = calculaMedia(gastosQTDEventos, somaGastos,gastosEvento, i, j);
	printf("A média dos gastos = %f",mediaGastos);
	
} 

 char leValidaNome(char nomeEvento[], int i){
	 do {
		printf("\nInforme o nome do Evento:\n");
		gets(nomeEvento);
		fflush(stdin);
		if(strcmp(nomeEvento,"") == 0){
			printf("ERRO. O nome do Evento não pode ser vazio.\n");
		} 	
	} while(strcmp(nomeEvento,"") == 0);
	for(i=0;i<strlen(nomeEvento);i++){	
	nomeEvento[i] = toupper(nomeEvento[i]);
	}
}
 int leValidaQTDGasto(int gastosQTDEventos){
	do{
		printf("Informe a quantidade de gastos realizados do Evento:\n");
		scanf("%i",&gastosQTDEventos);
		if(gastosQTDEventos < 3 || gastosQTDEventos > 50){
			printf("ERRO. Informe um valor acima de 3 e menor que 50.\n");
		}
		printf("Informe o valor ");
	}while(gastosQTDEventos < 3 || gastosQTDEventos > 50);
	return gastosQTDEventos;
}
 float leValidaGasto(float gastosEvento[], int i, int gastosQTDEventos, int j){
	for(j=0;j<gastosQTDEventos;j++) {
		do{
			printf("Informe o valor gasto:\n");
			scanf("%f",&gastosEvento[j]);
			if(gastosEvento[j] < 5000){
				printf("ERRO. O valor do gasto deve ser acima de R$5000,00.\n");
			}
		}while(gastosEvento[j] < 5000);
		
	}
}
 float calculaMedia(int gastosQTDEventos, float somaGastos,float gastosEvento[], int i, int j){
 	float media;
 	for(j=0;j<gastosQTDEventos;j++) {
 		somaGastos = somaGastos + gastosEvento[j];
 	}
 	media = (somaGastos/gastosQTDEventos);
 	return media;
 }
 
 
 
 
