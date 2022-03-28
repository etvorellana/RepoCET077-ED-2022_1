//Fibonacci de forma iterativa

#include <stdio.h>

int main(void){

  int n, primeiro = 1, segundo = 1, fibo = 0;

  printf("Insira a posição(n>2): ");
  scanf("%d", &n);
  
  for (int i = 2; i < n; i++)
  {
    fibo = primeiro + segundo;
    primeiro = segundo;
    segundo = fibo;
  }

  printf("Numero de Fibonacci: %d", fibo);
  printf("\n");

  return 0;
}
