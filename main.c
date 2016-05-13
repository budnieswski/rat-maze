#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAREDE      0x23 // #
#define LIVRE       0x20 // espaco em branco
#define VISITADA    0x2E // .
#define BECO        0x2D // -
#define ATUAL       0x40 // @

int labirinto[30][30];

void gera_labirinto();
void imprimir();


int main(int argc, char **argv)
{
  gera_labirinto(2, 2);
  imprimir();
  return 0;
}



/**
 * Initialize and fills the maze 
 * @param [int] x [Rat initial line position]
 * @param [int] y [Rat initial column position]
 */
void gera_labirinto(int x, int y)
{
  int i, j;

  // Alimenta o 'rand()', para que nao seja sempre a mesma sequencia
  srand( (unsigned)time(NULL) );

  for (i=0; i<30; i++)
  {
    for (j=0; j<30; j++)
    {
      // Filling maze borders
      if (i==0 || i==29)
      {
        labirinto[i][j] = PAREDE;
        labirinto[j][i] = PAREDE;
      }
      else if (j!=0 && j!=29) // Avoid overwriting sides walls
      {
        // Rand dos lugares
        if (rand()%3 == 0)
          labirinto[i][j] = PAREDE;
        else
          labirinto[i][j] = LIVRE;
      }
    }
  }

  // Setting rat start position
  labirinto[x][y] = ATUAL;
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