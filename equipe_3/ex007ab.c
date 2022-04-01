#include <stdio.h>

/*
Questão 7 letra B:
    - são n chamadas recursivas e sua complexidade é O(2^n);
*/

int calcular(int n);

int main(void){

    int n, resp;

    printf("Informe um valor para N: ");
    scanf("%d", &n);

    resp = calcular(n);

    printf("A resposta eh: %d", resp);
}

int calcular(int n){
    if(n == 1 || n == 2){
        return 0;
    }else{
        return 2*calcular(n-1) + calcular(n-2) + n;
    }
}
