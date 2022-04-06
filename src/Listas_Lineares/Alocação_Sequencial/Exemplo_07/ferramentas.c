#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"
 
int buscaAlunoR(TAluno lista[], int tam, int chave);

int buscaAluno(TAluno lista[], int tam, int chave)
{
    // Copiando a chave para a posição tam (fora da lista)
	lista[tam].numMatricula = chave;
    return buscaAlunoR(lista, tam, chave); 
}

int buscaAlunoR(TAluno lista[], int tam, int chave)
{
    if (lista[0].numMatricula >= chave)
		return 0;
	else
		return 1 + buscaAlunoR(&lista[1], tam - 1, chave);
}

/*
//implementação recursiva em lista não ordenada
int buscaAlunoR(TAluno lista[], int tam, int chave)
{
    if (lista[0].numMatricula == chave)
		return 0;
	else
		return 1 + buscaAlunoR(&lista[1], tam - 1, chave);
}
*/

void trocaAlunos(TAluno *aluno1, TAluno *aluno2){
    TAluno troca;
    troca.numMatricula = aluno1->numMatricula;
    strcpy(troca.nome, aluno1->nome);
    strcpy(troca.email, aluno1->email);
                
    aluno1->numMatricula = aluno2->numMatricula;
    strcpy(aluno1->nome, aluno2->nome);
    strcpy(aluno1->email, aluno2->email);

    aluno2->numMatricula = troca.numMatricula;
    strcpy(aluno2->nome, troca.nome);
    strcpy(aluno2->email, troca.email);
}

int incAluno(TAluno aluno, TAluno lista[], int *tam, int cap)
{   
    if (*tam == cap)
        return FALSE; //lista cheia
    int pos = buscaAluno(lista, *tam, aluno.numMatricula);
	if((lista[pos].numMatricula != aluno.numMatricula) || (pos == *tam)){
        for(int i = pos; i <= *tam; i++)
            trocaAlunos(&lista[i], &aluno);
        *tam += 1;
        return TRUE;
    }else
        return FALSE; 
}

int remAluno(int chave, TAluno lista[], int *tam){
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave){
        for(int i = pos; i < *tam - 1 ; i++)
            trocaAlunos(&lista[i], &lista[i+1]);
        *tam -= 1;
        return TRUE;
    }else
        return FALSE;
}

void printLista(TAluno lista[], int tam)
{
	printf("[ \n ");
	for (int i = 0; i < tam; i++)
	{
		printf("%d, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}