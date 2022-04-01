#include <stdio.h>
/*
    Um problema tipico em ciencia da computacao consiste em converter um numero da sua forma decimal 
    para a forma binaria. Por exemplo, o numero 12 tem a sua representacao binaria igual a 1100. 
    A forma mais simples de fazer isso eh dividir o número sucessivamente por 2, onde o resto da 
    i-esima divisao vai ser o digito i do número binario (da direita para a esquerda). Desenvolva 
    algoritmos recursivos para impressão de um número natural em base binária.
*/
void toBinary(int);

int main(void)
{
    int decimal;

    printf("Digite o numero decimal: ");
    scanf("%d", &decimal);

    toBinary(decimal);
    printf("\n");
    return 0;
}

void toBinary(int num)
{
    if (num < 1)
        printf("> ");
    else
    {
        toBinary(num / 2);
        printf("%d", num % 2);
    }
    return;
}    