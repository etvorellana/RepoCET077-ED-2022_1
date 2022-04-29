#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

#define LMAX 5

int main(void)
{

    srand(time(NULL));

    TAluno aux;
    TListAlunos *Lalunos, *Lreserva, *OrdemDiscursiva, *OrdemDiscursivaReserva;
    TPilhaAlunos Palunos;
    TFilaAlunos Falunos;

    Lalunos = geraListaDeAlunos(LMAX, LMAX, FALSE);
    Lreserva = iniListAlunos(LMAX, FALSE);
    OrdemDiscursiva = iniListAlunos(LMAX, FALSE);
    OrdemDiscursivaReserva = iniListAlunos(LMAX, FALSE);
    iniPilhaAlunos(&Palunos, LMAX);
    iniFilaAlunos(&Falunos, LMAX);

    while(Lreserva->tam != LMAX){
        incAlunoNaLista(Lalunos->lista[rand() % LMAX], Lreserva); //Simula uma ordem de entrega aleatoria
    }

    for(int i = 0; i < LMAX; i++){
        empilharAluno(Lreserva->lista[i], &Palunos); //O ultimo a entregar é o primeiro a escolher
    }

    while(Palunos.topo > 0){
        desempilharALuno(&aux, &Palunos); //O ultimo a entregar é o primeiro a escolher
        incAlunoNaLista(aux, OrdemDiscursiva);
    }

    while(OrdemDiscursivaReserva->tam != LMAX){
        incAlunoNaLista(OrdemDiscursiva->lista[rand() % LMAX], OrdemDiscursivaReserva); //Escolhe o tema e é armazenado no indice do tema
    }

    for(int i = 0; i < LMAX; i++){
        insereNaFila(OrdemDiscursivaReserva->lista[rand() % LMAX], &Falunos); //O primeiro a entregar é o primeiro a escolher
    }


    printf("Lista de alunos que irao fazer a prova:\n");
    printLista(Lalunos->lista, LMAX);
    printf("\n\n");
    printf("Ordem de entrega da primeira prova:\n");
    printLista(Palunos.pilha, LMAX);
    printf("\n\n");
    printf("Temas de 0 a 29 e quem escolheu cada tema:\n");
    printLista(OrdemDiscursivaReserva->lista, LMAX);
    printf("\n\n");
    printf("Ordem de conclusao da prova discursiva:\n");
    printFila(&Falunos);
    printf("\n\n");

    return 0;
}
