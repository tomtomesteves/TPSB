#include <stdio.h>
#include <string.h>

#include "opcode.h"



int opcodeDecode(char* instruction){
    if(!strcomp(instruction,"ADD")) //traduçao
    else if(!strcomp(instruction,"SUB")) //

}

char *IntToBin(int n){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(32+1);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = 31 ; c >= 0 ; c--){
    d = n >> c;
    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';
    count++;
  }
  *(pointer+count) = '\0';
  return  pointer;
}
