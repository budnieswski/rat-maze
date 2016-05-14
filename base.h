#define PAREDE      0xDB // block
#define LIVRE       0x20 // white space
#define VISITADA    0x2E // .
#define BECO        0xB0 // dotted block
#define ATUAL       0x40 // @

typedef struct Nodo
{
  int coordenadas;
  struct Nodo *prox;
} Nodo;

int labirinto[30][30];


/**
 * Converte as coordenadas em uma unica variavel
 * Facilita na busca e comparacao de elementos
 * @param  x [linha]
 * @param  y [coluna]
 * @return   [cordenadas codificadas]
 */
int codifica (int x, int y)
{
  return (x*100) + y;
}


/**
 * Decodifica a coordenada X (linha)
 * @param  codificado [coordenadas codificadas]
 * @return            [indice da posicao X que estava codificada]
 */
int get_x (int codificado)
{
  return codificado/100;
}


/**
 * Decodifica a coordenada Y (coluna)
 * @param  codificado [coordenadas codificadas]
 * @return            [indice da posicao Y que estava codificada]
 */
int get_y (int codificado)
{
  return codificado%100;
}


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
void push (Nodo **Pilha, int lin, int col)
{
  Nodo *n;
 
  n = criaNodo();
  n->coordenadas = codifica(lin, col); // OBS-1
  n->prox = NULL;

  if (*Pilha == NULL)
    *Pilha = n;
  else
  {
    Nodo *aux = *Pilha;

    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = n;
  }
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