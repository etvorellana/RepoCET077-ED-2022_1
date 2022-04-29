#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void)
{
    TListAlunos *alunosBiblioteca;
    TFilaAlunos filaDeEspera;

    TAluno testando;
    testando.numMatricula = 14141414;
    strcpy(testando.nome, "alberto");
    strcpy(testando.email, "alberto@alberto");

    alunosBiblioteca = geraListaDeAlunos(LSIZE-1, LSIZE, TRUE); // tam, cap, ordenada
    iniFilaAlunos(&filaDeEspera, MAX); //Inicializa a fila de espera com uma capacidade MAX

    printf("Alunos Utilizando a biblioteca: \n\n");
    printLista(alunosBiblioteca->lista, alunosBiblioteca->tam);

    if(incAlunoNaLista(testando, alunosBiblioteca)){ //Caso tenha espaço, insere o aluno na lista da biblioteca
        printf("\n\nAluno inserido com sucesso\n");
        printf("\nNova Lista:\n\n");
        printLista(alunosBiblioteca->lista, alunosBiblioteca->tam);
    }
    else{ //Caso não tenha insere na fila de espera
        printf("\n\nNao ha vaga, aluno na lista de espera\n");
        insereNaFila(testando, &filaDeEspera);
        printf("\nFila de espera:\n\n");
        printFila(&filaDeEspera);
    }

    testando.numMatricula = 14141415;
    strcpy(testando.nome, "alberto");
    strcpy(testando.email, "alberto@alberto");

    if(incAlunoNaLista(testando, alunosBiblioteca)){ //Caso tenha espaço, insere o aluno na lista da biblioteca
        printf("\n\nAluno inserido com sucesso\n");
        printf("\nNova Lista:\n\n");
        printLista(alunosBiblioteca->lista, alunosBiblioteca->tam);
    }
    else{ //Caso não tenha insere na fila de espera
        printf("Nao ha vaga, aluno na lista de espera\n");
        insereNaFila(testando, &filaDeEspera);
        printf("\nFila de espera:\n\n");
        printFila(&filaDeEspera);
    }

    testando.numMatricula = 14141416;
    strcpy(testando.nome, "alberto");
    strcpy(testando.email, "alberto@alberto");

    if(incAlunoNaLista(testando, alunosBiblioteca)){ //Caso tenha espaço, insere o aluno na lista da biblioteca
        printf("\n\nAluno inserido com sucesso\n");
        printf("\nNova Lista:\n\n");
        printLista(alunosBiblioteca->lista, alunosBiblioteca->tam);
    }
    else{ //Caso não tenha insere na fila de espera
        printf("Nao ha vaga, aluno na lista de espera\n");
        insereNaFila(testando, &filaDeEspera);
        printf("\nFila de espera:\n\n");
        printFila(&filaDeEspera);
    }

    testando.numMatricula = 14141414;
    strcpy(testando.nome, "alberto");
    strcpy(testando.email, "alberto@alberto");

    if(remAlunoDaLista(testando, alunosBiblioteca)){ //Remove o aluno da lista da biblioteca
        if(filaDeEspera.tam > 0){
            incAlunoNaLista(filaDeEspera.fila[filaDeEspera.ini], alunosBiblioteca);
            removeDaFila(&filaDeEspera.fila[filaDeEspera.ini], &filaDeEspera);
            printf("\nAluno removido da lista!!!\nPrimeiro da fila de espera inserido na lista\n");
            printLista(alunosBiblioteca->lista, alunosBiblioteca->tam);
        }
        else{
            printf("Fila vazia!!\n");
        }
    }
    else{
        printf("Nao esta na lista\n");
    }

    printf("\nFILA DE ESPERA:\n");

    printFila(&filaDeEspera);

    return 0;
}
