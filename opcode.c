#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcode.h"


int opcodeDecode(char* instruction,int *aux){
  if(!strcmp(instruction,      "stop")){
    return 0;
  }
  else if(!strcmp(instruction, "load")){
    aux = 1;
    return 2;
  }
  else if(!strcmp(instruction, "store")){
    aux = 2;
    return 2;
  }
  else if(!strcmp(instruction, "read")){
    aux =  3;
    return 3;
  }
  else if(!strcmp(instruction, "write")){
    aux = 4;
    return 3;
  }
  else if(!strcmp(instruction, "add")) {
    aux = 5;
    return 4;
  }
  else if(!strcmp(instruction, "subtract")) {
    aux = 6;
    return 4;
  }
  else if(!strcmp(instruction, "multiply")) {
    aux = 7;
    return 4;
  }
  else if(!strcmp(instruction, "divide")) {
    aux = 8;
    return 4;
  }
  else if(!strcmp(instruction, "jump")) {
    aux = 9;
    return 1;
  }
  else if(!strcmp(instruction, "jmpz")) {
    aux = 10;
    return 2;
  }
  else if(!strcmp(instruction, "jmpn")) {
    aux = 11;
    return 2;
  }
  else if(!strcmp(instruction, "move")) {
    aux = 12;
    return 4;
  }
  else if(!strcmp(instruction, "push")) {
    aux = 13;
    return 3;
  }
  else if(!strcmp(instruction, "pop"))      {
    aux = 14;
    return 3;
  }
  else if(!strcmp(instruction, "call"))     {
    aux = 15;
    return 1;
  }
  else if(!strcmp(instruction, "return"))   {
    aux = 32768;
    return 0;
  }
  else if(!strcmp(instruction, "load_s"))   {
    aux = 17;
    return 2;
  }
  else if(!strcmp(instruction, "store_s"))  {
    aux = 18;
    return 2;
  }
  else if(!strcmp(instruction, "loadc"))    {
    aux = 19;
    return 2;
  }
  else if(!strcmp(instruction, "loadi"))    {
    aux = 20;
    return 4;
  }
  else if(!strcmp(instruction, "storei"))   {
    aux = 21;
    return 4;
  }
  else if(!strcmp(instruction, "copytop"))  {
    aux = 22;
    return 3;
  }
  else return -1;
}

char *IntToBinOP(int *n){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(5);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = 4 ; c >= 0 ; c--){
    d = n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  return  pointer;
}
