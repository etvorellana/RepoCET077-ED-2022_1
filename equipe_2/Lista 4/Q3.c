#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"


int main(void) {
  int i, ale, chave;
  TPilhaAlunoEnc pilha, pilhaAux;
  TListAlunos *lista;
  TAluno aux;

  srand(time(NULL));
  
  lista = geraListaDeAlunos(LSIZE, LSIZE, 0);
  
  iniPilhaEncAlunos(&pilha);
  for(i=0;i<lista->tam;i++){
    empilharAlunoEnc(lista->lista[i],&pilha);
  }
  printf("Pilha inicial: \n");
  imprimePilha(&pilha);
  
  ale = rand()%LSIZE;
  chave = lista->lista[ale].numMatricula;
  printf("Chave deletada: %d\n\n", chave);

  iniPilhaEncAlunos(&pilhaAux);
  do{
    desempilharAlunoEnc(&aux, &pilha);
    if(aux.numMatricula!=chave)
      empilharAlunoEnc(aux, &pilhaAux);
  }while(aux.numMatricula!=chave);

  while(desempilharAlunoEnc(&aux, &pilhaAux)){
    empilharAlunoEnc(aux, &pilha);
  }

  printf("Pilha final: \n");
  imprimePilha(&pilha);
  
  
}
