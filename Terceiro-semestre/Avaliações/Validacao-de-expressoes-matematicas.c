/* Síntese
	Objetivo: Analisar se a expressão matemática é válida utilizando pilha com LSE.
	Autora: Layla Emanuele
	Data: 29/04/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração de tipo de variável
struct tOperadores {
	int qtd, qtdC, qtdCh; //contador parenteses, colchetes e chaves respectivamente
};

struct tNo {
	struct tOperadores dado;
	struct tNo *next;
};

//Protótipos das funções
void inicializar(struct tNo **);
int menu();
void parte1(struct tNo **, char []);
void push(struct tNo **, struct tNo *);
struct tNo *pop(struct tNo **, struct tNo *);
void mostrarErros(int );
void parte2(struct tNo **, char []);
void mostrarErros2(int );
void destruir(struct tNo **);

int main (void) {
	struct tNo *pilha;
	int opcao, flag = 0, flag1 = 0;
	char expressao[80];

	do {
		inicializar(&pilha);
		system("cls");
		opcao = menu();
		if(opcao != 0) {
			printf("Insira a expressao:");
			fflush(stdin);
			gets(expressao);

			switch(opcao) { //escolher qual parte
				case 1:
					parte1(&pilha, expressao);

					break;
				case 2:
					parte2(&pilha, expressao);

					break;
			}
		}
		destruir(&pilha);
	} while(opcao != 0);

	return 0;
}

//Funções
void inicializar(struct tNo **topo) {
	(*topo) = NULL;
}

int menu() {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1- Parte 1\n");
	printf("2- Parte 2\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}

void parte1(struct tNo **topo, char expressao[]) {
	struct tNo *p = (*topo);
	int i, chegou = 1;

	for(i=0; i<strlen(expressao); i++) {
		if(expressao[i] == '(') {
			p = malloc(sizeof(struct tNo));
			p->dado.qtd = 0;

			if((*topo) != NULL)  //se a pilha for diferente != Null pego o que tava na pilha e somo ++
				p->dado.qtd = (*topo)->dado.qtd;
			p->dado.qtd++;
			push(topo, p); //pilha recebendo o qtd adicionando um nó

		} else if(expressao[i] == ')') {
			if((*topo)!= NULL) {	//pilha não está vazia
				p = pop(topo, p);  //retorna o p

				if(p!= NULL) { //--
					free(p);
				}
			} else
				chegou = 0;
		}
	}
	if((*topo) != NULL)
		chegou = -2;

	mostrarErros(chegou);
}

void push(struct tNo **topo, struct tNo *p) {
	p->next = (*topo);
	(*topo) = p;
}

struct tNo *pop(struct tNo **topo, struct tNo *p) {
	(*topo) = p->next;
	return p;
}

void mostrarErros(int flag) {

	if(flag == 0)
		printf("Expressao invalida, erro na quantidade de parenteses, algum parenteses nao foi aberto "); //qtd de '(' errada
	else if(flag == -2)
		printf("Expressao invalida, erro na quantidade de parenteses, algum parenteses nao foi fechado"); //qtd de ')' errada
	else
		printf("Expressao valida");

	getch();
}

void parte2(struct tNo **topo, char expressao[]) {
	struct tNo *p = (*topo);
	int i, chegou = 0;

	for(i=0; i<strlen(expressao); i++) {
		if((expressao[i]=='(') ||(expressao[i]=='[') || (expressao[i]=='{')) {
			p = malloc(sizeof(struct tNo));
			p->dado.qtd = 0;
			p->dado.qtdC = 0;
			p->dado.qtdCh = 0;
		}
		switch(expressao[i]) {
			case '(':
				if((*topo) != NULL) { //se a pilha for diferente != Null pego o que tava na pilha e somo ++
					p->dado.qtd = (*topo)->dado.qtd;
					p->dado.qtdC = (*topo)->dado.qtdC;
					p->dado.qtdCh = (*topo)->dado.qtdCh;
				}
				p->dado.qtd++;
				push(topo, p); //pilha recebendo o qtd adicionando um nó

				break;

			case '[':

				if((*topo) != NULL) { //se a pilha for diferente != Null pego o que tava na pilha e somo ++
					p->dado.qtd = (*topo)->dado.qtd;
					p->dado.qtdC = (*topo)->dado.qtdC;
					p->dado.qtdCh = (*topo)->dado.qtdCh;
				}
				p->dado.qtdC++;
				push(topo, p); //pilha recebendo o qtd adicionando um nó

				break;

			case '{':
				if((*topo) != NULL) { //se a pilha for diferente != Null pego o que tava na pilha e somo ++
					p->dado.qtd = (*topo)->dado.qtd;
					p->dado.qtdC = (*topo)->dado.qtdC;
					p->dado.qtdCh = (*topo)->dado.qtdCh;
				}
				p->dado.qtdCh++;
				push(topo, p); //pilha recebendo o qtd adicionando um nó

				break;

			case ')':
				if((*topo)!= NULL) {	//pilha não está vazia
					if((p->dado.qtdC == 0) && (p->dado.qtdCh == 0)) {
						p = pop(topo, p);  //retorna o p

						if(p!= NULL)  //--
							free(p);
					} else
						chegou = -1; //erro de escopo fechou com ')' um [ ou {
				} else
					chegou = 1; //qtd de '(' errada

				break;

			case ']':
				if((*topo)!= NULL) {	//pilha não está vazia
					printf("%d",p->dado.qtd);
					printf("%d",p->dado.qtd);
					if((p->dado.qtd == 0) && (p->dado.qtdCh == 0)) {
						p = pop(topo, p);  //retorna o p

						if(p!= NULL)  //--
							free(p);
					} else
						chegou = -2; //erro de escopo fechou com ']' um ( ou {

				} else
					chegou = 2; //qtd de '[' errada

				break;

			case '}':
				if((*topo)!= NULL) {	//pilha não está vazia
					if((p->dado.qtd == 0) && (p->dado.qtdC == 0)) {
						p = pop(topo, p);  //retorna o p

						if(p!= NULL) { //--
							free(p);
						}
					} else
						chegou = -3; //erro de escopo fechou com '}' um ( ou [
				} else
					chegou = 3; //qtd de '{' errada, caso comece fechando

				break;
		}
	}
	if(((*topo) != NULL) && (chegou != -1) && (chegou != -2)&& (chegou != -3)) { //validação dos qtds>0
		if((*topo)->dado.qtd > 0)
			chegou = 4;
		else if((*topo)->dado.qtdC > 0)
			chegou = 5;
		else if((*topo)->dado.qtdCh > 0)
			chegou = 6;
	}

	mostrarErros2(chegou); //outra função para erros
}

void mostrarErros2(int flag) {
	if(flag == -1)
		printf("Expressao invalida, erro de escopo fechou com ')' um '['' ou '{'");
	else if(flag == 1)
		printf("Expressao invalida, erro na quantidade de parenteses, algum parenteses nao foi aberto ");
	else if(flag == 4)
		printf("Expressao invalida, erro na quantidade de parenteses, algum parenteses nao foi fechado"); //qtd de ')' errada
	else if(flag == -2)
		printf("Expressao invalida, erro de escopo fechou com ']' um '('' ou '{' ");
	else if(flag == 2)
		printf("Expressao invalida, erro na quantidade de colchetes, algum colchete nao foi aberto ");
	else if(flag == 5)
		printf("Expressao invalida, erro na quantidade de colchetes, algum colchetes nao foi fechado");
	else if(flag == -3)
		printf("Expressao invalida, erro de escopo fechou com '}' um '('' ou ']' ");
	else if(flag == 3)
		printf("Expressao invalida, erro na quantidade de chaves, alguma chave nao foi aberta ");
	else if(flag == 6)
		printf("Expressao invalida, erro na quantidade de chaves, algum chaves nao foi fechada");
	else
		printf("Expressao valida");

	getch();
}

void push2(struct tNo **topo, struct tNo *p) {
	p->next = (*topo);
	(*topo) = p;
}

void destruir(struct tNo **topo) {
	struct tNo *q, *p = (*topo);

	while(p!=NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	inicializar(topo);
}

