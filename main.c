#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"

void gera_labirinto();
int verifica_adjacentes(int coordenadas);
int is_beco(int coordenadas);
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

/**
 * Percorre o labirinto
 */
void percorre()
{
  int nova_posicao = verifica_adjacentes(pos_atual);

  int atual_x = get_x(pos_atual);
  int atual_y = get_y(pos_atual);

  if (nova_posicao != 0)
  {
    int novo_x = get_x(nova_posicao);
    int novo_y = get_y(nova_posicao);

    // Posicao atual é modificada como visitada
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
 * Verifica se as po
 * @return [description]
 */
int is_beco(int coordenadas)
{
  int x = get_x(coordenadas);
  int y = get_y(coordenadas);

  int em_volta[4] = {
    labirinto[ (x-1) ][y], // cima
    labirinto[ (x+1) ][y], // baixo
    labirinto[(x)][ (y+1) ], // direita
    labirinto[(x)][ (y-1) ], // esquerda
  };

  int count = 0; // Se a incidencia for 3 é um beco

  int i;
  for (i = 0; i < 4; ++i)
  {
    if (em_volta[i] == PAREDE || em_volta[i] == BECO)
      count++;
  }

  if (count > 2)
    return 1;

  return 0;
}


/**
 * Procura em volta se tem posicoes livres
 * @return [description]
 */
int preferencia_livre(int coordenadas)
{
  int x = get_x(coordenadas);
  int y = get_y(coordenadas);

  int em_volta[4] = {
    labirinto[ (x-1) ][y], // cima
    labirinto[ (x+1) ][y], // baixo
    labirinto[(x)][ (y+1) ], // direita
    labirinto[(x)][ (y-1) ], // esquerda
  };

  int count = 0; // Se a incidencia for 3 é um beco

  int i;
  for (i = 0; i < 4; ++i)
  {
    if (em_volta[i] == LIVRE)
      count++;
  }

  if (count > 2)
    return 1;

  return 0;
}


/**
 * Verify around positions
 * @return [coded positions]
 */
int verifica_adjacentes(int coordenadas)
{
  int x = get_x(coordenadas);
  int y = get_y(coordenadas);

  int cima      = labirinto[ (x-1) ][y];
  int baixo     = labirinto[ (x+1) ][y];
  int direita   = labirinto[(x)][ (y+1) ];
  int esquerda  = labirinto[(x)][ (y-1) ];

  int nova_posicao;
  // Procura primeiro as LIVRES
  if ( baixo == LIVRE )           nova_posicao = codifica((x+1), y);
  else if ( cima == LIVRE )       nova_posicao = codifica((x-1), y);
  else if ( direita == LIVRE )    nova_posicao = codifica(x, (y+1));
  else if ( esquerda == LIVRE )   nova_posicao = codifica(x, (y-1));

  // Se nenhuma livre, retrocede pelas ja VISITADAS
  else if ( baixo == VISITADA )           nova_posicao = codifica((x+1), y);
  else if ( cima == VISITADA )            nova_posicao = codifica((x-1), y);
  else if ( direita == VISITADA )         nova_posicao = codifica(x, (y+1));
  else if ( esquerda == VISITADA )        nova_posicao = codifica(x, (y-1));

  // Verifica se a nova posição não é um BECO
  int beco = is_beco(nova_posicao);
  if (beco == 1)
  {
    int beco_x = get_x(nova_posicao);
    int beco_y = get_y(nova_posicao);

    // Marca a posição do beco
    labirinto[beco_x][beco_y] = BECO;

    // Procura por uma nova posição
    return verifica_adjacentes(coordenadas);
  }

  // Dando preferencia para as posições LIVRES

  return nova_posicao;
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
