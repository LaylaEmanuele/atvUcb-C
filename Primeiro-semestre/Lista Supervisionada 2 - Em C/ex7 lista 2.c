/* Algoritmo diferancaNumero;
Síntese 
 Objetivo:  Apresentar a diferença do maior pelo menor.
 Entrada: Os dois números quaisquer.
 Saída: Uma mensagem apresentando a diferença deles.
*/

#include <math.h> //cálculos
#include <conio.h> //leitura e escrita 
#include <stdlib.h> //emulador 
#include <stdio.h> //entrada e saída
#include <locale.h> //idiomas 

main(){
	setlocale(LC_ALL, "Portuguese");
	float n1, n2;
	printf("Digite o primeiro número: ");
	scanf("%f", &n1);
	printf("Digite o segundo número: ");
	scanf("%f", &n2);
	
	system ("cls");
	if(n1 > n2){
		printf("A diferença é: %.2f ", n1-n2);
	}
	if(n1 < n2){
		printf("A diferença é: %.2f", n2-n1);
	}
	getch();
}

