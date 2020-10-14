/*Síntese
	Objetivo: Fazer um jogo da velha e informar se ouve ganhador ou se deu "velha".
	Data: 02/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
	char jogo[3][3];
	int posL, posC, qtdX, qtdO, xGanhou=0, oGanhou=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	for(posL=0;posL<3;posL++)
		for(posC=0;posC<3;posC++){
			do{
				printf("Insira X ou O.\n");
				jogo[posL][posC]=getche();
				jogo[posL][posC]=toupper(jogo[posL][posC]);
				printf("\n");
			}while(jogo[posL][posC]!='X' && jogo[posL][posC]!='O');
		}	

	for(posL=0;posL<3;posL++){
		qtdX=0;
		qtdO=0;
		for(posC=0;posC<3;posC++){
			if(jogo[posL][posC]=='X')
				qtdX++;	
			if(jogo[posL][posC]=='O')	
				qtdO++;
		}
		
		if(qtdX==3)
			xGanhou=1;
		else if(qtdO==3)
			oGanhou=1;
	}

	
	if(xGanhou!=1 && oGanhou!=1){
		qtdX=0;
		qtdO=0;
		for(posC=0;posC<3;posC++){
			qtdX=0;
			qtdO=0;
			for(posL=0;posL<3;posL++){
				if(jogo[posL][posC]=='X')
					qtdX++;	
				if(jogo[posL][posC]=='O')	
					qtdO++;
			}
			
			if(qtdX==3)
				xGanhou=1;
			else if(qtdO==3)
				oGanhou=1;
		}
	}
	
	if(xGanhou!=1 && oGanhou!=1){
		qtdX=0;
		qtdO=0;

		for(posL=0;posL<3;posL++){
			if(jogo[posL][posL]=='X')		
				qtdX++;
			if(jogo[posL][posL]=='O')		
				qtdO++;			
		}
		
		if(qtdX==3)
			xGanhou=1;
		else if(qtdO==3)
			oGanhou=1;
	}
	
	if(xGanhou!=1 && oGanhou!=1){
		
		qtdX=0;
		qtdO=0;
		
		for(posL=0, posC=2;posL<3;posL++, posC--){
			if(jogo[posL][posC]=='X')		
				qtdX++;
			if(jogo[posL][posC]=='O')		
				qtdO++;	
		}
	}
	
	if(qtdX==3)
		xGanhou=1;
	else if(qtdO==3)
		oGanhou=1;
	
	if(xGanhou==1)
		printf("X ganhou!!!");
	else if(oGanhou==1)
		printf("O ganhou!!!");
	else 
		printf("Deu velha");
					
	return 0;
}







