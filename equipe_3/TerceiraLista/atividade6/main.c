
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	srand(time(NULL));

// ATIVIDADE 6

	TListAlunos *alunoP = NULL;
	alunoP = geraListaDeAlunos(PROVA, PROVA, FALSE);
	TPilhaAlunos pilhaP;
	iniPilhaAlunos(&pilhaP, PROVA);
	TFilaAlunos filaP;
	iniFilaAlunos(&filaP, PROVA);

	// Prova de multiplas escolhas
	//// Os alunos recebem ao mesmo tempo
	printf("ALUNOS QUE RECEBERAM A PROVA DE MULTIPLAS ESCOLHAS (lista):\n");
	printLista(alunoP->lista, alunoP->tam);

	while (alunoP->tam > 0)
	{
		TAluno aluno = alunoP->lista[rand() % alunoP->tam];
		printf("> Aluno [%d] entregou a prova!\n", aluno.numMatricula);
		remAlunoDaLista(aluno, alunoP);
		empilharAluno(aluno, &pilhaP);
	}

	// Prova discursiva
	//// Os alunos são chamados na ordem inversa em que entregaram a prova anterior
	printf("\nORDEM DE SORTEIO PARA OS TEMAS DA PROVA DISCURSIVA (pilha):\n");
	printPilha(pilhaP.pilha, pilhaP.topo);

	while (pilhaP.topo > 0)
	{
		TAluno aluno;
		desempilharALuno(&aluno, &pilhaP);
		printf("> Aluno [%d] entregou a prova!\n", aluno.numMatricula);
		insereNaFila(aluno, &filaP);
	}

	// Atividade prática
	//// Os alunos são chamados na mesma ordem em que entregaram a prova anterior
	printf("\nORDEM DE SORTEIO PARA OS TEMAS DA PROVA PRATICA (fila):\n");
	printLista(filaP.fila + filaP.ini, filaP.fim - filaP.ini);

	free(alunoP->lista);
	free(pilhaP.pilha);
	free(filaP.fila);
	free(alunoP);
	return 0;
}