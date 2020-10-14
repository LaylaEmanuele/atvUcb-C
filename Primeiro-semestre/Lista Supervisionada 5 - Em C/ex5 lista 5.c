/* Algoritmo potenciacao;
 Síntese
 Objetivo: Fazer o cálculo de potenciação por meio de um sub-algoritmo utilizando procedimento.
 Entrada : O expoente e a base.
 Saída : O resultado do cálculo.
*/

#include <conio.h> //leitura e escrita.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void exponencial ( float base, int expoente);

main(){
	setlocale(LC_ALL,"Portuguese");
	float base;
	int expoente;
 	printf("Informe a base do expoente: ");
	scanf("%f", &base);
	printf("Informe o expoente que é o número que elevará a base: ");
	scanf("%i", &expoente);
	exponencial(base, expoente);
	getch();
}

void exponencial ( float base, int expoente){

	float rp;
	int i;
	rp=1;

	for( i = 0; i<expoente; i++){
	
	rp=rp*base;
	}
	system("cls");
	printf("O resultado do cálculo é: %.2f", rp);	
}
