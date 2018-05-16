#ifndef LABEL_H
#define LABEL_H
//LISTA DE LABELS
typedef struct TipoItem{
  char *label;
  int adress;
}TipoItem;

typedef struct Celula* apontador;

typedef struct Celula{
  TipoItem item;
  apontador prox;
}Celula;

typedef struct TipoLista{
  apontador primeiro, ultimo;
}TipoLista;

//inicializa a lista, recebendo um ponteiro para TipoLista
void inicializa_lista(TipoLista *lista);

//insere uma label e seu endereço na lista
void insere_lista(TipoLista* lista,int adress, char* label);

//Retorna o endereço associado a label fornecida. Caso não encontre a label, retorna -1
int pesquisa_lista(TipoLista *lista,char* label);

//Desaloca os elementos da lista
void free_lista(TipoLista* lista);

void imprime_lista(TipoLista *lista);

#endif
