/*Síntese
	Objetivo: "Lista de produtos feita através de uma LDE com descritor".
	Autora: Layla Emanuele.
	Data: 08/04/2020
*/	

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Declarações de tipos de variáveis 

struct tProduto{
	int codigo;
	char descricao[50];
};

struct tNo{
	struct tProduto dado;
	struct tNo *next;
	struct tNo *prev;
};

struct tDescritor{
	struct tNo *ini;
	struct tNo *fim; 
	int qtd;
};

//Protótipos das funções 
void inicializar(struct tDescritor *);	
int menu();
void incluir(struct tNo *, struct tDescritor *);
void listar(struct tDescritor );
struct tNo *consultar(int , struct tDescritor );
void alterar(struct tNo *, char []);
void excluir(struct tDescritor *, int );
void liberar(struct tDescritor *);

int main (void){
	int op, pesqCod;
	struct tNo *no, *consulta, *p;
	struct tDescritor lista;
	char novaD[50];
	setlocale(LC_ALL,"Portuguese"); 	

	inicializar(&lista);
	
	do{
		system("cls");
		
		printf("Quantidade de elementos na lista: %d\n", lista.qtd);
	
	
		op = menu();
		
		system("cls");
		
		switch(op){
			case 1:
				no = malloc(sizeof(struct tNo));
				
				printf("*******Inclusão*******\n");
				
				printf("Qual o código do produto?\n");
				scanf("%d", &(no->dado.codigo));
			
				printf("Qual a descrição do produto?\n");
				fflush(stdin);
				gets(no->dado.descricao);
				
				incluir(no, &lista);
				
			break;
				
			case 2:
				listar(lista);
			break;
					
			case 3:
				printf("Qual o código a ser consultado?\n");
				scanf("%d", &pesqCod);
				
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				
				if(consulta == NULL)
					printf("Código não encontrado!");
				else{
					printf("Código: %d\n", consulta->dado.codigo);
					printf("Descrição: %s\n", consulta->dado.descricao);
				}
				getch();
			break;
			 	
			case 4:
				printf("Qual o código a ser consultado?\n");
				scanf("%d", &pesqCod);
			
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
			
				if(consulta == NULL)
					printf("Código não encontrado!");
				else{
					printf("Descrição: %s \n", consulta->dado.descricao);
					printf("Qual a nova descrição?\n");
					fflush(stdin);
					gets(novaD);
			    	alterar(consulta, novaD);
			    	printf("Descrição do produto alterado com sucesso!");
				}
				getch();
				
			break;	
			
			case 5: 
				printf("Qual código será excluído?\n");
				scanf("%d", &pesqCod);
				
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				
				if(consulta == NULL){
					printf("Código não encontrado!");
					getch();
				}else
					excluir(&lista, pesqCod);		
		
				getch();
				
			break;
		}
	}while(op!=0);
	
	liberar(&lista);
	
	return 0;
}

void inicializar(struct tDescritor *list){	
	(*list).ini = (*list).fim = NULL;
	(*list).qtd = 0;
}

int menu(){
	int op;
	
	printf("*********MENU*********\n");
	printf("1 - Inclusão\n");
	printf("2 - Listagem\n");
	printf("3 - Consulta\n");
	printf("4 - Alteração\n");
	printf("5 - Exclusão\n");
	printf("0 - Sair\n");
	printf("Opção desejada:\n");
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

void listar(struct tDescritor list){
	struct tNo *p = list.ini;
	
	while(p!= NULL){
		printf("Código: %d\n", p->dado.codigo);
		printf("Descrição: %s\n", p->dado.descricao);
		
		p = p->next;
	}
	getch();
}	

struct tNo *consultar(int pesq, struct tDescritor list){
	struct tNo *p = list.ini;
	
	while(p!= NULL){
		if(p->dado.codigo == pesq)
			return p;
		p = p->next;
	}
	
	return p;
}	
	
void alterar(struct tNo *consult, char novaD[]){
	strcpy(consult->dado.descricao, novaD);
}

void excluir(struct tDescritor *list, int pesq){
	struct tNo *p = (*list).ini, *q;
	
	if((*list).qtd == 1) //unico
		(*list).ini = (*list).fim = NULL; 
	else	
		if(p->dado.codigo == pesq ){ //inicio
			(*list).ini = p->next;	
			(*list).ini->prev = NULL;
	
		}
		else{ //meio e fim 
			p = (*list).ini;
			
			while(p->dado.codigo != pesq){
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

void liberar(struct tDescritor *list){
	struct tNo *p = (*list).ini, *q;
	
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
	inicializar(list);
}

