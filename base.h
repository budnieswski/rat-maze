#define PAREDE      0x23 // #
#define LIVRE       0x20 // white space
#define VISITADA    0x2E // .
#define BECO        0x2D // -
#define ATUAL       0x40 // @

typedef struct Nodo
{
  int coordenadas;
  struct Nodo *prox;
} Nodo;

int labirinto[30][30];


/**
 * Inicializa a pilha como vazia
 * @param N [Ponteiro da pilha]
 */
void inicializa (Nodo **N)
{
  *N = NULL;
}


/**
 * Aloca espaco em memoria referente a pilha
 * @return [Ponteiro de pilha]
 */
Nodo * criaNodo ()
{
  Nodo *n;
  n = (Nodo *) malloc( sizeof(Nodo) );
 
  if (!n)
  {
    printf("Erro durante a alocação\n");
    exit(0);
  }
 
  return n;
}


/**
 * Insere um elemento no inicio da pilha
 * @param Pilha [Referencia do ponteiro da pilha]
 * @param lin   [Linha da coordenada a ser armazenada]
 * @param col   [Coluna da coordenada a ser armazenada]
 */
void insere (Nodo **Pilha, int lin, int col)
{
  Nodo *n;
 
  n = criaNodo();
  n->coordenadas = ((lin*100) + col); // OBS-1
  n->prox = *Pilha;

  /**
   * [OBS-1]
   * Armazena as coordenadas em uma unica variavel
   * Facilita na busca e comparacao de elementos */
 
  *Pilha = n;
}


/**
 * Libera todo o espaco em memoria ocupado pela pilha
 * @param Pilha [Referencia do ponteiro da pilha]
 */
void liberarEspaco (Nodo **Pilha)
{
  if (*Pilha != NULL)
  {
    Nodo *aux, *tmp  = *Pilha;
    while (tmp != NULL)
    {
      aux = tmp;
      tmp = tmp->prox;
      free (aux);
    }
    *Pilha = NULL;
  }
}