#ifndef LISTA_H
#define LISTA_H
//LISTA DE LABELS -
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

//inicializa a lista, recebendo um ponteiro para TipoLista
void inicializa_lista(TipoLista *lista);

//insere uma label e seu endereço na lista
void insere_lista(TipoLista* lista,int adress, char* label);

//Retorna o endereço associado a label fornecida. Caso não encontre a label, retorna -1
void pesquisa_lista(TipoLista *lista,char* label);

//Desaloca os elementos da lista
void free_lista(TipoLista* lista);

#endif
