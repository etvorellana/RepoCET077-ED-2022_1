
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	srand(time(NULL));

	// ATIVIDADE 3

	TListAlunos *listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
	TPilhaAlunos calouros;
	iniPilhaAlunos(&calouros, LSIZE);
	TFilaAlunos veteranos;
	iniFilaAlunos(&veteranos, LSIZE);

	printf("ALUNOS:\n");
	printLista(listaA->lista, listaA->tam);
	separaVetCal(listaA, &calouros, &veteranos);

	printf("\nPILHA DE CALOUROS\n");
	printPilha(calouros.pilha, calouros.topo);
	printf("\nFILA DE VETERANOS\n");
	printLista(veteranos.fila + veteranos.ini, veteranos.fim - veteranos.ini);

	listaA->tam = 0;
	for (int i = 0; i < listaA->cap; i++)
	{
		TAluno aluno;
		if (veteranos.fim != veteranos.ini)
			removeDaFila(&aluno, &veteranos);
		else
			desempilharALuno(&aluno, &calouros);
		incAlunoNaLista(aluno, listaA);
	}
	printf("\nALUNOS:\n");
	printLista(listaA->lista, listaA->tam);

	free(listaA->lista);
	free(listaA);
	free(calouros.pilha);
	free(veteranos.fila);
	return 0;
}

void separaVetCal(TListAlunos *listaA, TPilhaAlunos *cal, TFilaAlunos *vet)
{
	int aux = 202210000;
	for (int i = 0; i < listaA->tam; i++)
	{
		int matricula = listaA->lista[i].numMatricula;

		if (matricula >= aux && matricula < aux + 9999)
			empilharAluno(listaA->lista[i], cal);
		else
			insereNaFila(listaA->lista[i], vet);
	}
	return;
}
