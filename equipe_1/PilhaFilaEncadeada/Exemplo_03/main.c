#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main()
{
    TPilhaEncAlunos PAluno;
    TListAlunos* LAluno, *LAux;
    TAluno aux;
    int chave;

    srand(time(NULL));

    LAluno = geraListaDeAlunos(LSIZE, LSIZE, FALSE); //Lista preenchida com alunos aleatorios
    LAux = iniListAlunos(LSIZE, FALSE); //Lista auxiliar
    iniPilhaEncAlunos(&PAluno);
    chave = rand() % LAluno->tam-1; //Pegando uma posição aleatoria
    chave = LAluno->lista[chave].numMatricula; // Utilizando a posição aleatoria para pegar um numero de matricula aleatoria dentro da lista

    for(int i = 0; i < LAluno->tam; i++)
        empilharAlunoEnc(LAluno->lista[i], &PAluno); //Empilhando todos os alunos da lista

    printf("CHAVE: %d\n\n", chave);
    printf("PILHA:\n");
    imprimePilha(&PAluno); //Pilha antes de modificar

    while(PAluno.topo->numMatricula != chave){ //Verifico se o topo da minha pilha é difente da chave que to procurando
        desempilharALunoEnc(&aux, &PAluno); //Enquanto for diferente eu desempilho
        incAlunoNaLista(aux, LAux); //E guardo os valores na minha lista auxiliar
    }

    desempilharALunoEnc(&aux, &PAluno); //Quando saio do while o topo é o valor a ser descartado, então desempilho

    for(int i = LAux->tam-1; i >= 0; i--){
       empilharAlunoEnc(LAux->lista[i], &PAluno); //E vou empilhando de tras pra frente os valores da minha lista
    }

    printf("PILHA APOS REMOVER A CHAVE:\n");
    imprimePilha(&PAluno);

    return 0;
}
