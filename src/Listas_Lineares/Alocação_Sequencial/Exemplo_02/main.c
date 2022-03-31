#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int buscaAluno(TAluno lista[], int tam, int chave);
int buscaAlunoR(TAluno lista[], int tam, int chave);

int main(void)
{
    int tamLista, capLista;
    /* 
        capLista - Capacidade da lista.  Limite máximo de elementos
        que podem ser aramzenados na lista. Deve ser utilizado como
        o tamanho do array.
    */
    capLista = LSIZE;
    /* 
        tamLista - Tamanho da lista
        * tamLista == 0: Lista vazia;
        * tamLista == capLista: Lista cheia;
        * Se tamLista < capLista o índice i = tamLista representa a
        primeira posição disponível na lista
        * A cada inserção de um novo elemento tamLista deve ser 
        incrementado
        * Os índices válidos i para uma lista não vazia: 
                0 <= i < tamLista <= capLista 
    */
    tamLista = 0; //Lista inicialmente vazia
    // Uma lista como uma array alocado estaticamente
    TAluno lista[LSIZE];

    printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br   
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */

    // Adicionando o primeiro item na lista
    // Regrano Guedes Maia     201913425   regguemai@uesc.br
    lista[0].numMatricula = 201913425; // Posição inicial na posição indexada 0
    // Copiando uma string literal em uma array de char
    strcpy(lista[0].nome, "Regrano Guedes Maia");
    // Pode ser utilizada também como indexador o tamanho da lista
    strcpy(lista[tamLista].email, "regguemai@uesc.br");
    // Antes de incrementar o tamanho
    tamLista++;
    printf("Item inserido com sucesso!!!\n");

    // Adicionando um novo item na lista com chave repetida
    // Mengano Martins Pereira 201913425   menmarper@uesc.br
    //if (buscaAluno(lista, tamLista, 201913425) == tamLista)
    if (buscaAlunoR(lista, tamLista, 201913425) == tamLista)
    {
        lista[tamLista].numMatricula = 201913425;
        strcpy(lista[tamLista].nome, "Mengano Martins Pereira");
        strcpy(lista[tamLista].email, "menmarper@uesc.br");
        tamLista++;
        printf("Item inserido com sucesso!!!\n");
    }
    else
    {
        printf("Já tem Aluno na lista com matrícula 201913425\n");
    }

    // Adicionando um novo item na lista
    // Mengano Martins Pereira 201913245   menmarper@uesc.br
    //if (buscaAluno(lista, tamLista, 201913245) == tamLista)
    if (buscaAlunoR(lista, tamLista, 201913245) == tamLista)
    {
        lista[tamLista].numMatricula = 201913245;
        strcpy(lista[tamLista].nome, "Mengano Martins Pereira");
        strcpy(lista[tamLista].email, "menmarper@uesc.br");
        tamLista++;
        printf("Item inserido com sucesso!!!\n");
    }
    else
    {
        printf("Aluno já está na lista\n");
    }

    // Adicionando um novo item na lista
    // Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    if (buscaAluno(lista, tamLista, 201912345) == tamLista)
    //if (buscaAlunoR(lista, tamLista, 201912345) == tamLista)
    {
        lista[tamLista].numMatricula = 201912345;
        strcpy(lista[tamLista].nome, "Fulano Silva Oliveira");
        strcpy(lista[tamLista].email, "fulsiloli@uesc.br");
        tamLista++;
        printf("Item inserido com sucesso!!!\n");
    }
    else
    {
        printf("Aluno já está na lista\n");
    }

    // Imprimindo a lista
    printf("[ \n ");
    for (int i = 0; i < tamLista; i++)
    {
        printf("%d, ", lista[i].numMatricula);
        printf("%s, ", lista[i].nome);
        printf("%s;\n ", lista[i].email);
    }
    printf(" ]\n");

    // Removendo um item da lista 
    // remover item com número de matrícula 201913245
    int remover = 201913245;
    int pos = buscaAluno(lista, tamLista, remover);
    if (pos < tamLista){
        for(int i = pos; i < tamLista - 1 ; i++){
            lista[i].numMatricula = lista[i+1].numMatricula;
            strcpy(lista[i].nome, lista[i+1].nome);
            strcpy(lista[i].email, lista[i+1].email);
        }
        tamLista--;
        printf("Item removido com sucesso!!!\n");
    }else{
        printf("Aluno não está na lista\n");
    }
    // remover item com número de matrícula 201813245
    remover = 201813245;
    pos = buscaAluno(lista, tamLista, remover);
    if (pos < tamLista){
        for(int i = pos; i < tamLista - 1 ; i++){
            lista[i].numMatricula = lista[i+1].numMatricula;
            strcpy(lista[i].nome, lista[i+1].nome);
            strcpy(lista[i].email, lista[i+1].email);
        }
        tamLista--;
        printf("Item removido com sucesso!!!\n");
    }else{
        printf("Aluno não está na lista\n");
    }
    
    // Imprimindo a lista
    printf("[ \n ");
    for (int i = 0; i < tamLista; i++)
    {
        printf("%d, ", lista[i].numMatricula);
        printf("%s, ", lista[i].nome);
        printf("%s;\n ", lista[i].email);
    }
    printf(" ]\n");

    return 0;
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	a um array de tipo TAluno.
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna tam;
*/
//implementação recursiva
int buscaAlunoR(TAluno lista[], int tam, int chave)
{
	if(tam == 1) // so resta um elemento na lista
        if(lista[0].numMatricula == chave)
            return 0; // achou: retorna o índice da posição atual 
        else
            return 1; // não achou retorna o tamanho da lista
    else // tem mais itens na lista
        if(lista[0].numMatricula == chave)
            return 0; // achou: retorna o índice da posição atual
        else // não achou incrementa o índice e procura no resto da lista
            return 1 + buscaAlunoR(&lista[1], tam - 1, chave);
}
//implementação não recursiva
int buscaAluno(TAluno lista[], int tam, int chave)
{
	int i = 0;
	while (i < tam)
	{
		if (lista[i].numMatricula == chave)
			return i; //achou retorna o índice  
		i++;
	}
	return tam; //não achou, retorna tamLista
}


//gcc-11 -o listas main.c