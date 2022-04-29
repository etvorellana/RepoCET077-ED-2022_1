#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
  srandom(time(NULL));

  TListAlunos noAlunos;
  TPilhaAlunos calouros;
  TFilaAlunos veteranos;

  geraListaDeAluno(&noAlunos, LSIZE, LSIZE, 0);
  iniPilhaAlunos(&calouros, LSIZE);
  iniFilaAlunos(&veteranos, LSIZE);
  
  segregAlunos(&noAlunos, &calouros, &veteranos);

}
