#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void torre(int d,char origem,char aux,char destino){
    if(d==1){
        printf("\nMover de %c para %c",origem,destino);
    }else{
        torre(d-1,origem,destino,aux);
        printf("\nMover de %c para %c",origem,destino);
        torre(d-1,aux,origem,destino);
    }
}

int main(){
    int discos;
    printf("\nEscolha um numero de discos:");
    scanf("%d",&discos);
    torre(discos,'O','A','D');

    /*A complexidade do problema : 2^n , sendo n a quantidade de discos*/
    return 0;

}
