/* Algoritmo mediaNota;
Síntese:
 Objetivo: Realizar a média das notas dos estudantes de determinada disciplina.
 Entrada: As três notas do estudante.
 Saída: A média aritmética do estudante.
*/

#include <conio.h> //leitura e escrita.
#include <stdlib.h> //emulador.
#include <stdio.h> //entrada e saída.
#include <locale.h> //idiomas.
#include <math.h> //cálculos.
 
 float calculaMedia(float n1, float n2, float n3);
 float validaNota (float nota);
main() {
    float n1, n2, n3, media, validacao;
    char resposta;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("\n Insira a primeira nota: \n");
        scanf("%f", &n1);
        n1 = validaNota (n1);
        printf("Insira a segunda nota: \n");
        scanf("%f", &n2);
        n2 = validaNota (n2); 
        printf("Insira a terceira nota: \n");
        scanf("%f", &n3);
        n3 = validaNota (n3);
	
        system("cls");
        media = calculaMedia(n1, n2, n3);
        printf("A média do(a) aluno(a) é: %.2f", media);
        printf("\nDeseja continuar? Se 'SIM' digite 'S'. \n");
        resposta = getche();
        if(resposta >= 97 && resposta <= 122){
            resposta-= 32;
        }
    } while (resposta =='S');
    getch();
} 

 float calculaMedia(float n1, float n2, float n3){
     float resultado;
     resultado = (n1 + n2 + n3) / 3;
     return resultado; 
 }
 
 float validaNota (float nota){
 	while(nota > 10 || nota < 0) {
		printf("\n ERRO! Insira novamente nota: \n");
        scanf("%f", &nota);
	}
 	return nota;
 }
