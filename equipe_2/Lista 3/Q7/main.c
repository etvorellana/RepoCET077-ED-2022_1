#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
  int i=0;
  TListAlunos listaOrd, listaNOrd;
  TPilhaAlunos pilha;
  TFilaAlunos fila;
  TAluno aux;

  srandom(time(NULL));

  //a) gerando lista ordenada
  listaOrd = *geraListaDeAlunos(LSIZE,LSIZE, 1);
  printLista(listaOrd.lista, listaOrd.tam);
  iniPilhaAlunos(&pilha, listaOrd.cap);
  
  //b)
  //transfere lista em ordem crescente para pilha
  //
  //pilha vai estar em ordem crescente
  while(listaOrd.tam>0){
    aux = listaOrd.lista[0];
    remAlunoDaLista(aux, &listaOrd);
    empilharAluno(aux, &pilha);
  };
  printPilha(pilha.pilha, pilha.topo);
  

  //c)
  //transfere da pilha pra lista nao ordenada
  //
  //lista vai estar ordenada em ordem decrescente
  listaNOrd = *iniListAlunos(pilha.topo,0);
  while(pilha.topo>0){
    desempilharALuno(&aux, &pilha);
    incAlunoNaLista(aux,&listaNOrd);
  }
  printLista(listaNOrd.lista, listaNOrd.tam);

  //d)
  //remove lista nao ordenada do fim ao inicio e coloca em fila
  //
  //fila vai estar em ordem crescente
  iniFilaAlunos(&fila, listaNOrd.tam);
  i=listaNOrd.tam;
  while(listaNOrd.tam>0){
    aux = listaNOrd.lista[i-1];
    remAlunoDaLista(aux, &listaNOrd);
    insereNaFila(aux, &fila);
    i--;
  }
  printFila(fila);
  

  //e)
  //trafere da fila para  lista nao ordenada
  //
  //lista vai estar em ordem crescente
  while(fila.fim>fila.ini){
    aux = fila.fila[i%fila.cap];
    removeDaFila(&aux, &fila);
    incAlunoNaLista(aux, &listaNOrd);
  }
  printLista(listaNOrd.lista, listaNOrd.tam);
  
}
