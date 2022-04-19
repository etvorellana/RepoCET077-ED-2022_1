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
void difListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC){
    for(int i = 0; i < listaA->tam; i++){
        if(buscaChaveNaLista(listaA->lista[i].numMatricula, listaB) == listaB ->tam){//Percorro a lista B inteira, procurando a chave da lista A, caso não ache a chave, a busca retorna o tamanho da lista de B, ou seja, a chave não ta na lista e eu coloco na lista C. Se eu achar a chave significa que ela esta no vetor B, ou seja, não faço nada
            incAlunoNaLista(listaA->lista[i], listaC);
        }
    }
}
void intListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC){
        for(int i = 0; i < listaA->tam; i++){
        if(buscaChaveNaLista(listaA->lista[i].numMatricula, listaB) != listaB ->tam){//Percorro a lista B inteira, procurando a chave da lista A, caso encontre a chave, o valor sera diferente do tamanho de B, ou seja, a chave não esta na lista B, por isso insiro a chave na lista C, caso não encontre a chave retorno o tamanho de B e não faço nada.
            incAlunoNaLista(listaA->lista[i], listaC);
        }
    }
}
void ordenaLista(TListAlunos *listaA){

    if(!listaA->eOrd){ //Verifico se minha lista não é ordenada, caso seja não faço nada
    }
        listaA->eOrd = TRUE; //Caso não seja modifico o campo eOrd pra true
        mergesort(listaA->lista, 0, listaA->tam); //E passo minha lista no algoritmo de ordenação chamado mergesort
}
void merge(TAluno lista[], int comeco, int meio, int fim){
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = malloc(tam *sizeof(TAluno));

    while(com1 <= meio && com2 <= fim){
        if(lista[com1].numMatricula < lista[com2].numMatricula){
            vetAux[comAux] = lista[com1].numMatricula;
            com1++;
        }
        else{
            vetAux[comAux] = lista[com2].numMatricula;
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio){
        vetAux[comAux] = lista[com1].numMatricula;
        comAux++;
        com1++;
    }
    while(com2 <= fim){
        vetAux[comAux] = lista[com2].numMatricula;
        comAux++;
        com2++;
    }
    for(comAux = comeco; comAux <= fim; comAux++){
        lista[comAux].numMatricula = vetAux[comAux - comeco];
    }
    free(vetAux);
}
void mergesort(TAluno lista[], int comeco, int fim){
    if(comeco < fim){
        int meio = (fim+comeco)/2;

        mergesort(lista, comeco, meio);
        mergesort(lista, meio+1, fim);
        merge(lista, comeco, meio, fim);
    }
}
void geraListaDeAlunos(TListAlunos *listas){
    TAluno aluno;
    int chave;
    srand(time(NULL));

    while(listas->tam < listas->cap){ //Gera dados aleatorios do tamanho da lista ate a capacidade
        chave = ((2000 + rand() % 22)*100000)+ ((1 + (rand() % 2))*10000) + (rand() % 9999);
        aluno.numMatricula = chave ;
        strcpy(aluno.nome, "AlunoAleatorio");
        strcpy(aluno.email,"AlunoAleatorio.cic@uesc.br");
        incAlunoNaLista(aluno, listas);
    }
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