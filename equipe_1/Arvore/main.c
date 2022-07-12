#include <stdio.h>
#include <stdlib.h>

#include "ferramentas.h"

int main()
{
    PRaizArvAlunoAVL arvoreavl, busca;
    PRaizArvAluno arvorebi, buscabi;
    PRaizArvAluno arvoreNaoOrdenada, buscaNaoOrdenada;
    TListAlunos *lista, *listaF;

    lista = geraListaDeAlunos(10, 10, TRUE);
    listaF = geraListaDeAlunos(10, 10, FALSE);

    arvoreavl = criarArvoreDeListaAVL(lista);
    arvorebi = criarArvoreDeLista_(listaF);
    arvoreNaoOrdenada = criarArvoreDeLista__(lista);

    printf("LISTA ORDENADA:\n");
    printLista(lista->lista, lista->tam);
    printf("\n\n\n");

    printf("LISTA NAO ORDENADA:\n");
    printLista(listaF->lista, listaF->tam);
    printf("\n\n\n");

    printf("Arvore AVL:\n\n");
    printArvoreAVL(arvoreavl,0);
    printf("\n\n\n");

    busca = buscaArvAlunoRecAVL(arvoreavl, 200520971);
    printf("Resultado da busca procurando a chave '200520971':\n\n");
    printArvoreAVL(busca,0);
    printf("\n\n\n");

    printf("Arvore Binaria:\n\n");
    printArvore(arvorebi,0);
    printf("\n\n\n");

    buscabi = buscaArvAlunoOrd(arvorebi, 201020932);
    printf("Resultado da busca procurando a chave '201020932':\n\n");
    printArvore(buscabi,0);
    printf("\n\n\n");

    printf("Arvore Nao Ordenada:\n\n");
    printArvore(arvoreNaoOrdenada,0);
    printf("\n\n\n");

    buscaNaoOrdenada = buscaArvAluno(arvoreNaoOrdenada, 200520971);
    printf("Resultado da busca procurando a chave '200520971':\n\n");
    printArvore(buscaNaoOrdenada,0);
    printf("\n\n\n");

}
