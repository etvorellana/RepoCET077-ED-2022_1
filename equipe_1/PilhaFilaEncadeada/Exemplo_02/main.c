#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int main()
{
    TPilhaEncAlunos Paluno;
    TFilaEncAlunos Faluno;
    TAluno aluno;

    iniPilhaEncAlunos(&Paluno);
    iniFilaAlunosEnc(&Faluno);

    aluno.numMatricula = 1414;
    strcpy(aluno.nome, "alberto");
    strcpy(aluno.email, "alberto@uesc");

    empilharAlunoEnc(aluno, &Paluno);
    empilharAlunoEnc(aluno, &Paluno);

    printf("Pilha:\n");
    imprimePilha(&Paluno);

    liberaPilha(&Paluno);

    printf("\nFila:\n");
    insereNaFilaEnc(aluno, &Faluno);
    insereNaFilaEnc(aluno, &Faluno);

    imprimeFila(&Faluno);

    liberaFila(&Faluno);

    return 0;
}
