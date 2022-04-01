#include <stdio.h>
/*
    Multiplicacao de dois numeros naturais, atraves de incrementos sucessivos.
*/
int multInc(int x, int y);
int multIncF(int x, int y, int buffer);

int main(void)
{
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("Resultado: %d\n", multInc(x, y));
    return 0;
}


int multInc(int x, int y) { 
    return multIncF(x, y, x);
}

int multIncF(int x, int y, int buffer)
{
    if (y == 1)
        return x;
    else 
    {
        if (buffer > 0)
            return multIncF(x, y, --buffer) + 1;
        else
            return multIncF(x, --y, x);
    }
}