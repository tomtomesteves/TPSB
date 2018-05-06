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
      op = IntToBin(aux,9);
      strcat(op,"\0");
      return op;
    }
    else {
      aux = atoi(operandos);
      op = IntToBin(aux,9);
      strcat(op,"\0");
      return op;
    }
  }

  else if (flag == 2) { //reg(2)endereço(9)
    char* op = malloc(15*sizeof(char));
    char* aux2;
    char aux3[20];
    int aux;
    op = strtok(operandos," ");
    printf("op=%s\n",op);
    op = decodeReg(op,0);
    printf("newop=%s\n",op);
    aux2 = strtok(NULL," \0;");
    printf("aux2=%s\n",aux2);

    if(aux = pesquisa_lista(lista,aux2) != -1){
      printf("entrei.aux=%d\n",aux);
      aux2 = IntToBin(aux,9);
      printf("aux2=%s\n",aux2);
      strcpy(aux3,op);
      printf("aux3=%s\n",aux3);
      strcat(aux3,aux2);
      printf("aux3+aux2=%s\n",aux3);
      strcat(aux3,"\0");
      printf("aux3=%s\n",aux3);
      op=NULL;
      op=aux3;
      printf("op=%s\n",op);
      return op;
    }
    else{
      aux = atoi(aux2);
      aux2 = IntToBin(aux,9);
      strcat(op,aux2);
      strcat(op,"\0");
      return op;
    }
  }

  else if (flag == 3) { //reg(11(2 menos sig))
    char* op;
    printf("rwarw\n" );
    op = decodeReg(operandos,1);
    printf("op == %s\n",op );
    return op;
  }

  else if (flag == 4) { //reg1(2)reg2(9(2 menos sig))
    char* aux = malloc(15*sizeof(char));
    char* op;
    char aux3[20];
    //op = malloc(17*sizeof(char));
    aux = strtok(operandos," ");
    op = decodeReg(aux,0);
    strcpy(aux3,op);
    printf("op == %s\n",op );
    aux = strtok(NULL," \0\n;");
    printf("aux == %s\n",aux );
    printf("%d\n",strlen(aux) );
    op = decodeReg(aux,2);

    printf("aux == %s\n",aux );
    strcat(aux3,op);
    printf("aux3 == %s\n",aux3 );
    strcat(aux3,"\0");
    op = aux3;
    return op;
  }
}
