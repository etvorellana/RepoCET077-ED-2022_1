#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int vet[], int n);
int multiplica(int vet[], int n);

int main(void){

    int *vet, n, i;
    int resp1, resp2;

    printf ("Quantos numeros deseja colocar no vetor? ");
    scanf ("%d", &n);

    vet = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        printf ("Informe o %d valor >> ", i+1);
        scanf ("%d", &vet[i]);
    }

     resp1 = soma(vet, n);
     resp2 = multiplica(vet, n);

     printf("A soma dos elementos do vetor eh >> %d\n", resp1);
     printf("O produto dos elementos do vetor eh >> %d", resp2);

     free(vet);
}

int soma(int vet[], int n){
    if(n==0){
        return 0;
    }else{
        return vet[n-1] + soma(vet, n-1);
    }
}

int multiplica(int vet[], int n){
    if (n==0){
        return 1;
    }else{
        return vet[n-1] * multiplica(vet, n-1);
    }
}
