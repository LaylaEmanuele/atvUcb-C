/* Algoritmo: resto_quociente;
Síntese
 Objetivo: Fazer a leitura do resto e do quociente.
 Entrada: Os dois números que serão usados para realizar a divisão.
 Saída: O resto e quociente.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.

main ()
{
	int  n1, n2, resto, quociente;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o primeiro número: \n");
	scanf("%i",&n1);
	printf("Informe o segundo número: \n");
	scanf("%i",&n2);
	resto = n1 % n2;
	quociente = n1 / n2;
	system("cls");
	printf("O resto é: %i", resto);
	printf("\nO quociente é: %i", quociente);
	getch();
}

