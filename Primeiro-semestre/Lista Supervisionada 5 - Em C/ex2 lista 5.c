/* Algoritmo carro;
Síntese:
 Objetivo: Ajudar o cliente a escolher um carro.
 Entrada: O nome do cliente, a concessionária escolhida e o carro.
 Saída: Uma mensagem de agradecimento  com o nome do cliente e carro escolhido.
*/
#include <stdlib.h> //emulador.
#include <stdio.h> //entrada e saída.
#include <locale.h> //idiomas. 
char *fiat();
void opcoes();
char *chevrolet();
char *ford();
main(){
	setlocale(LC_ALL,"Portuguese");
    opcoes();
	getch();
}

void opcoes(){
	char  nome[100], escolha; 
	printf("Informe seu nome:\n");
	gets(nome);
	system("cls");
	printf("As concessionárias disponíveis são:\nFIAT \nCHEVROLET \nFORD"); 
	printf("\nEscolha 1 para FIAT, 2 para CHEVROLET e 3 para FORD. \n");
	escolha = getche(); 	
	if (escolha == '1'){
		printf("\nObrigado pela preferência sr.(a) %s! O carro escolhido foi o: %s", nome, fiat());
	}
	else if (escolha == '2'){
		printf("\nObrigado pela preferência sr.(a) %s! O carro escolhido foi o: %s", nome, chevrolet());
	}
	else if (escolha == '3'){
		printf("\nObrigado pela preferência sr.(a) %s! O carro escolhido foi o: %s", nome, ford());
	}
	
}


char *fiat(){
	char escolha;
	printf("\nSuas opções de carro são: A para Argo, P para Punto, L para Palio.\n");
	escolha =  getche();
	if(escolha >= 97 && escolha <= 122){
		escolha-= 32;
	}
	switch(escolha) {
		case 'A': 
		return "Argo";
		break; 
		case 'P': 
		return "Punto";
		break; 	
		case 'L': 
		return "Palio";
		break; 
	}
}

char *chevrolet(){
	char escolha;
	printf("\nSuas opções de carro são: P para Prisma, S para S10, O para Onix.\n");
	escolha =  getche();
	if(escolha >= 97 && escolha <= 122){
		escolha-= 32;
	}
	switch(escolha) {
		case 'p': 
		return "Prisma";
		break; 
		case 'S': 
		return "S10";
		break; 	
		case 'O': 
		return "Onix";
		break; 
	}	
}
	
char *ford(){
	char escolha;
	printf("\nSuas opções de carro são: K para Ka, R para Ranger, F para Fusion.\n");
	escolha =  getche();
	if(escolha >= 97 && escolha <= 122){
		escolha-= 32;
	}
	switch(escolha) {
		case 'K': 
		return "Ka";
		break; 
		case 'R': 
		return "Ranger";
		break; 	
		case 'F': 
		return "Fusion";
		break; 
	}
}


