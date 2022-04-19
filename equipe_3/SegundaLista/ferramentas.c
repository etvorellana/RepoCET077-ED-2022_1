#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  */
void quickSort(TAluno *lista, int inicio, int fim);

/* Manipulação de listas NAO ordenadas */
int buscaAluno_NOrd(TAluno *lista, int tam, int chave)
{
    lista[tam].numMatricula = chave;

    int i = 0;
    while (lista[i].numMatricula != chave)
    {
        i++; // retorna o tam se nao encontrar ou o indice se achar
    }
    return i;
}
int incAluno_NOrd(TAluno aluno, TAluno *lista, int *tam, int cap)
{
    if (*tam == cap)
    {
        // printf("Lista cheia!\n");
        return FALSE; /* Lista cheia */
    }
    if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam)
    {
        /* Chave nao foi encontrada entao add no final da lista */
        lista[*tam] = aluno; /* Copia os dados de aluno para lista[*tam] */
        *tam += 1;
        return TRUE;
    }
    else
        return FALSE; /* Chave foi encontrada */
}
int remAluno_NOrd(int chave, TAluno *lista, int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia

    int pos = buscaAluno_NOrd(lista, *tam, chave);
    // Se pos == *tam, entao a chave nao esta na lista para ser removida e
    // retornara FALSE
    if (pos < *tam)
    {
        *tam -= 1;
        lista[pos] = lista[*tam];
        return TRUE;
    }
    else
        return FALSE;
}

/* Manipulação de listas ordenadas */
int buscaAluno_Ord(TAluno *lista, int tam, int chave)
{
    int min = 0, max = tam, i = 0; // max=4 min=0
    while (min != max)
    {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i; // a verificacao parte para a metade da direita
        else if (lista[i].numMatricula > chave)
            max = i; // a verificacao parte para a metade da esquerda
        else
            return i;
    }
    return i;
}
int incAluno_Ord(TAluno aluno, TAluno *lista, int *tam, int cap)
{
    if (*tam == cap)
        return FALSE; // lista cheia

    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
    /*Caso pos == tam significa qua a chave nao esta na lista e deve esta na
        ultima posicao, ou seja, a chave eh maior que todas as que ja estao na lista.*/
    if (pos == *tam)
    {
        lista[*tam] = aluno;
        *tam += 1;
        return TRUE;
    }
    /*Se a pos != chave significa que a chave nao esta na lista e que deve estar na
          posicao lista[pos]*/
    else if (lista[pos].numMatricula != aluno.numMatricula)
    {
        for (int i = *tam; i > pos; i--)
        {
            lista[i] = lista[i - 1]; /*modificacao, evitando varias atribuicoes
                  dessa forma desloca cada indice para uma posicao a direita*/
        }
        lista[pos] = aluno;
        *tam += 1;
        return TRUE;
    }
    else
        return FALSE;
}
int remAluno_Ord(int chave, TAluno *lista, int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia

    int pos = buscaAluno_Ord(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave)
    {
        for (int i = pos; i < *tam - 1; i++)
        {
            lista[i] = lista[i + 1];
        }
        *tam -= 1;
        return TRUE;
    }
    else
        return FALSE;
}

/* Inicia uma lista de alunos */
TListAlunos *iniListAlunos(int cap, int eOrd)
{
    TAluno *lista = malloc(sizeof(TAluno) * (cap + 1));
    TListAlunos *lAlunos = malloc(sizeof(TListAlunos));
    if (lAlunos == NULL || lista == NULL)
    {
        puts("Erro de memoria!");
        exit(-1);
    }

    lAlunos->tam = 0;
    lAlunos->cap = cap;
    lAlunos->eOrd = eOrd;
    lAlunos->lista = lista;
    return lAlunos;
}

/* Funcoes intermediarias */
int buscaChaveNaLista(int chave, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return buscaAluno_NOrd(lista->lista, lista->tam, chave);
    return buscaAluno_Ord(lista->lista, lista->tam, chave);
}
int incAlunoNaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap);
    return incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap);
}
int remAlunoDaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return remAluno_NOrd(aluno.numMatricula, lista->lista, &lista->tam);
    return remAluno_Ord(aluno.numMatricula, lista->lista, &lista->tam);
}

void uniaoListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    diferenListas(lista1, lista2, lista3);
    diferenListas(lista2, lista1, lista3);
    interListas(lista1, lista2, lista3);
}
void diferenListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    for (int i = 0; i < lista1->tam; i++)
    {
        if (buscaAluno_NOrd(lista2->lista, lista2->tam,
                            lista1->lista[i].numMatricula) == lista2->tam)
        {
            // printf("\nDiferenca: %d",lista1->lista[i].numMatricula);
            incAlunoNaLista(lista1->lista[i], lista3);
        }
    }
}
void interListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    for (int i = 0; i < lista1->tam; i++)
    {
        if (buscaAluno_NOrd(lista2->lista, lista2->tam,
                            lista1->lista[i].numMatricula) != lista2->tam)
        {
            // printf("\nIntersecao: %d",lista1->lista[i].numMatricula);
            incAlunoNaLista(lista1->lista[i], lista3);
        }
    }
}

void ordenaLista(TListAlunos *listaA)
{
    if (listaA->eOrd == TRUE)
        return;

    quickSort(listaA->lista, 0, listaA->tam - 1);
    listaA->eOrd = TRUE;
    return;
}

TListAlunos *geraListAlunos(int tam, int cap, int eOrd)
{
    TListAlunos *lAlunos = iniListAlunos(cap, eOrd);
    srand(time(NULL));

    for (int i = 0; i < tam;)
    {
        TAluno aluno;
        // Ano 2000 a 2022 * 100000, ex. 201900000
        aluno.numMatricula = ((rand() % 22) + 2000) * 100000;
        // Semestre 1 a 2 * 10000, ex. 20000
        aluno.numMatricula += ((rand() % 2) + 1) * 10000;
        // Numero sequencial 1 a 800, ex. 240
        aluno.numMatricula += (rand() % 800) + 1; // 201920240
        sprintf(aluno.email, "aluno%d@gmail.com", i);
        sprintf(aluno.nome, "Aluno%d", i);
        // printf("\n %s",aluno.email);

        if (incAlunoNaLista(aluno, lAlunos))
            i++;
    }
    return lAlunos;
}

/* Algoritmo de ordenacao complexidade n^2 no pior caso, nos outros casos nlog(n) */
void quickSort(TAluno *lista, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = lista[fim].numMatricula;
        int i = inicio;
        int buffer = 0;
        //[8,7,5,4,6,9,1] pivo=1
        for (int j = inicio; j < fim; j++)
        {
            if (lista[j].numMatricula <= pivo)
            {
                buffer = lista[j].numMatricula;
                lista[j].numMatricula = lista[i].numMatricula;
                lista[i].numMatricula = buffer;
                i++;
            }
        }
        buffer = lista[fim].numMatricula;
        lista[fim].numMatricula = lista[i].numMatricula;
        lista[i].numMatricula = buffer;

        /* Fara o sort na lista da esquerda */
        quickSort(lista, inicio, i - 1);
        /* Fara o sort na lista da direita */
        quickSort(lista, i + 1, fim);
    }
    return;
}

void printLista(TListAlunos *lista)
{
    printf("[");
    for (int i = 0; i < lista->tam; i++)
        printf(" %d", lista->lista[i].numMatricula);
    printf(" ]\n");
    return;
}
