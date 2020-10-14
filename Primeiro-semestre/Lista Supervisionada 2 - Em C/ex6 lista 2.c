/* Algoritmo parOuImpar;
Síntese
 Objetivo: Determinar se um número inteiro é par ou ímpar.
 Entrada: Um número qualquer.
 Saída: Se o número é par ou ímpar.	
*/

#include <conio.h> //possibilita fazer a leitura a escrita
#include <math.h> //fazer cálculos
#include <stdlib.h> //emulador para o sistema operacional 
#include <stdio.h> //entrada e saída
#include <locale.h> //para idiomas 

main()
 {
	int n1, parImpar;
	setlocale(LC_ALL ,"Portuguese");
	printf("Informe o número: ");
	scanf("%i", &n1);
	parImpar = n1 % 2;
	
	system("cls");
	if(parImpar == 0){
		printf("O número informado é par!");
	}
	else {
		printf("O número informado é ímpar!");
	}
	getch();
}

