#include <stdio.h>

void hanoi(int, char, char, char);
int main(void){
  int qtd;

  printf("Insira a quantidade de discos: ");
  scanf("%d", &qtd);

  hanoi(qtd, 'A', 'C', 'B');

  return 0;
}

void hanoi(int qtd, char origem, char destino, char aux){
  if (qtd > 0)
  {
    hanoi(qtd-1, origem, aux, destino);
    printf("%c --> %c\n", origem, destino);
    hanoi(qtd-1, aux, destino, origem);
  }
}