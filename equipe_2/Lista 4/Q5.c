#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void) {
  int i, tam=5;
  TFilaDePilha filaPilha;
  TListAlunos *lista1, *lista2, *lista3, *lista4, *lista5;
  TPilhaAlunoEnc p1,p2,p3,p4,p5;
  TAluno remove;

  srand(time(NULL));
  lista1 = geraListaDeAlunos(tam,tam,0);
  lista2 = geraListaDeAlunos(tam,tam,0);
  lista3 = geraListaDeAlunos(tam,tam,0);
  lista4 = geraListaDeAlunos(tam,tam,0);
  lista5 = geraListaDeAlunos(tam,tam,0);

  iniPilhaEncAlunos(&p1);
  iniPilhaEncAlunos(&p2);
  iniPilhaEncAlunos(&p3);
  iniPilhaEncAlunos(&p4);
  iniPilhaEncAlunos(&p5);
  for(i=0;i<tam;i++){
    empilharAlunoEnc(lista1->lista[i],&p1);
    empilharAlunoEnc(lista2->lista[i],&p2);
    empilharAlunoEnc(lista3->lista[i],&p3);
    empilharAlunoEnc(lista4->lista[i],&p4);
    empilharAlunoEnc(lista5->lista[i],&p5);
  }

  iniFilaDePilhas(&filaPilha);
  inserePilha(&p1, &filaPilha);
  inserePilha(&p2, &filaPilha);
  inserePilha(&p3, &filaPilha);

  imprimeFilaDePilhasAll(filaPilha);
  
  removeEmPilha(0,&remove,&filaPilha);
  removeEmPilha(1,&remove,&filaPilha);
  removeEmPilha(1,&remove,&filaPilha);
  imprimeFilaDePilhasAll(filaPilha);
  
  removePilha(&p2,&filaPilha);

  inserePilha(&p4,&filaPilha);
  inserePilha(&p5,&filaPilha);
  imprimeFilaDePilhasAll(filaPilha);
  imprimePilha(&p2);
  
  
  
  
  
}