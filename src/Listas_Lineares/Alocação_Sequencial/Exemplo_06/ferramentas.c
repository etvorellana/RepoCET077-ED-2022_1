#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"
 
int buscaAluno_(TAluno lista[], int tam, int chave);

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno. Nesta implementação se assume que a chave
    procurada foi copiada no final da lista;
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1. A chave procurada deve ter sido copiada para
    o elemento de índice tam, que não pertence à lista; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna tam;
*/
int buscaAluno(TAluno lista[], int tam, int chave)
{
    // Copiando a chave para a posição tam (fora da lista)
	lista[tam].numMatricula = chave;
    return buscaAluno_(lista, tam, chave); 
}

int buscaAluno_(TAluno lista[], int tam, int chave)
{
    int i = 0;
	while (lista[i].numMatricula != chave){
		i++;
	}
	return i;
}

/*
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
*/

/*
Implementa a inclusão numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. Os elementos da lista
não podem repetir o mesmo atributi chave. 
Entrada:
- aluno: Variável de tipo TAluno com as informações do elemnto
    que se deseja incluir na lista;
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno. O array permite aloca um elementro a 
    mais do que a capacidade da lista para permitir um algorítmo de
    busca mais eficiente; 
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1; 
saída:
- A função retorna o verdadeiro caso o aluno seja incluído na lista
    e falso caso contrário. Nesta implementação o aluno não sera 
    incluído na lista se já tiver um elemento na lista com o mesmo
    atributo chave
*/
int incAluno(TAluno aluno, TAluno lista[], int *tam, int cap)
{   
    if (*tam == cap)
        return FALSE; //lista cheia
	if (buscaAluno(lista, *tam, aluno.numMatricula) == *tam){
		lista[*tam].numMatricula = aluno.numMatricula;
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}else
        return FALSE;
}

int remAluno(int chave, TAluno lista[], int *tam){
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno(lista, *tam, chave);
    if (pos < *tam){
        *tam -= 1;
        lista[pos].numMatricula = lista[*tam].numMatricula;
        strcpy(lista[pos].nome, lista[*tam].nome);
        strcpy(lista[pos].email, lista[*tam].email);
        return TRUE;
    }else
        return FALSE;
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