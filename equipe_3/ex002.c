#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int x,int y){
   if(y>0){
    soma(++x,--y);
   }
   else{
    return x;
   }
}

int main(){
    /*2-Considere um sistema numerico que nao tenha a operação de adicao implementada e que voce disponha somente dos
    operadores (funcoes) sucessor e predecessor.
    Entao, pede-se para escrever uma função recursiva que calcule a soma de dois números x e y atraves desses dois operadores

    */
    int num1,num2,total;
    printf("Digite 2 numeros:");
    scanf("%d %d",&num1,&num2);

    total=soma(num1,num2);
    printf("\nTotal:%d",total);

    return 0;

}
