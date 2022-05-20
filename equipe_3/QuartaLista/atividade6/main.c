#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  TListAlunos *lista = NULL;
  lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
  TFilaEncAlunos *fila1 = iniFilaAlunosEnc();
  TFilaEncAlunos *fila2 = iniFilaAlunosEnc();
  TFilaEncAlunos *fila3 = iniFilaAlunosEnc();

  for (int i = 0; i < 10; i++)
  {
    insereNaFilaEnc(lista->lista[i], fila1);
    insereNaFilaEnc(lista->lista[10 + i], fila2);
    insereNaFilaEnc(lista->lista[20 + i], fila3);
  }

  TPilhaEncDeFilas *pilha = iniPilhaEncDeFilas();
  empilharFilaEnc(fila1, pilha, 'F');
  empilharFilaEnc(fila2, pilha, 'G');
  empilharFilaEnc(fila3, pilha, 'H');

  imprimePilha(pilha);
  TFilaEncAlunos *fila = iniFilaAlunosEnc();
  desempilharFilaEnc(fila, pilha);
  imprimePilha(pilha);
  desempilharFilaEnc(fila, pilha);
  imprimePilha(pilha);

  liberaPilha(pilha);
  liberaLista(lista);
  return 0;
}