#ifndef DIFINSTRUC_H
#define DIFINSTRUC_H

//retorna a decodificacao dos oprerandos da instrucao
// recebe apenas os capos dos oprandos sem o primeiro espaco
char* DifInstruction(int flag, char* operandos,TipoLista *lista,char* label);

char *IntToBin(int n,int tamanho);


#endif
