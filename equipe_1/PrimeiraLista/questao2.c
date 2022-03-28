#include <stdio.h>

int sucessor(int);
int predecessor(int);
int soma(int, int);

int main(void){
  
  int x, y;

  printf("Insira X: ");
  scanf("%d", &x);
  printf("Insira Y: ");
  scanf("%d", &y);
  printf("Soma de X + Y = %d", soma(x,y));
  printf("\n");

  return 0;
}

int sucessor(int x){
  return ++x; //Retorna o valor depois incrementa.
}
int predecessor(int y){
  return --y; //Retorna o valor depois decrementa.
}
int soma(int x, int y){
  if (y == 0)
  {
    return x;
  }
  return soma(sucessor(x), predecessor(y)); //Chama novamente a função aumentando X e diminuindo Y até que Y seja 0.
}