#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
  srandom(time(NULL));

  TListAlunos alunosBiblio;
  TFilaAlunos alunosFila;

  iniListAlunosPar(&alunosBiblio,LSIZE,0);
  iniFilaAlunos(&alunosFila, LSIZE);

  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  /*insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);*/
  
  printf("\nLista dos Alunos na Biblioteca: \n");
  printLista(alunosBiblio.lista,alunosBiblio.tam);
  printf("\nLista dos Alunos na Fila de espera: \n");
  printFila(alunosFila);
  
  retirarAlunoBiblio(alunosBiblio.lista, &alunosBiblio, &alunosFila);

  printf("\nLista dos Alunos na Biblioteca: \n");
  printLista(alunosBiblio.lista,alunosBiblio.tam);
  printf("\nLista dos Alunos na Fila de espera: \n");
  printFila(alunosFila);
  
  retirarAlunoBiblio(&alunosBiblio.lista[rand()%alunosBiblio.tam], &alunosBiblio, &alunosFila);

  printf("\nLista dos Alunos na Biblioteca: \n");
  printLista(alunosBiblio.lista,alunosBiblio.tam);
  printf("\nLista dos Alunos na Fila de espera: \n");
  printFila(alunosFila);

  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  insereAlunoBiblio(&alunosBiblio, &alunosFila);

  printf("\nLista dos Alunos na Fila de espera: \n");
  printFila(alunosFila);

  insereAlunoBiblio(&alunosBiblio, &alunosFila);
  
}