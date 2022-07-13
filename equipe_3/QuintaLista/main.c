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
    TListAlunos *listaA = iniListAlunos(11, FALSE);
	
    listaA->lista[0].numMatricula = 63;
    listaA->lista[1].numMatricula = 7;
    listaA->lista[2].numMatricula = 2;
    listaA->lista[3].numMatricula = 59;
    listaA->lista[4].numMatricula = 52;
    listaA->lista[5].numMatricula = 60;
    listaA->lista[6].numMatricula = 69;
    listaA->lista[7].numMatricula = 65;
    listaA->lista[8].numMatricula = 90;
    listaA->lista[9].numMatricula = 83;
    listaA->lista[10].numMatricula = 84;
    listaA->tam=11;
    printLista(listaA->lista, listaA->tam);

    PRaizArvAluno arvoreA = criarArvoreDeLista_(*listaA);
    printArvore(arvoreA, 0);
    
    PRaizArvAluno no_pai = BuscarPaiArvDeBusca(arvoreA, 63);
		printf("\nno_pai: %d\n", no_pai ? no_pai->aluno.numMatricula : -1);

		RemoverNoArvDeBusca(arvoreA, 63);
		printArvore(arvoreA, 0);
		printf("\n\n");
		printf("retorno: %d\n", RemoverNoArvDeBusca(arvoreA, 63));
		printArvore(arvoreA, 0);
}