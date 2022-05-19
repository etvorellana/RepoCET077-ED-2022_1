#define TRUE 1
#define FALSE 0
#define LSIZE 10

#define MAX 100

// Armazenando as informa��es de um aluno
typedef struct
{
    int numMatricula; //chave com 9 d�gitos (INT_MAX +2147483647)
    char nome[100];   // nome com at� 99 caracteres
    char email[100];  // eMail com at� 99 caracteres
} TAluno;

// Manipula��o de listas n�o ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_NOrd(int chave, TAluno lista[], int *tam);

// Manipula��o de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_Ord(int chave, TAluno lista[], int *tam);

typedef struct{
	TAluno* lista;
	int cap;
	int tam;
    int eOrd;
} TListAlunos;

// Utilizar isto aqui no projeto
TListAlunos* iniListAlunos(int cap, int eOrd);
void iniListAlunosPar(TListAlunos *lista, int cap, int eOrd);
int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);
TListAlunos* uniaoListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* diferenListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB);
void ordenaLista(TListAlunos *listaA);

void printLista(TAluno lista[], int tam);
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd);

typedef struct{
	TAluno* pilha;
	int cap;  //pilha vazia quando topo = 0
	int topo; //pilha cheia quando topo = cap
}TPilhaAlunos; //last in first out - lifo

// Pilhas
void iniPilhaAlunos(TPilhaAlunos* pilha, int cap);
int empilharAluno(TAluno aluno, TPilhaAlunos* pilha); //push
int desempilharALuno(TAluno* aluno, TPilhaAlunos* pilha); //pop

typedef struct{
	TAluno* fila;
	int cap;
	int ini; 	//fila vazia quando ini = fim
	int fim;  //fila cheia quando fim - ini = cap
	int tam;
}TFilaAlunos; //first in first out - fifo

// Filas
void iniFilaAlunos(TFilaAlunos* fila, int cap);
int insereNaFila(TAluno aluno, TFilaAlunos* fila);
int removeDaFila(TAluno* aluno, TFilaAlunos* fila);
void printFila(TFilaAlunos* fila);
void colocaPilhaFila(TListAlunos* alunos, TPilhaAlunos* palunos, TFilaAlunos* falunos, int DATA);

// Pilha Encadeada
struct SNoALuno{
    int numMatricula;
    char nome[100];
    char email[100];
    struct SNoALuno *prox;
};

typedef struct SNoALuno TNoAluno;
typedef TNoAluno *PNoAluno;

struct SNoAluno{
    int numMatricula;
    char nome[100];
    char email[100];
    struct SNoAluno *dir;
    struct SNoAluno *esq;
};

typedef struct TPilhaEncAluno{
	PNoAluno topo;
	struct TPilhaEncAluno* prox;
}TPilhaEncAlunos;

void iniPilhaEncAlunos(TPilhaEncAlunos* pilha);
int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha);
int desempilharALunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha);
void liberaPilha(TPilhaEncAlunos* pilha);
void imprimePilha(TPilhaEncAlunos* pilha);

typedef struct{
    PNoAluno head;
    PNoAluno tail;
}TFilaEncAlunos;

void iniFilaAlunosEnc(TFilaEncAlunos* fila);
int insereNaFilaEnc(TAluno aluno,TFilaEncAlunos* fila);
int removeDaFilaEnc(TAluno* aluno,TFilaEncAlunos* fila);
void imprimeFila(TFilaEncAlunos* fila);
void liberaFila(TFilaEncAlunos* fila);

typedef struct{
    TPilhaEncAlunos* head;
    TPilhaEncAlunos* tail;
}FilaDePilhas;

void iniFilaDePilha(FilaDePilhas* fila);
int insereFilaDePilha(TPilhaEncAlunos* pilha, FilaDePilhas* fila);
int removeFilaDePilha(TPilhaEncAlunos* pilha, FilaDePilhas* fila);
void imprimeFilaPilha(FilaDePilhas* fila);
void liberaFilaDePilha(FilaDePilhas* fila);
