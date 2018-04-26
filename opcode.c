#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcode.h"



int opcodeDecode(char* instruction){
  if(!strcmp(instruction,      "stop"))     return 0;           // Encerra o programa, através da escrita da flag halt-bit.
  else if(!strcmp(instruction, "load"))     return 1;           // Carrega um dado da memória para um registrador
  else if(!strcmp(instruction, "store"))    return 2;           // Escreve o valor de um registrador em um endereço de memória
  else if(!strcmp(instruction, "read"))     return 3;           // Armazena o valor da entrada digitada no Registrador 1.
  else if(!strcmp(instruction, "write"))    return 4;           // Imprime o valor do registrado no console
  else if(!strcmp(instruction, "add"))      return 5;           // Faz a soma dos valores de dois registradores e escreve no primeiro registrador.
  else if(!strcmp(instruction, "subtract")) return 6;           // Faz a subtração dos valores de dois registradores e escreve no primeiro registrador
  else if(!strcmp(instruction, "multiply")) return 7;           // Faz a multiplicação dos valores de dois registradores e escreve no primeiro registrador.
  else if(!strcmp(instruction, "divide"))   return 8;           // Faz a divisão dos valores de dois registradores e escreve no primeiro registrador
  else if(!strcmp(instruction, "jump"))     return 9;           // Pula para a instrução contida no endereço de memória especificado.
  else if(!strcmp(instruction, "jmpz"))     return 10;          // Pula para a instrução contida no endereço de memória especificado, caso o valor contido no registrador seja igual a zero.
  else if(!strcmp(instruction, "jmpn"))     return 11;          // Pula para a instrução contida no endereço de memória especificado, caso o valor contido no registrador seja menor que zero.
  else if(!strcmp(instruction, "move"))     return 12;          // Move o valor de um registrador para o outro
  else if(!strcmp(instruction, "push"))     return 13;          // Insere um valor contido em um registrador na pilha.
  else if(!strcmp(instruction, "pop"))      return 14;          // Remove o topo da pilha e o coloca em um registrador.
  else if(!strcmp(instruction, "call"))     return 15;          // Chama o procedimento que está contido no endereço de memória especificado. Empilha o endereço da próxima instrução a ser chamada (pc, antes do redirecionamento) para ser usado pelo return posteriormente.
  else if(!strcmp(instruction, "return"))   return 32768;       // Encerra um procedimento e retorna para endereço especificado pelo valor no topo da pilha. ATENÇÃO: uma função chamada que insere elementos na pilha deve obrigatoriamente removê-los antes do return.
  else if(!strcmp(instruction, "load_s"))   return 17;          // Carrega um dado na pilha diretametne.
  else if(!strcmp(instruction, "store_s"))  return 18;          // Quando uma sub-rotina vai executar e possui argumento, ela precisará salvar o argumento de um registrador na pilha. Para fazer isso, deve-se utilizar a instrução "store_s".
  else if(!strcmp(instruction, "loadc"))    return 19;          // Carrega uma constante de 9 bits (Notação Complemento 2) em um registrador. A constante é armazenada em um registrador.
  else if(!strcmp(instruction, "loadi"))    return 20;          // Carregar dados da pilha em um registrador 1 onde o endereço dos dados na pilha está no registrador 2.
  else if(!strcmp(instruction, "storei"))   return 21;          // Armazena os dados do registrador 1 na pilha, onde o endereço na pilha está no registrador 2
  else if(!strcmp(instruction, "copytop"))  return 22;          // Carrega no registrador 1 o endereço do topo da pilha (ou seja, o endereço contido no ponteiro superior, não os dados no topo da pilha).
  else return -1;                                                // !!! instrução nao existe
}

char *IntToBinOP(int n){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(5+1);
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
  *(pointer+count) = '\0';
  return  pointer;
}
