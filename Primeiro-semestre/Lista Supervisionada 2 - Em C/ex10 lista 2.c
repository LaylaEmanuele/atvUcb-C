/* Algoritmo  qualNumeroMenor;
Síntese
 Objetivo: Encontrar o menor número entre os números informados.
 Entrada: Três números quais quer.
 Saída: Uma mensagem informando qual o menor número.
*/

#include <math.h> //para cálculos básicos
#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e saída
#include <stdlib.h> //emulador
#include <locale.h> //idioma

main (){
	setlocale(LC_ALL, "Portuguese");
	float n1, n2, n3;
	printf("Digite o primeiro número: ");
	scanf("%f", &n1);
	printf("Digite o segundo número: ");
	scanf("%f", &n2);
	printf("Digite o terceiro número: ");
	scanf("%f", &n3);
	
	system("cls");
	
	if((n1 < n2) && (n1 < n3)){
		printf("O número %.2f é o menor", n1);
	}
	if((n2 < n1) && (n2 < n3)){
		printf("O número %.2f é o menor", n2);
	}
	if((n3 < n2) && (n3 < n1)){
		printf("O número %.2f é o menor", n3);
	}
	getch();	
}
