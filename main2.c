#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "label.h"
#include "DifInstruc.h"
#include "regDecode.h"
#include "opcode.h"

int main(int argc, char const *argv[]) {

  TipoLista *lista;
  inicializa_lista(lista);
  printf("OIE\n" );

  FILE *in,*out;
  in = fopen("entrada.a","r");
  out = fopen("saida.mif","w");

  int PC=0,constante,*opcode,flag;
  char *aux,*data,*label,*buf,*op;
  buf=(char*)malloc(100*sizeof(int));
  //aux=(char *)malloc(50*sizeof(char));

//PRIMEIRA PASSADA = PEGAR LABELS

  while(fscanf(in,"%s",buf) != EOF){

    if(strncmp(buf,"_",1)){                     //caso leia uma label
      aux = buf + 1;                     //desconsidera o primeiro caracter
      label = strtok(aux,":");           //salva a label correspondente
      data = strtok(NULL," ");
      if(!strcmp(data,".data")){         //caso seja uma linha de dados
        data = strtok(NULL," ");
        data = strtok(NULL," \n;");
        constante = atoi(data);
        insere_lista(lista,constante,label);
      }
      else
        insere_lista(lista,PC,label);      //insere a label e seu endereço correspondente na lista de labels
      PC+=2;                             //incrementa o PC
    }
  }
//SEGUNDA PASSADA = TRADUZIR PROGRAMA
  PC=0;                                   //reseta PC
  rewind(in);                             //reseta ponteiro do arquivo

  while(fscanf(in,"%s",buf) != EOF){
    if(strncmp(buf,";",1)){                     //caso NÃO leia um comentário
      if(!strncmp(buf,"_",1)){                    //caso leia uma label, desconsidera o underscore
        aux = buf;
        data = strtok(aux," ");            //desconsidera a label
      }
      data = strtok(aux," ");            //pega a palavra seguinte à label
      if(strcmp(data,".data")){          //CASO SEJA INSTRUÇÃO
        flag = opcodeDecode(data,opcode);//salva a flag da instrução em "flag" e armazena o opcode em "opcode"
        op = IntToBinOP(opcode);          //converte o opCode para binário
        data = strtok(NULL,";\n");       //salva em data todo o resto da linha, reg + reg ou reg + end
        label = DifInstruction(flag,data,lista); //passa a flag e uma string contendo os 2 regs ou 1 reg + label
        strcat(op,label);                //concatena o opcode com o restante da instrução
        fprintf(out,"%x: ",PC);
        strncpy(label,op,8);
        fprintf(out,"%s\n",label);
        label = op + 8;
        fprintf(out,"%x: ",PC++);
        fprintf(out,"%s\n",label);
        PC++;
      }
    }
  }
return 0;
}
