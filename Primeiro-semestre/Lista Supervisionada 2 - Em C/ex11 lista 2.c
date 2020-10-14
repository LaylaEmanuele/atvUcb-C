/*Algoritmo tipoTriangulo;
Síntese
 Objetivo: Verificar o tipo de triângulo formado de acordo com a medida do seus lados.
 Entrada : 3 números quaiquer.
 Saída : Qual tipo de triângulo formado. 
*/
#include <locale.h> //idiomas 
#include <math.h> //cálculos
#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e saída
#include <stdlib.h> //emulador 
main(){
	float n1, n2, n3;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o primeiro número: \n");
	scanf("%f", &n1);
	printf("Digite o segundo número: \n");
	scanf("%f", &n2);	
	printf("Digite o terceiro número: \n");
	scanf("%f", &n3);	
	
	if(n1<(n2+n3) && n2<(n1+n3) && n3<(n2+n1)) {
        printf("O triângulo poderá ser formado.");
        	if((n1==n2) && (n2==n3 ) && (n3==n1 )) {
       	     printf("O triângulo formado é equilátero.");
        	} 
				else if ((n1==n2) && (n2!=n3 ) && (n3!=n1 )) {
					printf("O triângulo formado é isósceles.");
        		}		 
					else if((n1!=n2) && (n2!=n3 ) && (n3!=n1 )) {
        			    printf("O triângulo formado é escaleno");
        			}	 
}
    else
    printf("O triângulo não será formado");
    getch();
}
