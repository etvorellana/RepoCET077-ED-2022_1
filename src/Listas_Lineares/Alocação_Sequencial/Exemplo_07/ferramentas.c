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

int incAluno(TAluno aluno, TAluno lista[], int *tam, int cap)
{   
    if (*tam == cap)
        return FALSE; //lista cheia
    int pos = buscaAluno(lista, *tam, aluno.numMatricula);
	if ( pos == *tam){
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}else{
        if(lista[pos].numMatricula != aluno.numMatricula){
            TAluno troca;
            for(int i = pos; i < *tam; i++){
                troca.numMatricula = lista[i].numMatricula;
                strcpy(troca.nome, lista[i].nome);
                strcpy(troca.email, lista[i].email);
                
                lista[i].numMatricula = aluno.numMatricula;
                strcpy(lista[i].nome, aluno.nome);
                strcpy(lista[i].email, aluno.email);

                aluno.numMatricula = troca.numMatricula;
                strcpy(aluno.nome, troca.nome);
                strcpy(aluno.email, troca.email);
            }
            lista[*tam].numMatricula = aluno.numMatricula;
            strcpy(lista[*tam].nome, aluno.nome);
            strcpy(lista[*tam].email, aluno.email);
            *tam += 1;
            return TRUE;
        }else
            return FALSE;
    }   
}

int remAluno(int chave, TAluno lista[], int *tam){
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave){
        for(int i = pos; i < *tam - 1 ; i++){
            lista[i].numMatricula = lista[i+1].numMatricula;
            strcpy(lista[i].nome, lista[i+1].nome);
            strcpy(lista[i].email, lista[i+1].email);
        }
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