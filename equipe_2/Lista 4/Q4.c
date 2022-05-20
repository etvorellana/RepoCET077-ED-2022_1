#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"


int main(void) {
  int i, ale, chave;
  TFilaAlunoEnc fila, filaAux;
  TListAlunos *lista;
  TAluno aux;

  srand(time(NULL));
  
  lista = geraListaDeAlunos(LSIZE, LSIZE, 0);
  
  iniFilaAlunosEnc(&fila);
  for(i=0;i<lista->tam;i++){
    insereNaFilaEnc(lista->lista[i],&fila);
  }
  printf("Fila inicial: \n");
  imprimeFila(&fila);
  
  ale = rand()%LSIZE;
  chave = lista->lista[ale].numMatricula;
  printf("Chave deletada: %d\n\n", chave);

  iniFilaAlunosEnc(&filaAux);
  while(removeDaFilaEnc(&aux, &fila)){
    if(aux.numMatricula!=chave)
      insereNaFilaEnc(aux, &filaAux);
  };
  while(removeDaFilaEnc(&aux, &filaAux)){
      insereNaFilaEnc(aux, &fila);
  };


  printf("Fila final: \n");
  imprimeFila(&fila);

}
