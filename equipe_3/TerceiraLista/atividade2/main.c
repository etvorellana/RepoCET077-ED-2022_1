
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	srand(time(NULL));

// ATIVIDADE 2

	TListAlunos *alunos = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
	TListAlunos *biblioteca = iniListAlunos(BIBLI, FALSE);
	TFilaAlunos espera;
	TAluno aluno;

	int resp;
	iniFilaAlunos(&espera, LSIZE);

	do {
		printf("[1] Registrar acesso\n[2] Registrar saída\n[3] Printar listas\n[4] Fechar registro\n::");
		scanf("%d", &resp);

		switch (resp) {
		case 1:
			if (alunos->tam > 0)
			{
				aluno = alunos->lista[rand() % alunos->tam];
				remAlunoDaLista(aluno, alunos); // remove o aluno da uesc, isso tambem que o mesmo aluno seja sorteado dnv
				if (incAlunoNaLista(aluno, biblioteca))
					printf("> Aluno [%d] entrou na biblioteca!\n", aluno.numMatricula);
				else {
					if ((espera.fim - espera.ini) != espera.cap) {
						// Se fim-ini=cap a fila esta cheia
						printf("> Aluno [%d] entrou na fila de espera!\n", aluno.numMatricula);
						insereNaFila(aluno, &espera);
					}
				}
			}
			break;
		case 2:
			if (biblioteca->tam > 0) // a biblioteca nao esta vazia
			{
				aluno = biblioteca->lista[rand() % biblioteca->tam];
				remAlunoDaLista(aluno, biblioteca);
				incAlunoNaLista(aluno, alunos); // coloca o aluno que saiu da biblioteca na uesc
				if (espera.ini != espera.fim) {
					// Se inicio for igual ao fim a fila estaria vazia
					removeDaFila(&aluno, &espera);
					incAlunoNaLista(aluno, biblioteca);
				}
			}
			else
				printf("\n> Biblioteca vazia!\n");
			break;
		case 3:
			printf("UESC:\n");
			printLista(alunos->lista, alunos->tam);
			printf("BIBLIOTECA:\n");
			printLista(biblioteca->lista, biblioteca->tam);
			printf("FILA DE ESPERA:\n");
			printLista(espera.fila + espera.ini, espera.fim - espera.ini);
			break;
		case 4:
			free(alunos->lista);
			free(biblioteca->lista);
			free(alunos);
			free(biblioteca);
			free(espera.fila);
			break;
		default:
			break;
		}
	} while (resp != 4);

	return 0;
}
