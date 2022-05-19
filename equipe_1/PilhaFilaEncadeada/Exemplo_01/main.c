#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int main()
{
    TPilhaEncAlunos Paluno;
    TAluno aluno;

    iniPilhaEncAlunos(&Paluno);

    aluno.numMatricula = 1414;
    strcpy(aluno.nome, "alberto");
    strcpy(aluno.email, "alberto@uesc");

    empilharAlunoEnc(aluno, &Paluno);

    aluno.numMatricula = 1415;
    strcpy(aluno.nome, "alberto");
    strcpy(aluno.email, "alberto@uesc");

    empilharAlunoEnc(aluno, &Paluno);

    imprimePilha(&Paluno);

    desempilharALunoEnc(&aluno, &Paluno);

    imprimePilha(&Paluno);

    liberaPilha(&Paluno);
}
