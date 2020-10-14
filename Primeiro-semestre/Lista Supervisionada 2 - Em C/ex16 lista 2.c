/*algoritmo maiorAltura;
Síntese
 Objetivo: Apresentar a maior altura.
 Entrada : Nome  e a altura das pessoas.
 Saída : Apresentar a maior altura.	
*/

#include <conio.h> //leitura e escrita.
#include <stdio.h> //entrada e saída.
#include <stdlib.h> //emulador.
#include <math.h> //cálculos.
#include <locale> //idiomas. 

main() {
	char nome1[500], nome2[500], nome3[500];
	float altura1, altura2, altura3;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o nome da 1º pessoa:\n");
	gets(nome1);
	printf("Digite o nome da 2º pessoa:\n");
	gets(nome2);
	printf("Digite o nome da 3º pessoa:\n");
	gets(nome3);
	printf("Digite a primeira altura:\n");
	scanf("%f", &altura1);
	printf("Digite a segunda altura:\n");
	scanf("%f", &altura2);
	printf("Digite a terceira altura:\n");
	scanf("%f", &altura3);
	
	system("cls");
	if((altura1 > altura2) &&(altura1 > altura3)) {
		printf("A(o) %s é o maior.", nome1);
	}
	if((altura2 > altura1) &&(altura2 > altura3)){
		printf("A(o) %s é o maior.", nome2);
	}
	if ((altura3 > altura2) &&(altura3 > altura1)){
		printf("A(o) %s é o maior.", nome3);
	}
	if ((altura1 == altura2) &&(altura1 == altura3)){
		printf("São iguais as alturas.");
		
	}
	getch();
}
