/*Síntese
	Objetivo: "Lista de produtos feita através de uma LSE".
	Autora: Layla Emanuele.
	Data: 25/03/2020
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
};

//Protótipos das funções 
int menu();
void incluir(struct tNo *, struct tNo **);
void listar(struct tNo *);

struct tNo *consultar(int pesq, struct tNo *list){
	struct tNo *p = list;
	
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

int excluir(struct tNo **list, int pesq){
	struct tNo *p = *list, *q;
	
	if(*list == NULL)
		return 1;
	if(p->dado.codigo == pesq){
		*list = p->next;	
		free(p);	
	}
	else{
		p = *list;
		
		while(p!=NULL && p->dado.codigo <= pesq){
			if(p->dado.codigo == pesq){
				q->next = p->next;
				free(p);
				return 0;
			}
			q = p;
			p = p->next;
		}
	}
	return 0;
}

void liberar(struct tNo **list){
	struct tNo *p = *list, *q;
	
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
}

int main (void){
	int op, pesqCod;
	struct tNo *no, *lista=NULL, *consulta;
	char novaD[50];
	setlocale(LC_ALL,"Portuguese"); 	
	do{
		system("cls");
		
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
				excluir(&lista, pesqCod);		
		
			break;
		}
	}while(op!=0);
	
	liberar(&lista);
	
	return 0;
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

void incluir(struct tNo *novo, struct tNo **list){
	struct tNo *p, *q;
	
	if(((*list)==NULL) || (novo->dado.codigo <= (*list)->dado.codigo)){
		novo->next = *list;
		*list = novo;
	}
	else{
		p = *list;
		
		while((p != NULL) && (p->dado.codigo <= novo->dado.codigo)){
			q = p;
			p = p->next; 
		}
		q->next = novo;
		novo->next = p;		
	}
}

void listar(struct tNo *list){
	struct tNo *p = list;
	
	while(p!= NULL){
		printf("Código: %d\n", p->dado.codigo);
		printf("Descrição: %s\n", p->dado.descricao);
		
		p = p->next;
	}
	getch();
}	

	
	
	
	
	
