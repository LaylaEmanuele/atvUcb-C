 /* Algoritmo: ladoTriangulo;
Síntese
 Objetivo:Verificar se os 3 números podem ser o lado de um triângulo.
 Entrada: 3 números quaiquer.
 Saída: Se podem ser o não um triângulo.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.


main() 
{
	float n1,n2,n3;
	setlocale(LC_ALL, "Portuguese");	
	printf(" Digite o primeiro número: \n");
	scanf("%f", &n1);
	printf(" Digite o segundo número: \n");
	scanf("%f", &n2);
	printf(" Digite o terceiro número: \n");
	scanf("%f", &n3);
	system("cls");
	if((n1<n2+n3) &&(n2<n1+n3 ) &&(n3<n2+n1)) {
		printf("O triângulo pode ser formado.");
	}
	else{
		printf("O triângulo não será formado.");
	}
	getch();
}

