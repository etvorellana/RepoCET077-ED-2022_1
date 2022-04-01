#include <stdio.h>
/*
    A sequência de Fibonacci é uma sequencia de elementos f1, …, fn, definida do seguinte modo: 
    f1 = 0; f2 = 1;
    fj = fj-1 + fj-2 para j > 2.

    - Elaborar um algoritmo recursivo para calcular a sequencia de Fibonacci para qualquer valor de n;
    - Determinar o numero de chamadas recursivas e a complexidade do algoritmo implementado;
    - Construir um algoritmo nao recursivo para calcular o elemento n da sequencia, cuja complexidade seja linear com n.
*/
int recFib(int n);
int iterSequencia(int n);

int main(void)
{
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("> Recursivo: %d\n", recFib(n));
    printf("> Iterativo: %d\n", iterSequencia(n));
    return 0;
}

/*
    Numero de chamadas recursivas = n
    Complexidade do algoritmo = 0(2^n)
*/
int recFib(int n)
{

    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    return recFib(n-1) + recFib(n-2);
}

/*
    Complexidade do algoritmo = O(n)
*/
int iterSequencia(int n)
{
    int anterior = 0, atual = 1, total;

    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    for (int i = 2; i < n; i++)
    {
        total = anterior + atual;
        anterior = atual;
        atual = total;
    }
    return total;
}
