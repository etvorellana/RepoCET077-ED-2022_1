#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

#define MAX 199

int main(void)
{

    int contTrueB = 0, contFalseB = 0, contTrueC = 0, contFalseC = 0;

    TListAlunos listaA, listaB, listaC, listaD, listaE, listaF, listaG;

    iniListAlunos(&listaA, 2*LSIZE, FALSE); //Criar uma listaA não ordenada de tamanho 2*LSIZE preenchida de forma aleatória.

    geraListaDeAlunos(&listaA);

    iniListAlunos(&listaB, LSIZE, FALSE); // Declarar uma listaB não ordenada de capacidade LSIZE

    srand(time(NULL));

    for(int i = 0; i < LSIZE; i++){
        if(incAlunoNaLista(listaA.lista[rand() % MAX], &listaB)) // Selecione em ordem aleatória todos os itens da listaA e inclua na listaB.
            contTrueB++;
        else
            contFalseB++;
    }

    printf("\nLISTA B \n");
    printf("\nQuantidade de valores que foram implementados: %d\n", contTrueB); //Conte quantas vezes a função de inclusão retorna verdadeiro e quantas retorna falso. No final mostre os valores contabilizados junto com o tamanho da listaB
    printf("\nQuantidade de valores que nao foram implementados %d\n", contFalseB);
    printf("\nTamanho da lista: %d\n", listaB.tam);

    iniListAlunos(&listaC, LSIZE, TRUE); // Declarar uma listaC ordenada de capacidade LSIZE

    for(int i = 0; i < LSIZE; i++){
        if(incAlunoNaLista(listaA.lista[rand() % MAX], &listaC)) // Selecione em ordem aleatória todos os itens da listaA e inclua na listaC.
            contTrueC++;
        else
            contFalseC++;
    }

    printf("\nLISTA C \n");
    printf("\nQuantidade de valores que foram implementados: %d\n", contTrueC); //Conte quantas vezes a função de inclusão retorna verdadeiro e quantas retorna falso. No final mostre os valores contabilizados junto com o tamanho da lista C
    printf("\nQuantidade de valores que nao foram implementados %d\n", contFalseC);
    printf("\nTamanho da lista: %d\n", listaC.tam);

    iniListAlunos(&listaD, listaB.tam + listaC.tam, TRUE);
    uniListas(&listaB, &listaC, &listaD); //Crie a lista união da listaB com a ListaC.

    printf("\nTamanho da lista D(uniao B + C): %d\n", listaD.tam); //Mostre o tamanho desta lista.

    iniListAlunos(&listaE, listaB.tam, listaB.eOrd);
    difListas(&listaB, &listaC, &listaE);//Crie a lista diferença da listaB com a ListaC.

    printf("\nTamanho da lista E(diferenca B + C): %d\n", listaE.tam);//Mostre o tamanho desta lista.

    iniListAlunos(&listaF, listaC.tam, listaC.eOrd);
    difListas(&listaC, &listaB, &listaF);//Crie a lista diferença da listaC com a ListaB.

    printf("\nTamanho da lista F(diferanca C + B): %d\n", listaF.tam);//Mostre o tamanho desta lista.

    if(listaB.tam < listaC.tam)
        iniListAlunos(&listaG, listaB.tam, listaB.eOrd);
    else
        iniListAlunos(&listaG, listaC.tam, listaC.eOrd);

    intListas(&listaB, &listaC, &listaG);//Crie a lista intersecção da listaB com a ListaC.

    printf("\nTamanho da lista G(Interseccao B + C): %d\n", listaG.tam);//Mostre o tamanho desta lista.

    ordenaLista(&listaA);//Ordena lista A.

    return 0;
}