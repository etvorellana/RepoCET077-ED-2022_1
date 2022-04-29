#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    //srandom(time(NULL));
    srandom(1234567890);
    /*
        * Criar uma listaA não ordenada de tamanho
          LSIZE preenchida de forma aleatória.
    */

   srand(time(NULL));

    int numAleatorio = rand()%LSIZE;

    printf("%d\n", numAleatorio);

    TListAlunos *listaA;

    TPilhaAlunos pilhaA;

    iniPilhaAlunos(&pilhaA, LSIZE);

    listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    printf("A Lista A tem %d itens ", listaA->tam);
    printf("de um máximo de %d\n", listaA->cap);
    printLista(listaA->lista, listaA->tam);

    empilharListaAlunos(listaA->lista, &pilhaA, listaA->tam);

    printf("\n\nA Pilha A tem %d itens: \n", pilhaA.topo);
    printf("com uma capacidade de %d\n", pilhaA.cap);
    printPilha(pilhaA.pilha, pilhaA.topo);

    desempilharALunoNovaPilha(pilhaA.pilha[numAleatorio].numMatricula, &pilhaA);

    printf("\n\n");
    printf("Pilha A atualizado com o aluno de indice %d removido: \n", numAleatorio);
    printPilha(pilhaA.pilha, pilhaA.topo);

   

    return 0;
}

