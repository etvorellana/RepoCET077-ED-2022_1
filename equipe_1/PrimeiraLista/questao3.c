#include <stdio.h>

int multiplicaNatural(int, int);

int main(void){

  int i,j;

  printf("Insira o valor  1 e 2: ");
  scanf("%d%d", &i, &j);

  printf("Multiplicação Natural:.........: %d\n", multiplicaNatural(i,j));

  return 0;
}

int multiplicaNatural(int i, int j){
  if (i == 0)
  {
    return i;
  }
  else{
    return j + multiplicaNatural(i-1, j);
  }
}