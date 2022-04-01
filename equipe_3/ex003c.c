#include <stdio.h>
/*
    Inversao de uma string.
*/
void inversionString(char *);

int main(void)
{
    char str[20];

    printf("Digite uma string: ");
    scanf("%[^\n]", str); //Recebe uma string até encontrar o enter '\n'

    printf("String: %s\n", str);
    printf("Resultado: ");
    inversionString(str);
    printf("\n");

    return 0;
}

void inversionString(char * str)
{
    if(*str)
    {
        inversionString(str+1);
        putchar(*str);
    }
    return;
}