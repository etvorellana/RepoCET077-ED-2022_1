#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"


void sepAlunos(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet, int ano, int sem);
void sepAlunosAll(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet, int ano, int sem);

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
  sepAlunosAll(&lista, &calouros, &veteranos, UANO,2);
  printLista(lista.lista, lista.tam);
  
  return 0;
}

void sepAlunos(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet, int ano, int sem){
  int i;
  int strMat, endMat;
  int mat;
  TAluno aux;

  strMat = (ano*100000)+(sem*10000);
  endMat = strMat+10000;
  for(i=0;i<lista->tam;i++){
    mat = lista->lista[i].numMatricula;
    if(mat >= strMat && mat<endMat)
      empilharAluno(lista->lista[i], fresh);
    else
      insereNaFila(lista->lista[i], vet);
  }
  lista->tam=0;

  while(removeDaFila(&aux,vet)){
    incAlunoNaLista(aux, lista);
  }
  while(desempilharALuno(&aux,fresh)){
    incAlunoNaLista(aux, lista);
  }
  
}

void sepAlunosAll(TListAlunos *lista, TPilhaAlunos *fresh, TFilaAlunos *vet, int ano, int sem){
  int codAno = (ano*100000)+(sem*10000);
  if(codAno<=((PANO*100000)+10000)){
    sepAlunos(lista,fresh, vet, ano,sem);
  }else{
    if(sem==2){
      sepAlunosAll(lista, fresh, vet, ano, sem-1);
    }
    else{
      sepAlunosAll(lista, fresh, vet, ano-1, 2);
    }
    sepAlunos(lista,fresh, vet, ano,sem);
  }
  
}

/*void agrupaAlunos(TListAlunos *lista, TPilhaAlunos *calouros, TFilaAlunos *veteranos, int ano,int sem){
  int codAno = (ano*100000)+(sem*10000);
  if(codAno<=((PANO*100000)+10000)){
    segregAlunos(lista,calouros, veteranos, ano,sem);
    printf("%d|%d\n", ano, sem);
    printLista(lista->lista, lista->tam);
  }else{
    if(sem==2){
      agrupaAlunos(lista, calouros, veteranos, ano, sem-1);
    }
    else{
      agrupaAlunos(lista, calouros, veteranos, ano-1, 2);
    }
    segregAlunos(lista,calouros, veteranos, ano,sem);
    printf("%d|%d\n", ano, sem);
    printLista(lista->lista, lista->tam);
  }
  
}*/