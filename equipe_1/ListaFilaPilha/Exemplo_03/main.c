// A função geraAlunos foi modificada para gerar alunos entre 2020 e 2021.1 para facilitar a visualização do exercicio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

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

    colocaPilhaFila(alunos, &palunos, &falunos);

    printf("\n\nLista Organizada:\n");
    printf("LISTA\n");
    printLista(alunos->lista, alunos->tam);
    /*printf("PILHA\n");
    printLista(palunos.pilha, palunos.topo);
    printf("FILA\n");
    printFila(&falunos);*/

    return 0;
}
