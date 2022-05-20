#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
//a)
  TListAlunos *lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
  TPilhaEncAlunos *pilha = iniPilhaEncDeFilas();

  for (int i = 0; i < lista->tam; i++) {
    empilharAlunoEnc(lista->lista[i], pilha);
  }
  printf("PILHA:\n");
  imprimePilha(pilha);

//(b)
  int sorteado = rand() % LSIZE;
  printf("\n> aluno sorteado: %d\n", lista->lista[sorteado].numMatricula);

  // Guardando na lista os alunos que estao acima do
  // aluno sorteado na pilha e removendo o aluno sorteado
	lista->tam = 0;
  while (pilha->topo-1 >= sorteado) {
    TAluno aluno;
    desempilharAlunoEnc(&aluno, pilha);
    if (pilha->topo > sorteado) {
      incAlunoNaLista(aluno, lista);
    }
  }

  // Devolvendo os alunos da lista para a pilha
  while (lista->tam-1 >= 0) {
    TAluno aluno = lista->lista[lista->tam-1];
    empilharAlunoEnc(aluno, pilha);
    remAlunoDaLista(aluno, lista);
  }
  printf("\nPILHA (com aluno removido):\n");
  imprimePilha(pilha);

  liberaPilha(pilha);
  liberaLista(lista);
  return 0;
}