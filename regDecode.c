#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regDecode.h"


char* decodeReg(char* reg,int n){
  printf("reg == %s\n",reg );
  if(reg[1] == '0'){
    if(n == 0){
      return "00";
    }
    else if(n == 1){
      return "00000000000";
    }
    else if(n == 2){
      return "000000000";
    }
  }
  if(reg[1] == '1'){
    printf("aqui\n" );
    if(n == 0){
      return "01";
    }
    else if(n == 1){
      return "00000000001";
    }
    else if(n == 2){
      return "000000001";
    }
  }
  if(reg[1] == '2'){

    if(n == 0){
      return "10";
    }
    else if(n == 1){
      return "00000000010";
    }
    else if(n == 2){
      return "000000010";
    }
  }
  if(reg[1] == '3'){
    printf("teste\n" );
    if(n == 0){
      return "11";
    }
    else if(n == 1){
      return "00000000011";
    }
    else if(n == 2){
      return "000000011";
    }
  }
  printf("oiasoasi\n" );
}
