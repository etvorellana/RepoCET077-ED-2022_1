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
    struct SNoAluno *abaixo;
}SNoAluno;


typedef struct TPilhaAlunoEnc{
    SNoAluno *topo;
}TPilhaAlunoEnc;

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

//funcoes
void iniPilhaEncAlunos(TPilhaAlunoEnc *pilha){
    pilha->topo = NULL;
}

int empilharAlunoEnc(SNoAluno aluno, TPilhaAlunoEnc *pilha){
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux->numMatricula = aluno.numMatricula;
    strcpy(aux->nome, aluno.nome);
    strcpy(aux->email, aluno.email);
    aux->abaixo = NULL;

    if(pilha->topo == NULL){
        pilha->topo = aux;
        return 0;
    }
    aux->abaixo = pilha->topo;
    pilha->topo = aux;

    return 1;
}

int desempilharAlunoEnc(SNoAluno* aluno, TPilhaAlunoEnc* pilha){
    if(pilha->topo == NULL){
        printf("\nLista vazia. Não é possivel desempilhar.");
        return 0;
    }
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux = pilha->topo;
    aluno->numMatricula = aux->numMatricula;
    strcpy(aluno->email, aux->email);
    strcpy(aluno->nome, aux->nome);
    printf("\nremovido:  %d | %s | %s\n", aluno->numMatricula, aluno->email, aluno->nome );
    pilha->topo = aux->abaixo;
    return 1;
}
void imprimePilha(TPilhaAlunoEnc* pilha){
    SNoAluno *aux;
    aux = pilha->topo;
    while(aux!=NULL){
        printf("| Matricula: %d | E-mail: %s | Nome: %s |\n", aux->numMatricula, aux->email, aux->nome);
        aux = aux->abaixo;
    }
}

int removeJenga(TPilhaAlunoEnc* pilha, int indice){
    SNoAluno *aux;
    aux = pilha->topo;
    if(LSIZE==indice){
        pilha->topo = aux->abaixo;
        return 0;
    }
    for(int i = 1; i < LSIZE-indice ; i++){
        aux=aux->abaixo;
    }
    aux->abaixo = aux->abaixo->abaixo;
    aux=NULL;
    free(aux);
    return 1;
}

void liberaPilha(TPilhaAlunoEnc* pilha){

    SNoAluno *aux, *aux2;
    aux=pilha->topo;
    while(aux != NULL){
        aux2 = aux->abaixo;
        free(aux);
        aux = aux2;
        printf("Pilha liberada\n");

    }
    free(pilha);

}
int main(){

    srand(time(NULL));
    int indice;

    TPilhaAlunoEnc *pilha = (TPilhaAlunoEnc *) malloc(sizeof(TPilhaAlunoEnc));
    SNoAluno *alunoRemovido = (SNoAluno *) malloc(sizeof(SNoAluno));

    iniPilhaEncAlunos(pilha);

    for(int i=0; i<LSIZE; i++){
        empilharAlunoEnc(CriaAluno(), pilha);
    }

    printf("Empilhando 10: \n");
    imprimePilha(pilha);
    printf("\n");

    indice=(rand()%LSIZE) + 1;
    printf("Retirando aluno da posição: %d\n", indice);
    removeJenga(pilha, indice);
    imprimePilha(pilha);
    printf("\n");


    liberaPilha(pilha);

    printf("\n");

return 0;
}
