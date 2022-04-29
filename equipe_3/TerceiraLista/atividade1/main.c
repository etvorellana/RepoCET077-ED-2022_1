
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	srand(time(NULL));

// ATIVIDADE 1
//(a)
	TListAlunos *listaA = NULL;
	listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
	TPilhaAlunos pilhaA;
	iniPilhaAlunos(&pilhaA, LSIZE);

	for (int i = 0; i < pilhaA.cap; i++) {
		empilharAluno(listaA->lista[i], &pilhaA);
	}
	printf("ALUNOS:\n");
	printPilha(pilhaA.pilha, pilhaA.topo);
	printf("cap: %d\ttopo: %d\n", pilhaA.cap, pilhaA.topo);

//(b)
	TAluno aluno;
	TPilhaAlunos pilhaAux;
	iniPilhaAlunos(&pilhaAux, LSIZE);

	int sorteado = rand() % pilhaA.topo;
	printf("\n> Aluno sorteado: [%d] %d\n", sorteado, pilhaA.pilha[sorteado].numMatricula);

	while (pilhaA.topo-1 >= sorteado)
	{
		desempilharALuno(&aluno, &pilhaA);
		if (pilhaA.topo > sorteado) {
			empilharAluno(aluno, &pilhaAux);
		}
	}
	printf("\nPILHA AUX:\n");
	printPilha(pilhaAux.pilha, pilhaAux.topo);
	printf("cap: %d\ttopo: %d\n", pilhaAux.cap, pilhaAux.topo);

	while (pilhaAux.topo-1 >= 0) {
		desempilharALuno(&aluno, &pilhaAux);
		empilharAluno(aluno, &pilhaA);
	}
	printf("\nLISTA A Com item removido:\n");
	printPilha(pilhaA.pilha, pilhaA.topo);
	printf("cap: %d\ttopo: %d\n", pilhaA.cap, pilhaA.topo);

	free(pilhaAux.pilha);
	free(listaA);
	free(pilhaA.pilha);
	return 0;
}
