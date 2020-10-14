/* Algoritmo: mediaDe3Num;
Síntese
 Objetivo: Calcular a média de três números quaisquer.
 Entrada: Os três números. 
 Saída: A média.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.

main ()
{
	float n1, n2, n3, media;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o primeiro número: \n");
	scanf("%f",&n1);
	printf("Informe o segundo número: \n");
	scanf("%f",&n2);
	printf("Informe o terceiro número: \n");
	scanf("%f",&n3);
	media = (n1 + n2 + n3) / 3;
	system("cls");
	printf("A média dos três números é: %.2f", media);
	getch();
}
