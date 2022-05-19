#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main()
{
    TFilaEncAlunos FAluno;
    TListAlunos * LAluno, *LAux;
    TAluno aux;
    int chave;

    srand(time(NULL));

    LAluno = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
    LAux = iniListAlunos(LSIZE, FALSE);
    iniFilaAlunosEnc(&FAluno);
    chave = rand() % LAluno->tam-1;
    chave = LAluno->lista[chave].numMatricula;

    for(int i = 0; i < LAluno->tam; i++)
        insereNaFilaEnc(LAluno->lista[i], &FAluno);

    printf("CHAVE: %d\n\n", chave);
    printf("FILA:\n");
    imprimeFila(&FAluno);

    while(FAluno.head->numMatricula != chave){
        removeDaFilaEnc(&aux, &FAluno);
        incAlunoNaLista(aux, LAux);
    }

    removeDaFilaEnc(&aux, &FAluno);

    while(FAluno.head != FAluno.tail->prox){
        removeDaFilaEnc(&aux, &FAluno);
        incAlunoNaLista(aux, LAux);
    }

    for(int i = 0; i < LAux->tam; i++)
        insereNaFilaEnc(LAux->lista[i], &FAluno);

    printf("FILA APOS REMOVER A CHAVE:\n");
    imprimeFila(&FAluno);

    return 0;
}
