#define TRUE 1
#define FALSE 0
#define LSIZE 10

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_NOrd(int chave, TAluno lista[], int *tam);

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_Ord(int chave, TAluno lista[], int *tam);

// Listas Lineares de Alocação Sequencial 
typedef struct{
	TAluno* lista; 	// Para alocação dinâmica 
	int cap;		// Capacidade ou tamanho máximo da lista
	int tam;		// Tamanho da lista, inicialmente 0
    int eOrd;		// A lista é ordenada (TRUE ou FALSE)
} TListAlunos; // tam = 0 -> lista vazia; tam = cap -> lista cheia

// Funções para manipular TListAlunos 
TListAlunos* iniListAlunos(int cap, int eOrd);
void iniListAlunosPar(TListAlunos *lista, int cap, int eOrd);
int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);
TListAlunos* uniaoListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* diferenListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos* interListas(TListAlunos *listaA, TListAlunos *listaB);
void ordenaLista(TListAlunos *listaA);
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd);

// Percurso de listas lineares
void printLista(TAluno lista[], int tam);

// Listas Lineares de Alocação Sequencial: Pilha 
typedef struct{
	TAluno* pilha;
	int cap;  //pilha vazia quando topo = 0
	int topo; //pilha cheia quando topo = cap
}TPilhaAlunos; //last in first out - lifo

// Manipulação de Pilhas
void iniPilhaAlunos(TPilhaAlunos* pilha, int cap); 
int empilharAluno(TAluno aluno, TPilhaAlunos* pilha); //push
int desempilharALuno(TAluno* aluno, TPilhaAlunos* pilha); //pop 

// Listas Lineares de Alocação Sequencial: Filas
typedef struct{
	TAluno* fila;
	int cap;
	int ini; 	//fila vazia quando ini = fim
	int fim;  //fila cheia quando fim - ini = cap
}TFilaAlunos; //first in first out - fifo

// Manipulação de Filas
void iniFilaAlunos(TFilaAlunos* fila, int cap);
int insereNaFila(TAluno aluno, TFilaAlunos* fila);
int removeDaFila(TAluno* aluno, TFilaAlunos* fila);

// Nó encadeada
struct SNoALuno{
	int numMatricula; 		//chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   		// nome com até 99 caracteres
    char email[100];  		// eMail com até 99 caracteres
	struct SNoALuno *prox; 	// Endereço do próximo elemento
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

typedef struct{
	PNoAluno pilha;
	PNoAluno topo;
}TPilhaEncAlunos;

void iniPilhaEncAlunos(TPilhaEncAlunos* pilha);
int empulharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha);
int desempilharAlunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha);
void imprimePilha(TPilhaEncAlunos* pilha);
void liberaPilha(TPilhaEncAlunos* pilha);

typedef struct{
    PNoAluno head;
    PNoAluno tail;
}TFilaEncAlunos;

void iniFilaAlunosEnc(TFilaEncAlunos* fila);
int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos* fila);
int removeDaFilaEnc(TAluno* aluno, TFilaEncAlunos* fila);
void imprimeFila(TFilaEncAlunos* fila);
void liberaFila(TFilaEncAlunos* fila);