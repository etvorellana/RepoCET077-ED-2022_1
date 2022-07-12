//NOVA ARVORE PARA APRENDIZADO - TAINAH
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int info; 
    struct node* esq; 
    struct node* dir; 
} NO; 

NO* criaNo (int value);
NO* inserir (NO* raiz, int info);
void printArv(NO* raiz);
NO* busca(NO* raiz, int elem);
NO *removeAtual(NO *atual);
int remover(NO* raiz, int elem);

int main () {
    int control, valor, cont=0;
    NO *raiz = NULL; 
    
    do{
        printf("\nEscolha a operacao.:\t1 - Insercao\t2 - Busca\t3- Remocao\t4- Imprimir arvore\n");
        do{
            scanf("%d", &control);
        }while (control < 1 && control > 4);

        if(control==1){
            printf("\nDigite um valor inteiro:\t");
            valor = 2000 + rand() % 100;
            //scanf("%d", &valor);

            if(cont==0){
                raiz = inserir (raiz, valor);
            }
            else{
                inserir(raiz, valor);
            }

            printf("\n");
            printArv(raiz);
            printf("\n");
            
            cont++;
        }
        else if(control==2){
            printf("\nDigite o valor a ser pesquisado.:\t");
            scanf("%d", &valor);

            if(busca(raiz, valor)){
                printf("\nO elemento %d esta na arvore\n", valor);
            }
            else{ 
                printf("\nO elemento %d NAO esta na arvore\n", valor);
            }
        }
        else if(control==3){
            printf("%d\n", control);
            printf("\nDigite o valor a ser excluido.:\t");
            scanf("%d", &valor);

            if(remover(raiz, valor) != 0){
                printf("\nO elemento %d foi removido da arvore\n", valor);
            }
            else{ 
                printf("\nO elemento %d NAO esta na arvore\n", valor);
            }
        }
        else{
            printf("\n");
            printArv(raiz);
            printf("\n");
        }
        printf("\n1 - Continuar\t0- Finalizar\n");
        scanf("%d", &control);
    }while (control!=0);
    
    return 0;
}

NO* criaNo (int value) {
    NO* novoNode = malloc(sizeof(NO));
    novoNode->info = value;
    novoNode->esq = NULL;
    novoNode->dir = NULL;

    return novoNode;
}

NO* inserir (NO* raiz, int info) {
    if(raiz == NULL){
        return criaNo(info);
    }
    if(info < raiz->info){
        raiz->esq = inserir(raiz->esq, info);
    }
    else if(info > raiz->info){
        raiz->dir = inserir(raiz->dir, info);
    }
    return raiz;
}

void printArv(NO* raiz) {
    if(raiz != NULL) {
        printf("%d", raiz->info);
        printf(" ( ");
        printArv(raiz->esq);
        printArv(raiz->dir);
        printf(" ) ");
    }
}

NO* busca(NO* raiz, int elem) {
    if(raiz == NULL){
        return NULL;
    }
    if(elem == raiz->info){
        return raiz;
    }
    if(elem < raiz->info){
       return busca(raiz->esq, elem);
    }
    else{ 
       return busca(raiz->dir, elem);
    }
}

NO *removeAtual(NO *atual){
    NO *n1, *n2;
    if(atual->esq == NULL){ // Se não tiver esqueda
        n2 = atual->dir;
        free(atual);
        return n2;
    }
    n1 = atual;
    n2 = atual->esq;
    while(n2->dir != NULL){ // Enquanto não chegar ao elemento mais a direita do atual->esq
        n1 = n2;
        n2 = n2->dir;
    }
    if(n1 != atual){ // Se o elemento mais a direita do atual->esq não for o atual->esq->dir
        n1->dir = n2->esq;
        n2->esq = atual->esq;
    }
    n2->dir = atual->dir;
    free(atual);
    return n2;
}

int remover(NO* raiz, int elem){
    if(raiz==NULL){
        return 0;
    }
    NO *anterior = NULL;
    NO *atual = raiz;

    while(atual != NULL){
        if(elem == atual->info){ // Achou o nó
            if(atual == raiz){   
                raiz = removeAtual(atual); 
            }
            else{
                if(anterior->dir == atual){
                    anterior->dir = removeAtual(atual); // anterior->dir aponta para o novo nó (retorno da função removeAtual)
                }
                else{
                    anterior->esq = removeAtual(atual); // anterior->esq aponta para o novo nó (retorno da função removeAtual)
                }
            }
            return 1;
        }
        anterior = atual; // Não achou o nó
        // Verifica qual o próximo nó a ser analisado:
        if(elem > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
    

}