#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAREDE 		0x2A // *
#define LIVRE 		0x20 // espaco em branco
#define VISITADA 	0x2E // .
#define BECO 		0x23 // #
#define ATUAL  		0x40 // @

int labirinto[30][30];

void inicializa_paredes();
void imprimir();


int main(int argc, char **argv)
{
	inicializa_paredes();
	imprimir();
	return 0;
}


/**
 * Cria as bordas do labirinto
 */
void inicializa_paredes()
{
	int i, j;
	
	for (i=0; i<30; i++)
	{
		for (j=0; j<30; j++)
		{
			if (i==0 || i==29)
			{
				// Primeira e ultima linha & coluna
				labirinto[i][j] = PAREDE;
				labirinto[j][i] = PAREDE;
			}
		}
	}
}


void imprimir()
{
	int i, j;
	for (i=0; i<30; i++)
	{
		for (j=0; j<30; j++)
		{
			if (labirinto[i][j] == 0)
				printf("%c ", LIVRE);
			else
				printf("%c ", labirinto[i][j]);
		}
		printf("\n");
	}
}
