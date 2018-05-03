#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "opcode.h"

int main(int argc, char const *argv[]) {

  TipoLista *lista;
  inicializa_lista(lista);

  FILE *in,*out;
  in = fopen("entrada.a","r");
  out = fopen("saida.mif","w");

  int PC=0,constante,*opcode,flag;
  char *aux,*data,*label,*buf,*op;
  buf=(char*)malloc(100*sizeof(int));
  //aux=(char *)malloc(50*sizeof(char));

  fscanf(in,"%s",buf);

//PRIMEIRA PASSADA = PEGAR LABELS

  while(buf != EOF){

    if(buf[0]=='_'){                     //caso leia uma label
      aux = buf + 1;                     //desconsidera o primeiro caracter
      label = strtok(aux,':');           //salva a label correspondente
      data = strtok(NULL,' ');
      if(!strcmp(data,".data")){
        data = strtok(NULL,' ');
        data = strtok(NULL," \n;");
        constante = atoi(data);
        insere_lista(lista,label,constante);
      }
      else
        insere_lista(lista,label,PC);      //insere a label e seu endereço correspondente na lista de labels

      PC+=4;                             //incrementa o PC
    }
    fscanf(in,"%s",buf);                 //caso leia uma instrução normal
  }

//SEGUNDA PASSADA = TRADUZIR PROGRAMA
  PC=0;                                   //reseta PC
  rewind(in);                             //reseta ponteiro do arquivo

  fscanf(in,"%s",buf);                    //lê primeira linha

  while(buf != EOF){
    if(buf[0]==';')                      //enquanto ler comentários, continua
      fscanf(in,"%s",buf);

    else if(buf[0]=='_'){                //caso leia uma label
      aux = buf + 1;                     //desconsidera o primeiro caracter
      data = strtok(aux,' ');
      data = strtok(NULL,' ');
      if(strcmp(data,".data")){
        flag = opcodeDecode(data,opcode);
        op = InToBinOP(opcode);
        if(flag != 0 || flag != 1)      //caso segundo elemento seja um registrador
        data = strtok(NULL,';\n');
        label = DifInstruction(flag,data,lista); //passa a flag e uma string contendo os 2 regs ou 1 reg + label
        strcat(op,label);
        fprintf(out,"%x: ",PC);
        strncpy(label,op,8);
        fprintf(out,"%s\n",label);
        label = op + 8;
        fprintf(out,"%x",PC+=2);
        fprintf(out,"%s\n",label);
        PC+=2
      }
                                   //incrementa o PC
      fscanf(in,"%s",buf);               //lê proxima linha
    }

  }




  printf("%s\n",InToBinOP(opcodeDecode("jump")) );
return 0;
}
