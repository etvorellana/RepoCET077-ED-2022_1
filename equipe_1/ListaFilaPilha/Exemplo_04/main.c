#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

#define DATA 20191

int main(void)
{
    TListAlunos *alunos;
    TPilhaAlunos palunos;
    TFilaAlunos falunos;

    iniPilhaAlunos(&palunos, LSIZE);
    iniFilaAlunos(&falunos, LSIZE);
    alunos = geraListaDeAlunos(LSIZE, LSIZE, FALSE);

    printf("LISTA\n");
    printLista(alunos->lista, alunos->tam);
    /*printf("PILHA\n");
    printLista(palunos.pilha, palunos.topo);
    printf("FILA\n");
    printFila(&falunos);*/

    colocaPilhaFila(alunos, &palunos, &falunos, DATA);

    printf("\n\nLista Organizada:\n");
    printf("LISTA\n");
    printLista(alunos->lista, alunos->tam);
    /*printf("PILHA\n");
    printLista(palunos.pilha, palunos.topo);
    printf("FILA\n");
    printFila(&falunos);*/

    return 0;
}
