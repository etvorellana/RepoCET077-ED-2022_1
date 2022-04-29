#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
  srandom(time(NULL));

  TListAlunos etapa1;
  TListAlunos etapa1b;
  TPilhaAlunos etapa2;
  TFilaAlunos etapa3;

  geraListaDeAluno(&etapa1, LSIZE, LSIZE, 0);

  iniListAlunosPar(&etapa1b,LSIZE,0);
  iniPilhaAlunos(&etapa2, LSIZE);
  iniFilaAlunos(&etapa3, LSIZE);

  ordemEtapas(&etapa1 , &etapa1b, &etapa2, &etapa3);
}
