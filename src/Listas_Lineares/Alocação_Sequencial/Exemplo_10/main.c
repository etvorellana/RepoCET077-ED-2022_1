#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int main(void)
{
    int tamLista, capLista;
    /*
        capLista - Capacidade da lista.  Limite máximo de elementos
        que podem ser aramzenados na lista. Deve ser utilizado como
        o tamanho do array.
    */
    capLista = LSIZE;
    /*
        tamLista - Tamanho da lista
        * tamLista == 0: Lista vazia;
        * tamLista == capLista: Lista cheia;
        * Se tamLista < capLista o índice i = tamLista representa a
        primeira posição disponível na lista
        * A cada inserção de um novo elemento tamLista deve ser
        incrementado
        * Os índices válidos i para uma lista não vazia:
                0 <= i < tamLista <= capLista
    */
    tamLista = 0; // Lista inicialmente vazia
    // Uma lista como uma array alocado estaticamente
    TAluno lista[capLista+1];

    printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */
    TAluno aluno;
    // Adicionando o primeiro item na lista manualmente
    // Regrano Guedes Maia     201913425   regguemai@uesc.br
    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Regrano Guedes Maia");
    strcpy(aluno.email, "regguemai@uesc.br");
    if (incAluno(aluno, lista, &tamLista, capLista) == FALSE)
        printf("Aluno já está na lista\n");
    else
        printf("Item inserido com sucesso!!!\n");

    // Adicionando um novo item na lista
    // Mengano Martins Pereira 201913245   menmarper@uesc.br
    aluno.numMatricula = 201913245;
    strcpy(aluno.nome, "Mengano Martins Pereira");
    strcpy(aluno.email, "menmarper@uesc.br");
    if (incAluno(aluno, lista, &tamLista, capLista) == FALSE)
        printf("Aluno já está na lista\n");
    else
        printf("Item inserido com sucesso!!!\n");

    // Adicionando um novo item na lista com chave repetida
    // Fulano Silva Oliveira   201913245   fulsiloli@uesc.br
    aluno.numMatricula = 201913245;
    strcpy(aluno.nome, "Fulano Silva Oliveira");
    strcpy(aluno.email, "fulsiloli@uesc.br");
    if (incAluno(aluno, lista, &tamLista, capLista) == FALSE)
        printf("Aluno já está na lista\n");
    else
        printf("Item inserido com sucesso!!!\n");

    // Adicionando um novo item na lista
    // Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    aluno.numMatricula = 201912345;
    if (incAluno(aluno, lista, &tamLista, capLista) == FALSE)
        printf("Aluno já está na lista\n");
    else
        printf("Item inserido com sucesso!!!\n");

    // Imprimindo a lista
    printLista(lista, tamLista);

    // Removendo um item da lista
    // remover item com número de matrícula 201913245
    int remover = 201913245;
    if (remAluno(remover, lista, &tamLista) == TRUE)
        printf("Item removido com sucesso!!!\n");
    else
        printf("Aluno não está na lista\n");
    // remover item com número de matrícula 201813245
    remover = 201813245;
    if (remAluno(remover, lista, &tamLista) == TRUE)
        printf("Item removido com sucesso!!!\n");
    else
        printf("Aluno não está na lista\n");

    // Imprimindo a lista
    printLista(lista, tamLista);
    
    return 0;
}
