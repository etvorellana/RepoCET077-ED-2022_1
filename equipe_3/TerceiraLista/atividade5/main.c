
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
	TListAlunos* listaA = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
	quickSort(listaA->lista, 0, listaA->tam-1);
	listaA->eOrd = TRUE;

	printLista(listaA->lista, listaA->tam);
	
	free(listaA->lista);
	free(listaA);
	return 0;
}
