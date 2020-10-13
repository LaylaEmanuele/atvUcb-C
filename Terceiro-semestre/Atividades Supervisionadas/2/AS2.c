/* Síntese
	Objetivo: Fazer uma lista 
	Autora: Layla Emanuele 
	Data: 16/03/2020
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de tipos de variáveis 
struct tAluno{
	char nome[50];
	float nota;
};

struct tNo{
	struct tAluno dado;
	struct tNo *next;
};

struct tDescritor{
	struct tNo *ini;
	struct tNo *fim;
	int qtd;
};

//Protótipos das funções
void inicializar(struct tDescritor *);
int menu (int );
void listar (struct tDescritor *);
int incluir(struct tDescritor *, struct tNo *);
struct tNo *consultar (struct tDescritor , char [] );
void alterar (struct tNo *, char []);
int excluir (struct tDescritor * , float );
void destruir (struct tDescritor *);

int main (void){
	struct tNo *no, *consult;
	struct tDescritor lista;
	int opcao, escolha, inclui, exclusao;
	float nota;
	char pesqNome[50], nome[50];

	inicializar(&lista);

	do{	
		system("cls");
		
		escolha = menu(opcao);
		switch(escolha) {
			case 1:
				no = malloc(sizeof(struct tNo));
				
				fflush(stdin);
				
				printf("Qual o nome a ser adicionado?\n");
				gets((*no).dado.nome);
				
				fflush(stdin);
				
				printf("Qual a nota do aluno?\n");
				scanf("%f", &(*no).dado.nota);
				
				
				inclui = incluir(&lista, no);
			
				if(inclui == 0){
					printf("Seus dados foram salvos com sucesso!");
					getch();	
				}
				
			break;
				
			case 2:
			 	listar(&lista);
			 
			break;
			 
			case 3:
				printf("Qual o nome a ser consultado?\n");
				fflush(stdin);
				gets(pesqNome);
			
				consult = consultar(lista, pesqNome);
			
				if(consult == NULL){
					printf("Nome não encontrado!");
					getch();
				}
				else{
					printf("-> %2.2f %s \n", consult->dado.nota, consult->dado.nome);
					getch();
				}
			
			break;
			
			case 4:
				printf("Qual o nome será alterado?");
				fflush(stdin);
				gets(pesqNome);
				
				consult = consultar(lista, pesqNome);
			
				if(consult == NULL)
					printf("Nome não encontrado");
				else{
					printf("Dados-> %2.2f %s \n", consult->dado.nota, consult->dado.nome);
					
					printf("Qual o novo nome?");
					fflush(stdin);
					gets(nome);
					
					alterar(consult, nome);
					
					printf("Dados alterados com sucesso!");
					
					getch();
				}
					
			break;
				
			case 5:
				printf("Qual nota será excluída?");
				scanf("%f", &nota);
				
				exclusao=excluir(&lista, nota);
				
				if(exclusao == 1){
					printf("Lista vazia!");
					getch();
				}
				else{
					printf("Dados excluídos com sucesso");	
					getch();				
				}
				
			break;	
			
			case 6:
				printf("Quantidades de notas incluídas %i", lista.qtd);
				getch();
			
			break;	
		}
	}while(escolha != 0);
	
	destruir (&lista);
	
	return 0;
}

// Funções 
void inicializar(struct tDescritor *list){ //garante que a lista seja inicializada 
	(*list).ini = (*list).fim = NULL;
	(*list).qtd = 0; 
}

int menu (int op){ 
	FILE *arq;
	char menu[1000];
	
	arq = fopen("menu.txt", "r");
	
    while(fgets(menu,sizeof(menu),arq) != NULL)
        printf("%s", menu);
	
	fclose(arq);	
	
	if (arq == NULL){ // Se não conseguiu criar
        printf("Problemas na abertura do menu \n");
   		return 0;
	}
	printf("\n");
	printf("1 - Incluir \n");
	printf("2 - Listar \n");
	printf("3 - Consultar \n");
	printf("4 - Alterar \n");
	printf("5 - Exclusão \n");
	printf("6 - Quantidade de notas \n");
	printf("0 - Sair \n");
	
	scanf("%i", &op);
	
	return op; 
}

int incluir(struct tDescritor *list, struct tNo *novo){ //incluir os dados na lista 
	struct tNo *aux, *p = (*list).ini, *q; 
	
	if (((*list).ini == NULL) || (novo->dado.nota <= (*list).ini->dado.nota)) { // lista vazia e inclusao início
		novo->next = (*list).ini;
		(*list).ini = novo;
		(*list).fim = novo;
	}
	else { // meio e fim
		while ((p != NULL) && (p->dado.nota <= novo->dado.nota)) {
			q = p;
			p = p->next;
		}
		q->next = novo;
		novo->next = p;
		
		if(novo->dado.nota >= (*list).fim->dado.nota) 
			(*list).fim = novo;
	}
	(*list).qtd++; //contagem dos nos
	
	return 0;
}

void listar (struct tDescritor *list){
	struct tNo *p = (*list).ini;
	
	while(p != NULL){
		printf("-> %2.2f %s \n", p->dado.nota, p->dado.nome);
		p = p->next;
	}
	getch();
}

struct tNo *consultar (struct tDescritor list, char pesqNome[] ){
	struct tNo *p = list.ini;
	
	while(p != NULL && strcmp(pesqNome, p->dado.nome) != 0)
		p = p->next;	
	
	return p;
}

void alterar (struct tNo *p, char novoN[]){
	strcpy(p->dado.nome, novoN);
}

int excluir (struct tDescritor *list, float nota){
	struct tNo *p = (*list).ini, *q;
	
	if((*list).ini ==NULL)//lista vazia
		return 1;
		
	if(nota == p->dado.nota){  //inicio 
		(*list).ini = p->next;
		free(p);	
		(*list).qtd--;
		return 0;
	}
	else{ //meio e fim
		
		while(p!= NULL && nota >= p->dado.nota){
			if(nota == p->dado.nota){
				(*list).fim = q;
				q->next = p->next;
				free(p);
				(*list).qtd--;
				return 0; 
			}
			q = p;
			p = p->next;
		}
	} 
	return 0;
}

void destruir (struct tDescritor *list){
	struct tNo *p, *q;
	p = (*list).ini;
	
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
}


