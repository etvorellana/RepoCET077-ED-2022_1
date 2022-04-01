#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int soma (int num){
    if(num==2){
        return 1;
    }else{
        if(num==1){
        return 0;
        }else{
            return (num-1)+soma(num-1);
        }
    }
}
int main(){
    /*
    6-Implemente uma  soma(n) que calcula o somatrio dos n primeiros numeros inteiros.
    Qual e a ordem de complexidade da sua funcao? Qual seria a ordem de complexidade dessa mesma funcao
     implementada sem utilizar recursividade? O que voce conclui?
     ex:n=4
     0+1+2+3=6
    */

    //Conclui-se que a ordem de complexidade seria aproximadamente a mesma sendo iterativa ou recursiva.
    int n,total=0;

    printf("\nDigite o numero:");
    scanf("%d",&n);
    printf("\nResultado Recursivo:%d",soma(n));
    for(int i=0;i<n;i++){
        total=total+i;
    }
    printf("\nResultado:%d",total);
    return 0;
}
