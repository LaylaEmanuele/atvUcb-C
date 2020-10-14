 /* Algoritmo: moduloNumero;
Síntese
 Objetivo: Informar o módulo de um número qualquer.
 Entrada: Um número qualquer.
 Saída: O módulo do número.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.


main() 
{
	float n1;
	setlocale(LC_ALL, "Portuguese");	
	printf("Informe um número qualquer: \n");
	scanf("%f", &n1);
	system("cls");
	if(n1 > 0) {
		printf("O módulo do número é: %.2f", n1);
	}
	if(n1 < 0){
		n1=n1*-1;
		printf("Então módulo do número é: %.2f", n1);
	}
	getch();
}

