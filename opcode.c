#include <stdio.h>
#include <string.h>

#include "opcode.h"



int opcodeDecode(char* instruction){
    if(!strcomp(instruction,"stop"))                    // Encerra o programa, através da escrita da flag halt-bit.
    else if(!strcomp(instruction,"load"))               // Carrega um dado da memória para um registrador
    else if(!strcomp(instruction,"store"))              // Escreve o valor de um registrador em um endereço de memória
    else if(!strcomp(instruction,"read"))               // Armazena o valor da entrada digitada no Registrador 1.
    else if(!strcomp(instruction,"write"))              // Imprime o valor do registrado no console
    else if(!strcomp(instruction,"add"))                // Faz a soma dos valores de dois registradores e escreve no primeiro registrador.
    else if(!strcomp(instruction,"subtract"))           // Faz a subtração dos valores de dois registradores e escreve no primeiro registrador
    else if(!strcomp(instruction,"multiply"))           // Faz a multiplicação dos valores de dois registradores e escreve no primeiro registrador.
    else if(!strcomp(instruction,"divide"))             // Faz a divisão dos valores de dois registradores e escreve no primeiro registrador
    else if(!strcomp(instruction,"jump"))               // Pula para a instrução contida no endereço de memória especificado.
    else if(!strcomp(instruction,"jmpz"))               // Pula para a instrução contida no endereço de memória especificado, caso o valor contido no registrador seja igual a zero.
    else if(!strcomp(instruction,"jmpn"))               // Pula para a instrução contida no endereço de memória especificado, caso o valor contido no registrador seja menor que zero.
    else if(!strcomp(instruction,"move"))               // Move o valor de um registrador para o outro
    else if(!strcomp(instruction,"push"))               // Insere um valor contido em um registrador na pilha.
    else if(!strcomp(instruction,"pop"))                // Remove o topo da pilha e o coloca em um registrador.
    else if(!strcomp(instruction,"call"))               // Chama o procedimento que está contido no endereço de memória especificado. Empilha o endereço da próxima instrução a ser chamada (pc, antes do redirecionamento) para ser usado pelo return posteriormente.
    else if(!strcomp(instruction,"return"))             // Encerra um procedimento e retorna para endereço especificado pelo valor no topo da pilha. ATENÇÃO: uma função chamada que insere elementos na pilha deve obrigatoriamente removê-los antes do return.
    else if(!strcomp(instruction,"load_s"))             // Carrega um dado na pilha diretametne.
    else if(!strcomp(instruction,"store_s"))            // Quando uma sub-rotina vai executar e possui argumento, ela precisará salvar o argumento de um registrador na pilha. Para fazer isso, deve-se utilizar a instrução "store_s".
    else if(!strcomp(instruction,"loadc"))              // Carrega uma constante de 9 bits (Notação Complemento 2) em um registrador. A constante é armazenada em um registrador.
    else if(!strcomp(instruction,"loadi"))              // Carregar dados da pilha em um registrador 1 onde o endereço dos dados na pilha está no registrador 2.
    else if(!strcomp(instruction,"storei"))             // Armazena os dados do registrador 1 na pilha, onde o endereço na pilha está no registrador 2
    else if(!strcomp(instruction,"copytop"))            // Carrega no registrador 1 o endereço do topo da pilha (ou seja, o endereço contido no ponteiro superior, não os dados no topo da pilha).
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
