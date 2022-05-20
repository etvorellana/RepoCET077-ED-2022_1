#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>

PNoAluno iniNoAluno(void)
{
    PNoAluno novo_no;
    novo_no = (DNoAluno *)malloc(sizeof(DNoAluno));
    novo_no->dir = novo_no;
    novo_no->esq = novo_no;
    return novo_no;
}

//Pilhas
TPilhaEncAlunos *iniPilhaEncAlunos()
{
    TPilhaEncAlunos *pilha = (TPilhaEncAlunos *)malloc(sizeof(TPilhaEncAlunos));
    pilha->topo = 0;
    pilha->head = iniNoAluno();
    return pilha;
}

int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos *pilha)
{
    PNoAluno novo_no = iniNoAluno();
    if (pilha != NULL && novo_no != NULL)
    {
        PNoAluno ultimo = pilha->head->esq;

        novo_no->dir = pilha->head;
        novo_no->esq = ultimo;
        ultimo->dir = novo_no;
        pilha->head->esq = novo_no;

        novo_no->aluno = aluno;
        pilha->topo++;
        return TRUE;
    }
    else
        return FALSE;
}

int desempilharAlunoEnc(TAluno *aluno, TPilhaEncAlunos *pilha)
{
    if (pilha->topo > 0)
    {
        PNoAluno ultimo = pilha->head->esq;
        PNoAluno penultimo = ultimo->esq;
        
        //Isolamento social
        penultimo->dir = pilha->head;
        pilha->head->esq = penultimo;
        pilha->topo--;

        *aluno = ultimo->aluno;
        free(ultimo);
        return TRUE;
    }
    else
        return FALSE;
}

void imprimePilha(TPilhaEncAlunos *pilha)
{
    printf("[ \n ");
    PNoAluno atual = pilha->head->dir;
    while (atual != pilha->head)
    {
        printf("%d, ", atual->aluno.numMatricula);
        printf("%s, ", atual->aluno.nome);
        printf("%s;\n ", atual->aluno.email);
        atual = atual->dir;
    }
    printf(" ]\ntopo: %d\n", pilha->topo);
}

void liberaPilha(TPilhaEncAlunos *pilha)
{
    PNoAluno atual = pilha->head->dir;
    while (atual != pilha->head)
    {
        atual = atual->dir;
        free(atual->esq);
    }
    free(atual);
}

//Filas
TFilaEncAlunos *iniFilaAlunosEnc()
{
    TFilaEncAlunos *fila = (TFilaEncAlunos *)malloc(sizeof(TFilaEncAlunos));
    fila->tam = 0;
    fila->head = iniNoAluno();
    return fila;
}

int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos *fila)
{
    PNoAluno novo_no = iniNoAluno();
    if (fila != NULL && novo_no != NULL)
    {
        PNoAluno ultimo = fila->head->esq;
        novo_no->dir = fila->head;
        novo_no->esq = ultimo;
        ultimo->dir = novo_no;
        fila->head->esq = novo_no;

        novo_no->aluno = aluno;
        fila->tam++;
        return TRUE;
    }       
    else
        return FALSE;
}

int removeDaFilaEnc(TAluno *aluno, TFilaEncAlunos *fila)
{
    if (fila->tam > 0)
    {
        PNoAluno primeiro = fila->head->dir;
        PNoAluno segundo = primeiro->dir;
        fila->head->dir = segundo;
        segundo->esq = fila->head;

        *aluno = primeiro->aluno;
        free(primeiro);
        fila->tam--;
        return TRUE;
    }
    else
        return FALSE;
}

void imprimeFila(TFilaEncAlunos *fila)
{
    printf("[ \n ");
    PNoAluno atual = fila->head->dir;
    while (atual != fila->head)
    {
        printf("%d, ", atual->aluno.numMatricula);
        printf("%s, ", atual->aluno.nome);
        printf("%s;\n ", atual->aluno.email);
        atual = atual->dir;
    }
    printf(" ]\ntam: %d\n", fila->tam);
}

void liberaFila(TFilaEncAlunos *fila)
{
    PNoAluno atual = fila->head->dir;
    while (atual != fila->head)
    {
        atual = atual->dir;
        free(atual->esq);
    }
    free(atual);
}

