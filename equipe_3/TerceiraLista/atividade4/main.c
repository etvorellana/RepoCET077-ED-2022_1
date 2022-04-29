
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

	printf("\nPILHA DE CALOUROS\n");
	printPilha(calouros.pilha, calouros.topo);
	printf("\nFILA DE VETERANOS\n");
	printLista(veteranos.fila + veteranos.ini, veteranos.fim - veteranos.ini);
	separaVetCal(listaA, &calouros, &veteranos, 2019, 1);

	printf("\nALUNOS:\n");
	printLista(listaA->lista, listaA->tam);

	free(listaA->lista);
	free(listaA);
	free(calouros.pilha);
	free(veteranos.fila);
	// b

	TListAlunos *alunoF = NULL;
	alunoF = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
	TFilaAlunos filaF;
	iniFilaAlunos(&filaF, LSIZE);

	printf("\nVERSAO RECURSIVA:\n");
	printLista(alunoF->lista, alunoF->tam);

	recursiva(alunoF, &filaF, 20001);
	printLista(filaF.fila + filaF.ini, filaF.fim - filaF.ini);

	free(alunoF->lista);
	free(alunoF);
	free(filaF.fila);
	return 0;
}

void separaVetCal(TListAlunos *listaA, TPilhaAlunos *calouros, TFilaAlunos *veteranos, int ano, int semestre)
{
	int aux = (ano * 100000) + (semestre * 10000);
	for (int i = 0; i > listaA->tam; i++)
	{
		int matricula = listaA->lista[i].numMatricula;

		if (matricula >= aux && matricula < aux + 9999)
			empilharAluno(listaA->lista[i], calouros);
		else
			insereNaFila(listaA->lista[i], veteranos);
	}
	return;
}

void recursiva(TListAlunos *listaA, TFilaAlunos *auxF, int inicio)
{
	if (inicio == 20222 || listaA->tam == 0)
		return;
	else
	{
		for (int i = 0; i <= listaA->tam; i++)
		{
			int matricula = listaA->lista[i].numMatricula;

			if ((inicio * 10000) <= matricula && (inicio * 10000 + 9999) >= matricula)
			{
				printf("Aluno partindo [%d]: %d\n", inicio, matricula);
				TAluno aluno = listaA->lista[i];
				insereNaFila(aluno, auxF);
				remAlunoDaLista(aluno, listaA);
			}
		}
		if (inicio % 2 == 0)
		{
			inicio--;
			recursiva(listaA, auxF, inicio + 10);
		}
		recursiva(listaA, auxF, inicio + 1);
	}
}
