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
  if(qtd == 1){
    printf("\nMova o disco 1 da base %c --> %c\n", origem, destino);
    return;
  }
  {
    hanoi(qtd-1, origem, aux, destino); // Resolve para n-1 discos, movendo para o disco aux
    printf("\nMova o disco %d da base %c --> %c\n", qtd, origem, destino);
    hanoi(qtd-1, aux, destino, origem); // Resolve para n-1 discos, movendo da aux para o destino
  }
}