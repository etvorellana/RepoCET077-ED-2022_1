#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main()
{

    PilhaDeFilas PF;
    TFilaEncAlunos Faluno, Faluno2, Faluno3, aux;
    TAluno aluno;

    iniFilaAlunosEnc(&Faluno);
    iniFilaAlunosEnc(&Faluno2);
    iniFilaAlunosEnc(&Faluno3);
    iniPilhaDeFilas(&PF);

    printf("TESTANDO INSERCAO:\n");

    aluno.numMatricula = 201920540;
    strcpy(aluno.nome, "Alberto");
    strcpy(aluno.email, "alberto.cic@uesc.br");

    insereNaFilaEnc(aluno, &Faluno);

    aluno.numMatricula = 202019999;
    strcpy(aluno.nome, "Andressa");
    strcpy(aluno.email, "Andressa.cic@uesc.br");

    insereNaFilaEnc(aluno, &Faluno);

    inserePilhaDeFilas(&Faluno, &PF);

    aluno.numMatricula = 2020019993;
    strcpy(aluno.nome, "Lavinia");
    strcpy(aluno.email, "Lavinia.cic@uesc.br");

    insereNaFilaEnc(aluno, &Faluno2);

    inserePilhaDeFilas(&Faluno2, &PF);

    aluno.numMatricula = 2019029399;
    strcpy(aluno.nome, "Igor");
    strcpy(aluno.email, "Igor.cic@uesc.br");

    insereNaFilaEnc(aluno, &Faluno3);

    inserePilhaDeFilas(&Faluno3, &PF);

    imprimePilhaDeFilas(&PF);

    printf("\nTESTANDO REMOCAO:\n");

    removePilhaDeFilas(&aux, &PF);

    imprimePilhaDeFilas(&PF);

    printf("\nTESTANDO LIBERA PILHA:\n");

    liberaPilhaDeFilas(&PF);

    imprimePilhaDeFilas(&PF);

    return 0;
}
