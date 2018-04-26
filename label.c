#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void inicializa_lista(TipoLista *lista){

    lista.size = 0;
    lista->primeiro = (apontador)malloc(sizeof(TipoCelula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

void insere_lista(TipoLista* lista,int adress, char* label){

  int tam;

  lista->size++;
  lista->ultimo->prox = (apontador)malloc(sizeof(TipoCelula));
  lista->ultimo = lista->ultimo->prox;
  tam = strlen(label);
  lista->ultimo->item.label = (char*)malloc(tam*sizeof(char));
  lista->ultimo->item.adress = adress;
  lista->ultimo->item->label = *label;
  lista->ultimo->prox = NULL;
}


void free_lista(TipoLista* lista){
  apontador aux = lista->primeiro->prox;
  apontador aux2 = aux;
  while (aux != NULL){
    aux2 = aux;
    aux = aux->prox;
    free(aux2->item.label);
    free(aux2);
  }
}
