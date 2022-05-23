#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LSIZE 10

// structs
typedef struct SNoAluno{
    int numMatricula;
    char nome[100];
    char email[100];
    struct SNoAluno *prox;
}SNoAluno;


typedef struct TFilaAlunoEnc{
    SNoAluno *ini;
    SNoAluno *fim;
}TFilaAlunoEnc;

// funcoes
SNoAluno CriaAluno(){
    SNoAluno *newAluno = (struct SNoAluno*) malloc(sizeof(SNoAluno));
    // Ano 2000 a 2022 * 100000, ex. 20aa00000
    newAluno->numMatricula = (2000 + (rand() % 22)) * 100000;
    // Semestre 1 a 2 * 10000, ex. 20aas0000
    newAluno->numMatricula += ((rand() % 2) + 1) * 10000;
    // Numero sequencial 1 a 999, ex. 20aasxxxx
    newAluno->numMatricula += (rand() % 999) + 1;
    sprintf(newAluno->email, "%d@uesc.br", newAluno->numMatricula);
    sprintf(newAluno->nome, "Aluno_%d", newAluno->numMatricula);
    return *newAluno;
}


void iniFilaEncAlunos(TFilaAlunoEnc *fila){
    fila->ini = NULL;
    fila->fim = NULL;
}

int insereNaFilaEnc(SNoAluno aluno, TFilaAlunoEnc *fila){
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux->numMatricula = aluno.numMatricula;
    strcpy(aux->nome, aluno.nome);
    strcpy(aux->email, aluno.email);
    aux->prox = NULL;

    if(fila->ini == NULL){
        fila->ini = aux;
        fila->fim = fila->ini;
        return 0;
    }
    fila->fim->prox = aux;
    fila->fim = aux;
    return 1;
}

int removeDaFilaEnc(SNoAluno* aluno, TFilaAlunoEnc* lista){
    if(lista->ini == NULL) {
        lista->fim = NULL;
        printf("Lista vazia. Nao é possivel remover.\n");
        return 0;
    }
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux = lista->ini;
    aluno->numMatricula = aux->numMatricula;
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);

    lista->ini = aux->prox;
    //aluno = aux;
    free(aux);

    return 1;
}

void imprimeFila(TFilaAlunoEnc* fila){
    SNoAluno *aux;
    aux = fila->ini;
    int i = 1;
    while(aux!=NULL){
        printf("%d | Matricula: %d | E-mail: %s | Nome: %s |\n", i, aux->numMatricula, aux->email, aux->nome);
        aux = aux->prox;
        i++;
    }
}

int removeFuraFila(TFilaAlunoEnc* fila, int indice){
    SNoAluno *aux= (SNoAluno*) malloc(sizeof(SNoAluno));
    aux = fila->ini;
    for(int i = 0; i < indice-2 ; i++){
        aux=aux->prox;
    }
    aux->prox = aux->prox->prox;
    return 0;
}

void liberaFila(TFilaAlunoEnc* fila){
      SNoAluno *aux, *aux2;
      aux = fila->ini;
      while(aux!=NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(fila);
}

int main(){

    srand(time(NULL));

    int indice;

    TFilaAlunoEnc *fila = (TFilaAlunoEnc *) malloc(sizeof(TFilaAlunoEnc));
    SNoAluno *alunoRemovido = (SNoAluno *) malloc(sizeof(SNoAluno));

    iniFilaEncAlunos(fila);

    printf("Enfilerando 20: \n");
    for(int i=0; i<LSIZE; i++){
        insereNaFilaEnc(CriaAluno(),fila);
    }


    imprimeFila(fila);
    printf("\n\n");
    indice=(rand()%LSIZE)+1;
    printf("Retirando fura-fila na posicao: %d\n\n", indice);

    removeFuraFila(fila,indice);
    imprimeFila(fila);
    printf("\n\n");


    liberaFila(fila);
    printf("\n\n");

    return 0;

}
