//Diferenças de segunda ordem recursiva

#include <stdio.h>

int ordem(int);

int main(void){

  int n;

  printf("Insira o valor de N: ");
  scanf("%d", &n);
  printf("Yn = %d", ordem(n));
  printf("\n");

  return 0;
}

int ordem(int n){
  if(n == 1 || n == 2){
    return 0;
  }
  else{
    return (2 * (ordem(n-1))) + ordem(n-2) + n; 
  }
}