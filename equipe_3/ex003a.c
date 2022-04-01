#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mult(int a,int b){

    if(b==1){
        return a;
    }if(b==0){
        return 0;
    }else{
       return a+mult(a,--b);
    }

}

int main(){
    /*3-Desenvolva algoritmos recursivos para os seguintes problemas:
    a-Multiplicacao de dois numeros naturais, atraves de somas sucessivas (Ex.: 6 * 4 = 4+4+4+4+4+4).
    b-Multiplicacao de dois numeros naturais, atraves de incrementos sucessivos.
    c-Inversao de uma string.
    d-A partir de um vetor de numeros inteiros, calcule a soma e o produto dos elementos do vetor.
    f-Verifique se uma palavra e palindromo
    ex
     3*2
     1+1+1 + 1+1+1
    */
    int num1,num2,total;
    printf("\nDigite dois numeros para a multiplicacao:");
    scanf("%d %d",&num1,&num2);
    total=mult(num1,num2);
    printf("\n %d * %d = %d",num1,num2,total);
    return 0;
}
