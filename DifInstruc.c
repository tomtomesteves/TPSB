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
    if(label){
      int aux;
      if(aux = pesquisa_lista(lista,operandos) != -1){
        op = intToBin(aux);
        strcat(op,'\0');
        return op;
      }
    }
    else {
      int aux = int(operandos);//nao sei se funciona
      op = intToBin(aux);
    }
    strcat(op,'\0');
    return op;
  }
  else if (flag == 2) { //reg(2)endereço(9)
    char* op;
    if(label){
      int aux;
      if(aux = pesquisa_lista(lista,operandos) != -1){
        op = intToBin(aux);
        strcat(op,'\0');
        return op;
      }
    }
    else {
      char* aux;
      aux = strtok(operandos,' ');
      op = decodeReg(aux,0);
      aux = strtok(operandos,'\0');
      int a = (int)aux;
      aux = intToBin(a);
      strcat(op,aux);
    }
    strcat(op,'\0');
    return op;
  }
  else if (flag == 3) { //reg(11(2 menos sig))
    char* op;
    op = decodeReg(op,1);
    int aux = (int)op;
    op = intToBin(aux);
    return op;
  }
  else if (flag == 4) { //reg1(2)reg2(9(2 menos sig))
    char* aux;
    aux = strtok(operandos,' ');
    op = decodeReg(aux,0);
    aux = strtok(operandos,'\0');
    char* aux2;
    aux2 = decodeReg(aux,2);
    strcat(op,aux2);
    strcat(op,'\0');
    return op
  }
}


char *IntToBin(int n){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(12);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = 12 ; c >= 0 ; c--){
    d = n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  return  pointer;
}
