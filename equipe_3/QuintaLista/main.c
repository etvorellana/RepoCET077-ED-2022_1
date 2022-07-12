#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    // srandom(time(NULL));
    srandom(1234567890);
    /*
        * Criar uma listaA não ordenada de tamanho
        LSIZE preenchida de forma aleatória.
    */
    TListAlunos *listaA,*listaB;
    listaB=iniListAlunos(10,FALSE);
    listaB->lista[0].numMatricula=63;
    listaB->lista[1].numMatricula=7;
    listaB->lista[2].numMatricula=2;
    listaB->lista[3].numMatricula=59;
    listaB->lista[4].numMatricula=52;
    listaB->lista[5].numMatricula=60;
    listaB->lista[6].numMatricula=69;
    listaB->lista[7].numMatricula=65;
    listaB->lista[8].numMatricula=90;
    listaB->lista[9].numMatricula=83;
    listaB->tam=10;
  
    printLista(listaB->lista, listaB->tam);

    //linha 605 print de arvore
    //813 int RemoverNoArvBinaria(PRaizArvAluno raiz, int matricula)
    PRaizArvAluno arvoreA, arvoreB; // raiz da árvore vazia
    //arvoreA = criarArvoreDeLista(*listaA);
    //arvoreA = criarArvoreDeLista_C(*listaA);
    arvoreB = criarArvoreDeLista_(*listaB);
    printArvore(arvoreB, 0);
    
    int a=RemoverNoArvDeBusca(arvoreB, 65);
  
    printArvore(arvoreB, 0);
  /*
    //listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    printf("A Lista A tem %d intens ", listaA->tam);
    printf("de um máximos de %d\n", listaA->cap);
    //printLista(listaA->lista, listaA->tam);

    PRaizArvAluno arvoreA; // raiz da árvore vazia
    //arvoreA = criarArvoreDeLista(*listaA);
    //arvoreA = criarArvoreDeLista_C(*listaA);
    arvoreA = criarArvoreDeLista_(*listaA);
    printArvore(arvoreA, 1);
		//RemoverNoArvDeBusca(arvoreA, 201520186);
		RemoverNoArvDeBusca(arvoreA, 200710753);
		printf("\n\n");
		printArvore(arvoreA, 1);*/
    return 0;
}