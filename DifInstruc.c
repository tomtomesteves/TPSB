#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "label.h"
#include "DifInstruc.h"
#include "regDecode.h"
#include "opcode.h"

char *IntToBin(int n,int tamanho){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(tamanho);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = tamanho-1 ; c >= 0 ; c--){
    d = n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  return pointer;
}

char* DifInstruction(int flag, char* operandos,TipoLista* lista, char* label){
  if (flag == 0) {      //Zero(11)
    char* op;
    char aux[20];
    char* s = "00000000000";
    strcpy(aux,s);
    strcat(s,"\0");
    op = s;
    sprintf(label,"%s",op);
    printf("labellll  %s\n",label );
  }

  else if (flag == 1) { //Endereco(11(9 menos sig))
    char* op;
    int aux;
    if(pesquisa_lista(lista,operandos) != -1){
      aux = pesquisa_lista(lista,operandos);
      op = IntToBin(aux,11);
      strcat(op,"\0");
      sprintf(label,"%s",op);
      printf("aquiilabellll  %s\n",label );

    }
    else {
      aux = atoi(operandos);
      op = IntToBin(aux,9);
      strcat(op,"\0");
      sprintf(label,"%s",op);
      printf("labellll  %s\n",label );

    }
  }

  else if (flag == 2) { //reg(2)endereço(9)
    char* op = malloc(15*sizeof(char));
    char* aux2;
    char aux3[20];
    int aux;
    printf("operandos %s\n",operandos );
    op = strtok(operandos," ");
    printf("op == %s\n",op );
    op = decodeReg(op,0);
    aux2 = strtok(NULL," \0;");
    printf("aux2 == %s\n",aux2 );
    if(pesquisa_lista(lista,aux2) != -1){
      printf("pesquisando lista\n" );
      aux = pesquisa_lista(lista,aux2);
      printf("aux == %d\n",aux );
      aux2 = IntToBin(aux,9);
      strcpy(aux3,op);
      strcat(aux3,aux2);
      strcat(aux3,"\0");
      op=NULL;
      op=aux3;
      sprintf(label,"%s",op);
    }
    else{
      aux = atoi(aux2);
      aux2 = IntToBin(aux,9);
      strcat(op,aux2);
      strcat(op,"\0");
      sprintf(label,"%s",op);
      printf("labellll  %s\n",label );

    }
  }

  else if (flag == 3) { //reg(11(2 menos sig))
    char* op;
    op = decodeReg(operandos,1);
    sprintf(label,"%s",op);
  }

  else if (flag == 4) { //reg1(2)reg2(9(2 menos sig))
    char* aux = malloc(15*sizeof(char));
    char* op = malloc(15*sizeof(char));
    char aux3[20];
    //op = malloc(17*sizeof(char));
    aux = strtok(operandos," ");
    op = decodeReg(aux,0);
    printf("              op ===   %s\n",op );
    strcpy(aux3,op);
    aux = strtok(NULL," \0\n;");
    printf("aux %s\n",aux );
    op = decodeReg(aux,2);
    printf("              op == %s\n",op );
    strcat(aux3,op);
    strcat(aux3,"\0");
    op = NULL;
    op = aux3;
    printf("retorna ------- %s\n",op );
    sprintf(label,"%s",op);
  }
}
