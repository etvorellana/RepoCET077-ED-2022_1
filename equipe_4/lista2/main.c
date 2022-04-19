#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.c"

int main(void)
{
    	int i, falso, verdade;
    	
        /* Criar uma listaA não ordenada de tamanho 
        2*LSIZE preenchida de forma aleatória.*/
        
        TListAlunos *listaA = geraListaDeAlunos(2*LSIZE, 2*LSIZE, FALSE);
		printf("Matricula do primeiro elemento da lista A: %d\n",listaA->lista[0].numMatricula);
        
        /* Declarar uma listaB não ordenada de capacidade
        LSIZE*/
        
        TListAlunos *listaB = iniListAlunos(LSIZE, FALSE);
        printf("Matricula do primeiro elemento da lista B: %d\n",listaB->lista[0].numMatricula);
        
        
        /* Selecione em ordem aleatória todos os itens da 
        listaA e inclua na listaB. Conte quantas vezes a 
        função de inclusão retorna verdadeiro e quantas 
        retorna falso. No final mostre os valores 
        contabilizados junto com o tamanho da listaB*/
        
        falso = 0; verdade = 0;
        srand(time(NULL));
        while (listaB->tam < listaB->cap) {
        	if(incAluno_NOrd(listaA->lista[rand() % listaA->tam], listaB->lista, &listaB->tam, listaB->cap) == FALSE){
        		falso += 1;
			}
			else {
				verdade +=1;
			}
		}
		
		printf("Verdadeiro: %d | Falso: %d | Tamanho listaB: %d \n",verdade, falso, listaB->tam);
        
        
        /* Declarar uma listaC ordenada de capacidade
        LSIZE*/
        
        TListAlunos *listaC = iniListAlunos(LSIZE, TRUE);
        printf("Matricula do primeiro elemento da lista C: %d\n",listaC->lista[0].numMatricula);
        
        
        /* Selecione em ordem aleatória todos os itens da 
        listaA e inclua na listaC. Conte quantas vezes a 
        função de inclusão retorna verdadeiro e quantas 
        retorna falso. No final mostre os valores 
        contabilizados junto com o tamanho da listaC*/
        
        falso = 0; verdade = 0;
        srand(time(NULL));
        while (listaC->tam < listaC->cap) {
        	if(incAluno_Ord(listaA->lista[rand() % listaA->tam], listaC->lista, &listaC->tam, listaC->cap) == FALSE){
        		falso += 1;
			}
			else {
				verdade +=1;
			}
		}
		printf("Verdadeiro: %d | Falso: %d | Tamanho listaB: %d \n",verdade, falso, listaC->tam);
		
        
        /* Crie a lista união da listaB com a ListaC. 
        Mostre o tamanho desta lista.*/
        TListAlunos *Lista_Uniao = uniListas(listaA, listaB);
        printf("Tamanho Lista Uniao B e C: %d", Lista_Uniao->tam);
        
        
        
        
        
        /* Crie a lista diferença da listaB com a ListaC. 
        Mostre o tamanho desta lista.*/
        
        /* Crie a lista diferença da listaC com a ListaB. 
        Mostre o tamanho desta lista.*/
        
        /* Crie a lista intersecção da listaB com a ListaC. 
        Mostre o tamanho desta lista.*/
        
        /* Verifique se os tamanhos reportados são 
        consistentes.*/
        
        /* Transforma a listaA numa lista ordenada.*/
        
    return 0;
}
