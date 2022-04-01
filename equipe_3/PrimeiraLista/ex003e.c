#include <stdio.h>
#include <string.h>
/*
    Verifique se uma palavra eh palindromo.
*/
int isPalindromo(char *, int);

int main(void)
{
    char str[50];

    printf("Digite uma string: ");
    scanf("%[^\n]", str);

    printf("Resultado: ");
    if (isPalindromo(str, strlen(str)-1)) //oi
        printf("é um palindromo!\n");
    else
        printf("não é um palindromo!\n");
    return 0;
}

int isPalindromo(char * str, int end)
{
    static int start = 0;
    if (start == end || ((end - start) == 1 && (str[end] == str[start])))
        return 1;
    else 
    {
        if (str[start] == str[end]) {
            start++;
            return isPalindromo(str, --end);
        }
        else
            return 0; 
    }
}