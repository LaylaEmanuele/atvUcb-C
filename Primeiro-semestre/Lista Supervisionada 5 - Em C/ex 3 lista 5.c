/* ALgoritmo operacaoAritmetica;
Síntese:
  Objetivo: Realizar o cálculo de duas operações matemáticas.
  Entrada: Três números quaisquer.
  Saída: Resultado da operação e se o mesmo é maior, menor ou igual a zero.
*/

#include <conio.h> //leitura e escrita.
#include <stdlib.h> //emulador.
#include <stdio.h> //entrada e saída.
#include <math.h> //cálculos. 
#include <locale> //idiomas.

void verificaResultado(float r);
float calc(char resposta1, char resposta2, float n1, float n2, float n3);

main(){
	float n1, n2, n3, r;
	char resposta1, resposta2;
	setlocale(LC_ALL, "Portuguese");
	printf("Informe o primeiro número desejado: ");
	scanf("%f", &n1);
	printf("Informe o segundo número desejado: ");
	scanf("%f", &n2);	
	printf("Informe o terceiro número desejado: ");
	scanf("%f", &n3);	
	printf("Escolha o primeiro operador para realizar a operação metemática.Sendo + para adição, - para subtração, / para divisão e * para multiplicação :\n");
	resposta1 = getche ();
	printf("\nEscolha o segundo operador para realizar a operação metemática.Sendo + para adição, - para subtração, / para divisão e * para multiplicação: \n");
	resposta2 = getche ();
	r = calc(resposta1, resposta2, n1, n2, n3);
	system("cls");
	printf("\nA resposta da operação matemática é: %.2f", r);
	verificaResultado(r);
}

float calc(char resposta1, char resposta2, float n1, float n2, float n3){
	
	float calc2;
	if(resposta1 == '+' && resposta2 == '+'){
		calc2 = n1 + n2 + n3;		
	}
	else if (resposta1 == '+' && resposta2 == '-'){
		calc2 = n1 + n2 - n3;
	}
	else if (resposta1 == '+' && resposta2 == '*'){
		calc2 = n1 + (n2 * n3);
	}
	else if(resposta1 == '+' && resposta2 == '/'){
		calc2 = n1 + (n2 / n3);
	}
	else if (resposta1 == '-' && resposta2 == '-'){
		calc2 = n1 - n2 - n3;
	}
	else if (resposta1 == '-' && resposta2 == '+'){
		calc2 = n1 - n2 + n3;
	}
	else if (resposta1 == '-' && resposta2 == '*'){
		calc2 = n1 - (n2 * n3);
	}
	else if (resposta1 == '-' && resposta2 == '/'){
		calc2 = n1 - (n2 / n3);
	}
	if(resposta1 == '*' && resposta2 == '-') {
		calc2 = (n1 * n2) - n3;
	}
	else if (resposta1 == '*' && resposta2 == '+'){
		calc2 = (n1 * n2) + n3;
	} 
	else if (resposta1 == '*' && resposta2 == '-'){
		calc2 = n1 * n2 * n3;
	}
	else if (resposta1 == '*' && resposta2 == '/'){
		calc2 = n1 * n2 / n3;

	}
	else if (resposta1 == '/' && resposta2 == '-'){
		calc2 = (n1 / n2) - n3;
	}
	else if (resposta1 == '/' && resposta2 == '+'){
		calc2 = (n1 / n2) + n3;
	}
	else if(resposta1 == '/' && resposta2 == '*') {
		calc2 = n1 / n2 * n3;
	}
	else if (resposta1 == '/' && resposta2 == '/'){
		calc2 = n1 / n2 / n3;

	}
	return calc2;
}

void verificaResultado(float r){
	if(r > 0){
		printf("\nO resultado é maior. ");
	}
	else if (r < 0){
		printf("\nO resultado é menor. ");
	}
	else if(r == 0){
		printf("\nO resultado é igual a zero.");
	}
}
 
