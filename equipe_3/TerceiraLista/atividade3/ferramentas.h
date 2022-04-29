#define TRUE 1
#define FALSE 0
#define LSIZE 30

// Armazenando as informações de um aluno
typedef struct {
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

void ordenaLista(TListAlunos *listaA);

void printPilha(TAluno pilha[], int topo);
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
} TFilaAlunos; //first in first out - fifo

// Filas
void iniFilaAlunos(TFilaAlunos* fila, int cap);
int insereNaFila(TAluno aluno, TFilaAlunos* fila);
int removeDaFila(TAluno* aluno, TFilaAlunos* fila);

void separaVetCal(TListAlunos *listaA, TPilhaAlunos *calouros, TFilaAlunos *veteranos);