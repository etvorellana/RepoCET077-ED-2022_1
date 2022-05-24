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
    struct TPilhaAlunoEnc *prox;
}TPilhaAlunoEnc;

typedef struct FilaDePilha{
    TPilhaAlunoEnc *ini;
    TPilhaAlunoEnc *fim;
}FilaDePilha;


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
    pilha->prox = NULL;
}

int empilharAlunoEnc(SNoAluno aluno, TPilhaAlunoEnc *pilha){
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux->numMatricula = aluno.numMatricula;
    strcpy(aux->nome, aluno.nome);
    strcpy(aux->email, aluno.email);
    aux->abaixo = NULL;

    if(pilha->topo == NULL){
        pilha->topo = aux;
        //printf(" | Matricula: %d | E-mail: %s | Nome: %s |\n", aux->numMatricula, aux->email, aux->nome);
        return 0;
    }
    aux->abaixo = pilha->topo;
    pilha->topo = aux;
    //printf(" | Matricula: %d | E-mail: %s | Nome: %s |\n", aux->numMatricula, aux->email, aux->nome);
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

        aux = aux2;
        aux=NULL;
        free(aux);
        //printf("Pilha liberada\n");

    }
    pilha=NULL;
    free(pilha);

}

//FILA DE PILHA

void iniFilaPilha(FilaDePilha *filaPilha){
    filaPilha->ini = NULL;
    filaPilha->fim = NULL;
}

int insereNaFilaPilha(TPilhaAlunoEnc *pilha, FilaDePilha *fila){
    TPilhaAlunoEnc *aux = (TPilhaAlunoEnc*) malloc(sizeof(TPilhaAlunoEnc));
    aux->topo= pilha->topo;
    aux->prox = NULL;

    if(fila->ini== NULL){
        fila->ini = aux;
        fila->fim = fila->ini;
        return 0;
    }
    fila->fim->prox = aux;
    fila->fim = aux;
    return 1;
}

int removePilhaEnc(TPilhaAlunoEnc* pilha, FilaDePilha* fila){
    if(fila->ini == NULL) {
        fila->fim = NULL;
        printf("Lista vazia. Nao é possivel remover.\n");
        return 0;
    }
    TPilhaAlunoEnc *aux = (TPilhaAlunoEnc*) malloc(sizeof(TPilhaAlunoEnc));
    aux = fila->ini;
    pilha->topo = aux->topo;

    printf("\nremovido:" );
    imprimePilha(aux);
    fila->ini = aux->prox;
    free(aux);

    return 1;
}

void imprimeFilaPilha(FilaDePilha* fila){
    TPilhaAlunoEnc *auxPilha;
    auxPilha = fila->ini;
    int i = 1;
    printf("\nIMPRIMINDO: \n");
    while(auxPilha!=NULL){
        printf("\n%d:\n", i);
        imprimePilha(auxPilha);
        auxPilha = auxPilha->prox;
        i++;
    }
}

void liberaFilaPilha(FilaDePilha* fila){
      TPilhaAlunoEnc *aux, *auxPilha;
      aux = fila->ini;
      while(aux!=NULL){
        liberaPilha(aux);
        auxPilha = aux->prox;
        aux=NULL;
        free(aux);
        aux = auxPilha;
    }
    fila->ini=NULL;
    fila->fim=NULL;
    free(fila);
    printf("\nPILHA LIBERADA\n");
}

int main(){

    srand(time(NULL));
    int indice, i, j, quant;


    FilaDePilha *fPilha = (FilaDePilha *) malloc(sizeof(FilaDePilha));
    TPilhaAlunoEnc *pilha = (TPilhaAlunoEnc *) malloc(sizeof(TPilhaAlunoEnc));
    TPilhaAlunoEnc *pilhaRemovida = (TPilhaAlunoEnc *) malloc(sizeof(TPilhaAlunoEnc));

    iniFilaPilha(fPilha);
    iniPilhaEncAlunos(pilha);

    imprimeFilaPilha(fPilha);
    imprimePilha(pilha);


    printf("\nQUANTAS PILHAS DE 10 ALUNOS GOSTARIA DE POR NA FILA?: ");
    scanf("%d", &quant);
    printf("PONDO NA FILA %d PILHAS DE %d ALUNOS: \n", quant, LSIZE);

    for(j=0; j<quant; j++){
        for(i=0; i<LSIZE; i++){
            empilharAlunoEnc(CriaAluno(),pilha);
        }
        insereNaFilaPilha(pilha,fPilha);
        pilha->topo=NULL;
        pilha->prox=NULL;
    }
    imprimeFilaPilha(fPilha);
        printf("\n\n----------------------------------------------------------------------------------------------\n");
        printf("REMOVENDO 2 PILHAS DO INICIO DA FILA. \n\n\n\n");

        removePilhaEnc(pilhaRemovida, fPilha);
        removePilhaEnc(pilhaRemovida, fPilha);
        imprimeFilaPilha(fPilha);

        printf("\n\n----------------------------------------------------------------------------------------------\n");
        printf("INSERINDO MAIS 2 PILHA NO FIM DA FILA.\n\n\n\n");

        for(j=0; j<2; j++){
            for(i=0; i<LSIZE; i++){
             empilharAlunoEnc(CriaAluno(),pilha);
            }
            insereNaFilaPilha(pilha,fPilha);
            pilha->topo=NULL;
            pilha->prox=NULL;

        }
        imprimeFilaPilha(fPilha);

        printf("\n\n----------------------------------------------------------------------------------------------\n");
        printf("LIBERANDO PILHA DE FILAS.\n\n\n\n");


        liberaPilha(pilha);
        liberaFilaPilha(fPilha);

return 0;
}
