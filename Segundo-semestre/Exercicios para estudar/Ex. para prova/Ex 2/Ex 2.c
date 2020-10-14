#include <stdio.h>
#include <stdlib.h>

//tipo de variavel
struct tPessoa{
	int idade;
	char nome[10];
};


int main(void){
	struct tPessoa pessoa;
	FILE *file;
	
	file = fopen("pessoa.dat", "wb+");

	printf("Idade:\n");
	scanf("%d", &pessoa.idade);
	fflush(stdin);
	printf("Nome:\n");
	gets(pessoa.nome);
	fwrite(&pessoa, sizeof(pessoa), 1, file);
	
	system("cls");
	fseek(file,0,SEEK_SET);
	fread(&pessoa, sizeof(pessoa), 1, file); 
	printf("Leitura...\n");
	printf("\nIdade:\n");
	printf("%d", pessoa.idade);
	printf("\nNome:\n");
	printf("%s", pessoa.nome);

	
	fclose(file);
	
	return 0;
}
