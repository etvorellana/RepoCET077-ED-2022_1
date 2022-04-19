#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ferramentas.h"

int main(void) {
  TListAlunos listaA,listaB,listaC;
  TListAlunos uniao, inter, difB, difC;
  int alea, inc=0,naoInc=0;

  srand(time(NULL));
  geraListaDeAlunos(&listaA, 2*LSIZE,2*LSIZE,0);
  iniListAlunos(&listaB,LSIZE,0);

  
  while(inc<listaB.cap){
    alea = (rand()%listaA.tam);
    if(incAlunoNaLista(listaA.lista[alea],&listaB)){
      inc++;
      }
    else{
      naoInc++;
      }
    
  }

  printf("inclusões falsas: %i\ninclusões verdadeiras:%i",naoInc,inc);
  printf("\nTamanho listaB: %i",listaB.tam);

  inc=0;
  naoInc=0;
        
  iniListAlunos(&listaC,LSIZE,1);

  while(inc<listaC.cap){
    alea = (rand()%listaA.tam);
    if(incAlunoNaLista(listaA.lista[alea],&listaC)){
      inc++;
      }
    else{
      naoInc++;
      }
    } 
  
  printf("\n\ninclusões falsas: %i\ninclusões verdadeiras:%i",naoInc,inc);
  printf("\nTamanho listaC: %i",listaC.tam);

  printLista(listaA.lista,listaA.tam);
  printLista(listaB.lista,listaB.tam);
  printLista(listaC.lista,listaC.tam);

  uniaoListas(&listaB,&listaC,&uniao);
  printf("\ntamanho uniao B U C: %i", uniao.tam);

  difListas(&listaB,&listaC,&difB);
  printf("\ntamanho diferença B - C: %i", difB.tam);

  difListas(&listaC,&listaB,&difC);
  printf("\ntamanho diferença C - B: %i", difC.tam);

  intListas(&listaC,&listaB,&inter);
  printf("\ntamanho interseção C ^ B: %i", inter.tam);


  return 0;
}