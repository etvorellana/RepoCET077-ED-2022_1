#include <stdio.h>
/*
    Considere a seguinte sequencia definida a partir de uma equacao de diferencas de segunda ordem: 
    y(n) = 2y(n−1) + y(n−2) + n, com y(1) = 0 e y(2) = 0

    - Construir um algoritmo não recursivo para calcular o elemento n da sequência, cuja complexidade seja linear com n;
*/
int iterSequencia(int n);

int main(void)
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Resultado iterativo: %d\n", iterSequencia(n));
    return 0;
}

int iterSequencia(int n)
{
    int anterior = 0, atual = 0, prox;

    for (int i = 3; i <= n; i++)
    {
        prox = 2 * atual + anterior + i;
        anterior = atual;
        atual = prox;
    }
    return atual;
}