/*Algoritmo tempoVida;
Síntese
 Objetivo: Saber quanto tempo a pessoa já viveu.
 Entrada : Ano de nascimento e ano atual.
 Saída : O nome da pessoa e número de dias que ela viveu aproximadamente. 
*/

#include <conio.h> //leitura e escrita.
#include <stdio.h> //entrada e saída.
#include <stdlib.h> //emulador.
#include <math.h> //cálculos.
#include <locale.h> //idioma. 

main(){
	int nascimento, atual, calculo1,calculo2, dias;
	char nome[50];
	setlocale(LC_ALL, "Portuguese");
	printf("Digite seu nome: \n");
	gets(nome);
	printf("Digite o ano do seu nascimento: ");
	scanf("%i", &nascimento);
	printf("Informe o ano atual: ");
	scanf("%i", &atual);
	calculo1 = atual - nascimento;
	calculo2 = calculo1 * 365;
	dias = calculo2;
	
	system("cls");
	printf("O tempo que você está vivo em dias é: %i ", dias);
	getch();
}


