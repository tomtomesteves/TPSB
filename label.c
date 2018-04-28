#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void inicializa_lista(TipoLista *lista){ //aloca celula cabeça
    lista.size = 0;
    lista->primeiro = (apontador)malloc(sizeof(TipoCelula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

void insere_lista(TipoLista* lista,int adress, char* label){
  int tam;

  lista->size++;
  lista->ultimo->prox = (apontador)malloc(sizeof(TipoCelula)); //aloca celula
  lista->ultimo = lista->ultimo->prox;
  tam = strlen(label);                                         //pega tamanho da label
  lista->ultimo->item.label = (char*)malloc(tam*sizeof(char)); //aloca vetor char para a label
  lista->ultimo->item.adress = adress;
  lista->ultimo->item->label = *label;
  lista->ultimo->prox = NULL;
}

int pesquisa_lista(TipoLista* lista,char* label){
    int flag=-1; //enquanto igual a -1, label não reconhecida
    apontador aux; //ponteiro para percorrer a lista
    aux = lista->primeiro->prox;
    while(aux!=NULL && !strcmp(label,aux->item.label)) //enquanto nao acabar a lista e nao encontrar a label
      aux=aux->prox;
    if(aux!=NULL)//se saiu do while, verifica se foi por encontrar ou por terminar a lista
      return(aux->item.adress); //retorna o endereço acossiado a label caso tenha saido do while por ter enncontrado
    return flag;
}

void free_lista(TipoLista* lista){
  apontador aux = lista->primeiro->prox;
  apontador aux2 = aux;
  while (aux != NULL){
    aux2 = aux;
    aux = aux->prox;
    free(aux2->item.label); //desaloca string da label
    free(aux2);             //free na célula
  }
}
