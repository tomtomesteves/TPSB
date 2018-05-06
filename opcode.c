#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcode.h"


int opcodeDecode(char* instruction,int *aux){
  if(0==strcmp(instruction,"stop")){
    return 0;
  }
  else if(0==strcmp(instruction, "load")){
    *aux = 1;
    return 2;
  }
  else if(0==strcmp(instruction, "store")){
    *aux = 2;
    return 2;
  }
  else if(0==strcmp(instruction, "read")){
    *aux =  3;
    return 3;
  }
  else if(0==strcmp(instruction, "write")){
    *aux = 4;
    return 3;
  }
  else if(0==strcmp(instruction, "add")) {
    *aux = 5;
    return 4;
  }
  else if(0==strcmp(instruction, "subtract")) {
    *aux = 6;
    return 4;
  }
  else if(0==strcmp(instruction, "multiply")) {
    *aux = 7;
    return 4;
  }
  else if(0==strcmp(instruction, "divide")) {
    *aux = 8;
    return 4;
  }
  else if(0==strcmp(instruction, "jump")) {
    *aux = 9;
    return 1;
  }
  else if(0==strcmp(instruction, "jmpz")) {
    *aux = 10;
    return 2;
  }
  else if(0==strcmp(instruction, "jmpn")) {
    *aux = 11;
    return 2;
  }
  else if(0==strcmp(instruction, "move")) {
    *aux = 12;
    return 4;
  }
  else if(0==strcmp(instruction, "push")) {
    *aux = 13;
    return 3;
  }
  else if(0==strcmp(instruction, "pop"))      {
    *aux = 14;
    return 3;
  }
  else if(0==strcmp(instruction, "call"))     {
    *aux = 15;
    return 1;
  }
  else if(0==strcmp(instruction, "return"))   {
    *aux = 32768;
    return 0;
  }
  else if(0==strcmp(instruction, "load_s"))   {
    *aux = 17;
    return 2;
  }
  else if(0==strcmp(instruction, "store_s"))  {
    *aux = 18;
    return 2;
  }
  else if(0==strcmp(instruction, "loadc"))    {
    *aux = 19;
    return 2;
  }
  else if(0==strcmp(instruction, "loadi"))    {
    *aux = 20;
    return 4;
  }
  else if(0==strcmp(instruction, "storei"))   {
    *aux = 21;
    return 4;
  }
  else if(0==strcmp(instruction, "copytop"))  {
    *aux = 22;
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
    d = *n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  return  pointer;
}
