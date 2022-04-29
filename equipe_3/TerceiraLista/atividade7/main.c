
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	srand(time(NULL));

// ATIVIDADE 7
// a)
	TListAlunos *listaO = geraListaDeAlunos(LSIZE, LSIZE, TRUE);
	TListAlunos *listaNO = iniListAlunos(LSIZE, FALSE);
	TPilhaAlunos pilhaC;
	iniPilhaAlunos(&pilhaC, LSIZE);
	TFilaAlunos filaC;
	iniFilaAlunos(&filaC, LSIZE);

// b)
	printf("LISTA ORDENADA:\n");
	printLista(listaO->lista, listaO->tam);

	while (listaO->tam > 0)
	{
		TAluno aluno = listaO->lista[0];
		// Sempre removera o primeiro primeiro
		remAlunoDaLista(aluno, listaO);
		empilharAluno(aluno, &pilhaC);
	}
	printf("> Removendo os elementos da lista do menor para o maior e acrescentando na pilha.\n");
	printf("PILHA:\n");
	printPilha(pilhaC.pilha, pilhaC.topo);

// c) 
	/* 
		Os elementos da fila estarao na ordem decrescente, pois ao passar a lista ordenada 
		para a pilha os elementos ficaram em organizados da seguinte forma: o primeiro 
		elemento da lista sera o ultimo a sair, e o segundo o penultimo ... Dessa forma 
		ao transferir da pilha para uma lista nao ordenada o primeiro elemento da mesma 
		sera o ultimo da original. 
	*/
	while (pilhaC.topo > 0)
	{
		TAluno aluno;
		desempilharALuno(&aluno, &pilhaC);
		incAlunoNaLista(aluno, listaNO);
	}
	printf("> Transferindo os elementos da pilha para uma lista não ordenada.\n");
	printf("LISTA NAO ORDENADA:\n");
	printLista(listaNO->lista, listaNO->tam);

// d) Remova os elementos da nova lista do último para o primeiro e acrescente numa fila;

	while (listaNO->tam > 0)
	{
		TAluno aluno = listaNO->lista[listaNO->tam - 1];
		// Sempre removera o ultimo da lista
		remAlunoDaLista(aluno, listaNO);
		insereNaFila(aluno, &filaC);
	}
	printf("> Removendo os elementos da nova lista do último para o primeiro e acrescente na fila\n");
	printf("FILA:\n");
	printLista(filaC.fila + filaC.ini, filaC.fim - filaC.ini);

// e)Transfira os elementos da fila para uma lista não ordenada.
	/* 
		A operacao de sair de uma lista para uma fila ou vice e versa , é equivalente a 
		multiplicacao por 1,nesse caso como estamos pegando o "inverso da lista" de forma 
		analoga a fila sera tambem o "inverso".Dessa forma tinhamos : um lista ordenada de 
		forma decrescente,passando para o inverso sendo crescente.
	*/
	while (filaC.ini != filaC.fim)
	{
		TAluno aluno;
		removeDaFila(&aluno, &filaC);
		incAlunoNaLista(aluno, listaNO);
	}
	printf("> Transferindo os elementos da fila para uma lista não ordenada.\n");
	printf("FILA NAO ORDENADA (saida ordenada):\n");
	printLista(listaNO->lista, listaNO->tam);

	return 0;
}