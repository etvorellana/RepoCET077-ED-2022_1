#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    //srandom(time(NULL));
    srandom(1234567890);
    /*
        * Criar uma listaA não ordenada de tamanho
        2*LSIZE preenchida de forma aleatória.
    */
    TListAlunos *listaA;
    listaA = geraListaDeAlunos(3 * LSIZE, 3 * LSIZE, FALSE);
    printf("A Lista A tem %d intens ", listaA->tam);
    printf("de um máximos de %d\n", listaA->cap);
    printLista(listaA->lista, listaA->tam);
    /*
        * Declarar uma listaB não ordenada de capacidade
        LSIZE
    */
    TListAlunos *listaB;
    listaB = iniListAlunos(2*LSIZE, FALSE);
    /*
        * Selecione em ordem aleatória todos os itens da
        listaA e inclua na listaB. Conte quantas vezes a
        função de inclusão retorna verdadeiro e quantas
        retorna falso. No final mostre os valores
        contabilizados junto com o tamanho da listaB
    */
    short int *check = (short int *)calloc(listaA->tam, sizeof(short int));
    int simInc = 0, naoInc = 0;
    for (int i = 0; i < listaA->tam; i++)
    {
        int pos = random() % listaA->tam;
        while (check[pos] != FALSE)
        {
            pos = random() % listaA->tam;
        }
        check[pos] = TRUE;
        if (incAlunoNaLista(listaA->lista[pos], listaB))
            simInc++;
        else
            naoInc++;
    }
    free(check);
    printf("Foram incluídos %d itens da Lista A ", simInc);
    printf("na Lista B. FIcaram de fora %d itens\n", naoInc);
    printf("A Lista B tem %d intens ", listaB->tam);
    printf("de um máximos de %d\n", listaB->cap);
    printLista(listaB->lista, listaB->tam);
    /*
        * Declarar uma listaC ordenada de capacidade
        LSIZE
    */
    TListAlunos *listaC;
    listaC = iniListAlunos(LSIZE, TRUE);
    /*
        * Selecione em ordem aleatória todos os itens da
        listaA e inclua na listaC. Conte quantas vezes a
        função de inclusão retorna verdadeiro e quantas
        retorna falso. No final mostre os valores
        contabilizados junto com o tamanho da listaC
    */
    check = (short int *)calloc(listaA->tam, sizeof(short int));
    simInc = naoInc = 0;
    for (int i = 0; i < listaA->tam; i++)
    {
        int pos = random() % listaA->tam;
        while (check[pos] != FALSE)
        {
            pos = random() % listaA->tam;
        }
        check[pos] = TRUE;
        if (incAlunoNaLista(listaA->lista[pos], listaC))
            simInc++;
        else
            naoInc++;
    }
    free(check);
    printf("Foram incluídos %d itens da Lista A ", simInc);
    printf("na Lista C. Ficaram de fora %d itens\n", naoInc);
    printf("A Lista C tem %d intens ", listaC->tam);
    printf("de um máximos de %d\n", listaC->cap);
    printLista(listaC->lista, listaC->tam);
    /*
        * Crie a lista união da listaB com a ListaC.
        Mostre o tamanho desta lista.
    */
    TListAlunos *listaUni;
    listaUni = uniaoListas(listaB, listaC);
    printf("A Lista união de B e C tem %d intens ", listaUni->tam);
    printf("de um máximos de %d\n", listaUni->cap);
    printLista(listaUni->lista, listaUni->tam);
    /*
        * Crie a lista diferença da listaB com a ListaC.
        Mostre o tamanho desta lista.
    */
    TListAlunos *listaDifBC;
    listaDifBC = diferenListas(listaB, listaC);
    printf("A Lista diferença de B com C tem %d intens ", listaDifBC->tam);
    printf("de um máximos de %d\n", listaDifBC->cap);
    printLista(listaDifBC->lista, listaDifBC->tam);
    /*
        * Crie a lista diferença da listaC com a ListaB.
        Mostre o tamanho desta lista.
    */
    TListAlunos *listaDifCB;
    listaDifCB = diferenListas(listaC, listaB);
    printf("A Lista diferença de C com B tem %d intens ", listaDifCB->tam);
    printf("de um máximos de %d\n", listaDifCB->cap);
    printLista(listaDifCB->lista, listaDifCB->tam);
    /*
        * Crie a lista intersecção da listaB com a ListaC.
        Mostre o tamanho desta lista.
    */
    TListAlunos *listaIntCB;
    listaIntCB = interListas(listaC, listaB);
    printf("A Lista intercepção de C com B tem %d intens ", listaIntCB->tam);
    printf("de um máximos de %d\n", listaIntCB->cap);
    printLista(listaIntCB->lista, listaIntCB->tam);
    /*
        * Verifique se os tamanhos reportados são
        consistentes.
    */

    printf("%d + %d + %d == %d?\n", listaDifBC->tam, listaDifCB->tam, listaIntCB->tam, listaUni->tam);
    printf("%d == %d?\n", listaDifBC->tam + listaDifCB->tam + listaIntCB->tam, listaUni->tam);
    /*
     * Transforma a listaA numa lista ordenada.
     */
    ordenaLista(listaA);
    printLista(listaA->lista, listaA->tam);    
    return 0;
}

