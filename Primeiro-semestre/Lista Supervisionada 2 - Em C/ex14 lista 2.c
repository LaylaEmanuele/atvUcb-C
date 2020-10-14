/* Algoritmo numeroMaior;
Síntese
 Objetivo: Mostrar qual é o maior número.
 Entrada : 3 números quaisquer.
 Saída : O maior número entre os três.
*/
 #include <conio.h> //leitura e escrita 
 #include <stdio.h> //entrada e saída 
 #include <stdlib.h> //emulador
 #include <locale.h> //idiomas
 #include <math.h> //cálculos
 
 main(){
    float n1, n2, n3;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o primeiro número: \n");
    scanf("%f", &n1);
     printf("Digite o segundo número: \n");
    scanf("%f", &n2);
     printf("Digite o terceiro número: \n");
    scanf("%f", &n3);
     if ((n1>n2) && (n1>n3)){
         printf("O %.2f é o maior.", n1);
     }
     if ((n2>n1) && (n2>n3)){
         printf("O %.2f é o maior.", n2);
     }
    if ((n3>n2) && (n3>n1)){
        printf("O %.2f é o maior.", n3);
    }
    if ((n1==n2) && (n1==n3)){
        printf("Os números %.2f são os maiores.", n1);
    }
	getch();
 }
