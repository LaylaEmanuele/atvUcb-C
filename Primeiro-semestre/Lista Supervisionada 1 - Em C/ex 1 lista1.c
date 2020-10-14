/* Algoritmo: transformaHoras
Síntese
 Objetivo:  Transformar horas em minutos e segundos.
 Entrada: O número de horas.
 Saída: As horas em minutos e segundos.
 */
 
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() 
{
	int horas, minutos, segundos; 
	setlocale(LC_ALL, "Portuguese");	
	printf("Digite a hora a ser transformada: \n");
	scanf("%i",&horas);
	minutos = horas * 60;
	segundos = horas * 3600;
	system("cls");
	printf("A hora informada foi: %i transformada em minutos: %i transformada em segundos: %i", horas, minutos, segundos );

	getch();
	return 0;
	
}

