#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
#include "ferramentas.h"

// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave){
    // Copiando a chave para a posição tam (fora da lista)
    lista[tam].numMatricula = chave;
    int i = 0;
    while (lista[i].numMatricula != chave)
        i++;
    return i;
}

int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap){
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


// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave){
    int min = 0, max = tam, i;
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

int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap){
    if (*tam == cap)
        return FALSE; // lista cheia
    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
    if (pos == *tam)
    {
        lista[*tam] = aluno;
        *tam += 1;
        return TRUE;
    }else{
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

TListAlunos* iniListAlunos(int cap, int eOrd){
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

int incAlunoNaLista(TAluno aluno, TListAlunos *lista){
    if (lista->eOrd == TRUE)
        return (incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap));
    else
        return (incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap));
}

TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd){
    TListAlunos *lista = iniListAlunos(cap, eOrd);
    TAluno aluno;
    if (tam > cap)
        tam = cap;
    for (int i = 0; i < tam;)
    {
        // Ano 2000 a 2022 * 100000, ex. 20aa00000
        aluno.numMatricula = (2000 + (random() % 22)) * 100000;
        // Semestre 1 a 2 * 10000, ex. 20aas0000
        aluno.numMatricula += ((random() % 2) + 1) * 10000;
        // Numero sequencial 1 a 999, ex. 20aasxxxx
        aluno.numMatricula += (random() % 999) + 1;
        sprintf(aluno.email, "%d@uesc.br", aluno.numMatricula);
        sprintf(aluno.nome, "Aluno_%d", aluno.numMatricula);
        if (incAlunoNaLista(aluno, lista))
            i++;
    }
    return lista;
}

PNoAluno iniNoAluno(void){
	PNoAluno no;  								
  no = (PNoAluno) malloc(sizeof(TNoAluno)); 	
	no->prox = NULL;
	return no;
}

PNoAlunoD iniNoAlunoD(void){
	PNoAlunoD no;  								
  no = (PNoAlunoD) malloc(sizeof(TNoAlunoD)); 	
	no->dir = NULL;
  no->esq = NULL;
	return no;
}


void iniPilhaEncAlunos(TPilhaAlunoEnc* pilha){
  if(pilha != NULL){
    pilha->topo = NULL;
  }
}

int empilharAlunoEnc(TAluno aluno, TPilhaAlunoEnc* pilha){
  
  PNoAluno aux = (PNoAluno) malloc(sizeof(PNoAluno));
  if(aux==NULL){
    return FALSE;
  }
  aux->numMatricula = aluno.numMatricula; //passando os dados que estao na estrutura de dados.
  strcpy(aux->nome, aluno.nome);
  strcpy(aux->email,aluno.email);

  aux->prox = pilha->topo;

  pilha->topo = aux;

  return TRUE;

}

int desempilharAlunoEnc(TAluno* aluno, TPilhaAlunoEnc* pilha){
  PNoAluno aux = pilha->topo; 


  if(pilha->topo == NULL){
    return FALSE; //pilha vaz ia
  }
  else{

    pilha->topo =   aux->prox;
    aux->prox = NULL;

    aluno->numMatricula = aux->numMatricula;
    strcpy(aluno->nome,aux->nome);
    strcpy(aluno->email,aux->email);

    free(aux);
    return FALSE;
  }
}

void imprimePilha(TPilhaAlunoEnc* pilha){
  PNoAluno aux = pilha->topo;

  if(pilha->topo == NULL){
    //lista vazia.
  }
  else{
    do{
      printf("%d\n", aux->numMatricula);
      printf("%s\n", aux->nome);
      printf("%s\n", aux->email);
      
      aux = aux->prox;

    }while(aux != NULL);
  }
}

void liberaPilha(TPilhaAlunoEnc* pilha){
  TAluno aluno;

  if(pilha->topo == NULL){
    //pilha vazia
  }
  else{
    while(desempilharAlunoEnc(&aluno,pilha));
  }
  
}

/*
void iniPilhaEncAlunos(TPilhaAlunoEnc* pilha){
  PNoAlunoD no0 = iniNoAlunoD() , head= iniNoAlunoD();
  pilha->pilha = head;
  no0->dir = pilha->pilha;
  no0->esq = pilha->pilha;
  pilha->pilha->dir = no0;
  pilha->pilha->esq = no0;
  pilha->topo = no0;
  pilha->tam = 0;
}

int empilharAlunoEnc(TAluno aluno, TPilhaAlunoEnc* pilha){
  PNoAlunoD novoNo = iniNoAlunoD();

  if(novoNo!=NULL){
    pilha->topo->numMatricula = aluno.numMatricula;
    strcpy(pilha->topo->email, aluno.email);
    strcpy(pilha->topo->nome, aluno.nome);
  
    novoNo->dir = pilha->pilha;
    novoNo->esq = pilha->topo;
    pilha->topo->dir = novoNo;

    pilha->topo = novoNo;
    pilha->tam++;
    
    return TRUE;
  }
  return FALSE;
}

int desempilharAlunoEnc(TAluno* aluno, TPilhaAlunoEnc* pilha){
  PNoAlunoD aux = pilha->topo->esq;

  if(aux != pilha->pilha){
    aluno->numMatricula = aux->numMatricula;
    strcpy( aluno->email, aux->email);
    strcpy(aluno->nome, aux->nome);

    aux = aux->esq;
    free(aux->dir);
    aux->dir = pilha->topo;
    pilha->topo->esq = aux;
    
    pilha->tam--;
    return TRUE;
  }
  return FALSE;
}

void imprimePilha(TPilhaAlunoEnc* pilha){
  int i;
  PNoAlunoD atual = pilha->pilha->dir;
  for(i= 0;i<pilha->tam;i++){
    printf("| ");
    printf("%d, ", atual->numMatricula);
    printf("%s, ", atual->nome);
    printf("%s", atual->email);
    printf(" |\n");
    atual = atual->dir;
  }
  printf("\n");
}

void liberaPilha(TPilhaAlunoEnc* pilha){
  PNoAlunoD anterior = pilha->topo->esq;

  while(anterior!=pilha->pilha){
    anterior = anterior->esq;
    free(anterior->dir);
  }
  pilha->pilha->dir = pilha->topo;
  pilha->pilha->esq = pilha->topo;
  pilha->topo->esq = pilha->pilha;
  pilha->tam = 0;
}
*/



void iniFilaAlunosEnc(TFilaAlunoEnc* fila){
  PNoAluno inicio = iniNoAluno();
  
  fila->fila = iniNoAluno();
  inicio->prox = fila->fila;
  fila->fila->prox = inicio;
  
  fila->ini = inicio;
  fila->fim = inicio;
  fila->tam = 0;
}

int insereNaFilaEnc(TAluno aluno, TFilaAlunoEnc* fila){
  PNoAluno novoNo = iniNoAluno();

  if(novoNo!=NULL){
    fila->fim->numMatricula = aluno.numMatricula;
    strcpy(fila->fim->email, aluno.email);
    strcpy(fila->fim->nome, aluno.nome);
  
    novoNo->prox = fila->fila;
    fila->fim->prox = novoNo;

    fila->fim = novoNo;
    fila->tam++;
    
    return TRUE;
  }
  return FALSE;
}

int removeDaFilaEnc(TAluno* aluno, TFilaAlunoEnc* fila){
  PNoAluno rem = fila->ini;

  if(rem->prox != fila->fila){
    aluno->numMatricula = rem->numMatricula;
    strcpy( aluno->email, rem->email);
    strcpy(aluno->nome, rem->nome);

    fila->fila->prox = rem->prox;
    fila->ini = rem->prox;
    free(rem);
    
    fila->tam--;
    return TRUE;
  }
  return FALSE;
}

void imprimeFila(TFilaAlunoEnc* fila){
  int i;
  PNoAluno atual = fila->fila->prox;
  for(i= 0;i<fila->tam;i++){
    printf("| ");
    printf("%d, ", atual->numMatricula);
    printf("%s, ", atual->nome);
    printf("%s", atual->email);
    printf(" |\n");
    atual = atual->prox;
  }
  printf("\n");
}

void liberaFila(TFilaAlunoEnc* fila){
  PNoAluno atual = fila->ini, proximo;

  
  while(atual->prox!=fila->fila){
    proximo = atual->prox;
    free(atual);
    atual = proximo;
  }
  fila->fila->prox = atual;
  fila->ini = atual;
  fila->tam = 0;
}

PNoPilha iniNoPilha(void){
  PNoPilha no;  								
  no = (PNoPilha) malloc(sizeof(TNoPilha)); 	
	no->prox = NULL;
	return no;
}

void iniFilaDePilhas(TFilaDePilha* fp){
  PNoPilha novoNo = iniNoPilha();

  fp->pilha = iniNoPilha();
  novoNo->prox = fp->pilha;
  fp->pilha->prox = novoNo; 
  fp->fim = novoNo;
  fp->ini = fp->pilha->prox;
  fp->pilhas = 0;
}

int inserePilha(TPilhaAlunoEnc* pilhaOrg, TFilaDePilha* fp){
  PNoPilha novaPilha = iniNoPilha();

  if(novaPilha!=NULL){
    novaPilha->pilha = pilhaOrg;
    novaPilha->prox = fp->fim;

    
    fp->fim= novaPilha;
    
    

    fp->pilhas++;
    return TRUE;
  }
  return FALSE;
}
int removePilha(TPilhaAlunoEnc* popPilha, TFilaDePilha* fp){
  PNoPilha rem = fp->pilha->prox;
  if(rem != fp->pilha){
    popPilha = (rem->pilha);

    fp->pilha->prox = rem->prox;
    free(rem);
   
    fp->pilhas--;
    return TRUE;
  }
  return FALSE;
}
int insereEmPiha(int indice, TAluno aluno, TFilaDePilha* fp){
  int i=0;
  PNoPilha pos = fp->pilha;
  
  if(indice<=(fp->pilhas - 1) || indice>0 || fp->pilhas != 0){
    do{
      pos = pos->prox;
      i++;
    }while(i<indice);

    empilharAlunoEnc(aluno,pos->pilha);
    return TRUE;
  }
  return  FALSE;
}
int removeEmPilha(int indice, TAluno* aluno, TFilaDePilha* fp){
  int i=0;
  PNoPilha pos = fp->pilha;
  if(indice<=(fp->pilhas - 1) || indice>0 || fp->pilhas != 0){
    do{
      pos = pos->prox;
      i++;
    }while(i<=indice);
    
    desempilharAlunoEnc(aluno,pos->pilha);
    return TRUE;
  }
  return  FALSE;
}
void imprimeFilaDePilhasAll(TFilaDePilha fp){
  int i;
  PNoPilha atual = fp.pilha->prox;

  for(i=0;i<fp.pilhas;i++){
    printf("Pilha %d:\n", i);
    imprimePilha(atual->pilha);
    printf("\n");
    atual = atual->prox;
  }
}
int imprimeFilaDePilha(int indice, TFilaDePilha fp){
  int i=0;
  PNoPilha pos = fp.pilha;
  
  if(indice<=(fp.pilhas - 1) || indice>0 || fp.pilhas != 0){
    do{
      pos = pos->prox;
      i++;
    }while(i<=indice);

    printf("Pilha %d:\n", indice);
    imprimePilha(pos->pilha);
    printf("\n");
    return TRUE;
  }
  return  FALSE;
}
void liberaFilaDePilhasAll(TFilaDePilha* fp){
  PNoPilha atual = fp->pilha->prox, proximo;

  while(atual!=fp->pilha){
    proximo = atual->prox;
    free(atual);
    atual = proximo;
  }

  fp->fim = fp->pilha;
  fp->pilha->prox = fp->fim; 
  fp->pilhas = 0;

}
int liberaFilaDePilha(int indice, TFilaDePilha* fp){
  int i=0;
  PNoPilha pos = fp->pilha;
  
  if(indice<=(fp->pilhas - 1) || indice>0 || fp->pilhas != 0){
    do{
      pos = pos->prox;
      i++;
    }while(i<=indice);

    liberaPilha(pos->pilha);
    return TRUE;
  }
  return  FALSE;
}
