#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"

void gera_labirinto();
int verifica_adjacentes();
void percorre();
void imprimir();

int pos_atual;

int main(int argc, char **argv)
{
  Nodo *Pilha;
  inicializa(&Pilha);

  gera_labirinto(2, 2);
  pos_atual = codifica(2, 2);

  int i;
  for (i = 0; i < 100; ++i)
  {
    percorre();
    imprimir();
  }

  return 0;
}


void percorre()
{
  int nova_posicao = verifica_adjacentes();
  if (nova_posicao != 0)
  {
    int atual_x = get_x(pos_atual);
    int atual_y = get_y(pos_atual);

    int novo_x = get_x(nova_posicao);
    int novo_y = get_y(nova_posicao);

    // Posicao atual e modificada como visitada
    labirinto[atual_x][atual_y] = VISITADA;

    // Muda visualmente o local do rato
    labirinto[novo_x][novo_y] = ATUAL;

    // Muda a atual para a nova posicao
    pos_atual = nova_posicao;

    //
    // ARMAZENAR NA PILHA
    //
  }
}


/**
 * Verify around positions
 * @return [coded positions]
 */
int verifica_adjacentes()
{
  int atual_x = get_x(pos_atual);
  int atual_y = get_y(pos_atual);

  int cima      = labirinto[ (atual_x-1) ][atual_y];
  int baixo     = labirinto[ (atual_x+1) ][atual_y];
  int direita   = labirinto[(atual_x)][ (atual_y+1) ];
  int esquerda  = labirinto[(atual_x)][ (atual_y-1) ];

  // Procurar primeiro as livres
  if ( baixo == LIVRE ) return codifica((atual_x+1), atual_y);
  if ( cima == LIVRE ) return codifica((atual_x-1), atual_y);
  if ( direita == LIVRE ) return codifica(atual_x, (atual_y+1));
  if ( esquerda == LIVRE ) return codifica(atual_x, (atual_y-1));

  // Se nenhuma livre, retrocede pelas ja visitadas
  if ( baixo == VISITADA ) return codifica((atual_x+1), atual_y);
  if ( cima == VISITADA ) return codifica((atual_x-1), atual_y);
  if ( direita == VISITADA ) return codifica(atual_x, (atual_y+1));
  if ( esquerda == VISITADA ) return codifica(atual_x, (atual_y-1));

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
  system("cls");
  int i, j;
  for (i=0; i<30; i++)
  {
    for (j=0; j<30; j++)
    {
        printf("%c", labirinto[i][j]);
        // busca
    }
    printf("\n");
  }
  // sleep();
}
