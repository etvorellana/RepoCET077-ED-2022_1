#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    srand(time(NULL));

    int chave;

    TAluno aux;
    TPilhaAlunos pilha, pilhaReserva;
    TListAlunos *lista;

    iniPilhaAlunos(&pilha, LSIZE);
    iniPilhaAlunos(&pilhaReserva, LSIZE);
    lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);

    for(int i = 0; i < lista->tam; i++)
        empilharAluno(lista->lista[i], &pilha); //Empilha os alunos gerados aleatoriamente na pilha

    printf("\nPilha:\n");
    printLista(pilha.pilha, pilha.topo);

    chave = lista->lista[rand() % lista->tam].numMatricula; //Uma chave aleatoria que eu irei remover da minha pilha

    printf("\nCHAVE: %d\n", chave);

    while(chave != pilha.pilha[pilha.topo-1].numMatricula){ //Vou procurar a chave
        desempilharALuno(&aux, &pilha); //Cada vez que eu não achar a chave eu desempilho
        empilharAluno(aux, &pilhaReserva); //E guardo o valor desempilhado em uma pilha reserva
    }

    printf("\n\nPilha Original\n\n");
    printLista(pilha.pilha, pilha.topo);
    printf("\n\nPilha Reserva\n\n");
    printLista(pilhaReserva.pilha, pilhaReserva.topo);

    desempilharALuno(&pilha.pilha[pilha.topo-1], &pilha); //Quando eu saio do while o topo é o valor que eu quero desempilhar

    printf("\n\nCHAVE DESEMPILHADA");

    while(pilhaReserva.topo > 0){
        empilharAluno(pilhaReserva.pilha[pilhaReserva.topo-1], &pilha); //Pego todos os valores da pilha reserva e empilho na principal
        desempilharALuno(&aux, &pilhaReserva);
    }

    printf("\n\n\n");
    printLista(pilha.pilha, pilha.topo);
    printf("\n\n\n");

    return 0;
}

