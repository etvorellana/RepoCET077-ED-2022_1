#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave)
{
    // Copiando a chave para a posição tam (fora da lista)
    lista[tam].numMatricula = chave;
    int i = 0;
    while (lista[i].numMatricula != chave)
        i++;//se for igual a tamanho é pq nao achou
    return i;
}

int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap)
{
    if (*tam == cap)
        return FALSE; // lista cheia
    if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam)
    {
        lista[*tam] = aluno;
        *tam += 1;
        return TRUE;
    }
    else
        return FALSE;
}

int remAluno_NOrd(int chave, TAluno lista[], int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia
    int pos = buscaAluno_NOrd(lista, *tam, chave);
    if (pos < *tam)
    {
        *tam -= 1;
        lista[pos] = lista[*tam];
        return TRUE;
    }
    else
        return FALSE;
}

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave)
{
    int min = 0, max = tam, i = 0;
    while (min != max)
    {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i;
        else if (lista[i].numMatricula > chave)
            max = i;
        else
            return i;
    }
    return i;
}

int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap)
{
    if (*tam == cap)
        return FALSE; // lista cheia
    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
    if (pos == *tam)
    {
        lista[*tam] = aluno;
        *tam += 1;
        return TRUE;
    }
    else
    {
        if (lista[pos].numMatricula != aluno.numMatricula)
        {
            for (int i = *tam; i > pos; i--)
                lista[i] = lista[i-1];
            lista[pos] = aluno;
            *tam += 1;
            return TRUE;
        }
        else
            return FALSE;
    }
}

int remAluno_Ord(int chave, TAluno lista[], int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia
    int pos = buscaAluno_Ord(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave)
    {
        for (int i = pos; i < *tam - 1; i++)
            lista[i] = lista[i + 1];
        *tam -= 1;
        return TRUE;
    }
    else
        return FALSE;
}

TListAlunos* iniListAlunos(int cap, int eOrd)
{
    TListAlunos* listaA;
    TAluno *lista;

    if (eOrd)
        lista = (TAluno *)malloc(sizeof(TAluno) * cap);
    else
        lista = (TAluno *)malloc(sizeof(TAluno) * (cap + 1));

    listaA = (TListAlunos *)malloc(sizeof(TListAlunos));
    listaA->lista = lista;
    listaA->tam = 0;
    listaA->cap = cap;
    listaA->eOrd = eOrd;
    return listaA; 
}

void iniListAlunosPar(TListAlunos *listaA, int cap, int eOrd)
{
    TAluno *lista;

    if (eOrd)
        lista = (TAluno *)malloc(sizeof(TAluno) * cap);
    else
        lista = (TAluno *)malloc(sizeof(TAluno) * (cap + 1));

    listaA->lista = lista;
    listaA->tam = 0;
    listaA->cap = cap;
    listaA->eOrd = eOrd;
}

int buscaChaveNaLista(int chave, TListAlunos *lista)
{
    if (lista->eOrd == TRUE)
        return (buscaAluno_Ord(lista->lista, lista->tam, chave));
    else
        return (buscaAluno_NOrd(lista->lista, lista->tam, chave));
}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == TRUE)
        return (incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap));
    else
        return (incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap));
}

int remAlunoDaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == TRUE)
        return (remAluno_Ord(aluno.numMatricula, lista->lista, &lista->tam));
    else
        return (remAluno_NOrd(aluno.numMatricula, lista->lista, &lista->tam));
}

void ordenaListaBolha(TAluno lista[], int tam){
    TAluno bolha;
    int trocou;
    for(int i = 0; i < tam-1; i++){
        bolha = lista[0];
        trocou = FALSE; 
        for(int j = 1; j < tam - i; j++){
            if(bolha.numMatricula < lista[j].numMatricula) 
                bolha = lista[j];
            else{
                lista[j-1]=lista[j];
                lista[j] = bolha;
                trocou = TRUE;
            }
        }
        if (!trocou){
            printf("Parou na iteração %d de %d\n", i, tam - 2); 
            break;
        }
    }
}


void ordenaLista(TListAlunos *lista)
{
    if (!lista->eOrd){
        ordenaListaBolha(lista->lista, lista->tam);
        //ordenaListaBolhaPlus(lista->lista, lista->tam);
        lista->eOrd = TRUE;
    }
}

void printLista(TAluno lista[], int tam)
{
    printf("[ \n ");
	for (int i = 0; i < tam; i++)
	{
		printf("[%d] %d, ",i, lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}

void printPilha(TAluno pilha[], int topo)
{
    printf("[ \n ");
	for (int i = topo-1; i >= 0; i--)
	{
		printf("[%d] %d, ", i, pilha[i].numMatricula);
		printf("%s, ",pilha[i].nome);
		printf("%s;\n ", pilha[i].email);
	}
	printf(" ]\n");
}
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd)
{
    TListAlunos *lista = iniListAlunos(cap, eOrd);
    TAluno aluno;
    if (tam > cap)
        tam = cap;
    for (int i = 0; i < tam;)
    {
			// Ano 2000 a 2022 * 100000, ex. 20aa00000
			aluno.numMatricula = (2000 + (random() % 23)) * 100000;
			// Semestre 1 a 2 * 10000, ex. 20aas0000
      aluno.numMatricula += (aluno.numMatricula == 202200000) ? 10000 : ((random() % 2) + 1) * 10000;
			// Numero sequencial 1 a 999, ex. 20aasxxxx
			aluno.numMatricula += (random() % 999) + 1;
			sprintf(aluno.email, "%d@uesc.br", aluno.numMatricula);
			sprintf(aluno.nome, "Aluno_%d", aluno.numMatricula);
			if (incAlunoNaLista(aluno, lista))
					i++;
    }
    return lista;
}

// Pilhas
void iniPilhaAlunos(TPilhaAlunos *pilha, int cap)
{
    pilha->cap = cap;
    pilha->topo = 0;
    pilha->pilha = (TAluno *) malloc(sizeof(TAluno) * cap);
}

int empilharAluno(TAluno aluno, TPilhaAlunos *pilha) // push
{
    if (pilha->topo < pilha->cap)
    {
        pilha->pilha[pilha->topo] = aluno;
         //ao atribuir pilha[x]=aluno todos os campos do aluno são incluidos juntos.
        pilha->topo++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int desempilharALuno(TAluno *aluno, TPilhaAlunos *pilhaA) // pop
{
	if (pilhaA->topo > 0)
	{
		pilhaA->topo--;
    *aluno = pilhaA->pilha[pilhaA->topo];
    /*
    
    */
		//printf("%x %x\n", aluno, &pilhaA->pilha[pilhaA->topo]);
		/*aluno->numMatricula = pilhaA->pilha[pilhaA->topo].numMatricula;
		strcpy(aluno->nome, pilhaA->pilha[pilhaA->topo].nome);
		strcpy(aluno->email, pilhaA->pilha[pilhaA->topo].email);*/
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void iniFilaAlunos(TFilaAlunos *fila, int cap)
{
    fila->cap = cap;
    fila->ini = 0;
    fila->fim = 0;
    fila->fila = (TAluno *) malloc(sizeof(TAluno) * cap);
}

int insereNaFila(TAluno aluno, TFilaAlunos *fila)
{
    if ((fila->fim - fila->ini) < fila->cap)
    {
        int pos = fila->fim % fila->cap;
        fila->fila[pos] = aluno;
        fila->fim++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int removeDaFila(TAluno *aluno, TFilaAlunos *fila)
{
    if (fila->ini < fila->fim)
    {
        int pos = fila->ini % fila->cap;
        aluno->numMatricula = fila->fila[pos].numMatricula;
        strcpy(aluno->nome, fila->fila[pos].nome);
        strcpy(aluno->email, fila->fila[pos].email);
        fila->ini++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}