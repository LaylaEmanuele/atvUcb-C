/* Algoritmo: levarMulta
Síntese
 Objetivo: Informar se ao motorista se ele se multado ou não.
 Entrada: Velocidade e plava do carro.
 Saída: Se foi multado ou não.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas funções de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que você está programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para funções matemáticas básicas.


main() 
{
	float velocidadeCarro;
	char placadoCarro[7];
	setlocale(LC_ALL, "Portuguese");	
	printf("Informe a placa do carro: \n");
	gets(placadoCarro);
	printf("Informe a velocidade do carro: \n");
	scanf("%f",&velocidadeCarro);

	system("cls");
	if(velocidadeCarro >= 80) {
		printf("O carro %s será multado!", placadoCarro);
	}
	else{
		printf("O carro %s não vai ser multado!", placadoCarro);
	}
	getch();
}

