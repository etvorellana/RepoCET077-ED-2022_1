#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"
 
int main(void)
{
    
    srandom(1234567890);

    TListAlunos *listaA;
    listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    printf("A Lista A tem %d intens ", listaA->tam);
    printf("de um máximos de %d\n", listaA->cap);
    printLista(listaA->lista, listaA->tam);

    PNoAluno listaE;
    listaE = criarListEncDeListSeq(listaA);
    printLisEncAluno(listaE);

    return 0;
}