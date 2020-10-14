/* Algoritmo: areaCirculo
Síntese
 Objetivo: Calcular a area do círculo.
 Entrada: O raio. 
 Saída: A área do círculo.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.

main ()
{
	float raio, area, expoente;
	expoente = 2;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o valor do raio: \n");
	scanf("%f",&raio);
	area = 3.14 * pow(raio, expoente);	
	system("cls");
	printf("A área do círculo é: %.2f", area);
	getch();
}
