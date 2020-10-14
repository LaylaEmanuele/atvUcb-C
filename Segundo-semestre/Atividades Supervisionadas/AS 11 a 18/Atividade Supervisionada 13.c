/*Síntese:
   Objetivo: Criar uma lista(modularizada) de produtos com seus dados (struct[codigo, valor, nome]) podendo se fazer: alteração da lista, deletar os dados inseridos, backup, restaução, ordenação e pesquisa binária.
   Data: 02/10/2019
   Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 100

struct tProdutos {
	int codigo;
	float valor;
	char nome[100];
};


void listar(struct tProdutos[], int);
int adicionar(struct tProdutos[], struct tProdutos, int*);
int consultar(struct tProdutos[], int, int);
int alterar(struct tProdutos[], int, int);
int deletar(struct tProdutos[], int*, int);
int menu();
int receberCodigo();
void receberDados(struct tProdutos*);
void criarBackup(struct tProdutos[], struct tProdutos[], int, int*);
void restaurarBackup(struct tProdutos[], struct tProdutos[], int*, int);
void ordenar(struct tProdutos[], int, int);
int pesquisar(struct tProdutos[], int, int);

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	int escolha, qtd=0, pesquisa, posicao, backupQtd, inicio=0, ordenado=0, pos;

	struct tProdutos produtos[TAM];
	struct tProdutos produto;
	struct tProdutos backup[TAM];

	do {
		escolha = menu();

		switch(escolha) {
			case 1 :
				ordenado=0;
				produto.codigo = receberCodigo();
				receberDados(&produto);
				if(!adicionar(produtos, produto, &qtd)) {
					printf("Estoque cheio!");
					getch();
				}
				break;

			case 2 :

				listar(produtos, qtd);
				break;

			case 3 :

				system("cls");
				printf("Digite o código do produto que você deseja procurar:");
				scanf("%i",&pesquisa);

				posicao=consultar(produtos, qtd, pesquisa);

				if(posicao!=-1)
					printf("%10s - R$%3.2f", produtos[posicao].nome, produtos[posicao].valor);
				else
					printf("Produto não encontrado!");
				getch();
				break;

			case 4 :

				system("cls");
				printf("Digite o código do produto que você deseja alterar os dados:");
				scanf("%i",&pesquisa);

				posicao=consultar(produtos, qtd, pesquisa);

				if(posicao!=-1) {
					receberDados(&produtos[posicao]);
					printf("\nAlteração feita com sucesso!");
				} else
					printf("Produto não encontrado!");
				getch();
				break;


				break;

			case 5:

				system("cls");
				printf("Digite o código do produto que deseja excluir:\n");
				scanf("%i",&pesquisa);

				if(!deletar(produtos, &qtd, pesquisa))
					printf("Produto não encontrado!");
				else
					printf("Deletado com sucesso!");
				getch();
				break;

			case 6:
				system("cls");
				criarBackup(produtos,backup, qtd, &backupQtd);
				printf("Backup realizado com sucesso!");



				getch();
				break;

			case 7:
				system("cls");
				restaurarBackup(produtos,backup, &qtd, backupQtd);
				printf("Restauração realizada com sucesso!");

				getch();
				break;

			case 8:
				system("cls");
				if(ordenado==0) {
					ordenar(produtos, inicio, qtd-1);
					printf("Ordenação realizada com sucesso!");
					ordenado=1;
				} else
					printf("A lista já está ordenada!");
				getch();
				break;

			case 9:
				system("cls");
				if(ordenado==1){
					printf("Qual a o número que você deseja procurar?\n");
					scanf("%d",&pesquisa);
					system("cls");
	
					pos=pesquisar(produtos, pesquisa, qtd);
					if(pos!=-1)
						printf("O número %d foi encontrado na posição %d",pesquisa ,pos+1);
					else
						printf("O número não foi encontrado!");
				}else
					printf("Os produtos precisam estar ordenados!");
				getch();
				break;
		}

	} while(escolha!=0);
	return 0;
}

int menu () {
	int opcao;

	system("cls");
	printf("1 - Para adicionar produto.\n");
	printf("2 - Para ver os produtos já adicionados.\n");
	printf("3 - Para consultar\n");
	printf("4 - Para alterar\n");
	printf("5 - Para deletar um produto adicionado a lista.\n");
	printf("6 - Para realizar o backup.\n");
	printf("7 - Para realizar a restauração.\n");
	printf("8 - Para realizar a ordenação de forma crescente.\n");
	printf("9 - Para realizar uma pesquisa utilizando o método binário.\n");
	printf("0 - Para sair.\n");
	scanf("%i",&opcao);

	return opcao;
}

int receberCodigo() {
	int cod;

	system("cls");
	printf("Informe o código do produto:");
	scanf("%i",&cod);

	return cod;
}

void receberDados(struct tProdutos *prod) {

	system("cls");
	printf("Insira o nome do produto:");
	fflush(stdin);
	gets((*prod).nome);

	system("cls");
	printf("Informe o valor do produto:");
	scanf("%f",&((*prod).valor));

}

int adicionar(struct tProdutos aProdutos[], struct tProdutos aProduto, int *aQtd) {
	if(*aQtd>=TAM)
		return 0;

	aProdutos[*aQtd] = aProduto;
	(*aQtd)++;

	return 1;
}

void listar(struct tProdutos lProdutos[], int lQtd) {
	int j;
	system("cls");
	for(j = 0; j<lQtd; j++)
		printf("%10i - %10s - R$%1.2f \n", lProdutos[j].codigo, lProdutos[j].nome,  lProdutos[j].valor);
	getch();
}

int consultar(struct tProdutos cProdutos[], int cQtd, int cPesquisa) {
	int j;

	for(j=0; j<cQtd; j++)
		if(cPesquisa == cProdutos[j].codigo)
			return j;

	return -1;
}

int deletar(struct tProdutos dProdutos[], int *dQtd, int dPesquisa) {
	int j;

	for(j=0; j<*dQtd; j++)
		if(dPesquisa == dProdutos[j].codigo) {
			dProdutos[j]=dProdutos[*dQtd-1];
			(*dQtd)--;
			return 1;
		}

	return 0;
}

void criarBackup(struct tProdutos bProdutos[], struct tProdutos bBackup[], int bQtd, int *bBackupQtd) {
	int j;

	for(j=0; j<bQtd; j++)
		bBackup[j] = bProdutos[j];

	*bBackupQtd=bQtd;

}

void restaurarBackup(struct tProdutos rProdutos[], struct tProdutos rBackup[], int *rQtd, int rBackupQtd) {
	int j;

	for(j=0; j<*rQtd; j++)
		rProdutos[j] = rBackup[j];

	*rQtd=rBackupQtd;
}

void ordenar(struct tProdutos prods[], int ini, int fim) {
	int i=ini, j=fim, pivo=prods[(ini+fim)/2].codigo;
	struct tProdutos aux;
	while(i<j) {

		while(pivo>prods[i].codigo && i<fim)
			i++;

		while(pivo<prods[j].codigo && j>ini)
			j--;

		if(i<=j) {
			aux=prods[i];
			prods[i]=prods[j];
			prods[j]=aux;
			i++;
			j--;
		}
	}

	if(j>ini)
		ordenar(prods, ini, j);
	if(i<fim)
		ordenar(prods, i, fim);
}

int pesquisar(struct tProdutos prods[], int chave, int qtd) {    //pesquisa binária
	int inicio=0, fim=qtd-1, meio=(inicio+fim)/2;

	while(inicio<=fim && chave!=prods[meio].codigo) {
		meio=(inicio+fim)/2;
		if(chave == prods[meio].codigo)
			return meio;
		else if(chave > prods[meio].codigo)
			inicio = meio+1;
		else if(chave < prods[meio].codigo)
			fim = meio-1;
	}
	
	if(inicio>fim)
		return -1;
	
	return meio;	
}
