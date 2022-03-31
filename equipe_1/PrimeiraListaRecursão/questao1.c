#include <stdio.h>

int decPraBin(int);

int main(void){

  int n;

  printf("Insira o Numero em Decimal: ");
  scanf("%d", &n);
  printf("Numero em Binario: %d", decPraBin(n));
  printf("\n");

  return 0;
}

int decPraBin(int n){
  if (n == 0)
  {
    return n;
  }
  else{
    return (n%2) + 10 * decPraBin(n/2); // Pega o resto do numero por 2, soma com 10 e chama função novamente passando esse numero divido por 2, até que esse numero chegue em zero, ai volta multiplicando o ultimo resto pelos anteriores.
  }
}