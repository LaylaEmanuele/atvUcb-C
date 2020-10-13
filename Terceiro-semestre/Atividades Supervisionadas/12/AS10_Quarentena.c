/* Síntese
	Objetivo: Fazer uma fila utilizando pilha
	Autora: Layla Emanuele
	Data: 27/05/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaracoes de tipos
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

//Protótipos das funções
int menu();
void inicializar(struct tNo**, struct tNo**);
void enqueue(struct tNo **, struct tNo *);
void push(struct tNo **, struct tNo *);
struct tNo * dequeue(struct tNo **, struct tNo **); 
struct tNo *pop(struct tNo **);
void listar(struct tNo*);
void destruir(struct tNo**, struct tNo **);

int main(void) {
	struct tNo *fila, *fila2;
	struct tNo *p;
	int opcao;

	inicializar(&fila, &fila2);
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Enfileirar ***\n\n");
				p = malloc(sizeof(struct tNo)); // Criar um no
				printf("Digite o codigo...: ");
				scanf("%d", &(p->dado.codigo));
				printf("Digite a descricao: ");
				fflush(stdin);
				gets(p->dado.descricao);
				enqueue(&fila, p); // Incluir o no com produto criado na lista
				break;
			case 2:
				printf("\n\n*** Desinfileirar ***\n\n");
				p = dequeue(&fila, &fila2);
				if (p != NULL) {
					printf("Desinfileirou: %s\n", p->dado.descricao);
					free(p);
				} else
					printf("Fila estava vazia!\n");
				getch();	
				break;
			case 3:
				printf("\n\n*** Listagem ***\n\n");
				p = fila;
				listar(p); // Listar (mostrar na tela) todos os produtos
				getch();
				break;
		}
	} while (opcao != 0);
	destruir(&fila, &fila2);
	return 0;
}

//Funções
int menu() {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Enfileirar\n");
	printf("2. Desinfileirar\n");
	printf("3. Listagem\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}

void inicializar(struct tNo **fila, struct tNo **fila2) {
	(*fila) = NULL;
	(*fila2) = NULL;
}

void enqueue(struct tNo **fila, struct tNo *novo) {  
	push(fila, novo);
}

void push(struct tNo **fila, struct tNo *p){ 
	p->prox = (*fila);
	(*fila) = p;
}

struct tNo * dequeue(struct tNo **fila, struct tNo **fila2) { 
	struct tNo *p = (*fila), *q;

	while(p->prox!= NULL){
		p = pop(fila);
		push(fila2, p);
		p = (*fila);
	}
	(*fila) = NULL;	

	do{
		q = pop(fila2);
		if(q != NULL)
			push(fila, q);
	
	}while(q != NULL);

	return p;
}

struct tNo *pop(struct tNo **fila) { 
	struct tNo *p = (*fila);
	if (p != NULL)
		(*fila) = p->prox;
	return p;
}

void listar(struct tNo *p) {
	if(p==NULL)
		return;
	listar(p->prox);	
	printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
}

void destruir(struct tNo **fila, struct tNo **fila2) {
	struct tNo *p = (*fila), *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(fila,fila2);
}


