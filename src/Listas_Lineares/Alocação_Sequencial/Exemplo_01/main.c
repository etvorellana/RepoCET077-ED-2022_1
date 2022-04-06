#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{   // ano  Semestre    sequencial
    // 2019 1           1234
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647) 4 bytes
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

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
    TAluno lista[capLista];

    printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br   
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */

    // Adicionando o primeiro item da lista
    // Regrano Guedes Maia     201913425   regguemai@uesc.br
    lista[0].numMatricula = 201913425; // Item inicial na posição 0
    // Copiando uma string literal em uma array de char
    strcpy(lista[0].nome, "Regrano Guedes Maia"); 
    // Pode ser utilizada também como indexador o tamanho da lista
    strcpy(lista[tamLista].email, "regguemai@uesc.br");
    // Antes de incrementar o tamanho
    tamLista++;
    printf("Item inserido com sucesso!!!\n");

    // Adicionando um novo item na lista com chave repetida
    // Mengano Martins Pereira 201913425   menmarper@uesc.br
    if (lista[0].numMatricula != 201913425)
    {
        lista[tamLista].numMatricula = 201913425;
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
    // Mengano Martins Pereira 201913245   menmarper@uesc.br
    if (lista[0].numMatricula != 201913245){
        lista[tamLista].numMatricula = 201913245;
        strcpy(lista[tamLista].nome, "Mengano Martins Pereira");
        strcpy(lista[tamLista].email, "menmarper@uesc.br");
        tamLista++;
        printf("Item inserido com sucesso!!!\n");
    }
    else
        printf("Aluno já está na lista\n");

    // Adicionando um novo item na lista
    // Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    if (lista[0].numMatricula != 201912345 && lista[1].numMatricula != 201912345){
        lista[tamLista].numMatricula = 201912345;
        strcpy(lista[tamLista].nome, "Fulano Silva Oliveira");
        strcpy(lista[tamLista].email, "fulsiloli@uesc.br");
        tamLista++;
        printf("Item inserido com sucesso!!!\n");
    }
    else
        printf("Aluno já está na lista\n");

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
    // percorrer a lista 
    int remover = 201913245;
    for(int i = 0; i < tamLista; i++){
        if(lista[i].numMatricula == remover){
            if(i < (tamLista - 1)){
                remover = lista[i+1].numMatricula; 
                lista[i].numMatricula = lista[i+1].numMatricula;
                strcpy(lista[i].nome, lista[i+1].nome);
                strcpy(lista[i].email, lista[i+1].email);
            }else{
                tamLista--;
                printf("Item removido com sucesso!!!\n");
            }
        }
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


//gcc-11 -o listas main.c