/* Síntese
	Objetivo: Fazer uma lista 
	Autora: Layla Emanuele 
	Data: 04/03/2020
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

//Protótipos das funções
void inicializar(struct tNo **list){ //garante que a lista seja inicializada 
	*list = NULL;
}

int incluir(struct tNo **list, struct tNo *novo){ //inclui os dados na lista 
	struct tNo *aux, *p = *list; 
	
	if(*list == NULL){
		*list = novo; // lista esteja vazia 
		novo->next = NULL;
	}
	else{
		
		if(novo->dado.nota < (*list)->dado.nota){
			novo->next = *list; // inclusão início 
			*list = novo;
		}
		else{
			while(p->next != NULL){
				p = p->next;
			}
			
			if(novo->dado.nota > p->dado.nota){
				novo->next = NULL;  // inclusão final 
				p->next = novo;
			}
			else{
				p = *list;
				while(novo->dado.nota < p->dado.nota){
					aux = p;
					p = p->next; // inclusao meio 
				}
				 novo->next = p;
				 aux->next = novo; 
			}
			
		}
	}
	
	
	return 0;
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
	printf("0 - Sair \n");
	
	scanf("%i", &op);
	
	return op; 
}

void listar (struct tNo *list){
	struct tNo *p = list;
	
	while(p != NULL){
		printf("-> %2.2f %s \n", p->dado.nota, p->dado.nome);
		p = p->next;
	}
	getch();
}

struct tNo *consultar (struct tNo *list, char pesqNome[] ){
	struct tNo *p = list;
	
	while(strcmp(pesqNome, p->dado.nome) != 0 && p != NULL)
		p = p->next;	
	
	return p;
}

void alterar (struct tNo *p, char novoN[]){
	strcpy(p->dado.nome, novoN);
}

int main (void){
	struct tNo *lista, *no, *consult, *p, *q;
	int opcao, escolha, inclui;
	char pesqNome[50], novoNome[50];


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
			
				if(inclui == 0)
					printf("Seus dados foram salvos com sucesso!");
			break;
				
			case 2:
			 	listar(lista);
			 
			break;
			 
			case 3:
				printf("Qual o nome a ser consultado?");
				fflush(stdin);
				gets(pesqNome);
			
				consult = consultar(lista, pesqNome);
			
				if(consult == NULL)
					printf("Nome não encontrado");
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
					gets(novoNome);
					
					alterar(consult, novoNome);
					
					printf("Dados alterados com sucesso!");
				}		
		}
	}while(escolha != 0);
	
	p=lista;
	
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	
	return 0;
}
