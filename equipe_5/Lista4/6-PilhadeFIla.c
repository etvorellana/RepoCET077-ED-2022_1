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
    struct TFilaAlunoEnc *abaixo;
}TFilaAlunoEnc;

typedef struct PilhaDeFila{
    TFilaAlunoEnc *topo;
}PilhaDeFila;

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

void imprimeFila(TFilaAlunoEnc* fila){
    if(fila->fim==NULL)
        printf("\nFILA VAZIA, IMPOSSIVEL IMPRIMIR\n\n");
    else{
        SNoAluno *aux;
        aux = fila->ini;
        int i = 1;
        while(aux!=NULL){
            printf("%d | Matricula: %d | E-mail: %s | Nome: %s |\n", i, aux->numMatricula, aux->email, aux->nome);
            aux = aux->prox;
            i++;
        }
    }
}

void iniFilaEncAlunos(TFilaAlunoEnc *fila){
    fila->ini = NULL;
    fila->fim = NULL;
    fila->abaixo = NULL;
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
        //printf("ALUNO INSERIDO: %d | %s | %s\n", aux->numMatricula, aux->email, aux->nome);
        return 0;
    }
    fila->fim->prox = aux;
    fila->fim = aux;
    //printf("ALUNO INSERIDO: %d | %s | %s\n", aux->numMatricula, aux->email, aux->nome);
    return 1;
}

int removeDaFilaEnc(SNoAluno* aluno, TFilaAlunoEnc* lista){
    if(lista->ini == NULL) {
        lista->fim = NULL;
        printf("LISTA VAZIA, NAO EH POSSIVEL REMOVER.\n");
        return 0;
    }
    SNoAluno *aux = (SNoAluno*) malloc(sizeof(SNoAluno));
    aux = lista->ini;
    aluno->numMatricula = aux->numMatricula;
    strcpy(aluno->nome, aux->nome);
    strcpy(aluno->email, aux->email);
    lista->ini = aux->prox;
    free(aux);
    return 1;
}


void liberaFila(TFilaAlunoEnc* fila){
      SNoAluno *aux, *aux2;
      aux = fila->ini;
      while(aux!=NULL){
        aux2 = aux->prox;
        aux->prox=NULL;
        aux=NULL;
        free(aux);
        aux = aux2;
    }
    fila->fim=NULL;
    fila=NULL;
    free(fila);
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

//PILHA DE FILA

void iniPilhaDeFila(PilhaDeFila *pilhaFila){
    pilhaFila->topo = NULL;
}

int empilharFilaEnc(TFilaAlunoEnc *fila, PilhaDeFila *pilha){
    TFilaAlunoEnc *aux = (TFilaAlunoEnc*) malloc(sizeof(TFilaAlunoEnc));
    aux->ini = fila->ini;
    aux->fim = fila->fim;
    aux->abaixo = NULL;

    if(pilha->topo == NULL){
        pilha->topo = aux;
        //printf("\n\n");
        //imprimeFila(aux);
        //printf("\n\n");
        return 0;
    }
    aux->abaixo = pilha->topo;
    pilha->topo = aux;
    //printf("\n\n");
    //imprimeFila(aux);
    //printf("\n\n");
    return 1;
}

int removeFilaEnc(TFilaAlunoEnc* fila, PilhaDeFila* pilha){
   if(pilha->topo == NULL){
        printf("\nPILHA VAZIA, NAO EH POSSIVEL DESEMPILHAR.");
        return 0;
    }
    TFilaAlunoEnc *aux = (TFilaAlunoEnc*) malloc(sizeof(TFilaAlunoEnc));
    aux = pilha->topo;
    fila->ini = aux->ini;
    fila->fim = aux->fim;
    fila->abaixo = aux->abaixo;
    //printf("\nremovido:" );
    //imprimeFila(aux);
    pilha->topo = aux->abaixo;
    liberaFila(aux);
    return 1;
}

void imprimePilhaFila(PilhaDeFila* pilha){
    if(pilha->topo==NULL)
        printf("\nPILHA VAZIA, IMPOSSIVEL IMPRIMIR\n\n");
    else{
        TFilaAlunoEnc *auxFila;
        int i;
        auxFila = pilha->topo;
        i = 1;
        printf("\nIMPRIMINDO DO TOPO PARA BAIXO: \n");
        while(auxFila!=NULL){
            printf("\n%d:\n", i);
            imprimeFila(auxFila);
            auxFila=auxFila->abaixo;
            i++;
        }
    }
}

void liberaPilhaFila(PilhaDeFila* pilha){
    TFilaAlunoEnc *aux, *auxFila;
    auxFila=pilha->topo;
    aux=pilha->topo;
    while(aux != NULL){
        liberaFila(aux);
        aux=auxFila->abaixo;
        auxFila=auxFila->abaixo;
    }
    pilha->topo=NULL;
    pilha=NULL;
    free(pilha);
    printf("\nPILHA LIBERADA\n");
}

int main(){

    srand(time(NULL));

    int indice,i, j, quant;
    PilhaDeFila *pFila = (PilhaDeFila *) malloc(sizeof(PilhaDeFila));
    TFilaAlunoEnc *fila = (TFilaAlunoEnc *) malloc(sizeof(TFilaAlunoEnc));
    TFilaAlunoEnc *filaRemovida = (TFilaAlunoEnc *) malloc(sizeof(TFilaAlunoEnc));

    iniPilhaDeFila(pFila);
    iniFilaEncAlunos(fila);

    imprimePilhaFila(pFila);
    imprimeFila(fila);

    printf("\nQUANTAS FILAS DE 10 ALUNOS GOSTARIA DE EMPILHAR?: ");
    scanf("%d", &quant);
    printf("EMPILHANDO %d FILAS DE %d ALUNOS: \n", quant, LSIZE);

    for(j=0; j<quant; j++){
        for(i=0; i<LSIZE; i++){
            insereNaFilaEnc(CriaAluno(),fila);
        }
        empilharFilaEnc(fila,pFila);
        fila->abaixo=NULL;
        fila->fim=NULL;
        fila->ini=NULL;
    }

    imprimePilhaFila(pFila);

    printf("\n\n----------------------------------------------------------------------------------------------\n");
    printf("REMOVENDO 2 FILAS DO TOPO DA PILHA. \n\n\n\n");

    removeFilaEnc(filaRemovida, pFila);
    removeFilaEnc(filaRemovida, pFila);
    imprimePilhaFila(pFila);

    printf("\n\n----------------------------------------------------------------------------------------------\n");
    printf("INSERINDO MAIS 2 FILAS NO TOPO DA PILHA.\n\n\n\n");

    for(j=0; j<2; j++){
        for(i=0; i<LSIZE; i++){
            insereNaFilaEnc(CriaAluno(),fila);
        }
        empilharFilaEnc(fila,pFila);
        fila->abaixo=NULL;
        fila->fim=NULL;
        fila->ini=NULL;
    }

    imprimePilhaFila(pFila);

    printf("\n\n----------------------------------------------------------------------------------------------\n");
    printf("LIBERANDO PILHA DE FILAS.\n\n\n\n");

    liberaPilhaFila(pFila);
    imprimePilhaFila(pFila);

    return 0;

}
