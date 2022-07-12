#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"
#include "ferramentas.c"

int main(void)
{
    // srandom(time(NULL));
    srandom(1234567890);
    /*
        * Criar uma listaA não ordenada de tamanho
        LSIZE preenchida de forma aleatória.
    */
    TListAlunos *listaA;
    PRaizArvAluno arvoreA, arvoreB, result,testeresult;
    PRaizArvAlunoAVL arvoreC;
    listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    //printf("A Lista A tem %d intens ", listaA->tam);
    //printf("de um máximos de %d\n", listaA->cap);
    //printLista(listaA->lista, listaA->tam);

    /*
        * Criar uma árvore binária alocando os nós de
        forma aleatória
    */
    
    arvoreA = criarArvoreDeLista(*listaA); // arvore bagunçada
    arvoreB = criarArvoreDeLista_(*listaA);//arvore binaria
    arvoreC = criarArvoreAVLDeLista(*listaA); // arvore AVL
    //11
    //12

    result = buscaArvSimples(arvoreA, 11);
    printf("%d", result->aluno.numMatricula);
    
    //result = buscaArvSimples(arvoreA, 200420766);
    /*  printArvore(arvoreA, 0);
    testeresult = removerRec(arvoreA, 11); 
    //printLista(listaA->lista, listaA->tam);
     printf("Separaaaaaaaaaaaaa\n"); */
    
    //printf("%d", result->aluno.numMatricula);

    //printArvore(result, 0);
    return 0;
}