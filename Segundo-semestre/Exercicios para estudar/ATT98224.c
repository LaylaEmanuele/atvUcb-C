/*Síntese:
   Objetivo: Criar uma lista(modularizada) de livros com seus dados (struct[codigo, valor, nome]) podendo se fazer: alteração da lista, deletar os dados inseridos, backup, restaução, ordenação e pesquisa binária.
   Data: 07/10/2019
   Autora: Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 1

struct tLivros{						//declaração do tipo de variável
	char nome[50];
	int ano;
	float valor;
};

int menu(){
	int opcaoE;
	
	printf("----------MENU---------\n");
	printf("1- Adicionar um novo livro\n");
	printf("0- Para sair\n");
	scanf("%d",&opcaoE);
	
	return opcaoE;
}

int adicionar(int flag, struct tLivros livros[], int *qtd){
	if(*qtd>=TAM)
		return 0;
		
	printf("Insira o nome do livro:\n");
	fflush(stdin);
	gets(livros[*qtd].nome); 
	(*qtd)++;
	
	return 1;
}


int main(){
	struct tLivros livros[TAM];
	int opcao, flag=0, adiciona, qtd=0;
	
	do{
		opcao = menu();
		
		system("cls");
		
		switch(opcao){
			
			case 1:
				opcao == '1';				
				if(!sadicionar(flag, livros, &qtd))
					printf("A lista está cheia");
				else	
					printf("Os dados do novo livro foram armazenados");
			
			
		}
			
		
	}while(opcao!=0);
	
	
	
	
	return 0;
}






