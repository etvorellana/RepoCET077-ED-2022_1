#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int buscaChaveNaLista(int chave, TListAlunos *lista){

    /*
        Procurar uma chave na lista e retornar o índice
        no array em que a chave se encontra ou a posição em
        que um elemento com esta chave deveria ser incluído
        na lista. Lembre que as listas não possuem elementos
        com chave repetida.  
    */
   if(lista->eOrd){
        return buscaAluno_Ord(lista->lista, &lista->tam, chave);
   }else{
        return buscaAluno_NOrd(lista->lista, &lista->tam, chave);

   }

}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista){
    /*
        Incluir um aluno na lista. A função retorna 
        verdadeiro se o item for incluído e falso 
        caso contrario. Um novo item não podera ser
        incluído na lista se já tiver um outro item
        nela com a mesma chave ou se a lista estiver 
        cheia. 
    */
   if(lista->eOrd){
        return incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap);
   }else{
        return incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap);
   }
}

int remAlunoDaLista(TAluno aluno, TListAlunos *lista){
    /*
        Remover um aluno na lista. A função retorna 
        verdadeiro se o item for removido e falso 
        caso contrario. Um novo item não podera ser
        removido da lista se não tiver um item
        nela com a chave do aluno que se deseja remover 
        ou se a lista estiver vazia. 
    */
   if(lista->eOrd){
        return remAluno_Ord(aluno.numMatricula, &lista->lista, lista->tam);
   }else{
        return remAluno_NOrd(aluno.numMatricula, &lista->lista, lista->tam);

   }
}

TListAlunos* uniListas(TListAlunos *listaA, TListAlunos *listaB){
    /*
        Retorna uma nova lista formada pela união das duas
        listas (listaA e listaB). A nova lista deverá ser
        do mesmo tipo das listas de entrada (ordenada ou
        não ordenada) caso as duas listas sejam do mesmo 
        tipo. Escolha como definir o tipo da lista de saída
        caso as listas de entrada seja de tipos diferentes. 
        Como discutido em sala de aula, a capacidade da 
        lista de saída se calcula como a soma do tamanho da
        listaA e o tamanho da lista B. 
    */
    //criar uma nova lista com tamanho e cap = tamanho Lista A + tamanho Lista B
    // juntar elementos Lista A + elementos Lista B
    int tam = listaA->tam + listaB->tam;
    int eOrd = FALSE;
    if (listaA->eOrd == listaB->eOrd) {
        eOrd = listaA->eOrd;
    }
    TListAlunos* resultado = iniListAlunos(tam, eOrd);
    int i;
    for (i = 0; i < listaA->tam; i++) {
        resultado->lista[i] = listaA->lista[i];
    }
    for (i = 0; i < listaB->tam; i++) {
        if (eOrd) {
            incAluno_Ord(listaB->lista[i], resultado->lista, &resultado->tam, resultado->cap);
        } else {
            incAluno_NOrd(listaB->lista[i], resultado->lista, &resultado->tam, resultado->cap);
        }
    }
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
	printf("]\n");
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
int empilharAluno2(TAluno* aluno, TPilhaAlunos *pilha) // push
{
    if (pilha->topo < pilha->cap)
    {
        pilha->pilha[pilha->topo].numMatricula = aluno->numMatricula;
        strcpy(pilha->pilha[pilha->topo].nome, aluno->nome);
        strcpy(pilha->pilha[pilha->topo].email, aluno->email);
        pilha->topo++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int empilharListaAlunos(TAluno lista[], TPilhaAlunos *pilha, int tam){
    for(int i = 0; i < tam; i++ ){
        empilharAluno(lista[i], pilha);
    }
}

TAluno desempilharALuno(TPilhaAlunos *pilha) // pop
{
    
    TAluno aluno;

    if (pilha->topo > 0)
    {
        pilha->topo--;
        aluno.numMatricula = pilha->pilha[pilha->topo].numMatricula;
        strcpy(aluno.nome, pilha->pilha[pilha->topo].nome);
        strcpy(aluno.email, pilha->pilha[pilha->topo].email);
        return aluno;
    }
    return aluno;
}

void desempilharALunoNovaPilha(int chave, TPilhaAlunos *pilha) // pop
{
    int i=pilha->topo;

    TPilhaAlunos pilhaAux;

    iniPilhaAlunos(&pilhaAux, pilha->cap);

    while(pilha->topo > 0){
        i--;
        pilha->topo--;
        if(chave != pilha[0].pilha[i].numMatricula){
            empilharAluno2(&pilha->pilha[i], &pilhaAux);
        }else{
            break;
        }
    }
    tranferirPilha(&pilhaAux, pilha);
}

void tranferirPilha(TPilhaAlunos *origem, TPilhaAlunos *destino){
    TAluno aluno;

    while(origem->topo > 0){
        aluno = desempilharALuno(origem);

       empilharAluno(aluno, destino);

    }

}



void printPilha(TAluno pilha[], int tam)
{
    printf("[ \n ");
	for (int i = 0; i < tam; i++)
	{
		printf("%d, ", pilha[i].numMatricula);
		printf("%s, ", pilha[i].nome);
		printf("%s;\n ", pilha[i].email);
	}
	printf("]\n");
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