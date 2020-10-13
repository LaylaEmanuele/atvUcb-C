/*Síntese:
	Objetivo:
	Autora: Layla Emanuele
	Data: 17/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Tipos de variáveis
struct tLista {
	int
	char
};

struct tNo {
	struct tLista dado;
	struct tNo *prox;
};

struct tDescritor{
	struct tNo *ini;
	struct tNo *fim;
};

//Protótipos das Funções
void inicializar(struct tNo **lst);
int menu();
void incluir(struct tNo **lst, struct tNo *novo);

//Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	struct tDescritor lista, *no;
	int opcao

	inicializar(&lista);

	do {
		system("cls");
		opcao = menu();
		system("cls");

		switch(opcao) {
			case 1:
				printf("----Inclusão----");
				no = malloc(sizeof(struct tNo));
				printf("Qual.....?");
				scanf("%d", & no->);
				incluir(&lista,no);

				break;

			case 2:
				printf("----Listagem----");
				break;

			case 3:
				printf("----Consulta----");
				break;

			case 4:
				printf("----Alteração----");
				break;

			case 5:
				printf("----Exclusão----");
				break;
		}

	} while(opcao != 0);




	return 0;
}

void inicializar(struct tDescritor *lst) {
	(*lst)->ini = 	(*lst)->fim = NULL;
}

int menu() {
	int op;

	printf("----MENU----\n");
	printf("1. Inclusão\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alteração\n");
	printf("5. Exclusão\n");
	printf("0. Sair\n");

	scanf("%d", &op);

	return op;
}

void incluir(struct tNo *novo, struct tDescritor *list){
	struct tNo *p = (*list).ini, *q;
	
	if(((*list).ini == NULL) || (novo->dado.codigo <= (*list).ini->dado.codigo)){ //lista vazia e inicio 
		if((*list).ini == NULL)//exclusivo de lista vazia 
			(*list).fim = novo;	
		else
			(*list).ini->prev = novo;
				
		novo->next = (*list).ini;
		(*list).ini = novo;	
		novo->prev = NULL;
	}
	else{ //meio e fim 
		if(novo->dado.codigo > (*list).fim->dado.codigo){ //fim 
			(*list).fim->next = novo;
			novo->prev = (*list).fim;
			novo->next = NULL;
			(*list).fim = novo;
		}
		else{
			while((p != NULL) && (p->dado.codigo <= novo->dado.codigo)){ //meio
				q = p;
				p = p->next; 
			}
			q->next = novo;
			novo->next = p;	
			novo->prev = q;	
		}
	}
	(*list).qtd++;
}

void excluir(struct tDescritor *list, int pesq, struct tNo *consult){
	struct tNo *p = (*list).ini, *q;
	
	if((*list).qtd == 1) //unico
		(*list).ini = (*list).fim = NULL; 
	else	
		if(p == consult ){ //inicio
			(*list).ini = p->next;	
			(*list).ini->prev = NULL;
	
		}
		else{ //meio e fim 
			p = (*list).ini;
			
			while(p != consult){
				q = p;
				p = p->next;
			}
			q->next = p->next;
			
			if(q->next == NULL)
				(*list).fim = q;
			else
				p->next->prev = q;	 
		}
	free(p);	
	(*list).qtd--;
}	

struct tNo *consultar(struct tDescritor lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}
