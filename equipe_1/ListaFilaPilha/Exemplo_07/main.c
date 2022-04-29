#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    TAluno aux;
    TListAlunos *alunos, *alunosNord, *alunosNord2;
    TPilhaAlunos pilhaAlunos;
    TFilaAlunos filaAlunos;

    alunos = geraListaDeAlunos(LSIZE, LSIZE, TRUE);
    iniPilhaAlunos(&pilhaAlunos, LSIZE);
    alunosNord = iniListAlunos(LSIZE, FALSE);
    iniFilaAlunos(&filaAlunos, LSIZE);
    alunosNord2 = iniListAlunos(LSIZE, FALSE);


    printf("LISTA:\n");
    printLista(alunos->lista, alunos->tam);

    for(int i = 0; i < LSIZE; i++){
        empilharAluno(alunos->lista[i], &pilhaAlunos);
    }

    printf("PILHA:\n");
    printLista(pilhaAlunos.pilha, pilhaAlunos.topo);

    while(pilhaAlunos.topo > 0){
        desempilharALuno(&aux, &pilhaAlunos);
        incAlunoNaLista(aux, alunosNord);
    }

    printf("LISTA N ORD:\n");
    printLista(alunosNord->lista, alunosNord->tam); //Estão ordenados de forma decrescente

    for(int i = LSIZE-1; i >= 0; i--){
        insereNaFila(alunosNord->lista[i], &filaAlunos);
    }
    printf("FILA COM ELEMENTOS DA LISTA N ORD:\n");
    printFila(&filaAlunos);

    while(filaAlunos.tam > 0){
        removeDaFila(&aux, &filaAlunos);
        incAlunoNaLista(aux, alunosNord2);
    }

    printf("LISTA N ORD COM ELEMENTOS DA FILA\n");
    printLista(alunosNord2->lista, alunosNord2->tam); //Estão ordenados

    return 0;
}
