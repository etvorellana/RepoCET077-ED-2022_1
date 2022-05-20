#include <stdio.h>
#include <stdlib.h>
#include "ferramentas.h"

int main(void)
{
	TListAlunos *lista = NULL;
  lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
  TPilhaEncAlunos *pilha1 = iniPilhaEncDeFilas();
  TPilhaEncAlunos *pilha2 = iniPilhaEncDeFilas();
  TPilhaEncAlunos *pilha3 = iniPilhaEncDeFilas();

  for (int i = 0; i < 10; i++) {
    empilharAlunoEnc(lista->lista[i], pilha1);
    empilharAlunoEnc(lista->lista[10+i], pilha2);
    empilharAlunoEnc(lista->lista[20+i], pilha3);
  }

  TFilaEncDePilhas* fila = iniFilaAlunosEnc();
  insereNaFilaEnc(pilha1, fila, 'A');
  insereNaFilaEnc(pilha2, fila, 'B');
  insereNaFilaEnc(pilha3, fila, 'C');

  imprimeFila(fila);
  printf("\n> Removendo 1 elemento da Fila\n\n");
  TPilhaEncAlunos *pilha = iniPilhaEncDeFilas();
  removeDaFilaEnc(pilha,fila);
  imprimeFila(fila);

	liberaFila(fila);
	return 0;
}