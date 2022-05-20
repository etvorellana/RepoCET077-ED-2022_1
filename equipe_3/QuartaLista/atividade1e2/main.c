#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  TPilhaEncAlunos *pilha = iniPilhaEncDeFilas();
  TAluno aluno;

  aluno.numMatricula = 98765432;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202333312;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202020421;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202020122;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202011230;
  empilharAlunoEnc(aluno, pilha);

  imprimePilha(pilha);

  desempilharAlunoEnc(&aluno, pilha);
  imprimePilha(pilha);
  liberaPilha(pilha);

  TFilaEncAlunos *fila = iniFilaAlunosEnc();

  aluno.numMatricula = 98765432;
  insereNaFilaEnc(aluno, fila);
  aluno.numMatricula = 202333312;
  insereNaFilaEnc(aluno, fila);
  aluno.numMatricula = 202020421;
  insereNaFilaEnc(aluno, fila);
  aluno.numMatricula = 202020122;
  insereNaFilaEnc(aluno, fila);
  aluno.numMatricula = 202011230;
  insereNaFilaEnc(aluno, fila);

  imprimeFila(fila);

  removeDaFilaEnc(&aluno, fila);
  imprimeFila(fila);
  // liberaPilha(pilha);
  return 0;
}