#include <stdio.h>
#include <stdlib.h>

#include "ferramentas.h"

int main()
{
    PRaizArvAlunoAVL arvoreavl, busca, *avl;
    PRaizArvAluno arvorebi, buscabi, *bi;
    PRaizArvAluno arvoreNaoOrdenada, buscaNaoOrdenada; /*naoOrd*/
    TListAlunos *lista, *listaF;

    lista = geraListaDeAlunos(10, 10, TRUE);
    listaF = geraListaDeAlunos(10, 10, FALSE);

    arvoreavl = criarArvoreDeListaAVL(lista);
    avl = &arvoreavl;
    arvorebi = criarArvoreDeLista_(listaF);
    bi = &arvorebi;
    arvoreNaoOrdenada = criarArvoreDeLista__(lista);
    //naoOrd = &arvoreNaoOrdenada;

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


    remArvAlunoAVL(200520971, avl);
    printf("Resultado da remocao da chave '200520971':\n\n");
    printArvoreAVL(arvoreavl,0);
    printf("\n\n\n");

    printf("Arvore Binaria:\n\n");
    printArvore(arvorebi,0);
    printf("\n\n\n");

    buscabi = buscaArvAlunoOrd(arvorebi, 201020932);
    printf("Resultado da busca procurando a chave '201020932':\n\n");
    printArvore(buscabi,0);
    printf("\n\n\n");

    remArvAlunoOrd(201020932, bi);
    printf("Resultado da remocao da chave '201020932':\n\n");
    printArvore(arvorebi,0);
    printf("\n\n\n");

    printf("Arvore Nao Ordenada:\n\n");
    printArvore(arvoreNaoOrdenada,0);
    printf("\n\n\n");

    buscaNaoOrdenada = buscaArvAluno(arvoreNaoOrdenada, 200520971);
    printf("Resultado da busca procurando a chave '200520971':\n\n");
    printArvore(buscaNaoOrdenada,0);
    printf("\n\n\n");

    /*remArvAluno(200520971, naoOrd);
    printf("Resultado da remocao da chave '200520971':\n\n");
    printArvore(arvoreNaoOrdenada,0);
    printf("\n\n\n");*/
}
