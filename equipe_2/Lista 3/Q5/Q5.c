#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *vet, int esq, int dir);

int main(){
    int count, vetor[10] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};

    quick_sort(vetor, 0, 9);

    for(count = 0; count<10; count++){
        printf("%i\n", vetor[count]);
    }


    return 0;
}

void quick_sort(int *vet, int esq, int dir){
    int i, j, pivo, aux; //Inicia as variáveis

    i= esq; // i = primeiro valor da lista
    j= dir; // j = ultimo valor da lista 
    pivo = vet[(esq + dir)/2]; // Define o meio da lista como pivo


    while(i<=j){  //enquanto o da esquerda esiver em uma posição menor ou igual o da direita
        while(vet[i] < pivo  && i < dir){ //verifica se tem algum numero maior q o pivo na esquerda e aponta pra ele
            i++;
        }
        while(vet[j] > pivo  && j > esq){ //verifica se tem um numero menor q o pivo na direita
            j--;
        }
        

        if(i <= j){ //troca o valor de i com o de j
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }

    }
    if(j > esq){
        quick_sort(vet, esq, j);
    }
    if(i < dir){
        quick_sort(vet, i, dir);
    }
}