/*Síntese
	Objetivo: "Lista de produtos feita através de uma Lista Circular, ordenada de forma não decrescente".
	Autora: Layla Emanuele.
	Data: 22/04/2020
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
void inicializar(struct tNo **); 
int menu();
void incluir(struct tNo *, struct tNo **);
void listar(struct tNo *);
struct tNo *consultar(int , struct tNo *);
struct tNo *comparaD(struct tNo *, char [], int );
void alterar(struct tNo *, char []);
int excluir(struct tNo **, int , struct tNo *);
void liberar(struct tNo **);

int main (void){
	int op, pesqCod;
	struct tNo *no, *lista=NULL, *consulta, *p;
	char novaD[50], descricao[50], word[40];
	setlocale(LC_ALL,"Portuguese"); 	
	
	inicializar(&lista);
	
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
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descrição: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				}
				getch();
			break;
			 	
			case 4:
				printf("Qual o código a ser consultado?\n");
				scanf("%d", &pesqCod);
			
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				p = consulta;
				if(consulta == NULL)
					printf("Código não encontrado!");
				else{
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descrição: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				
					printf("Informe qual descrição será alterada:\n");
					fflush(stdin);
					gets(descricao);
					
					consulta = comparaD(p, descricao, pesqCod);
					
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
				p = consulta;
				
				if(consulta == NULL)
					printf("Código não encontrado!");
				else{
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descrição: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				
					printf("Informe qual descrição será excluída:\n");
					fflush(stdin);
					gets(descricao);
					
					consulta = comparaD(p, descricao, pesqCod);
					if(consulta == NULL )
						printf("Descrição incompatível!!");
					else
						excluir(&lista, pesqCod, consulta);	
				}
				getch();	
		
			break;
		}
	}while(op!=0);
	
	liberar(&lista);
	
	return 0;
}

void inicializar(struct tNo **list){	
	(*list) = NULL;
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
	struct tNo *p, *q = *list;
	
	if((*list) == NULL){ // lista vazia 
		novo->next = novo;
		(*list) = novo;
	}
	else{ //meio 
		p = q->next;
		
		while((novo->dado.codigo < (*list)->dado.codigo) && (p->dado.codigo <= novo->dado.codigo)){
			q = p;
			p = p->next; 
		}
		q->next = novo;
		novo->next = p;		
		
		if(novo->dado.codigo > (*list)->dado.codigo)
			(*list) = novo;
	}
}

void listar(struct tNo *list){
	struct tNo *p = list;
	
	if(p == NULL)
		return;
	do{
		p = p->next;
		printf("Código: %d\n", p->dado.codigo);
		printf("Descrição: %s\n", p->dado.descricao);
	}while(p != list); 
	 
	getch();
}	

struct tNo *consultar(int pesq, struct tNo *list){
	struct tNo *p = list;
	
	if(p == NULL)
		return;
	do{
		p = p->next;
		
		if(p->dado.codigo == pesq)
			return p;
			
	}while(p != list); 

	return NULL;
}	
	
struct tNo *comparaD(struct tNo *p, char descricao[], int pesq){
	while((p != NULL) && (p->dado.codigo == pesq)){
		if((strcmp(p->dado.descricao, descricao)) == 0)
			return p;
		p = p->next;
	}	
	return NULL;
}	

void alterar(struct tNo *consult, char novaD[]){
	strcpy(consult->dado.descricao, novaD);
}	
	
int excluir(struct tNo **list, int pesq, struct tNo *consult){
	struct tNo *p = *list;
	
	if(p == consult){ //único
		*list = NULL;	
	}
	else{ //meio 
		while(p->next != consult)
			p = p->next;
		p->next = consult->next;	
		if((*list) == consult)
			(*list) = p; 
	}
	free(consult);
	return 0;
}	

void liberar(struct tNo **list){
	struct tNo *p = *list, *q;
	
	if(p!= NULL){
		q = p; 
		p = p->next;
		q->next = NULL;
	}
	
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
}
