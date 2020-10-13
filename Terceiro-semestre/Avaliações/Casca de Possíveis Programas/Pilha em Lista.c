/*Síntese
	Objetivo: 
	Autora: Layla Emanuele.
	Data: 17/06/2020
*/


struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};


int menu(void);
void inicializar(struct tNo**);
void push(struct tNo**, struct tNo *);
struct tNo* pop(struct tNo**);
void listar(struct tNo*);
void destruir(struct tNo**);


int main(void) {
	struct tNo *pilha, *p;
	int opcao;
	
	inicializar(&pilha);
	do {
        opcao = menu();
        switch (opcao) {
               case 1: 
                    printf("\n\n*** Empilhar ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    fflush(stdin);
                    gets(p->dado.descricao);
                    push(&pilha, p);
	                break;
               case 2: 
                    printf("\n\n*** Desempilhar ***\n\n");
                    p = pop(&pilha);
                    if (p != NULL) {
                    	printf("Desempilhou: %s\n", p->dado.descricao);
                    	free(p);
					}
                    else
                    	printf("Pilha estava vazia!\n");
	                break;
               case 3: 
                    printf("\n\n*** Listagem ***\n\n");
                    listar(pilha); // Listar (mostrar na tela) todos os produtos
        }
    } while (opcao != 0);
	destruir(&pilha);
	return 0;
}

int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Empilhar\n");
    printf("2. Desempilhar\n");
    printf("3. Listagem\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}


void inicializar(struct tNo **topo) {
	(*topo) = NULL;
}


void push(struct tNo **topo, struct tNo *novo) {
	novo->prox = (*topo);
	(*topo) = novo;
}


struct tNo *pop(struct tNo **topo) {
	struct tNo *p = (*topo);
	if (p != NULL)
		(*topo) = p->prox;
	return p;
}


void listar(struct tNo *topo) {
	struct tNo *p = topo;
	while (p != NULL) {
		printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}

void destruir(struct tNo **topo) {
	struct tNo *p = (*topo), *q;	
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(topo);
}
