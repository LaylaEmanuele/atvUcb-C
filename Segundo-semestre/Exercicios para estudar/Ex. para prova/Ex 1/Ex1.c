#include <stdio.h>
#include <stdlib.h>


int main(void){
	FILE *arq;
	char caracter;
	
	arq=fopen("arq.txt","rw");
	//gravação no arquivo
	do{
		printf("\nDigite 0 para terminar\n");
		caracter=getche();
		
		fprintf(arq, "%c", caracter);
	
	}while(caracter!='0');
	
	
	
	//leitura
	system("cls");
	
	
	do{
		fscanf(arq, "%c", &caracter);
		if(caracter !='0')
			printf("%c", caracter);
	 }while(caracter !='0');
	
	fclose(arq);
	
	return 0;
}
