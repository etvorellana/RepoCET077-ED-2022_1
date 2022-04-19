#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int buscaAluno_NOrd(TAluno lista[], int tam, int chave) {
  // Copiando a chave para a posição tam (fora da lista)
  int i = 0;
  lista[tam].numMatricula = chave;
  while (lista[i].numMatricula != chave) {
    i++;
  }
  return i;
}

int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap) {
  if (*tam == cap)
    return FALSE; // lista cheia
  if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam) {
    lista[*tam].numMatricula = aluno.numMatricula;
    strcpy(lista[*tam].nome, aluno.nome);
    strcpy(lista[*tam].email, aluno.email);
    *tam += 1;
    return TRUE;
  } else
    return FALSE;
}

int remAluno_NOrd(int chave, TAluno lista[], int *tam) {
  if (*tam == 0)
    return FALSE; // lista vazia

  int pos = buscaAluno_NOrd(lista, *tam, chave);
  if (pos < *tam) {
    *tam -= 1;
    lista[pos].numMatricula = lista[*tam].numMatricula;
    strcpy(lista[pos].nome, lista[*tam].nome);
    strcpy(lista[pos].email, lista[*tam].email);
    return TRUE;
  } else
    return FALSE;
}

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave) {
  int min = 0, max = tam, i;
  while (min != max) {
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

int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap) {
  int i ;
  if (*tam == cap)
    return FALSE; // lista cheia
  int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);

  if (pos == *tam) {
    lista[*tam].numMatricula = aluno.numMatricula;
    strcpy(lista[*tam].nome, aluno.nome);
    strcpy(lista[*tam].email, aluno.email);
    *tam += 1;
    return TRUE;
  } else {
    if (lista[pos].numMatricula != aluno.numMatricula) {
      for (i = *tam; i > pos; i--) {
        lista[i].numMatricula = lista[i - 1].numMatricula;
        strcpy(lista[i].nome, lista[i - 1].nome);
        strcpy(lista[i].email, lista[i - 1].email);
      }

      lista[pos].numMatricula = aluno.numMatricula;
      strcpy(lista[pos].nome, aluno.nome);
      strcpy(lista[pos].email, aluno.email);
      *tam += 1;
      return TRUE;
    }
    return FALSE;
  }
}

int remAluno_Ord(int chave, TAluno lista[], int *tam) {
  if (*tam == 0)
    return FALSE; // lista vazia
  int pos = buscaAluno_Ord(lista, *tam, chave);
  if (pos < *tam && lista[pos].numMatricula == chave) {
    for (int i = pos; i < *tam - 1; i++) {
      lista[i].numMatricula = lista[i + 1].numMatricula;
      strcpy(lista[i].nome, lista[i + 1].nome);
      strcpy(lista[i].email, lista[i + 1].email);
    }
    *tam -= 1;
    return TRUE;
  } else
    return FALSE;
}

void iniListAlunos(TListAlunos *lista, int cap, int eOrd) {
  TAluno *lista1;

  if (eOrd)
    lista1 = (TAluno *)malloc(sizeof(TAluno) * cap);
  else
    lista1 = (TAluno *)malloc(sizeof(TAluno) * (cap + 1));

  lista->lista = lista1;
  lista->tam = 0;
  lista->cap = cap;
  lista->eOrd = eOrd;
}

int buscaChaveNaLista(int chave, TListAlunos *lista) {

  /*
      Procurar uma chave na lista e retornar o índice
      no array em que a chave se encontra ou a posição em
      que um elemento com esta chave deveria ser incluído
      na lista. Lembre que as listas não possuem elementos
      com chave repetida.
  */
  if (lista->eOrd == 0) {
    return buscaAluno_NOrd(lista->lista, lista->tam, chave);
  } else {
    return buscaAluno_Ord(lista->lista, lista->tam, chave);
  }
}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista) {

  if (lista->eOrd == 0) {
    return incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap);
  } else {
    return incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap);
  }
}
int remAlunoDaLista(TAluno aluno, TListAlunos *lista, int *tam, int chave) {

  if (lista->eOrd == 0) {
    return remAluno_NOrd(aluno.numMatricula, lista->lista, &lista->tam);
  } else {
    return remAluno_Ord(aluno.numMatricula, lista->lista, &lista->tam);
  }
}

void uniaoListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *uniao) {
  int Ord = listaA->eOrd + listaB->eOrd;
  int i;

  iniListAlunos(uniao, listaA->cap + listaB->cap, Ord);

  for (i = 0; i < listaA->tam; i++) {
    incAlunoNaLista(listaA->lista[i], uniao);
  }
  for (i = 0; i < listaB->tam; i++) {
    incAlunoNaLista(listaB->lista[i], uniao);
  }
}

void difListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *dif) {
  int i, chaveA, chaveB;
  iniListAlunos(dif, listaA->tam, listaA->eOrd);

  for (i = 0; i < listaA->tam; i++) {
    chaveA = listaA->lista[i].numMatricula;
    chaveB = buscaChaveNaLista(chaveA, listaB);
    if (chaveB == listaB->tam)
      incAlunoNaLista(listaA->lista[i], dif);
  }
}

void printLista(TAluno lista[], int tam) {
  printf("[ \n ");
  for (int i = 0; i < tam; i++) {
    printf("%d, ", lista[i].numMatricula);
    printf("%s, ", lista[i].nome);
    printf("%s;\n ", lista[i].email);
  }
  printf(" ]\n");
}
void ordenaLista(TListAlunos *listaA,int inicio,int fim) {
  /*int i,j,k,meio;
  TListAlunos *vetorTemp;
  if(inicio==fim) return;

  meio = (inicio + fim) / 2;
  mergeSort(listaA->lista,,inicio,meio);
  mergeSort(listaA->lista,meio+1,fim);

  i = inicio;
  j = meio +1 ;
  k = 0;
  *vetorTemp =  malloc(sizeof(TAluno)* (fim - inicio+1));

  while(i<meio +1 || j<fim +1){
    if(i==meio+1){
      vetorTemp[k] = listaA->lista[j].numMatricula;
      i++;
      k++;
    }
    else{
      if(listaA->lista[i].matricula < listaA->lista[j]){

      }
    }
  }*/
}

void intListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *inter){
    int i,Ord = listaA->eOrd + listaB->eOrd;
    int chaveA, chaveB;
    
    if(listaA-> tam < listaB->tam)
        iniListAlunos(inter, listaA->tam, Ord);
    else
        iniListAlunos(inter, listaB->tam, Ord);
        
    
    if(listaA->eOrd){
        for(i=0;i<listaB->tam;i++){
            chaveB=listaB->lista[i].numMatricula;
            
            //aqui falta pensar se tiver na última casa
            if(buscaChaveNaLista(chaveB,listaA)<listaA->tam)
                incAlunoNaLista(listaB->lista[i], inter);
        }
    }else{
        for(i=0;i<listaA->tam;i++){
            chaveA=listaA->lista[i].numMatricula;
            
            //aqui falta pensar se tiver na última casa
            if(buscaChaveNaLista(chaveA,listaB)<listaB->tam)
                incAlunoNaLista(listaA->lista[i], inter);
        }
    }
    
    
  }

void geraListaDeAlunos(TListAlunos *lista, int tam, int cap, int eOrd){
    TAluno reg;
    int i, ano, sem, aleat;
    iniListAlunos(lista, cap, eOrd);
    for(i=0; i<tam; i++){
        strcpy(reg.email,"i@gmail.com");
        strcpy(reg.nome,"fulaninho-i");
        ano = (1991 + (rand()%31))* 100000;
        sem = (1+(rand()%2))*10000;
        aleat = rand()%10000;
        reg.numMatricula = ano + sem + aleat;
        if(!incAlunoNaLista(reg, lista))
            i--;
    }
}