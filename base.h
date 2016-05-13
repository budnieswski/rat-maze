#define PAREDE      0x23 // #
#define LIVRE       0x20 // white space
#define VISITADA    0x2E // .
#define BECO        0x2D // -
#define ATUAL       0x40 // @

typedef struct NODO
{
  int coordenadas;
  struct NODO *prox;
} NODO;

int labirinto[30][30];