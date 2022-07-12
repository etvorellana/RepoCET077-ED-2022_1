#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	// srandom(time(NULL));
	srandom(1234567890);
	/*
			* Criar uma listaA não ordenada de tamanho
			LSIZE preenchida de forma aleatória.
	*/
	TListAlunos *listaA;
	listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);

	/*
			* Criar uma árvore binária alocando os nós de
			forma aleatória
	*/
	PRaizArvAluno arvoreA; // raiz da árvore vazia
	PRaizArvAluno arvoreB; // raiz da árvore vazia
	PRaizArvAlunoAVL arvoreC; // raiz da árvore vazia
	arvoreA = criarArvoreDeLista(*listaA);
	arvoreB = criarArvoreDeLista_(*listaA);
	arvoreC = criarArvoreDeLista_AVL(*listaA);
	while(1){
		printf("\n\n");
		printf("Digite a opção desejada:\n");
		printf("1 - Remover um aluno\n");
		printf("2 - Remover um aluno - BS\n");
		printf("3 - Remover um aluno - AVL\n");
		printf("4 - Buscar um aluno\n");
		printf("5 - Buscar um aluno - BS\n");
		printf("6 - Buscar um aluno - AVL\n");
		printf("7 - Imprimir a árvore\n");
		printf("8 - Imprimir a árvore - B\n");
		printf("9 - Imprimir a árvore - AVL\n");
		printf("0 - Sair\n");
		printf("\n");
		printf("Opção: ");
		int matricula;
		int op;
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				removerAlunoArvore_B(matricula,arvoreA);
				break;
			case 2:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				removerAlunoArvore_BS(matricula, arvoreB);
				break;
			case 3:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				removerAlunoArvore_BAVL(matricula, arvoreC);
				break;
			case 4:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				buscarAlunoArvore_B(matricula, arvoreA);
				break;
			case 5:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				buscarAlunoArvore_BS(matricula, arvoreB);
				break;
			case 6:
				printf("Digite o numero de matricula do aluno: ");
				scanf("%d", &matricula);
				buscarAlunoArvore_BAVL(matricula, arvoreC);
				break;
			case 7:
				printArvore(arvoreA, 1);
				break;
			case 8:
				printArvore(arvoreB, 1);
				break;
			case 9:
				printArvoreAVL(arvoreC, 1);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção inválida\n");
				break;
		}
	}
	return 0;
}
