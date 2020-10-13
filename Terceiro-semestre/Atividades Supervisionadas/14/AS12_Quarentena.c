/* Sintese
	Objetivo: Realizar um busca de largura e profundidade de um grafo representado em uma matriz de adjacência
	Autora: Layla Emanuele
	Data:  10/06/2020
*/
#include <stdio.h>
#include <stdlib.h>

// Declaracoes de tipos
struct tVertice {
	char rotulo;
	char visitado; // 1/0 = V/F
	int aresta;
};

// Prototipos de funcoes
void inicializarMatriz(struct tVertice grafo[][4]);
void incluirA(struct tVertice grafo[][4], char origem, char destino);
int indice(struct tVertice grafo[][4], char vertice);
int menu();
void mostrarMatriz(struct tVertice grafo[][4]);
void bfs(struct tVertice grafo[][4], int i);
void visitado(struct tVertice grafo[][4]);
void dfs(struct tVertice grafo[][4], int i);

// Bloco Principal
int main(void) {
	struct tVertice grafo[4][4];
	int opcao, i = 0,j = 0;
	char rotulo;

	inicializarMatriz(grafo);

	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1: //mostrar grafo
				printf("\n\n*** Matriz ***\n\n");
				mostrarMatriz(grafo);
				getch();
				break;
			case 2: //largura grafo
				printf("\n\n*** BFS ***\n\n");
				i = indice(grafo, 'A');
				bfs(grafo, i);
				getch();
				break;
			case 3: //profundidade do grafo
				printf("\n\n*** DFS ***\n\n");
				visitado(grafo);
				i = indice(grafo, 'A');
				dfs(grafo, i);
				getch();
				break;
		}
	} while (opcao != 0);

	return 0;
}

//Funções
void inicializarMatriz(struct tVertice grafo[][4]) {
	int i, j;
	int aux = 0;

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			grafo[i][j].aresta = 0;
			grafo[i][j].visitado = 0;
		}
	}
	grafo[aux][aux].rotulo = 'A';
	aux++;

	grafo[aux][aux].rotulo = 'B';
	aux++;

	grafo[aux][aux].rotulo = 'C';
	aux++;

	grafo[aux][aux].rotulo = 'D';

	incluirA(grafo, 'A','B');
	incluirA(grafo, 'A','C');
	incluirA(grafo, 'B','C');
	incluirA(grafo, 'C','D');
};

void incluirA(struct tVertice grafo[][4], char origem, char destino) {
	int id, id2;

	id = indice(grafo, origem);
	id2 = indice(grafo, destino);

	grafo[id][id2].aresta = 1;
}

int indice(struct tVertice grafo[][4], char vertice) {
	int i, j, id;

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(grafo[i][j].rotulo == vertice)
				id = i;
		}
	}
	return id;
}

int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Ver grafo\n");
	printf("2. BFS\n");
	printf("3. DFS\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}

void mostrarMatriz(struct tVertice grafo[][4]) {
	int i, j;

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			printf("%d ", grafo[i][j].aresta);
		}
		printf("\n");
	}
}

void bfs(struct tVertice grafo[][4], int i) {
	int aux = i, aux2;
	int k = 0, id[4], cont;
	id[k] = aux;
	k++;
	do {
		if(k!=0) {
			while(k!=0) {
				aux2 = id[k-1];
				if(grafo[aux2][aux2].visitado != 1) {
					printf("%c ", grafo[aux2][aux2].rotulo);
					grafo[aux2][aux2].visitado = 1;
				}
				k--;
			}
			for(cont=0; cont<4; cont++) {
				if(grafo[aux2][cont].aresta == 1) {
					id[k] = cont;
					k++;
				}

			}
		}
	} while(k!=0);

}

void visitado(struct tVertice grafo[][4]) {
	int i, j;
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++)
			grafo[i][j].visitado = 0;
	}
}

void dfs(struct tVertice grafo[][4], int i) {
	int aux = i, aux2 = 0;
	int k = 0, id[4], cont = 0;
	id[k] = aux;
	k++;

	do {
		if(k!=0) {
			aux2 = id[k-1];
			if(grafo[aux2][aux2].visitado != 1) {
				printf("%c ", grafo[aux2][aux2].rotulo);
				grafo[aux2][aux2].visitado = 1;
			}
			k--;
			for(cont=0; cont<4; cont++) {
				if(grafo[aux2][cont].aresta == 1) {
					id[k] = cont;
					k++;
				}

			}	
		}
	} while(k!=0);

}
