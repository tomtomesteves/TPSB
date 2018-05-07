#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "label.h"
#include "DifInstruc.h"
#include "regDecode.h"
#include "opcode.h"

char *binario(int n,int tamanho,int len){
  int c, d, count;
  char *pointer;
  count = 0;
  pointer = (char*)malloc(tamanho+1);
  if (pointer == NULL)
    exit(EXIT_FAILURE);
  for (c = tamanho-2 ; c >= 0 ; c--){
    d = n >> c;
    if (c > len) {
      *(pointer+count) = 0 + '0';
    }
    else {
      if (d & 1)
      *(pointer+count) = 1 + '0';
      else
      *(pointer+count) = 0 + '0';
    }
    count++;
  }
  return pointer;
}


int main(int argc, char const *argv[]) {

  TipoLista lista;
  inicializa_lista(&lista);

  FILE *in,*out;
  in = fopen("entrada.a","r");
  out = fopen("saida.mif","w");

  int PC=0,constante,opcode,flag,i,j;
  char *aux,*data,*label,*buf,*op;
  buf=(char*)malloc(100*sizeof(int));
  //aux=(char *)malloc(50*sizeof(char));

//PRIMEIRA PASSADA = PEGAR LABELS
  while(fscanf(in,"%[^\n]",buf) != EOF){
    while (buf[i] == ' ') {
      i++;
    }

    if(strncmp(buf,"_",1)==0){                     //caso leia uma label
      aux = buf + 1;                     //desconsidera o primeiro caracter
      label = strtok(aux,":");           //salva a label correspondente
      data = strtok(NULL," ");
      if(strcmp(data,".data")==0){         //caso seja uma linha de dados
        data = strtok(NULL," ");
        constante = atoi(data);
        data = strtok(NULL," \n;");
        insere_lista(&lista,PC,label);
        PC+= constante;
      }
      else{
        insere_lista(&lista,PC,label);      //insere a label e seu endereço correspondente na lista de labels
        PC+=2;                             //incrementa o PC
      }
    }
    else PC+=2;
    getc(in);
  }
//SEGUNDA PASSADA = TRADUZIR PROGRAMA
  PC=0;                                   //reseta PC
  rewind(in);                             //reseta ponteiro do arquivo
  fprintf(out,"DEPTH = 128;\nWIDTH = 8;\nADDRESS_RADIX = HEX;\nDATA_RADIX = BIN;\nCONTENT\nBEGIN\n\n");

  while(fscanf(in,"%[^\n]",buf) != EOF){
    if(strncmp(buf,";",1)!=0){
      if(strncmp(buf,"_",1)==0){
        data = strtok(buf,":");            //desconsidera a label
        data = strtok(NULL," ");
      }
      else {
        data = strtok(buf," ");            //desconsidera a label

      }
      //data = strtok(buf," ");            //pega a palavra seguinte à label
      if(strcmp(data,".data")!=0){          //CASO SEJA INSTRUÇÃO
        flag = opcodeDecode(data,&opcode);//salva a flag da instrução em "flag" e armazena o opcode em "opcode"
        op = IntToBinOP(&opcode);          //converte o opCode para binário
        data = strtok(NULL,";\n");       //salva em data todo o resto da linha, reg + reg ou reg + end
        DifInstruction(flag,data,&lista,label); //passa a flag e uma string contendo os 2 regs ou 1 reg + label
        if(label != NULL)strcat(op,label);                //concatena o opcode com o restante da instrução
        char* imprimir;
        char* imprimir2;
        imprimir = malloc(9*sizeof(char));
        imprimir2 = malloc(9*sizeof(char));
          for(i = 0; i<8;i++){
            imprimir[i] = op[i];
          }
          fprintf(out,"%02X: ",PC++);
          fprintf(out,"%s ;\n",imprimir);
          j = 0;
          for(i = 8; i<16;i++){
            imprimir2[j] = op[i];
            j++;
          }
          fprintf(out,"%02X: ",PC++);
          fprintf(out,"%s ;\n",imprimir2);
      }
      else{

        int Daniel;
        int Carlos;
        char* bytes;
        char* numero;
        char* bin;
        bytes = strtok(NULL," ");
        numero = strtok(NULL," \n;");
        Daniel = atoi(bytes);
        bin = malloc(Daniel*8*sizeof(char));
        Carlos = atoi(numero);
        bin = binario(Carlos,(Daniel*8)+1,strlen(numero));
        char* imprimir3;
        imprimir3 = malloc(9*sizeof(char));
        while (Daniel) {
          snprintf(imprimir3,9,"%s",bin);
          fprintf(out,"%02X: ",PC++);
          fprintf(out,"%s ;\n",imprimir3);
          bin +=8;
          Daniel--;
        }
      }
    }
    getc(in);
  }
  fprintf(out,"[%02X..7F]: 00000000 ;\nEND;",PC++);

return 0;
}
