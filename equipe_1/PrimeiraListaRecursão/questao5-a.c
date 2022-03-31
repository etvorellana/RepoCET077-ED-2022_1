//Fibonacci de forma recursiva
//Para cada N é chamada 2 funções
//Complexidade de 2^n
#include <stdio.h>

int fibonacci(int);

int main(void){

  int n;

  printf("Insira a posição: ");
  scanf("%d", &n);
  printf("Numero de Fibonacci: %d", fibonacci(n));
  printf("\n");

  return 0;
}

int fibonacci(int n){
  if(n == 1 || n == 0){
    return n;
  }
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}