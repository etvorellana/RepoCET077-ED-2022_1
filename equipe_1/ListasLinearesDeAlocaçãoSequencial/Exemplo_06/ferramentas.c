#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"


// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave){
    int i = 0;
	while (i < tam)
	{
		if (lista[i].numMatricula == chave)
			return i; //achou retorna o índice
		i++;
	}
	return tam; //não achou, retorna tamLista
}
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap){
    if (*tam == cap){
        return FALSE; //lista cheia
    }
	if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam){ //Acha o final da lista
		lista[*tam].numMatricula = aluno.numMatricula;
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE; //Retorna verdadeiro caso tenha incluido
	}else{
        return FALSE;
    }
}
int remAluno_NOrd(int chave, TAluno lista[], int *tam){
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno_NOrd(lista, *tam, chave);
    if (pos < *tam){
        *tam -= 1;
        lista[pos].numMatricula = lista[*tam].numMatricula;
        strcpy(lista[pos].nome, lista[*tam].nome);
        strcpy(lista[pos].email, lista[*tam].email);
        return TRUE;
    }else
        return FALSE;
}

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave){
    int min = 0, max = tam, i;
    while (min != max)      {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i;
        else
            if (lista[i].numMatricula > chave)
                max = i;
            else
                return i;
    }
    return i;
}
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap){
    if (*tam == cap)
        return FALSE; //lista cheia
    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
	if ( pos == *tam){
        lista[*tam].numMatricula = aluno.numMatricula;
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}else{
        if(lista[pos].numMatricula != aluno.numMatricula){
            for(int i = *tam; i > pos; i--){ //Vai do ultimo valor até pos
                lista[i].numMatricula = lista[i-1].numMatricula; //Vai andando pra esquerda do vetor, colocando o elemento encontrado mais a direita até a achar a pos que deve ser inserido o novo valor.
                strcpy(lista[i].nome, lista[i-1].nome);
                strcpy(lista[i].email, lista[i-1].email);
            }
            lista[pos].numMatricula = aluno.numMatricula; // Quando encontra a posição, sai do laço for e insere o novo valor;
            strcpy(lista[pos].nome, aluno.nome);
            strcpy(lista[pos].email, aluno.email);
            *tam += 1; //Aumenta o tamanho da lista
            return TRUE;
        }else
            return FALSE;
    }
}
int remAluno_Ord(int chave, TAluno lista[], int *tam){
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno_Ord(lista, *tam, chave);
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

void iniListAlunos(TListAlunos* listas, int cap, int eOrd){
    if(eOrd){
        listas->lista = malloc(cap*sizeof(TAluno)); //Aloca a lista ordenada
    }
    else{
        listas->lista = malloc((cap+1)*sizeof(TAluno)); //Aloca a lista não ordenada +1
    }
    listas->cap = cap; //Define a capacidade da lista
    listas->eOrd = eOrd; //Define se é ordenada ou não
    listas->tam = 0; //Define o tamanho, sempre igual a 0
}
int buscaChaveNaLista(int chave, TListAlunos *listas){
    if(listas->eOrd){ //Verifico se a lista é ordenada
        return buscaAluno_Ord(listas->lista, listas->tam, chave); //Se for chamo a função de busca ordenada
    }
    else{
        return buscaAluno_NOrd(listas->lista, listas->tam, chave); //Se não for chamo a função de busca não ordenada
    }
}
int incAlunoNaLista(TAluno aluno, TListAlunos *listas){
    if(listas->eOrd){ //Verifica se a lista é ordenada
        return incAluno_Ord(aluno, listas->lista, &listas->tam, listas->cap); //Se for chama a função de inclusão para listas ordenadas
    }
    else{
        return incAluno_NOrd(aluno, listas->lista, &listas->tam, listas->cap); //Se não chama a função de inclusão para listas não ordenadas
    }
}
int remAlunoDaLista(TAluno aluno, TListAlunos *listas){
    if(listas->eOrd){ //Verifica se a lista é ordenada
        return remAluno_Ord(aluno.numMatricula, listas->lista, &listas->tam);//Se for chama a função de remoção para listas ordenadas
    }
    else{
        return remAluno_NOrd(aluno.numMatricula, listas->lista, &listas->tam);//Se não chama a função de remoção para listas não ordenadas
    }
}
void uniListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC){
    for(int i = 0; i < listaA->tam; i++) //Percorro completamente a lista A
        incAlunoNaLista(listaA->lista[i], listaC); //Chamo a função de incluir para colocar os valores da lista A na lista C
    for(int i = 0; i < listaB->tam; i++) //Percorro completamente a lista B
        incAlunoNaLista(listaB->lista[i], listaC); //Chamo a função de incluir para colocar os valores da lista B na lista C
}
void printLista(TListAlunos *listas){
    if(listas->tam == 0){
        printf("Lista Vazia!!!");
    }
    else{
        for(int i = 0; i < listas->tam; i++){
            printf("\n");
            printf("Numero de Matricula: %d\n", listas->lista[i].numMatricula);
            printf("Nome do Aluno: %s\n", listas->lista[i].nome);
            printf("Email do Aluno: %s\n", listas->lista[i].email);
            printf("\n");
        }
    }
}