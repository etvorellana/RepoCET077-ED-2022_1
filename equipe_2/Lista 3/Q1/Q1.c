#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void){
    srandom(time(NULL));

    TPilhaAlunos pilhaAlunos;

    iniPilhaAlunos(&pilhaAlunos, LSIZE);

    geraPilhaDeAlunos(&pilhaAlunos);

    printPilha(pilhaAlunos.pilha, pilhaAlunos.topo);

    desempilharALuno(&pilhaAlunos.pilha[rand()%pilhaAlunos.topo], &pilhaAlunos);

    printPilha(pilhaAlunos.pilha, pilhaAlunos.topo);

    desempilharALuno(&pilhaAlunos.pilha[rand()%pilhaAlunos.topo], &pilhaAlunos);

    printPilha(pilhaAlunos.pilha, pilhaAlunos.topo);

}