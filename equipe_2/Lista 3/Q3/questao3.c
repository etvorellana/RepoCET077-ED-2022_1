#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"


void sepAlunos(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet);

int main(void) {
  TListAlunos lista;
  TPilhaAlunos calouros;
  TFilaAlunos veteranos;
  TAluno aux;

  srand(time(NULL));
  lista = *geraListaDeAlunos(LSIZE, LSIZE,0);
  iniPilhaAlunos(&calouros, lista.tam);
  iniFilaAlunos(&veteranos, lista.tam);

  printLista(lista.lista, lista.tam);
  sepAlunos(&lista, &calouros, &veteranos);

  while(removeDaFila(&aux,&veteranos)){
    incAlunoNaLista(aux, &lista);
  }
  while(desempilharALuno(&aux,&calouros)){
    incAlunoNaLista(aux, &lista);
  }
  printLista(lista.lista, lista.tam);
  
  
  return 0;
}

void sepAlunos(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet){
  int i;
  for(i=0;i<lista->tam;i++){
    if(lista->lista[i].numMatricula >= 202210000)
      empilharAluno(lista->lista[i], fresh);
    else
      insereNaFila(lista->lista[i], vet);
  }
  lista->tam=0;
  
}
