#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  /* Criar uma listaA não ordenada de tamanho 2*LSIZE
     preenchida de forma aleatória. */
  TListAlunos *listA = geraListAlunos(2 * LSIZE, 2 * LSIZE, FALSE);
  puts("> Lista A:");
  printLista(listA);
	
/* TESTE FUNCOES DE REMOCAO
	TAluno aluno;
	scanf("%d", &aluno.numMatricula);
	remAlunoDaLista(aluno, listA);
	printLista(listA);
	printf("Tamanho de A: %d\n", listA->tam);
*/
	
  /* Declarar uma listaB não ordenada de capacidade LSIZE */
  TListAlunos *listB = iniListAlunos(LSIZE, FALSE);
  /*
    Selecione em ordem aleatória todos os itens da
    listaA e inclua na listaB. Conte quantas vezes a
    função de inclusão retorna verdadeiro e quantas
    retorna falso. No final mostre os valores
    contabilizados junto com o tamanho da listaB
  */
  srand(time(NULL));
  int f = 0, i = 0;
  do {
    int n = rand() % (listA->tam);
    //printf("\nValor do sorteio: %d", n);
    if (incAlunoNaLista(listA->lista[n], listB) == TRUE) { // true
      i++;
    }
    else {
      f++;
    }
  } while (i < listB->cap);

  puts("\n> Lista B:");
  printLista(listB);
  printf("TRUE: %d\tFALSE: %d\n", i, f);

  /* Declarar uma listaC ordenada de capacidade LSIZE */
  TListAlunos *listC = iniListAlunos(LSIZE, TRUE);
  /*
    Selecione em ordem aleatória todos os itens da
    listaA e inclua na listaC. Conte quantas vezes a
    função de inclusão retorna verdadeiro e quantas
    retorna falso. No final mostre os valores
    contabilizados junto com o tamanho da listaC
  */
	f = i = 0;
  do {
    int n = rand() % (listA->tam);
    if (incAlunoNaLista(listA->lista[n], listC) == TRUE) { // true
      i++;
    } 
  } while (i < listC->cap);

  puts("\n> Lista C:");
  printLista(listC);
	printf("TRUE: %d\tFALSE: %d\n", i, f);

  int cap = listB->cap + listC->cap;
  TListAlunos *listUniao = iniListAlunos(cap, FALSE);
  /*
    Crie a lista união da listaB com a ListaC.
    Mostre o tamanho desta lista.
  */
  uniaoListas(listB, listC, listUniao);
  printf("\n> Lista Uniao B e C:\n");
  printLista(listUniao);
  printf("Tamanho da Uniao: %d\n", listUniao->tam);

  /*
    Crie a lista diferença da listaB com a ListaC.
    Mostre o tamanho desta lista.
  */
  TListAlunos *listDiferBC = iniListAlunos(LSIZE, FALSE);
  diferenListas(listB, listC, listDiferBC);
  printf("\n> Lista Diferenca B e C:\n");
  printLista(listDiferBC);
  printf("Tamanho da Diferenca: %d\n", listDiferBC->tam);

  /*
    Crie a lista diferença da listaC com a ListaB.
    Mostre o tamanho desta lista
  */
  TListAlunos *listDiferCB = iniListAlunos(LSIZE, FALSE);
  // No pior caso a diferenca sera a propria lista C

  diferenListas(listC, listB, listDiferCB);
  printf("\n> Lista Diferenca C e B:\n");
  printLista(listDiferCB);
  printf("Tamanho da Diferenca: %d\n", listDiferCB->tam);

  /*
    Crie a lista intersecção da listaB com a ListaC.
    Mostre o tamanho desta lista.
  */
  cap = (listB->cap > listC->cap) ? listC->cap : listB->cap;
  /* No pior caso a intersecao sera a menor lista, ou seja a 
	capacidade da resultante sera igual a capacidade da menor lista */

  TListAlunos *listInterBC = iniListAlunos(cap, FALSE);
  interListas(listB, listC, listInterBC);
  printf("\n> Lista Interseccao B e C:\n");
  printLista(listInterBC);
  printf("Tamanho da Interseccao: %d\n", listInterBC->tam);

  /*
    Verifique se os tamanhos reportados são
    consistentes.
  */

  /*
     Transforma a listaA numa lista ordenada.
  */
  ordenaLista(listA);
  printf("\n> Lista A ordenada:\n");
  printLista(listA);

  free(listA);
  free(listB);
  free(listC);
  free(listInterBC);
  free(listUniao);
  free(listDiferBC);
  free(listDiferCB);
  return 0;
}