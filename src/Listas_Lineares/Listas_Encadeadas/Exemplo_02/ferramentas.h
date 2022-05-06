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

// Nó lista simplesmente encadeada
struct SNoALuno{
	int numMatricula; 		//chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   		// nome com até 99 caracteres
    char email[100];  		// eMail com até 99 caracteres
	struct SNoALuno *prox; 	// Endereço do próximo elemento
};

typedef struct SNoALuno TNoAluno;
typedef TNoAluno *PNoAluno;

// Criar e inicializar um no 
PNoAluno iniNoAluno(void);
PNoAluno criarListEncDeListSeq(TListAlunos* listaS);

// Percurso de listas lineares
void printLisEncAluno(PNoAluno lista);

// Manipulação de listas encadeadas não ordenadas
PNoAluno buscaAlunoEnc_NOrd(PNoAluno head, PNoAluno tail, int chave);
int incAlunoEnc_NOrd(TAluno aluno, PNoAluno head, PNoAluno tail);
int remAlunoEnc_NOrd(int chave, PNoAluno head, PNoAluno tail);

// Manipulação de listas encadeadas ordenadas
PNoAluno buscaAlunoEnc_Ord(PNoAluno head, PNoAluno tail, int chave);
int incAlunoEnc_Ord(TAluno aluno, PNoAluno head, PNoAluno tail);
int remAlunoEnc_Ord(int chave, PNoAluno head, PNoAluno tail);

// Listas Lineares encadeadas
typedef struct{
	PNoAluno head; 	// Ponteiros para a cabeça 
	PNoAluno tail; 	// Ponteiro para a calda
	int tam;		// Tamanho da lista, inicialmente 0
    int eOrd;		// A lista é ordenada (TRUE ou FALSE)
} TListAlunosEnc; 	// head->prox = tail -> lista vazia

TListAlunosEnc* iniListAlunosEnc(int eOrd);