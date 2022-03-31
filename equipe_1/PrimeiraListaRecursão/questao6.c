//somatorio recursivo

#include <stdio.h>

int somatorio(int);

int main(void){

  int n;

  printf("Insira a quantidade de numeros a serem calculados: ");
  scanf("%d", &n);
  printf("Somatorio: %d", somatorio(n));
  printf("\n");

  return 0;
}

int somatorio(int n){
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return n + somatorio(n-1);
  }
}