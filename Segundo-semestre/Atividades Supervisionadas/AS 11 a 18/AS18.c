/*Síntese:
	Objetivo: CRUD de arquvios modularizado de produtos com exclusão lógica.
	Data: 04/11/2019
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


// Prototipos de funcao
int menu(void);
int receberCodigo();
void receberDados(struct tProduto *prod); 
int incluir(struct tProduto prod, FILE *arq);
int listar(FILE *arq, struct tProduto prod);
int consultar(FILE *arq, int cod, struct tProduto *prod);
int alterar(FILE *arq, int cod, struct tProduto *prod);
int excluir(FILE *arq, int cod, struct tProduto *prod);


//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	struct tProduto produto;
	FILE *prod;
	int pesqCod, opcao;
	
	
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				produto.codigo=receberCodigo();			
				receberDados(&produto);
				if(incluir(produto, prod))				
					printf("Produto adicionado com sucesso!");
				else
					printf("Um erro ocorreu, o produto não foi adicionado!");
						
				break;
				
			case 2:
				
				printf("\n\n*** Listagem ***\n");
				
				if(!listar(prod, produto))				
					printf("Um erro ocorreu, o arquivo não foi aberto!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;

			case 3:
				printf("\n\n*** Consulta ***\n");				

				pesqCod=receberCodigo();

				if(!consultar(prod, pesqCod, &produto))
					printf("Produto não encontrado!");
				else{
					printf("Produto encontrado!\n");	
					printf("Valor: %10f | Descricao: %10s | Codigo: %10d", produto.valor, produto.descricao, produto.codigo);
				}
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;

			case 4:
				printf("\n\n*** Alterar ***\n");				

				pesqCod=receberCodigo();

				if(!alterar(prod, pesqCod, &produto))
					printf("Produto não encontrado!");
				else
					printf("Produto alterado!");
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;
				
			case 5:
				printf("\n\n*** Excluir ***\n");				

				pesqCod=receberCodigo();

				if(!excluir(prod, pesqCod, &produto))
					printf("Produto não encontrado!");
				else
					printf("Produto excluído!");
				
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;	
			
				
		}
	} while (opcao != 0);
	
	return 0; 
}

//--- Menu --------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Alterar\n");
	printf("5. Excluir\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}
//--- Recebe o código ----------------------------------------------------
int receberCodigo(){
	int cod;
	printf("Digite o código do produto: ");
	scanf("%d", &cod);
	return cod;
}

//--- Recebe os dados ----------------------------------------------------
void receberDados(struct tProduto *prod){
	printf("Digite a descrição do produto: ");
	fflush(stdin);
	gets((*prod).descricao);
	printf("Digite o valor do produto: ");
	scanf("%f", &(*prod).valor);
}

//--- Inclusão -----------------------------------------------------------
int incluir(struct tProduto prod, FILE *arq){
	arq=fopen("produtos.dat","ab");
	if(arq==NULL)
		return 0;
	
	fwrite(&prod,sizeof(prod),1,arq);
	fclose(arq);
	return 1;
}

//--- Listagem -----------------------------------------------------------
int listar(FILE *arq, struct tProduto prod){
	arq=fopen("produtos.dat","rb");
	if(arq==NULL)
		return 0;
		
	while(fread(&prod,sizeof(prod),1,arq))
		if(prod.codigo!=-1)
			printf("Valor: %10f | Descricao: %10s | Codigo: %10d\n", prod.valor, prod.descricao, prod.codigo);
	
	fclose(arq);
	return 1;
}

//--- Consultar -----------------------------------------------------------
int consultar(FILE *arq, int cod, struct tProduto *prod){
	arq=fopen("produtos.dat","rb");
	if(arq==NULL)
		return 0;
		
	while(fread(&*prod,sizeof(*prod),1,arq)){
		if(cod==(*prod).codigo && (*prod).codigo!=-1)
			return 1;
	}
	fclose(arq);	
	return 0;
}

//--- Alterar -------------------------------------------------------------
int alterar(FILE *arq, int cod, struct tProduto *prod){
	arq=fopen("produtos.dat","rb+");
	if(arq==NULL)
		return 0;
		
	while(fread(&*prod,sizeof(*prod),1,arq)){
		if(cod==(*prod).codigo){		
			printf("x");
			receberDados(&(*prod));
			printf("y");
			fseek(arq,-sizeof(*prod),SEEK_CUR);
			fwrite(&*prod,sizeof(*prod),1,arq);
			fseek(arq, 0,SEEK_CUR);
			return 1;
		}	
	}
	fclose(arq);	
	return 0;
}

//--- Excluir -------------------------------------------------------------
int excluir(FILE *arq, int cod, struct tProduto *prod){
	arq=fopen("produtos.dat","rb+");
	if(arq==NULL)
		return 0;
		
	while(fread(&*prod,sizeof(*prod),1,arq)){
		if(cod==(*prod).codigo){		
			(*prod).codigo=-1;
			fseek(arq,-sizeof(*prod),SEEK_CUR);
			fwrite(&*prod,sizeof(*prod),1,arq);
			fseek(arq, 0,SEEK_CUR);
			return 1;
		}	
	}
	fclose(arq);	
	return 0;
}
