#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	//a)
  TListAlunos *lista = NULL;
  lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
  TFilaEncAlunos *fila = iniFilaAlunosEnc();

  for (int i = 0; i < lista->cap; i++) {
    insereNaFilaEnc(lista->lista[i], fila);
  }
  printf("FILA:\n");
  imprimeFila(fila);

  //(b)
  int sorteado = rand() % LSIZE;
  printf("\n> aluno sorteado: %d\n", lista->lista[sorteado].numMatricula);

  // Guardando na lista os alunos que estao acima do
  // aluno sorteado na pilha e removendo o aluno sorteado
	lista->tam = 0;
  for (int i = 0; i <= sorteado; i++) {
    TAluno aluno;
    removeDaFilaEnc(&aluno, fila);
    if (i < sorteado) {
      incAlunoNaLista(aluno, lista);
    }
  }

  // Devolvendo os alunos da lista para a pilha
  for (int i = 0; i < LSIZE; i++) {
    TAluno aluno;
		removeDaFilaEnc(&aluno, fila);
		incAlunoNaLista(aluno, lista);
  }

  for (int i = 0; i < lista->tam; i++) {
		TAluno aluno = lista->lista[i];
		insereNaFilaEnc(aluno, fila);
	}
  printf("\nFILA (com aluno removido):\n");
  imprimeFila(fila);

  liberaFila(fila);
  liberaLista(lista);
  return 0;
}
