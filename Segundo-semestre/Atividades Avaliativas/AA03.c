/*Síntese:
	Objetivo: LSE modularizada de produtos com exclusão, backup, restore.
	Data: 24/10/2019
	Autores: Gabriel Raposo e Layla Emanuele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

// Prototipos de funcao
int menu(void);
void incluir(struct tNo **lis, struct tNo *novo);
void listar(struct tNo *lis);
struct tNo* consultar(int cod, struct tNo *lis);
int alterar(int cod, struct tNo *lis);
void backupear(struct tNo* p, struct tNo** q, struct tNo** backup);
void restaurar(struct tNo* p, struct tNo** q, struct tNo** lst);

//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	struct tNo *lista=NULL, *backup=NULL;
	struct tNo *p, *q, *pesquisa;
	int opcao, pesqCod, exc, encontrou;
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				p = malloc(sizeof(struct tNo));

				printf("Digite o código do produto: ");
				scanf("%d", &( (*p).dado.codigo ));
				printf("Digite a descrição do produto: ");
				fflush(stdin);
				gets( (*p).dado.descricao );
				printf("Digite o valor do produto: ");
				scanf("%f", &((*p).dado.valor) );
				incluir(&lista,p);
				break;
				
			case 2:
				
				printf("\n\n*** Listagem ***\n");
				listar(lista);
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;

			case 3:
				printf("\n\n*** Consulta ***\n");				

				printf("Qual o código do produto que deseja encontrar?\n");
				scanf("%d",&pesqCod);
				pesquisa=consultar(pesqCod,lista);				

				if(pesquisa == NULL)
					printf("Produto não encontrado!");
				else
					printf("Produto encontrado!");	
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;

			case 4:

				printf("\n\n*** Alterar ***\n");
				printf("Qual o código do produto que deseja alterar as informações?\n");
				scanf("%d",&pesqCod);
				encontrou=alterar(pesqCod, lista);


				if(encontrou !=1)
					printf("Produto não encontrado!");
				else
					printf("Produto alterado com sucesso!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;
			case 5:
				printf("\n\n*** Exclusão ***\n");
				printf("Qual o produto que deseja excluir?\n");
				scanf("%d",&exc);
				encontrou=excluir(exc, &lista);
				
				if(encontrou !=1)
					printf("Produto não encontrado!");
				else
					printf("Produto excluido com sucesso!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;
			case 6: 
				printf("\n\n*** Backupear ***\n");
				p = lista;
				backupear(p, &q, &backup);
				printf("Backup feito com sucesso!");
				break;
			case 7:
				printf("\n\n*** Restaurar ***\n");
				p = backup;
				restaurar(p, &q, &lista);
				printf("Restauracao feita com sucesso!");
				break;
		}
	} while (opcao != 0);
	
	p = lista;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	return 0; 
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alteração\n");
	printf("5. Exclusão\n");
	printf("6. Backup\n");
	printf("7. Restaurar\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//--- Inclusão -----------------------------------------------------------
void incluir(struct tNo **lis, struct tNo *novo){
	novo->prox = *lis;
	*lis = novo;	
}

//--- Listagem -----------------------------------------------------------
void listar(struct tNo *lis){
	while (lis != NULL) {
		printf("--> %s\n", lis->dado.descricao);
		lis = lis->prox;
	}
}

//--- Consultar -----------------------------------------------------------
 struct tNo* consultar(int cod, struct tNo *lis){
	while (lis != NULL) {
		if(lis->dado.codigo == cod)
			return lis;
		
		lis = lis->prox;
	}
	
	return NULL;
}

//--- Alterar ------------------------------------------------------------
int alterar(int cod, struct tNo *lis){
	
	while (lis != NULL) {
		if(lis->dado.codigo == cod){
			printf("Digite a nova descrição do produto: ");
			fflush(stdin);
			gets(lis->dado.descricao );
			printf("Digite o novo valor do produto: ");
			scanf("%f", &(lis->dado.valor) );
			return 1;
		}
		lis = lis->prox;
	}
	
	return 0;
}

//--- Excluir ------------------------------------------------------------

int excluir(int cod, struct tNo **lis) {
	struct tNo *aux, *anterior;
	aux = *lis;

	if(aux->dado.codigo == cod) { //caso seja o primeiro
		*lis = aux->prox;
		free(aux);
		return 1;
	}

	do {
		if(aux->dado.codigo == cod) { //caso faça parte do meio
			anterior->prox = aux->prox;
			free(aux);

			return 1;
		}
		anterior = aux;
		aux = aux->prox;
	} while (aux->prox != NULL);

	if(aux->dado.codigo == cod) { //caso seja o último
		anterior->prox = NULL;
		free(aux);		
		return 1;
	}

	return 0; //retorna 0 caso não encontre o código pesquisado
}

//--- Backup ------------------------------------------------------------
void backupear(struct tNo* p, struct tNo** q, struct tNo** backup){
	struct tNo *r;
	*q=*backup;
	while((*q)!=NULL){
		r = *q;
		*q = (*q)->prox;
		free(r); 
	}
	*backup=NULL;
	while(p!=NULL){
		*q = malloc(sizeof(struct tNo));
		(*q)->dado = p->dado;
		p=p->prox;
		(*q)->prox = *backup;
		*backup = *q;
	}
}
//--- restaurar ------------------------------------------------------------
void restaurar(struct tNo* p, struct tNo** q, struct tNo** lst){
	struct tNo *r;
	*q=*lst;
	while((*q)!=NULL){
		r = *q;
		*q = (*q)->prox;
		free(r); 
	}
	*lst=NULL;
	while(p!=NULL){
		*q = malloc(sizeof(struct tNo));
		(*q)->dado = p->dado;
		p=p->prox;
		(*q)->prox = *lst;
		*lst = *q;
	}
}

