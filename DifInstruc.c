#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DifInstruc.h"

char* DifInstruction(int flag, char* operandos,TipoLista* lista){
  if (flag == 0) {      //Zero(11)
    char* s;
    strcpy(s,"00000000000");
    strcat(s,"\0");
    return s;
  }

  else if (flag == 1) { //Endereco(11(9 menos sig))
    char* op;
    int aux;
    if(aux = pesquisa_lista(lista,operandos) != -1){
      op = intToBin(aux,11);
      strcat(op,'\0');
      return op;
    }
    else {
      aux = atoi(operandos);
      op = intToBin(aux,11);
      strcat(op,'\0');
      return op;
    }
  }

  else if (flag == 2) { //reg(2)endereço(9)
    char* op;
    char* aux2;
    int aux;
    op = strtok(operandos," ");
    op = decodeReg(op,0);
    aux2 = strtok(NULL," \0;");

    if(aux = pesquisa_lista(lista,aux2) != -1){
      aux2 = intToBin(aux,9);
      strcat(op,aux2);
      strcat(op,'\0');
      return op;
    }
    else{
      aux = atoi(aux2);
      aux2 = intToBin(aux,9);
      strcat(op,aux2);
      strcat(op,"\0");
      return op;
    }
  }

  else if (flag == 3) { //reg(11(2 menos sig))
    char* op;
    op = decodeReg(op,1);
    return op;
  }

  else if (flag == 4) { //reg1(2)reg2(9(2 menos sig))
    char* aux;
    aux = strtok(operandos,' ');
    op = decodeReg(aux,0);
    aux = strtok(NULL,' \0;');
    aux = decodeReg(aux,2);
    strcat(op,aux2);
    strcat(op,'\0');
    return op
  }
}


char *IntToBin(int n,int tamanho){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(tamanho+1);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = tamanho ; c >= 0 ; c--){
    d = n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  return  pointer;
}
