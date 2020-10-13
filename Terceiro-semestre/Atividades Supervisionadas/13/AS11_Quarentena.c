/* Sintese
	Objetivo: Realizar o DFS
	Autora: Layla Emanuele 
	Data:  03/06/2020
*/
#include <stdio.h>
#include <stdlib.h>

//*** Declaracoes de tipos *****************************************************
struct tVertice {
	char rotulo;
	struct tAresta *arestas;
	char visitado; // 1/0 = V/F
	struct tVertice *prox; // LISTA DE VERTICES
};

struct tAresta {
	int peso;
	struct tVertice *destino;
	struct tAresta *prox; // LISTA DE ARESTAS
};

struct tNoFila {
	struct tVertice *vertice;
	struct tNoFila *prox;
};

struct tFila {
	struct tNoFila *ini;
	struct tNoFila *fim;
};

struct tPilha{
	struct tVertice *vertice;
	struct tPilha *prox;	
};


//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializarGrafo(struct tVertice**);
struct tVertice *criarVertice(char);
void incluirVertice(struct tVertice**, struct tVertice*);
struct tVertice *consultarVertice(struct tVertice*, char);
void incluirAresta(struct tVertice*, int, struct tVertice*);
void listarGrafo(struct tVertice*);
void destruirGrafo(struct tVertice**);
void inicializarFila(struct tFila*);
void enqueue(struct tFila*, struct tNoFila*);
struct tNoFila *dequeue(struct tFila*);
int filaVazia(struct tFila);
void destruirFila(struct tFila*);
void bfs(struct tVertice*);
void inicializarPilha(struct tPilha **);
void push(struct tPilha **, struct tPilha *);
struct tPilha *pop(struct tPilha **);
void dfs(struct tVertice *, struct tPilha **);

// Bloco Principal 
int main(void) {
	struct tVertice *grafo, *verticeOrigem, *verticeDestino;
	char rotulo;
	int opcao, peso;
	struct tPilha *pilha;
	
	inicializarGrafo(&grafo);
	do {
		system("cls");
        opcao = menu();
        system("cls");
        switch (opcao) {
               case 1: 
                    printf("\n\n*** Inclusao de Vertice ***\n\n");
                    printf("Valor (char): ");
                    fflush(stdin);
                    scanf("%c", &rotulo);
                    incluirVertice(&grafo, criarVertice(rotulo));
	                break;
               case 2: 
                    printf("\n\n*** Inclusao de Aresta ***\n\n");
                    printf("Vertice origem (char).: ");
                    fflush(stdin);
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    printf("Vertice destino (char): ");
                    fflush(stdin);
                    scanf("%c", &rotulo);
                    verticeDestino = consultarVertice(grafo, rotulo);
                    if ((verticeOrigem == NULL) || (verticeDestino == NULL))
                    	printf("Vertice nao localizado!");
                    else {
						printf("Peso..................: ");
	                    scanf("%d", &peso);
	                    incluirAresta(verticeOrigem, peso, verticeDestino);
					}
					getch();
	                break;
               case 3: 
                    printf("\n\n*** Listagem ***\n\n");
                    listarGrafo(grafo);
                    getch();
	                break;
               case 4: 
                    printf("\n\n*** Caminhamento BFS ***\n\n");
                    printf("Vertice (char): ");
                    fflush(stdin);
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    if (verticeOrigem == NULL)
                    	printf("Vertice nao localizado!");
                    else {
                    	verticeDestino = grafo;
						while (verticeDestino != NULL) {
							verticeDestino->visitado = 0;
							verticeDestino = verticeDestino->prox;
						}
	                    bfs(verticeOrigem);
					}
					getch();
					break;
					
				case 5: 
                    printf("\n\n*** Caminhamento DFS ***\n\n");
                    printf("Vertice (char): ");
                    fflush(stdin);
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    if (verticeOrigem == NULL)
                    	printf("Vertice nao localizado!");
                    else {
                    	verticeDestino = grafo;
						while (verticeDestino != NULL) {
							verticeDestino->visitado = 0;
							verticeDestino = verticeDestino->prox;
						}
						inicializarPilha(&pilha);
	                    dfs(verticeOrigem, &pilha);
					}
					getch();
					break;	
        }
    } while (opcao != 0);
	destruirGrafo(&grafo);
	return 0;
}

//Menu 
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Inclusao de vertice\n");
    printf("2. Inclusao de aresta\n");
    printf("3. Listar\n");
    printf("4. Caminhamento BFS\n");
    printf("5. Caminhamento DFS\n");
	printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

// Inicializar Grafo 
void inicializarGrafo(struct tVertice **grf) {
	(*grf) = NULL;
}

// Criar vertice 
struct tVertice *criarVertice(char rotulo) {
	struct tVertice *novo = malloc(sizeof(struct tVertice));
	novo->rotulo = rotulo;
	novo->arestas = NULL;
	return novo;
}

// Incluir vertice 
void incluirVertice(struct tVertice **grf, struct tVertice *novo) {
	struct tVertice *p = *grf;
	if (*grf == NULL)
		(*grf) = novo;
	else {
		while (p->prox != NULL)
			p = p->prox;
		p->prox = novo;
	}
	novo->prox = NULL;
}

// Consultar vertice
struct tVertice *consultarVertice(struct tVertice *grf, char rotulo) {
	struct tVertice *vertice = grf;
	while (vertice != NULL) {
		if (vertice->rotulo == rotulo)
			return vertice;
		vertice = vertice->prox;
	}
}

// Incluir aresta 
void incluirAresta(struct tVertice *origem, int peso, struct tVertice *destino) {
	struct tAresta *p = origem->arestas;
	struct tAresta *novo = malloc(sizeof(struct tAresta));
	novo->peso = peso;
	novo->destino = destino;
	
	if (origem->arestas == NULL)
		origem->arestas = novo;
	else {
		while (p->prox != NULL)
			p = p->prox;
		p->prox = novo;
	}
	novo->prox = NULL;
}

// Listar Grafo 
void listarGrafo(struct tVertice *grf) {
	struct tVertice *vertice = grf;
	struct tAresta *aresta;	
	while (vertice != NULL) {
		printf("%c(", vertice->rotulo);
		aresta = vertice->arestas;
		while (aresta != NULL) {
			printf(" %c[%d]", aresta->destino->rotulo, aresta->peso);
			aresta = aresta->prox;
		}
		printf(" ) ");
		vertice = vertice->prox;
	}
}

// Destruir Grafo 
void destruirGrafo(struct tVertice **grf) {
	struct tVertice *vertice = (*grf), *verticeAux;	
	struct tAresta *aresta, *arestaAux;	
	while (vertice != NULL) {
		aresta = vertice->arestas;
		while (aresta != NULL) {
			arestaAux = aresta;
			aresta = aresta->prox;
			free(arestaAux);
		}
		verticeAux = vertice;
		vertice = vertice->prox;
		free(verticeAux);
	}
}

// Inicializar Fila 
void inicializarFila(struct tFila *desc) {
	(*desc).ini = NULL;
	(*desc).fim = NULL;
}

// Enqueue 
void enqueue(struct tFila *desc, struct tNoFila *novo) {
	if ((*desc).ini == NULL) // vazia
		(*desc).ini = novo;
	else
		(*desc).fim->prox = novo;
	(*desc).fim = novo;
	novo->prox = NULL;
}

// Dequeue 
struct tNoFila *dequeue(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini;
	if (p != NULL) {
		(*desc).ini = p->prox;
		if ((*desc).ini == NULL)
			(*desc).fim = NULL;
	}
	return p;
}

// Fila vazia 
int filaVazia(struct tFila desc) {
	if (desc.ini == NULL)
		return 1;
	return 0;
}

// Destruir Fila 
void destruirFila(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini, *q;	
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializarFila(desc);
}

// Caminhamento BFS 
void bfs(struct tVertice *vertice) {
	struct tFila fila; 
	struct tNoFila *noFila;
	struct tVertice *cara; //vertice 
	struct tAresta *aresta;	//ponteiro para uma aresta 

	inicializarFila(&fila);
    vertice->visitado = 1; //marca o ponto de partida como visitado
    noFila = malloc(sizeof(struct tNoFila));  //criaçao do no
    noFila->vertice = vertice; //esse novo no aponto pro vertice 
    enqueue(&fila, noFila); //inclui ele na fila 
    while (!filaVazia(fila)) {
    	noFila = dequeue(&fila);
    	cara = noFila->vertice;
    	free(noFila);
    	printf("%c, ", cara->rotulo);
		aresta = cara->arestas;
		while (aresta != NULL) {
	        if (!aresta->destino->visitado) {
			    noFila = malloc(sizeof(struct tNoFila));
			    noFila->vertice = aresta->destino;
			    enqueue(&fila, noFila);
				aresta->destino->visitado = 1;
	        }
			aresta = aresta->prox;
		}
	}
}

// Inicialização Pilha
void inicializarPilha(struct tPilha **pilha) {
	(*pilha) = NULL;
}
// Push 
void push(struct tPilha **pilha, struct tPilha *novo) {
	novo->prox = (*pilha);
	(*pilha) = novo;
}
// Pop
struct tPilha *pop(struct tPilha **pilha) {
	struct tPilha *p = (*pilha);
	if (p != NULL)
		(*pilha) = p->prox;
	return p;
}
// Caminhamento DFS
void dfs(struct tVertice *vertice, struct tPilha **pilha){
	struct tPilha *p;
	struct tVertice *cara; 
	struct tAresta *aresta;
	
	vertice->visitado = 1;
	p = malloc(sizeof(struct tPilha));
	p->vertice = vertice;	
	push(pilha, p);
	if(p != NULL){ 
    	cara = p->vertice; 
		printf("%c, ", cara->rotulo); 
		aresta = cara->arestas;
		while(aresta != NULL){
			if(aresta->destino->visitado != 1){
				cara = aresta->destino;
				dfs(cara, pilha);
				aresta->destino->visitado = 1;
			}
			aresta = aresta->prox;
		}
		p = pop(pilha);
		free(p);	
	}
}

