/* Algoritmo nomeSexo;
Síntese
 Objetivo: Informar o peso ideal da pessoa.
 Entrada: Nome, sexo da pessoa e a altura.
 Saída: Aparecera mensagem: “Ilmo. Sr.” ou “Ilma. Sra.” informando em seguida qual o peso ideal.
*/

#include <conio.h> //leitura e escrita
#include <stdlib.h> //emulador 
#include <stdio.h> //entrada e saída
#include <locale> //idiomas
#include <math.h> //cálculos

main(){
	float altura, peso;
	char nome[500], sexo;
	setlocale(LC_ALL, "Portuguese");	
	printf("Digite o seu nome: \n");
	gets(nome);
	printf("Informe seu sexo(F/M): \n");
	sexo = getche();
	printf("\n Informe sua altura (utilize ',' e não '.'): \n");
	scanf("%f", &altura);
	
	if(sexo>='a' && sexo <='z') {
	sexo=sexo-32;
	}

	if( sexo =='F'){
		peso = (62.1 * altura) - 44.7;
		printf("Ilma. Sra. %s seu peso ideal é: %.2f", nome, peso );
	}
	
	 if( sexo =='M'){
	 	peso = (72.5 * altura) - 58;
		printf("Ilmo. Sr. %s seu peso ideal é %.2f", nome, peso);
	}
	getch();
}

