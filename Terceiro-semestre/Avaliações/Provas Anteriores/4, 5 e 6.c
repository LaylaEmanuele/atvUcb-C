/*Síntese
	Objetivo: Realizar operações com os devedores de uma lista (listar, remover)
	Autora: Layla Emanuele
	Data: 15/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

//Declaração de tipo
struct tPessoa {
	char nome[50];
	int idade;
	float divida;
};

struct tNo1 {
	struct tPessoa dado;
	struct tNo1 *prox;
};

struct tNo2 {
	struct tNo2 *ant;
	struct tPessoa dado;
	struct tNo2 *prox;
};

//Principal
int main(void) {
	struct tPessoa pilha[TAM];
	int topo = 0;
	struct tNo1 *devedores = NULL;
	struct tNo2 *naoDevedores = NULL;

}



//Funções
int listagemDevedores(struct tNo1 *devedores) { //questão 4
	int dividaTotal = 0;
	struct tNo1 *p = devedores;

	while(p != NULL) {
		printf("%s", p->dado.nome);
		dividaTotal = dividaTotal + p->dado.divida;
		p = p->prox;
	}
	return dividaTotal;
}

void atualizarDevedores(struct tNo2 **naoDevedores, struct tNo1 **devedores) { //questão 5
	struct tNo1 *p = (*naoDevedores), *q;

	if((*naoDevedores) == NULL)
		return 0;

	if((*devedores)->dado.divida > 0) //exclusao unico e inicio
		(*devedores) = pessoa->prox;
	else { //meio e fim
		while(p->dado.divida > 0) {
			q = p;
			p = p->prox;
		}
		q->prox = pessoa->prox;
	}

	(*naoDevedores)->prox->ant = pessoa;
	pessoa->prox = (*naoDevedores);
	(*naoDevedores) = pessoa;
}

int listagemDupla(struct tNo2 *naoDevedores, struct tNo1 *devedores) { //questão 6
	int pessoas = 0;
	struct tNo1 *p = devedores;
	struct tNo2 *q = naoDevedores;

	while(p != NULL) {
		i*q = naoDevedores;
		while(q!= NULL) {
			if(q == p) {
				printf("%s",q->dado.nome);
				pessoas = pessoas + 1;
			}
			q = q->prox;
		}
		printf("%s", p->dado.nome);
		dividaTotal = dividaTotal + p->dado.divida;
		p = p->prox;
	}

	return pessoas;
}



