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
    int trocas = 0, comp = 0;
    for(int i = 0; i < tam-1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(lista[j].numMatricula > lista[j+1].numMatricula) 
            {
                bolha = lista[j];
                lista[j]=lista[j+1];
                lista[j+1] = bolha;
                trocas++;
            }
            comp ++;
        }
    }
    printf("Parou na iteração %d de %d\n", tam - 2, tam - 2);
    printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);
}

void ordenaListaBolhaShort(TAluno lista[], int tam){
    TAluno bolha;
    int trocou, trocas = 0, comp = 0;
    for(int i = 0; i < tam-1; i++){
        //bolha = lista[0];
        trocou = FALSE; 
        for(int j = 0; j < tam - i - 1; j++){
            if(lista[j].numMatricula > lista[j+1].numMatricula) 
            {
                bolha = lista[j];
                lista[j]=lista[j+1];
                lista[j+1] = bolha;
                trocou = TRUE;
                trocas++;
            }
            comp++;
        }
        if (!trocou){
            printf("Parou na iteração %d de %d\n", i, tam - 2);
            printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);
            break;
        }
    }
    if (trocou){
            printf("Parou na iteração %d de %d\n", tam - 2, tam - 2);
            printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);        
    }
}

void ordenaListaBolhaShortPlus(TAluno lista[], int tam){
    TAluno bolha;
    int trocou, trocas = 0, comp = 0;
    for(int i = 0; i < tam-1; i++){
        trocou = FALSE; 
        for(int j = i; j < tam - i - 1; j++){
            if(lista[j].numMatricula > lista[j+1].numMatricula) 
            {
                bolha = lista[j];
                lista[j]=lista[j+1];
                lista[j+1] = bolha;
                trocou = TRUE;
                trocas++;
            }
            comp++;
        }
        if (!trocou){
            printf("Parou na iteração %d de %d\n", i, tam - 2);
            printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);
            break;
        }
        trocou = FALSE;
        for(int j = tam - i - 2; j > i; j--){
            if(lista[j].numMatricula < lista[j-1].numMatricula) 
            {
                bolha = lista[j];
                lista[j]=lista[j-1];
                lista[j-1] = bolha;
                trocou = TRUE;
                trocas++;
            }
            comp++;
        }
        if (!trocou){
            printf("Parou na iteração %d de %d\n", i, tam - 2);
            printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);
            break;
        }
    }
    if (trocou){
        printf("Parou na iteração %d de %d\n", tam - 2, tam - 2);
        printf("Foram %d trocas e %d comparações\n", 3*trocas, comp);
    } 

}

void ordenaLista(TListAlunos *lista)
{
    if (!lista->eOrd){
        //ordenaListaBolha(lista->lista, lista->tam);
        //ordenaListaBolhaShort(lista->lista, lista->tam);
        ordenaListaBolhaShortPlus(lista->lista, lista->tam);
        //ordenaListaShell(lista->lista, lista->tam);
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

// Cria um ponteiro para o TNoAluno
PRaizArvAluno iniArvAluno(void)
{
	PRaizArvAluno no;  								
    no = (PRaizArvAluno) malloc(sizeof(TRaizArvAluno)); 	
	no->esq = NULL;
	no->dir = NULL;					
	return no;
}

PRaizArvAluno criarArvoreDeLista(TListAlunos listaS){
    PRaizArvAluno raiz = iniArvAluno();
    PRaizArvAluno no = raiz;
    if(listaS.tam > 0)
        raiz->aluno = listaS.lista[0];
    for(int i = 1; i < listaS.tam; i++){
        do{
            int dir = rand()%2; //escolhe uma direção
            if(dir == 1){ // se for a direita
                if(no->dir != NULL) // se tiver um nó na direita
                    no = no->dir; // pula para o nó a direita
                else{ // se não
                    no->dir = iniArvAluno(); // cria um nó a direita
                    no = no->dir; // pula para o nó a direita
                    // copia o aluno da lista no novo nó
                    no->aluno = listaS.lista[i];
                    break; // saindo do loop interno (do)
                }
            }else{ // se não então é esquerda
                if(no->esq != NULL) // se tiver um nó na esquerda
                    no = no->esq; // pula para o nó a esquerda
                else{ // se não
                    no->esq = iniArvAluno();  // cria um nó a esquerda
                    no = no->esq; // pula para o nó a esquerda
                    // copia o aluno da lista no novo nó
                    no->aluno = listaS.lista[i];
                    break; // saindo do loop interno (do)
                }
            }
        }while(1); // loop interno
        no = raiz; // volta para o nó raiz e vamos inserir o próximo
    }
    return raiz;
}


PRaizArvAluno criarArvoreDeLista_C(TListAlunos listaS){
    PRaizArvAluno raiz = iniArvAluno();
    PRaizArvAluno no = raiz;
    if(listaS.tam > 0){
        raiz->aluno = listaS.lista[0];
        printf("Raiz: %d\n", raiz->aluno.numMatricula);
    }
    for(int i = 1; i < listaS.tam; i++){
        printf("Começando pelo nó Raiz: \n");
        int j = 1;
        do{
            int dir = rand()%2; //escolhe uma direção
            if(dir == 1){ // se for a direita
                if(no->dir != NULL){ // se tiver um nó na direita
                    printf("%d - pula para nó da direita; \n", j++);
                    no = no->dir; // pula para o nó a direita
                }else{ // se não
                    no->dir = iniArvAluno(); // cria um nó a direita
                    no = no->dir; // pula para o nó a direita
                    // copia o aluno da lista no novo nó
                    no->aluno = listaS.lista[i];
                    printf("%d - aloca nó na direita para %d; \n", j++, no->aluno.numMatricula);
                    break; // saindo do loop interno (do)
                }
            }else{ // se não então é esquerda
                if(no->esq != NULL){ // se tiver um nó na esquerda
                    printf("%d - pula para nó da esquerda; \n", j++);
                    no = no->esq; // pula para o nó a esquerda
                }else{ // se não
                    no->esq = iniArvAluno();  // cria um nó a esquerda
                    no = no->esq; // pula para o nó a esquerda
                    // copia o aluno da lista no novo nó
                    no->aluno = listaS.lista[i];
                    printf("%d - aloca nó na esquerda para %d; \n", j++, no->aluno.numMatricula);
                    break; // saindo do loop interno (do)
                }
            }
        }while(1); // loop interno
        printf("Volta para o nó raiz\n");
        no = raiz; // volta para o nó raiz e vamos inserir o próximo
    }
    return raiz;
}

PRaizArvAluno incAlunoNaArv(TAluno aluno, PRaizArvAluno raiz)
{
    if(raiz == NULL){
        raiz = iniArvAluno();
        raiz->aluno = aluno;
    }else{
        int dir = rand()%2; //escolhe uma direção
        if(dir == 1) // se for a direita
            raiz->dir =  incAlunoNaArv(aluno, raiz->dir); // inclui na sub-arv da direita
        else // se não então é esquerda
            raiz->esq =  incAlunoNaArv(aluno, raiz->esq); // inclui na sub-arv da direita
    }
    return raiz;
}

PRaizArvAluno incAlunoNaArvOrd(TAluno aluno, PRaizArvAluno raiz)
{
    if(raiz == NULL){
        raiz = iniArvAluno();
        raiz->aluno = aluno;
    }else{
        int dir = (aluno.numMatricula > raiz->aluno.numMatricula);
        if(dir == 1) // se for a direita
            raiz->dir =  incAlunoNaArvOrd(aluno, raiz->dir); // inclui na sub-arv da direita
        else // se não então é esquerda
            raiz->esq =  incAlunoNaArvOrd(aluno, raiz->esq); // inclui na sub-arv da direita
    }
    return raiz;
}

PRaizArvAluno criarArvoreDeLista_(TListAlunos listaS){
    PRaizArvAluno raiz = NULL;
    for(int i = 0; i < listaS.tam; i++)
        raiz = incAlunoNaArvOrd(listaS.lista[i], raiz);
    return raiz;
}

void printArvore(PRaizArvAluno raiz, int modo)
{
  
    if(raiz != NULL)
        switch (modo){
        case 0:
            printf("[ %d, ", raiz->aluno.numMatricula);
		    printf("%s, ", raiz->aluno.nome);
		    printf("%s ] ;\n ", raiz->aluno.email);
            printArvore(raiz->esq, modo);
            printArvore(raiz->dir, modo);
            break;
        case 1:
            printArvore(raiz->esq, modo);
            printf("[ %d, ", raiz->aluno.numMatricula);
		    printf("%s, ", raiz->aluno.nome);
		    printf("%s ] ;\n ", raiz->aluno.email);
            printArvore(raiz->dir, modo);
            break;
        case 2:
            printArvore(raiz->esq, modo);
            printArvore(raiz->dir, modo);
            printf("[ %d, ", raiz->aluno.numMatricula);
		    printf("%s, ", raiz->aluno.nome);
		    printf("%s ] ;\n ", raiz->aluno.email);
            break;
        }
	else
        printf("[ ]\n");
}


PRaizArvAlunoAVL iniArvAlunoAVL(void)
{
	PRaizArvAlunoAVL no;  								
    no = (PRaizArvAlunoAVL) malloc(sizeof(TRaizArvAlunoAVL)); 	
    if(no)
    {
        no->esq = NULL;
	    no->dir = NULL;					
        no->altura = 0;
    }
    else
        printf("\nERRO criando um novo nó!!!!!\n");
	return no;
}

short alturaDoNoAVL(PRaizArvAlunoAVL no)
{
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

short balanceamento(PRaizArvAlunoAVL no)
{
    if(no)
        return (alturaDoNoAVL(no->esq) - alturaDoNoAVL(no->dir));
    else
        return 0;
}

PRaizArvAlunoAVL rotaEsquerda(PRaizArvAlunoAVL raiz)
{
    PRaizArvAlunoAVL dir, esqDodir;
    dir = raiz->dir;
    esqDodir = dir->esq;

    dir->esq = raiz;
    raiz->dir = esqDodir;
    short a = alturaDoNoAVL(raiz->esq);
    short b = alturaDoNoAVL(raiz->dir);
    raiz->altura = ((a > b) ? a : b) + 1;
    a = alturaDoNoAVL(dir->esq); 
    b = alturaDoNoAVL(dir->dir);
    dir->altura = ((a > b) ? a : b) + 1;
    return dir;
}

PRaizArvAlunoAVL rotaDireita(PRaizArvAlunoAVL raiz)
{
    PRaizArvAlunoAVL esq, dirDoesq;
    esq = raiz->esq;
    dirDoesq = esq->dir;

    esq->dir = raiz;
    raiz->esq = dirDoesq;
    short a = alturaDoNoAVL(raiz->esq); 
    short b = alturaDoNoAVL(raiz->dir);
    raiz->altura = ((a > b) ? a : b) + 1;
    a = alturaDoNoAVL(esq->esq); 
    b = alturaDoNoAVL(esq->dir);
    esq->altura = ((a > b) ? a : b) + 1;
    return esq;
}

PRaizArvAlunoAVL rotaDirEsq(PRaizArvAlunoAVL raiz)
{
    raiz->dir = rotaDireita(raiz->dir);
    return rotaEsquerda(raiz);
}

PRaizArvAlunoAVL rotaEsqDir(PRaizArvAlunoAVL raiz)
{
    raiz->esq = rotaEsquerda(raiz->esq);
    return rotaDireita(raiz);
}

PRaizArvAlunoAVL incAlunoNaArvAVL(TAluno aluno, PRaizArvAlunoAVL raiz)
{
    if(raiz == NULL){
        raiz = iniArvAlunoAVL();
        raiz->aluno = aluno;
    }else{
        if (aluno.numMatricula != raiz->aluno.numMatricula){
            int dir = (aluno.numMatricula > raiz->aluno.numMatricula);
            if(dir == 1) // se for a direita
                raiz->dir =  incAlunoNaArvAVL(aluno, raiz->dir); // inclui na sub-arv da direita
            else // se não então é esquerda
                raiz->esq =  incAlunoNaArvAVL(aluno, raiz->esq); // inclui na sub-arv da direita
        }
    }
    short a = alturaDoNoAVL(raiz->esq); 
    short b = alturaDoNoAVL(raiz->dir);
    raiz->altura = ((a > b) ? a : b) + 1;
    raiz = balancear(raiz);
    return raiz;
}

PRaizArvAlunoAVL balancear(PRaizArvAlunoAVL raiz)
{
    short fb = balanceamento(raiz);
    short fb_dir = balanceamento(raiz->dir);
    short fb_esq = balanceamento(raiz->esq);
    if(fb < -1 && fb_dir <= 0)
        raiz = rotaEsquerda(raiz);
    else if (fb > 1 && fb_esq >= 0)
        raiz = rotaDireita(raiz);
    else if (fb > 1 && fb_esq < 0)
        raiz = rotaEsqDir(raiz);
    else if(fb < -1 && fb_dir > 0)
        raiz = rotaDirEsq(raiz);
    return raiz;
}

PRaizArvAluno buscaArvSimples(PRaizArvAluno raiz, int chave){
  PRaizArvAluno aux;
  if(raiz == NULL){
      printf("A arvore não existe\n");
      return NULL;
  }
  
  if(raiz->aluno.numMatricula == chave){
    printf("\n\nA matricula foi Encontrada!!!\n\n");
    printf("Matricula: %i\nNome:%s\nEmail:%s", raiz->aluno.numMatricula, raiz->aluno.nome, raiz->aluno.email);
    return raiz;
  }
  
  if(raiz->dir != NULL){
    aux = buscaArvSimples(raiz->dir, chave);
  }
  if(raiz->esq != NULL){
    aux = buscaArvSimples(raiz->esq, chave);
  }

  if(aux->aluno.numMatricula == chave){
  return aux;
  }
  else{
    strcpy(aux->aluno.email, "");
    strcpy(aux->aluno.nome, "");
    aux->aluno.numMatricula = 0;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
  }
    

};

/*
PRaizArvAluno buscaArvSimplesPai(PRaizArvAluno raiz, int chave){
  PRaizArvAluno aux;
  if(raiz == NULL){
      printf("A arvore não existe\n");
      return NULL;
  }
  
  if(raiz->aluno.numMatricula == chave){
    printf("\n\nA matricula foi Encontrada!!!\n\n");
    return raiz;
  }
  
  if(raiz->dir != NULL){
    aux = buscaArvSimples(raiz->dir, chave);
  }
  if(raiz->esq != NULL){
    aux = buscaArvSimples(raiz->esq, chave);
  }

  if(aux->aluno.numMatricula == chave){
  return aux;
  }
  else{
    strcpy(aux->aluno.email, "");
    strcpy(aux->aluno.nome, "");
    aux->aluno.numMatricula = 0;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
  }
};*/

PRaizArvAluno buscaArvBinaria(PRaizArvAluno raiz, int chave){
  
    if(raiz == NULL){
      printf("A arvore não existe");
      return NULL;
    }
  
    if(raiz->aluno.numMatricula == chave){
      return raiz;
    }
    else if(chave>raiz->aluno.numMatricula && raiz->dir != NULL){
      printf("Direita de %d: %d\n", raiz->aluno.numMatricula, raiz->dir->aluno.numMatricula);
        return buscaArvBinaria(raiz->dir, chave);
    }
    else if(chave<raiz->aluno.numMatricula && raiz->esq != NULL){
        printf("Esquerda de %d: %d\n", raiz->aluno.numMatricula, raiz->esq->aluno.numMatricula);
        return buscaArvBinaria(raiz->esq, chave);
    }
    else{
      printf("O aluno não foi encontrado!");
      return raiz;
    }
  
};


PRaizArvAluno removerRec(PRaizArvAluno raiz, int chave) {
   PRaizArvAluno aux, Filho_dir;
    if(raiz == NULL){
      printf("Elemento nao encontrado!");
    }
    else{
      if(raiz->aluno.numMatricula == chave){ //Apagar Raiz
        if(raiz->esq == raiz->dir){
          free(raiz);
          return NULL;
          printf("[1]");
        }
        else
          if(raiz->esq == NULL && raiz->dir != NULL){ // So tem filho a direita
            aux = raiz->esq;
            free(raiz);
            return aux;
            printf("[2]");
          }
          else
            if(raiz->dir == NULL&& raiz->esq != NULL ){ // So tem filho a esquerda
              aux = raiz->dir;
              free(raiz);
              return aux;
              printf("[3]");
            }
            else{
              Filho_dir = raiz->dir;
              aux = Filho_dir;
              while(aux->esq)               
                  aux = aux->esq;
              aux->esq = raiz->esq;
              free(raiz);
              return Filho_dir;
              printf("[4]");
            }
          
        
      }
      if(raiz->aluno.numMatricula < chave){
        raiz->dir = removerRec(raiz->dir,chave);
      }
      else{
        raiz->esq = removerRec(raiz->esq,chave);
      }
      return(raiz);      
    }
}


PRaizArvAlunoAVL criarArvoreAVLDeLista(TListAlunos listaS){
  PRaizArvAlunoAVL raiz = NULL;
    for(int i = 0; i < listaS.tam; i++)
        raiz = incAlunoNaArvAVL(listaS.lista[i], raiz);
    return raiz;
}




/*
[ 
 200420513, Aluno_200420513, 200420513@uesc.br; raiz
 200710753, Aluno_200710753, 200710753@uesc.br;
 200420314, Aluno_200420314, 200420314@uesc.br;
 200420766, Aluno_200420766, 200420766@uesc.br;
 201220418, Aluno_201220418, 201220418@uesc.br;
 202020949, Aluno_202020949, 202020949@uesc.br;
 201520109, Aluno_201520109, 201520109@uesc.br;
 200220412, Aluno_200220412, 200220412@uesc.br;
 200920719, Aluno_200920719, 200920719@uesc.br;
 201520186, Aluno_201520186, 201520186@uesc.br;
  ]
[ 200420513, Aluno_200420513, 200420513@uesc.br ] ;
 [ 200420766, Aluno_200420766, 200420766@uesc.br ] ;
 [ 201220418, Aluno_201220418, 201220418@uesc.br ] ;
 [ ]
[ 202020949, Aluno_202020949, 202020949@uesc.br ] ;
 [ ]
[ ]
[ ]
[ 200710753, Aluno_200710753, 200710753@uesc.br ] ;
 [ 201520109, Aluno_201520109, 201520109@uesc.br ] ;
 [ 200220412, Aluno_200220412, 200220412@uesc.br ] ;
 [ ]
[ 201520186, Aluno_201520186, 201520186@uesc.br ] ;
 [ ]
[ ]
[ ]
[ 200420314, Aluno_200420314, 200420314@uesc.br ] ;
 [ ]
[ 200920719, Aluno_200920719, 200920719@uesc.br ] ;
 [ ]
[ ]
*/

/*
[ 
 200420513, Aluno_200420513, 200420513@uesc.br;
 200710753, Aluno_200710753, 200710753@uesc.br;
 200420314, Aluno_200420314, 200420314@uesc.br;
 200420766, Aluno_200420766, 200420766@uesc.br;
 201220418, Aluno_201220418, 201220418@uesc.br;
 202020949, Aluno_202020949, 202020949@uesc.br;
 201520109, Aluno_201520109, 201520109@uesc.br;
 200220412, Aluno_200220412, 200220412@uesc.br;
 200920719, Aluno_200920719, 200920719@uesc.br;
 201520186, Aluno_201520186, 201520186@uesc.br;
  ]
[ ]
[ 201220418, Aluno_201220418, 201220418@uesc.br ] ;
 [ ]
[ 202020949, Aluno_202020949, 202020949@uesc.br ] ;
 [ ]
[ 200420766, Aluno_200420766, 200420766@uesc.br ] ;
 [ ]
[ 200420513, Aluno_200420513, 200420513@uesc.br ] ;
 [ ]
[ 200220412, Aluno_200220412, 200220412@uesc.br ] ;
 [ ]
[ 201520186, Aluno_201520186, 201520186@uesc.br ] ;
 [ ]
[ 201520109, Aluno_201520109, 201520109@uesc.br ] ;
 [ ]
[ 200710753, Aluno_200710753, 200710753@uesc.br ] ;
 [ ]
[ 200420314, Aluno_200420314, 200420314@uesc.br ] ;
 [ ]
[ 200920719, Aluno_200920719, 200920719@uesc.br ] ;
 [ ]
*/

/*
[ 
 200420513, Aluno_200420513, 200420513@uesc.br;
 200710753, Aluno_200710753, 200710753@uesc.br;
 200420314, Aluno_200420314, 200420314@uesc.br;
 200420766, Aluno_200420766, 200420766@uesc.br;
 201220418, Aluno_201220418, 201220418@uesc.br;
 202020949, Aluno_202020949, 202020949@uesc.br;
 201520109, Aluno_201520109, 201520109@uesc.br;
 200220412, Aluno_200220412, 200220412@uesc.br;
 200920719, Aluno_200920719, 200920719@uesc.br;
 201520186, Aluno_201520186, 201520186@uesc.br;
  ]
[ ]
[ 200920719, Aluno_200920719, 200920719@uesc.br ] ;
 [ ]
[ 200420314, Aluno_200420314, 200420314@uesc.br ] ;
 [ ]
[ 200710753, Aluno_200710753, 200710753@uesc.br ] ;
 [ ]
[ 201520109, Aluno_201520109, 201520109@uesc.br ] ;
 [ ]
[ 201520186, Aluno_201520186, 201520186@uesc.br ] ;
 [ ]
[ 200220412, Aluno_200220412, 200220412@uesc.br ] ;
 [ ]
[ 200420513, Aluno_200420513, 200420513@uesc.br ] ;
 [ ]
[ 200420766, Aluno_200420766, 200420766@uesc.br ] ;
 [ ]
[ 202020949, Aluno_202020949, 202020949@uesc.br ] ;
 [ ]
[ 201220418, Aluno_201220418, 201220418@uesc.br ] ;
 [ ]
*/
