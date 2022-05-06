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
        i++;
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

void geraListaDeAluno(TListAlunos *lista, int tam, int cap, int eOrd) {
    TAluno reg;
    int i, ano, sem, aleat;
    iniListAlunosPar(lista, cap, eOrd);
    for (i = 0; i < tam; i++) {
      strcpy(reg.email, "i@gmail.com");
      strcpy(reg.nome, "fulaninho-i");
      ano = (1991 + (rand() % 31)) * 100000;
      sem = (1 + (rand() % 2)) * 10000;
      aleat = rand() % 10000;
      reg.numMatricula = ano + sem + aleat;
      if (!incAlunoNaLista(reg, lista))
        i--;
    }
  }

// Utilizar isto aqui no projeto
// void iniListAlunos(TListAlunos* lista, int cap, int eOrd)
// ou
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

TListAlunos* uniaoListas(TListAlunos *listaA, TListAlunos *listaB)
{
    /*
        a capacidade da lista de saída se calcula como a soma
        do tamanho da listaA e o tamanho da lista B.
    */
    int cap = listaA->tam + listaB->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de saída será igual a tipo da listaA
    */
    int eOrd = listaA->eOrd;
    TListAlunos *listaC = iniListAlunos(cap, eOrd);
    // colocando todos os elementos de A em C
    for (int i = 0; i < listaA->tam; i++)
        listaC->lista[i] = listaA->lista[i];
    listaC->tam = listaA->tam;
    // colocando os elementos de B que não estão em A
    for (int i = 0; i < listaB->tam; i++)
        incAlunoNaLista(listaB->lista[i], listaC);
    return listaC;
}

TListAlunos* diferenListas(TListAlunos *listaA, TListAlunos *listaB)
{

    // a capacidade da lista de saída é o tamanho da listaA.
    int cap = listaA->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de saída será igual a tipo da listaA
    */
    int eOrd = listaA->eOrd;
    TListAlunos *listaC = iniListAlunos(cap, eOrd);
    // colocando todos os elementos em C
    int chaveA, chaveB, pos;
    for (int i = 0; i < listaA->tam; i++)
    {
        chaveA = listaA->lista[i].numMatricula;
        pos = buscaChaveNaLista(chaveA, listaB);
        if (listaB->eOrd == TRUE)
        {
            if (pos < listaB->tam)
            {
                chaveB = listaB->lista[pos].numMatricula;
                if (chaveA != chaveB)
                    incAlunoNaLista(listaA->lista[i], listaC);
            }
            else
            {
                incAlunoNaLista(listaA->lista[i], listaC);
            }
        }
        else if (pos == listaB->tam)
            incAlunoNaLista(listaA->lista[i], listaC);
    }
    return listaC;
}

TListAlunos *interListas(TListAlunos *listaA, TListAlunos *listaB)
{
    /* 
        a capacidade da lista de saída é o menor valor entre
        o tamanho da listaA e da listaB.
    */
    int cap = (listaA->tam < listaB->tam) ? listaA->tam:listaB->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de saída será igual a tipo da listaA
    */
    int eOrd = listaA->eOrd;
    TListAlunos *listaC = iniListAlunos(cap, eOrd);
    // colocando todos os elementos em C
    int chaveA, chaveB, pos;
    for (int i = 0; i < listaA->tam; i++)
    {
        chaveA = listaA->lista[i].numMatricula;
        pos = buscaChaveNaLista(chaveA, listaB);
        if (listaB->eOrd == TRUE)
        {
            if (pos < listaB->tam)
            {
                chaveB = listaB->lista[pos].numMatricula;
                if (chaveA == chaveB)
                    incAlunoNaLista(listaA->lista[i], listaC);
            }
        }
        else if (pos < listaB->tam)
            incAlunoNaLista(listaA->lista[i], listaC);
    }
    return listaC;
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

void ordenaListaBolhaPlus(TAluno lista[], int tam){
    TAluno bolha;
    int trocou;
    for(int i = 0; i < tam-1; i++){
        bolha = lista[i];
        trocou = FALSE; 
        for(int j = i + 1; j < tam - i; j++){
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
        bolha = lista[tam - i - 2];
        trocou = FALSE; 
        for(int j = tam - i - 3; j >= i; j--){
            if(bolha.numMatricula > lista[j].numMatricula) 
                bolha = lista[j];
            else{
                lista[j+1]=lista[j];
                lista[j] = bolha;
                trocou = TRUE;
            }
        }
        if (!trocou){
            printf("Parou no retorno da iteração %d de %d\n", i, tam - 2); 
            break;
        }
    }
}


void ordenaLista(TListAlunos *lista)
{
    if (!lista->eOrd){
        //ordenaListaBolha(lista->lista, lista->tam);
        ordenaListaBolhaPlus(lista->lista, lista->tam);
        lista->eOrd = TRUE;
    }
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
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd)
{
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

// Pilhas
void iniPilhaAlunos(TPilhaAlunos *pilha, int cap)
{
    pilha->cap = cap;
    pilha->topo = 0;
    pilha->pilha = (TAluno *)malloc(sizeof(TAluno) * cap);
}

int empilharAluno(TAluno aluno, TPilhaAlunos *pilha) // push
{
    if (pilha->topo < pilha->cap)
    {
        pilha->pilha[pilha->topo].numMatricula = aluno.numMatricula;
        strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
        strcpy(pilha->pilha[pilha->topo].email, aluno.email);
        pilha->topo++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int desempilharALuno(TAluno aluno[], TPilhaAlunos *pilha) // pop
{
    if (pilha->topo > 0)
    {   pilha->topo--;
        aluno->numMatricula = pilha->pilha[pilha->topo].numMatricula;
        strcpy(aluno->nome, pilha->pilha[pilha->topo].nome);
        strcpy(aluno->email, pilha->pilha[pilha->topo].email);
      
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void geraPilhaDeAlunos(TPilhaAlunos* pilha)
{
    TAluno aluno;
    if (pilha->topo < pilha->cap)
      for (int i = 0; i < pilha->cap;)
      {
          // Ano 2000 a 2022 * 100000, ex. 20aa00000
          aluno.numMatricula = (2000 + (random() % 22)) * 100000;
          // Semestre 1 a 2 * 10000, ex. 20aas0000
          aluno.numMatricula += ((random() % 2) + 1) * 10000;
          // Numero sequencial 1 a 999, ex. 20aasxxxx
          aluno.numMatricula += (random() % 999) + 1;
          sprintf(aluno.email, "%d@uesc.br", aluno.numMatricula);
          sprintf(aluno.nome, "Aluno_%d", aluno.numMatricula);
          if (empilharAluno(aluno, pilha))
              i++;
      }
}

void printPilha(TAluno pilha[], int tam) {
  printf("[ \n ");
  for (int i = 0; i < tam; i++) {
    printf("%d, ", pilha[i].numMatricula);
    printf("%s, ", pilha[i].nome);
    printf("%s;\n ", pilha[i].email);
  }
  printf(" ]\n");
}

void iniFilaAlunos(TFilaAlunos *fila, int cap)
{
    fila->cap = cap;
    fila->ini = 0;
    fila->fim = 0;
    fila->fila = (TAluno *)malloc(sizeof(TAluno) * cap);
}

int insereNaFila(TAluno aluno, TFilaAlunos *fila)
{
    if ((fila->fim - fila->ini) < fila->cap)
    {
        int pos = fila->fim % fila->cap;
        fila->fila[pos].numMatricula = aluno.numMatricula;
        strcpy(fila->fila[pos].nome, aluno.nome);
        strcpy(fila->fila[pos].email, aluno.email);
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

void printFila(TFilaAlunos fila){
  int cont = fila.ini;
  printf("[");
  for(int i = fila.ini; i < fila.fim; i++){
    printf("%d, ", fila.fila[cont].numMatricula);
    printf("%s, ", fila.fila[cont].nome);
    printf("%s;\n ", fila.fila[cont].email);
    cont++;
    if(i == fila.cap-1){
      cont = 0;
    }
  }
  printf("]\n");
}

void insereAlunoBiblio(TListAlunos* lista, TFilaAlunos *fila){

  TAluno aluno;

  aluno.numMatricula = (2000 + (random() % 22)) * 100000;
  // Semestre 1 a 2 * 10000, ex. 20aas0000
  aluno.numMatricula += ((random() % 2) + 1) * 10000;
  // Numero sequencial 1 a 999, ex. 20aasxxxx
  aluno.numMatricula += (random() % 999) + 1;
  sprintf(aluno.email, "%d@uesc.br", aluno.numMatricula);
  sprintf(aluno.nome, "Aluno_%d", aluno.numMatricula);

  if(incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap)){
    printf("O aluno com matricula %i entrou na biblioteca!\n", aluno.numMatricula);
  }else{
    if(insereNaFila(aluno, fila)){
      printf("Biblioteca Cheia!\nO aluno com matricula %i entrou na fila de espera!\n", aluno.numMatricula);
    }else{
      printf("Biblioteca Cheia e Fila cheia!");
    }
  }
}

void retirarAlunoBiblio(TAluno* aluno, TListAlunos* lista, TFilaAlunos* fila){
  
  printf("O aluno com matricula %i está saindo da biblioteca!\n", aluno->numMatricula);
  if(remAluno_NOrd(aluno->numMatricula, lista->lista, &lista->tam)){
    printf("O aluno saiu da biblioteca!");
    if((lista->tam == lista->cap-1) && (fila->ini != fila->fim)){
      lista->tam += 1;
      lista->lista[lista->tam] = fila->fila[fila->ini];
      printf("\nO aluno com matricula %i esta saindo da fila e entrando na biblioteca!", fila->fila[fila->ini].numMatricula);
      if(removeDaFila(aluno, fila)){
        printf("\nO aluno entrou na Biblioteca!");
      }else{
        printf("\nO aluno não entrou na biblioteca!");
      }
    }
  }else{
    printf("\nO aluno não saiu da biblioteca!");
  }
  
}

void segregAlunos(TListAlunos *lista,TPilhaAlunos *calouros, TFilaAlunos *veteranos){

  printf("Velha Lista\n");
  printLista(lista->lista ,lista->tam);
  
  int tamLista = lista->tam;
  int tamFila;
  int tamPilha;
  
  for(int i = 0; i < tamLista; i++){
    //printf("%i - %i\n", lista->lista[i].numMatricula, lista->tam);
    if(lista->lista[i].numMatricula >= 202000000){
      empilharAluno(lista->lista[i], calouros);
      remAluno_NOrd(lista->lista[i].numMatricula, &lista->lista[i], &lista->tam);
    }else{
      insereNaFila(lista->lista[i], veteranos);
      remAluno_NOrd(lista->lista[i].numMatricula, &lista->lista[i], &lista->tam);
    }
  }

  printf("\nPilha de Calouros\n");
  printPilha(calouros->pilha, calouros->topo);
  printf("\nFila de Veteranos\n");
  printFila(*veteranos);
  
  tamFila = veteranos->fim - veteranos->ini;
  for(int i = 0; i < tamFila; i++){
    lista->lista[lista->tam] = veteranos->fila[veteranos->ini];
    removeDaFila(lista->lista, veteranos);
    lista->tam += 1;
  }

  tamPilha = calouros->topo;
  for(int i = 0; i < tamPilha; i++){
    lista->lista[lista->tam] = *calouros->pilha;
    desempilharALuno(&lista->lista[lista->tam], calouros);
    lista->tam += 1;
  }

  printf("\n\nNova Lista\n");
  printLista(lista->lista ,lista->tam);
  
}

/*Função criada para o exercício 6, usada para realizar o sorteio e a distribuição dos alunos nas etapas*/
void ordemEtapas(TListAlunos* etapa1, TListAlunos* etapa1b, TPilhaAlunos* etapa2, TFilaAlunos* etapa3){

  int pos; //variável usada para decidir armazenar o número gerado aleatoriamente que será a posição da listas
  TAluno aux; //variável usada para armazenar os alunos desempilhados/retirados da fila e atribuir a lista/pilha

  printf("\nAlunos que irão realizar as etapas:\n");
  printLista(etapa1->lista, etapa1->tam); //printando a lista inicial dos alunos
  
  for(int i = 0; i < LSIZE; i++){ //for usado para transferir os alunos aleatorios da lista para a pilha
    pos = rand()%etapa1->tam; //escolhendo uma posição aleatoria
    if(empilharAluno(etapa1->lista[pos], etapa2)){ //empilhando aluno de uma posição aleatoria na pilha, se retornar true, executa o if abaixo
      if(!(remAluno_NOrd(etapa1->lista[pos].numMatricula, etapa1->lista, &etapa1->tam))){
        printf("ERRO!"); //Se a condição acima for cumprida, executa a função que remove o aluno da lista
      }
    }else{
      printf("ERRO!");
    }
  }

  printf("\nOrdem dos alunos que terminaram a etapa 1:\n");
  printPilha(etapa2->pilha, etapa2->topo); //printando a pilha de alunos
  
  do{ //laço de repetição para transferir os alunos da pilha para a fila
    desempilharALuno(&aux, etapa2); 
    insereNaFila(aux,etapa3);
  }while(etapa2->topo >0);
  
  printf("\nOrdem dos alunos que irão escolher os temas da atividade pratica: \n");
  printFila(*etapa3); //printando a fila de alunos

  do{ //laço de repetição para o primeiro da fila escolher aleatoriamente um tema que no caso é representado 
      //por uma posição na lista, assim sendo, essa posição fica preenchida, ficando indisponivel para outra escolha
    pos = rand()%LSIZE; //escolhendo uma posição aleatoria
    if(etapa1b->lista[pos].numMatricula == 0){ //verificando se nessa posição da lista não existe outro aluno
      removeDaFila(&aux, etapa3); //se não houver aluno na lista, é primeiro aluno da fila é removido e seus dados guardados na variavel aux
      etapa1b->lista[pos] = aux; //é copiado as informações do aluno para dentro da lista na posição gerada anteriormente
      etapa1b->tam++; //o tamanha da lista é aumentado
    }
  }while(etapa3->ini != etapa3->fim);//ira executar até a fila ficar vazia

  printf("\n\nOrdem da apresentação da atividade pratica: \n");
  
  printLista(etapa1b->lista, etapa1b->tam);//printando a ordem da atividade pratica
}
