#ifndef LISTA_H
#define LISTA_H

typedef struct TipoItem{
  char *label;
  int adress;
}TipoItem;

typedef TipoCelula* apontador;

typedef struct node{
  TipoItem item;
  apontador prox;
}TipoCelula;

typedef struct lista {
  int size;
  apontador primeiro, ultimo;
}TipoLista;

//inicializa a lista a
void inicializa_lista(TipoLista *lista);

//insere vertice v na lista a
void insere_lista(TipoLista* lista,int adress, char* label);

//Remove da lista a celula aux
void remove_lista(TipoLista* lista,apontador aux,apontador anterior);

//imprime a lista
void imprime_lista(TipoLista* lista);

//free parav vetor de listas de tamanho n
void free_lista(TipoLista* lista);

#endif
