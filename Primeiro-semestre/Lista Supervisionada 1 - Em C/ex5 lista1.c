/* Algoritmo: rolos;
Síntese
 Objetivo: Auxiliar um construtor a descobrir a quantidade de rolos e a quantidade de metros avulsos de fios que ele precisa adquirir.
 Entrada: Quantidade de metros.
 Saída: Quantidade de rolos e o que sobra.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.

main ()
{
	int  tamanhoDoRolo, quantoRolo, restoRolo;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Digite a quantidade de metros:\n");
	scanf("%i",&tamanhoDoRolo);
	quantoRolo = tamanhoDoRolo / 50;
	restoRolo = tamanhoDoRolo % 50;
	system("cls");
	printf("Quantidade de rolos é:  %i", quantoRolo);
	printf("\nRestará: %i metros de rolo", restoRolo);
	getch();
}
