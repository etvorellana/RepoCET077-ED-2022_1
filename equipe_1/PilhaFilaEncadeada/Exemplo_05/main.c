#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main()
{

    FilaDePilhas FP;
    TPilhaEncAlunos PAluno, PAluno2, PAluno3, aux;
    TAluno aluno;

    iniPilhaEncAlunos(&PAluno);
    iniPilhaEncAlunos(&PAluno2);
    iniPilhaEncAlunos(&PAluno3);
    iniFilaDePilha(&FP);

    aluno.numMatricula = 201920540;
    strcpy(aluno.nome, "Alberto");
    strcpy(aluno.email, "alberto.cic@uesc.br");

    empilharAlunoEnc(aluno, &PAluno);

    aluno.numMatricula = 202019999;
    strcpy(aluno.nome, "Andressa");
    strcpy(aluno.email, "Andressa.cic@uesc.br");

    empilharAlunoEnc(aluno, &PAluno);

    insereFilaDePilha(&PAluno, &FP);

    aluno.numMatricula = 2020019993;
    strcpy(aluno.nome, "Lavinia");
    strcpy(aluno.email, "Lavinia.cic@uesc.br");

    empilharAlunoEnc(aluno, &PAluno2);

    insereFilaDePilha(&PAluno2, &FP);

    aluno.numMatricula = 2019029399;
    strcpy(aluno.nome, "Igor");
    strcpy(aluno.email, "Igor.cic@uesc.br");

    empilharAlunoEnc(aluno, &PAluno3);

    insereFilaDePilha(&PAluno3, &FP);

    imprimeFilaPilha(&FP);

    printf("Testando a remocao!!\n");

    removeFilaDePilha(&aux, &FP);

    imprimeFilaPilha(&FP);

    printf("\n TESTANDO LIBERA FILA:\n");

    liberaFilaDePilha(&FP);

    imprimeFilaPilha(&FP);

    return 0;
}
