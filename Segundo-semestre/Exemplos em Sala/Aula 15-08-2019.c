// Sintese
//   objetivo "CRUD de produtos com VETOR de registro (struct) modularizado"
//   data "15/08/2019"
//   autor "Edson F. da Fonseca & Turma de Programacao Estruturada de 2019/2"
#include <stdio.h>
#include <stdlib.h>

// Declaracao de constante
#define TAM 50

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

// Prototipos de funcao
int menu(void);
int receberCodigo(void);
void receberDados(struct tProduto*);
void mostrarProduto(struct tProduto);
int incluir(struct tProduto[], int*, struct tProduto);
int consultar(struct tProduto[], int, int);
void listar(struct tProduto[], int);

//--- Main ---------------------------------------------------------------
int main(void) {
	struct tProduto produtos[TAM];
	struct tProduto produto;
	int qtd=0, opcao, i, codigo, achei, posicao;
	
	do {
		opcao = menu();
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				produto.codigo = receberCodigo();
				receberDados(&produto);
				if (!incluir(produtos, &qtd, produto))
					printf("Encheu!!!");
				break;
			case 2:
				printf("\n\n*** Listagem ***\n");
				listar(produtos, qtd);
				break;
			case 3:
				printf("\n\n*** Consulta ***\n");
				posicao = consultar(produtos, qtd, receberCodigo());
				if (posicao != -1)
					mostrarProduto(produtos[posicao]);
				else
					printf("Codigo nao encontrado!!!");
				break;
			case 4:
				printf("\n\n*** Alteracao ***\n");
				posicao = consultar(produtos, qtd, receberCodigo());
				if (posicao != -1) {
					mostrarProduto(produtos[posicao]);
					receberDados(&produtos[posicao]);
				}
				else
					printf("Codigo nao encontrado!!!");
				break;
				break;
			case 5:
				printf("\n\n*** Exclusao ***\n");
				printf("Digite o codigo: ");
				scanf("%d", &codigo);
				achei = 0;
				for (i=0; i<qtd; i++) {
					if (codigo == produtos[i].codigo) {
						printf("%3d - %20s - R$ %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
						produtos[i] = produtos[qtd-1];
						qtd--;
						achei = 1;
					}
				}
				if (!achei)
					printf("Codigo nao encontrado!!!");
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alteracao\n");
	printf("5. Exclusao\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//--- Receber o codigo do produto ----------------------------------------
int receberCodigo(void) {
	int codigo;
	printf("Digite o codigo do produto...: ");
	scanf("%d", &codigo);
	return codigo;
}

//--- Receber os demais dados do produto ---------------------------------
void receberDados(struct tProduto *prod) {
	printf("Digite a descricao do produto: ");
	fflush(stdin);
	gets((*prod).descricao);
	printf("Digite o valor do produto....: ");
	scanf("%f", &((*prod).valor));
}

//--- Mostrar dos dados (exceto codigo) do produto -----------------------
void mostrarProduto(struct tProduto prod) {
	printf("Descricao....................: %s\n", prod.descricao);
	printf("Valor........................: R$ %.2f\n", prod.valor);
}

//--- Incluir ------------------------------------------------------------
int incluir(struct tProduto prods[], int *qtd, struct tProduto prod) {
	if (*qtd >= TAM)
		return 0; // falso = fracasso
	prods[*qtd] = prod;
	(*qtd)++;
	return 1; // verdadeiro = sucesso
}

//--- Consultar ----------------------------------------------------------
int consultar(struct tProduto prods[], int qtd, int cod) {
	int i;
	for (i=0; i<qtd; i++)
		if (cod == prods[i].codigo)
			return i;
	return -1; // nao encontrado
}

//--- Listar -------------------------------------------------------------
void listar(struct tProduto prods[], int qt) {
	int i;
	for (i=0; i<qt; i++)
		printf("%3d - %20s - R$ %.2f\n", prods[i].codigo, prods[i].descricao, prods[i].valor);
}

//------------------------------------------------------------------------
