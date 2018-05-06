#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "label.h"
#include "DifInstruc.h"
#include "regDecode.h"
#include "opcode.h"

int main(int argc, char const *argv[]) {

  TipoLista lista;
  inicializa_lista(&lista);

  FILE *in,*out;
  in = fopen("entrada.a","r");
  out = fopen("saida.mif","w");

  int PC=0,constante,opcode,flag;
  char *aux,*data,*label,*buf,*op;
  buf=(char*)malloc(100*sizeof(int));
  //aux=(char *)malloc(50*sizeof(char));

//PRIMEIRA PASSADA = PEGAR LABELS
  while(fscanf(in,"%[^\n]",buf) != EOF){
    printf("%s\n",buf );

    if(strncmp(buf,"_",1)==0){                     //caso leia uma label
      aux = buf + 1;                     //desconsidera o primeiro caracter
      printf("sem label = %s\n",aux);

      label = strtok(aux,":");           //salva a label correspondente
      data = strtok(NULL," ");
      if(strcmp(data,".data")==0){         //caso seja uma linha de dados
        data = strtok(NULL," ");
        data = strtok(NULL," \n;");
        constante = atoi(data);
        insere_lista(&lista,constante,label);
      }
      else
        insere_lista(&lista,PC,label);      //insere a label e seu endereço correspondente na lista de labels
      PC+=2;                             //incrementa o PC
    }
    getc(in);
  }
  printf("\n\nIMPRIMINDO A LISTA\n\n");
  imprime_lista(&lista);
//SEGUNDA PASSADA = TRADUZIR PROGRAMA
  PC=0;                                   //reseta PC
  rewind(in);                             //reseta ponteiro do arquivo
  printf("oi\n");
  while(fscanf(in,"%[^\n]",buf) != EOF){
    printf("%s\n",buf);
    if(strncmp(buf,";",1)!=0){                     //caso NÃO leia um comentário
      if(strncmp(buf,"_",1)==0){                    //caso leia uma label, desconsidera o underscore
        data = strtok(buf," ");            //desconsidera a label
      }
      printf("novamente =%s\n",buf);
      data = strtok(buf," ");            //pega a palavra seguinte à label
      if(strcmp(data,".data")!=0){          //CASO SEJA INSTRUÇÃO
        flag = opcodeDecode(data,&opcode);//salva a flag da instrução em "flag" e armazena o opcode em "opcode"
        printf("flag=%d\nopcode=%d\n",flag,opcode);
        op = IntToBinOP(&opcode);          //converte o opCode para binário
        data = strtok(NULL,";\n");       //salva em data todo o resto da linha, reg + reg ou reg + end
        label = DifInstruction(flag,data,&lista); //passa a flag e uma string contendo os 2 regs ou 1 reg + label
        printf("label=%s\n",label);
        strcat(op,label);                //concatena o opcode com o restante da instrução
        printf("tudo=%s\n",op);
        printf("pc=%x: ",PC);
        strncpy(label,op,8);
        printf("label=%s\n",label);
        label = op + 8;
        fprintf(out,"%x: ",PC++);
        fprintf(out,"%s\n",label);
        PC++;
      }
    }
    getc(in);
  }
return 0;
}
