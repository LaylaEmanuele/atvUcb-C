/*Síntese
	Objetivo: Informar quantas vezes um dígito aparece em um nº.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pesquisar(int num, int pesq, int ocorre){
	
	if(num==0)
		return ocorre;
	if(num%10==pesq)
		ocorre++;
	num=num/10;	
	pesquisar(num, pesq, ocorre); 
}

int main(void){
	int numero, pesquisa, ocorrencias=0; //refere-se ao nº digitado e ao nº a ser pesquisado, respectivamente 

	setlocale(LC_ALL,"Portuguese");

	printf("Digite o número:\n");
	scanf("%d",&numero);
	printf("Insira o número a ser pesquisado dentro do número já informado:\n");
	scanf("%d",&pesquisa);
	
	ocorrencias=pesquisar(numero, pesquisa, ocorrencias);	
	printf("O número de ocorrências do número a ser pesquisado foi: %d", ocorrencias);
	
	return 0;
}
