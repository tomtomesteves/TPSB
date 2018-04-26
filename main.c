#include <stdio.h>
#include <stdlib.h>

#include "opcode.h"

int main(int argc, char const *argv[]) {
<<<<<<< HEAD
  // FILE* in,out;
  // in = fopen(,"r");
  // out = fopen(,"w");
  // fprintf(out, "%s\n", );
  printf("%s\n",IntToBinOP(opcodeDecode("jump")) );
=======
  FILE* in,out;
  in = fopen(,"r");
  out = fopen(,"w");
  fprintf(out, "%s\n", );
>>>>>>> 
  return 0;
}
