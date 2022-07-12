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
    TListAlunos *listaA;
    listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    printf("A Lista A tem %d intens ", listaA->tam);
    printf("de um máximos de %d\n", listaA->cap);
    printLista(listaA->lista, listaA->tam);

    /*
        * Criar uma árvore binária alocando os nós de
        forma aleatória
    */
    PRaizArvAluno arvoreA; // raiz da árvore vazia
    //arvoreA = criarArvoreDeLista(*listaA);
    //arvoreA = criarArvoreDeLista_C(*listaA);
    arvoreA = criarArvoreDeLista_(*listaA);
    printArvore(arvoreA, 1);
    return 0;
}
