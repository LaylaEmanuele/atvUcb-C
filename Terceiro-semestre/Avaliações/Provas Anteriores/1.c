/* Síntese
	Objetivo: Implementar a função hash
	Autora: Layla Emanuele
	Data: 15/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//Declarações de Tipo
struct tTipo {
	float codigo;
	int situacao;
};

//Protótipos de Funções
int menu();
void incluir(struct tTipo vet[], float cod, int cont);
void inicializarVet(struct tTipo vetor[]);
int hushing(struct tTipo vet[], float cod, int cont);
void listar(struct tTipo vet[]);

//Principal
int main(void) {
	struct tTipo vet[10];
	float codigo;
	int i = 0, op, cont = 0;

	inicializarVet(vet);
	do {
		system("cls");
		op = menu();
		system("cls");
		switch(op) {
			case 1:
				printf("***INCLUSÃO***\n");
				if(i<10) {
					printf("Informe o código a ser inserido:");
					scanf("%f", &codigo);		
					incluir(vet, codigo, cont);
					i++;
				} else
					printf("Limite excedido");

				break;
			case 2:
				printf("***LISTAGEM***\n");
				listar(vet);
				getch();
				break;
		}
	} while(op != 0);

	return 0;
}

//Função
int menu() {
	int opcao;
	printf("***Menu***\n");
	printf("1. Incluir\n");
	printf("2. Listar\n");
	printf("0. Sair\n");
	scanf("%d", &opcao);
	return opcao;
}

void inicializarVet(struct tTipo vetor[]) {
	int i;
	for(i = 0; i < 10; i++) {
		vetor[i].situacao = -1;
	}
}

void incluir(struct tTipo vet[], float cod, int cont) {
	int id;
	id = hushing(vet, cod, cont);
	vet[id].codigo = cod;
	vet[id].situacao = 0;
}

int hushing(struct tTipo vet[], float cod, int cont) {
	int indice, num;
	num = cod;	
	
	indice = (num + cont) % 10;

	if(vet[indice].situacao == -1 )
		return indice;
	else if(cont < 10)
		indice = hushing(vet, cod, cont+1);

	if(cont >=10)
		return -2;
}

void listar(struct tTipo vet[]) {
	int i;
	for(i=0; i<10; i++) {
		if(vet[i].situacao != -1)
			printf("%2.f", vet[i].codigo);
	}
}
