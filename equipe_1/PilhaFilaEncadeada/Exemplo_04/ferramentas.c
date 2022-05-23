#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

// Manipula��o de listas n�o ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave)
{
    // Copiando a chave para a posi��o tam (fora da lista)
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

// Manipula��o de listas ordenadas
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
        a capacidade da lista de sa�da se calcula como a soma
        do tamanho da listaA e o tamanho da lista B.
    */
    int cap = listaA->tam + listaB->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de sa�da ser� igual a tipo da listaA
    */
    int eOrd = listaA->eOrd;
    TListAlunos *listaC = iniListAlunos(cap, eOrd);
    // colocando todos os elementos de A em C
    for (int i = 0; i < listaA->tam; i++)
        listaC->lista[i] = listaA->lista[i];
    listaC->tam = listaA->tam;
    // colocando os elementos de B que n�o est�o em A
    for (int i = 0; i < listaB->tam; i++)
        incAlunoNaLista(listaB->lista[i], listaC);
    return listaC;
}

TListAlunos* diferenListas(TListAlunos *listaA, TListAlunos *listaB)
{

    // a capacidade da lista de sa�da � o tamanho da listaA.
    int cap = listaA->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de sa�da ser� igual a tipo da listaA
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
        a capacidade da lista de sa�da � o menor valor entre
        o tamanho da listaA e da listaB.
    */
    int cap = (listaA->tam < listaB->tam) ? listaA->tam:listaB->tam;
    /*
        caso as listas de entrada seja de tipos diferentes a
        lista de sa�da ser� igual a tipo da listaA
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
            printf("Parou na itera��o %d de %d\n", i, tam - 2);
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
            printf("Parou na itera��o %d de %d\n", i, tam - 2);
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
            printf("Parou no retorno da itera��o %d de %d\n", i, tam - 2);
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
    srand(time(NULL));

    TListAlunos *lista = iniListAlunos(cap, eOrd);
    TAluno aluno;
    if (tam > cap)
        tam = cap;
    for (int i = 0; i < tam;)
    {
        // Ano 2000 a 2022 * 100000, ex. 20aa00000
        aluno.numMatricula = (2000 + (rand() % 22)) * 100000;
        // Semestre 1 a 2 * 10000, ex. 20aas0000
        aluno.numMatricula += ((rand() % 2) + 1) * 10000;
        while(aluno.numMatricula/10000 > 20211){
            aluno.numMatricula = (2020 + (rand() % 2)) * 100000;
            aluno.numMatricula += ((rand() % 2) + 1) * 10000;
        }
        // Numero sequencial 1 a 999, ex. 20aasxxxx
        aluno.numMatricula += (rand() % 999) + 1;
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
int desempilharALuno(TAluno *aluno, TPilhaAlunos *pilha) // pop
{
    if (pilha->topo > 0)
    {
        pilha->topo--;
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

void iniFilaAlunos(TFilaAlunos *fila, int cap)
{
    fila->cap = cap;
    fila->ini = 0;
    fila->fim = 0;
    fila->tam = 0;
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
        fila->tam++;
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
        fila->tam--;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void printFila(TFilaAlunos* fila){
    int aux = fila->ini;
    printf("[ \n ");
    {
        for(int i = 0; i < fila->tam; i++){
            printf("%d, ", fila->fila[aux].numMatricula);
            printf("%s, ", fila->fila[aux].nome);
            printf("%s;\n ", fila->fila[aux].email);
            aux++;
        }
    }
    printf(" ]\n");
}

void colocaPilhaFila(TListAlunos* alunos, TPilhaAlunos* palunos, TFilaAlunos* falunos, int DATA){
    TAluno aux;
    for(int i = 0; i < LSIZE; i++){ //Vou percorrer a lista inteira
        if((alunos->lista[i].numMatricula / 10000) == DATA) //Verifico se o aluno � calouro
            empilharAluno(alunos->lista[i], palunos); //Se for calouro eu empilho
        else
            insereNaFila(alunos->lista[i], falunos); //Se n�o for eu coloco na fila
    }

    for(int i = 0; i < LSIZE; i++){ //Removo todos os elementos da minha lista
        remAlunoDaLista(palunos->pilha[i], alunos);
        remAlunoDaLista(falunos->fila[i], alunos);
    }

    while(falunos->tam > 0){ //Percorro a fila inteira
        removeDaFila(&aux, falunos); //Removo da fila
        incAlunoNaLista(aux, alunos); //Adiciono na lista
    }

    while(palunos->topo > 0){ //Percorro a pilha inteira
        desempilharALuno(&aux, palunos); //Removo da pilha
        incAlunoNaLista(aux, alunos); //Adiciono na lista
    }
}

//Pilha Encadeada

void iniPilhaEncAlunos(TPilhaEncAlunos* pilha){
    pilha->topo = NULL; //Para iniciar uma pilha encadeada basta apontar o topo da pilha para NULL
}

int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha){

    PNoAluno aux = (PNoAluno)malloc(sizeof(TNoAluno)); //Aloco o espa�o de um PNoAluno em uma variavel auxiliar do tipo PNoAluno

    if(aux == NULL){  //Verifico se a aloca��o foi bem sucedida
        printf("ERRO DE ALOCA��O!!");
        return FALSE;
    }

    aux->numMatricula = aluno.numMatricula; //Passo os dados recebidos para o no
    strcpy(aux->nome, aluno.nome);
    strcpy(aux->email, aluno.email);

    aux->prox = pilha->topo; //No aponta pro topo da pilha
    pilha->topo = aux; //Antigo topo agora aponta pro meu novo no

    return TRUE;
}

int desempilharALunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha){
    PNoAluno aux = pilha->topo; //Auxiliar recebe o topo da minha pilha

    if(aux == NULL){ //Verifico se o topo esta vazio
        //printf("Pilha vazia!!!");
        return FALSE;
    }


    pilha->topo = aux->prox; // Topo aponta para o proximo no

    aluno->numMatricula = aux->numMatricula; //Passo os dados do no para um TAluno
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);

    free(aux); //Libero o no

    return TRUE;
}

void liberaPilha(TPilhaEncAlunos* pilha){
    TAluno aluno;

    while(desempilharALunoEnc(&aluno, pilha)); //Desempilho at� a pilha ficar vazia
}

void imprimePilha(TPilhaEncAlunos* pilha){
    PNoAluno aux = pilha->topo;

    if(aux == NULL){
        printf("Pilha vazia!!\n");
        return;
    }

    printf("[\n");
    while(aux != NULL){
        printf("%d, %s, %s\n", aux->numMatricula, aux->nome, aux->email);
        aux = aux->prox;
    }
    printf("]\n");
}

void iniFilaAlunosEnc(TFilaEncAlunos* fila){
    fila->head = NULL;
    fila->tail = NULL;
}

int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos* fila){

    PNoAluno aux = (PNoAluno)malloc(sizeof(TNoAluno)); //Aloco o espa�o de um PNoAluno em uma variavel auxiliar do tipo PNoAluno

    if(aux == NULL){  //Verifico se a aloca��o foi bem sucedida
        printf("ERRO DE ALOCA��O!!");
        return FALSE;
    }

    aux->numMatricula = aluno.numMatricula; //Passo os dados recebidos para o no
    strcpy(aux->nome, aluno.nome);
    strcpy(aux->email, aluno.email);

    aux->prox = NULL; //Aponto o ultimo elemento para NULL

    if(fila->head == NULL){ //Verifico se � o primeiro elemento da fila a ser inserido
        fila->head = aux; //Se for o Head aponta pra ele
    }
    else{
        fila->tail->prox = aux; //Sen�o o proximo elemento do tail aponta pra ele
    }

    fila->tail = aux; //E o tail aponta pra ele tambem

    return TRUE;
}

int removeDaFilaEnc(TAluno* aluno, TFilaEncAlunos* fila){
    PNoAluno aux = fila->head;

    if(aux == NULL){
        printf("FILA VAZIA!!");
        return FALSE;
    }

    fila->head = aux->prox;

    aluno->numMatricula = aux->numMatricula; //Passo os dados do no para um TAluno
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);

    free(aux);

    return TRUE;
}

void imprimeFila(TFilaEncAlunos* fila){
    PNoAluno aux = fila->head;

    if(aux == NULL){
        printf("FILA VAZIA!!");
        return;
    }

    printf("[\n");
    while(aux != NULL){
        printf("%d, %s, %s\n", aux->numMatricula, aux->nome, aux->email);
        aux = aux->prox;
    }
    printf("]\n");
}

void liberaFila(TFilaEncAlunos* fila){
    TAluno aluno;
    while(removeDaFilaEnc(&aluno, fila));
}
