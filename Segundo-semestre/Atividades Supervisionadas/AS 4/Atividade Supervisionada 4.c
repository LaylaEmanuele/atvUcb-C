/*	Síntese
	Objetivo: Reacriar algumas das funções da biblioteca string.h
	Data: 21/08/2019.
	Autor(a): Gabriel Raposo e Layla Emanuele.
*/

#include <stdlib.h>
#include <stdio.h>

int strlenLariel(char []);
void strcpyLariel(char [], char []);
int strcmpLariel(char [], char []);
void strcatLariel(char [], char []);
void getsLariel(char []);
void putsLariel(char []);

// Main usado apenas para teste das funções 
int main(void){
	char str[50], str2[50];
	int tam;
	
	getsLariel(str);
	printf("%s", str);	
	
	return 0;
}	

int strlenLariel(char string[]){
	int i=0;
	
	do{
		i++;
	}while(string[i]!='\0');
	return i;
}

void strcpyLariel(char destino[], char origem[]){
	int i=0;
		
	do {
		destino[i] = origem[i];
		i++;
	}while(origem[i] != '\0');
	destino[i]='\0';	
}

int strcmpLariel(char primeira[], char segunda[]){
	int i=0, tamanho;
	
	if(strlenLariel(primeira)>strlenLariel(segunda))
		tamanho=strlenLariel(primeira);
	else
		tamanho=strlenLariel(segunda);
		
	do{
		if(primeira[i]!=segunda[i]){
			i++;		
			if(segunda[i]>primeira[i])
				i=i*-1;						
			return i;
		}		
		i++;	
	}while(i<=tamanho);
			
	return 0;
}

void strcatLariel(char destino[], char origem[]){
	int i, j=0;
	
	i=strlenLariel(destino); 	
	do{
		destino[i]=origem[j];
		i++;
		j++;
	}while(origem[j]!='\0');
	destino[i]='\0';
}

void getsLariel(char string[]){
    int i=0, ascii;
    do{
        ascii = getchar();
        string[i]=ascii; //inteiro transformado em char 
        i++;
    }while(ascii!=10);
    string[i]='\0';
}

void putsLariel(char string[]){
	int i;
	 
	for(i=0; i<=strlenLariel(string); i++)
		printf("%c", string[i]);
	printf("\n");
}






