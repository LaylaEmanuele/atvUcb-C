// Sintese
// objetivo "Gincana. Modalidade Programação. Nível júnior. 2a Fase de 2011.
// site "https://olimpiada.ic.unicamp.br/pratique/pj/2011/f2/gincana/"
// Requisito "1 - Lista de lista"
// autor "Layla Emanuele Efren Costa"
// data "24/06/2020"
#include <stdio.h>
#include <stdlib.h>
// Tipo de variável ***********************************************************
struct tNo {
	int aluno;
	struct tNo *prox;
	struct tNo *time;
};
// Protótipo de função ********************************************************
void incluir(struct tNo **lst, struct tNo *novo);
struct tNo *consultar(struct tNo *lst, int codigo);
void destruir(struct tNo **list);

int main(void) {
	int nAlunos, mLista;
	struct tNo *lista=NULL, *no, *no2, *consulta1, *consulta2, *p; 
	int iAluno, jAluno, times=0, i, aux=0;

	scanf("%d %d", &nAlunos, &mLista);
	
	for (i=0; i<mLista; i++) {
	
		scanf("%d %d", &iAluno, &jAluno);
		consulta1 = consultar(lista,iAluno);
		consulta2 = consultar(lista, jAluno);
		
		if((consulta1 == NULL) && (consulta2 == NULL)) { //nenhum dos dois inclusos 
			no = malloc(sizeof(struct tNo));
			no->aluno = iAluno;
			no2 = malloc(sizeof(struct tNo));
			no2->aluno = jAluno;
			no->time= no;
			incluir( &lista, no);
			incluir( &lista, no2);
		}
		
		if((consulta1 == NULL) && (consulta2 != NULL)) { //o primeiro nao add na lista 
			no = malloc(sizeof(struct tNo));
			no->aluno = iAluno;
			no->time= no2->time;
			incluir( &lista, no);
		}
		
		if((consulta1 != NULL) && (consulta2 == NULL)) { //o segundo nao add na lista 
			no2 = malloc(sizeof(struct tNo));
			no2->aluno = jAluno;
			no2->time= no->time;
			incluir( &lista, no2);
		}
		
		
	}
	p = lista;
	
	while(p != NULL){
		times++;
		p = p->prox;
	}
	
	while(times!= nAlunos){
		aux++;
		times++;
	}
	
	printf("%d", times);
	
	destruir(&lista);
	return 0;
}

//Funções

void incluir(struct tNo **list, struct tNo *novo){

	struct tNo *p, *q;
	
	if(((*list)==NULL) || (novo->aluno <= (*list)->aluno)){
		novo->prox = *list;
		*list = novo;
	}
	else{
		p = *list;
		
		while((p != NULL) && (p->aluno <= novo->aluno)){
			q = p;
			p = p->prox; 
		}
		q->prox = novo;
		novo->prox = p;		
	}
}

struct tNo *consultar(struct tNo *lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->aluno == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}

void destruir(struct tNo **list){
	struct tNo *p = (*list), *q;
	
	while(p!=NULL){
		q = p;
		p = p->prox;
		free(q);
	}
}


//*** FIM *********************************************************************
