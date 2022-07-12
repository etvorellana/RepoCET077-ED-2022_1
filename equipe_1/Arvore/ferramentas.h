#define TRUE 1
#define FALSE 0
#define LSIZE 10

// Armazenando as informa��es de um aluno
typedef struct
{
    int numMatricula; // chave com 9 d�gitos (INT_MAX +2147483647)
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

// Listas Lineares de Aloca��o Sequencial
typedef struct
{
    TAluno *lista; // Para aloca��o din�mica
    int cap;       // Capacidade ou tamanho m�ximo da lista
    int tam;       // Tamanho da lista, inicialmente 0
    int eOrd;      // A lista � ordenada (TRUE ou FALSE)
} TListAlunos;     // tam = 0 -> lista vazia; tam = cap -> lista cheia

// Fun��es para manipular TListAlunos
TListAlunos *iniListAlunos(int cap, int eOrd);
void iniListAlunosPar(TListAlunos *lista, int cap, int eOrd);
int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);
TListAlunos *uniaoListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos *diferenListas(TListAlunos *listaA, TListAlunos *listaB);
TListAlunos *interListas(TListAlunos *listaA, TListAlunos *listaB);
void ordenaLista(TListAlunos *listaA);
TListAlunos *geraListaDeAlunos(int tam, int cap, int eOrd);

// Percurso de listas lineares
void printLista(TAluno lista[], int tam);

// Listas Lineares de Aloca��o Sequencial: Pilha
typedef struct
{
    TAluno *pilha;
    int cap;    // pilha vazia quando topo = 0
    int topo;   // pilha cheia quando topo = cap
} TPilhaAlunos; // last in first out - lifo

// Manipula��o de Pilhas
void iniPilhaAlunos(TPilhaAlunos *pilha, int cap);
int empilharAluno(TAluno aluno, TPilhaAlunos *pilha);     // push
int desempilharALuno(TAluno *aluno, TPilhaAlunos *pilha); // pop

// Listas Lineares de Aloca��o Sequencial: Filas
typedef struct
{
    TAluno *fila;
    int cap;
    int ini;   // fila vazia quando ini = fim
    int fim;   // fila cheia quando fim - ini = cap
} TFilaAlunos; // first in first out - fifo

// Manipula��o de Filas
void iniFilaAlunos(TFilaAlunos *fila, int cap);
int insereNaFila(TAluno aluno, TFilaAlunos *fila);
int removeDaFila(TAluno *aluno, TFilaAlunos *fila);


// N� lista duplamente encadeada
struct SNoAlunoDE
{
    TAluno aluno;
    struct SNoAlunoDE *dir; // Endere�o do pr�ximo elemento
    struct SNoAlunoDE *esq; // Endere�o do elemento anterior
};

typedef struct SNoAlunoDE TRaizArvAluno;
typedef TRaizArvAluno *PRaizArvAluno;

PRaizArvAluno iniArvAluno(void);
PRaizArvAluno criarArvoreDeLista(TListAlunos listaS);
PRaizArvAluno criarArvoreDeLista_C(TListAlunos listaS);
PRaizArvAluno criarArvoreDeLista_(TListAlunos *listaS);
PRaizArvAluno criarArvoreDeLista__(TListAlunos *listaS);
PRaizArvAluno incAlunoNaArv(TAluno aluno, PRaizArvAluno raiz);
PRaizArvAluno incAlunoNaArvOrd(TAluno aluno, PRaizArvAluno raiz);
void printArvore(PRaizArvAluno raiz, int modo);


//AVL Adelson, Velskii and Landis

struct SNoAlunoAVL
{
    TAluno aluno;
    struct SNoAlunoAVL *dir; // Endere�o do pr�ximo elemento
    struct SNoAlunoAVL *esq; // Endere�o do elemento anterior
    short int altura;
};

typedef struct SNoAlunoAVL TRaizArvAlunoAVL;
typedef TRaizArvAlunoAVL *PRaizArvAlunoAVL;

PRaizArvAlunoAVL iniArvAlunoAVL(void);
short alturaDoNoAVL(PRaizArvAlunoAVL no);
short balanceamento(PRaizArvAlunoAVL no);
PRaizArvAlunoAVL rotaEsquerda(PRaizArvAlunoAVL raiz);
PRaizArvAlunoAVL rotaDireita(PRaizArvAlunoAVL raiz);
PRaizArvAlunoAVL rotaDirEsq(PRaizArvAlunoAVL raiz);
PRaizArvAlunoAVL rotaEsqDir(PRaizArvAlunoAVL raiz);
PRaizArvAlunoAVL balancear(PRaizArvAlunoAVL raiz);
PRaizArvAlunoAVL incAlunoNaArvAVL(TAluno aluno, PRaizArvAlunoAVL raiz);
void printArvoreAVL(PRaizArvAlunoAVL raiz, int modo);

//Implementar
PRaizArvAlunoAVL buscaArvAlunoRecAVL(PRaizArvAlunoAVL raiz, int chave);
int remArvAlunoAVL(int aluno, PRaizArvAlunoAVL *raiz);
PRaizArvAlunoAVL procuraMenor(PRaizArvAlunoAVL atual);

PRaizArvAluno buscaArvAlunoOrd(PRaizArvAluno raiz, int chave);
int remArvAlunoOrd(int aluno, PRaizArvAluno *raiz);
PRaizArvAluno remAtualOrd(PRaizArvAluno atual);

PRaizArvAluno buscaArvAluno(PRaizArvAluno raiz, int chave);
PRaizArvAluno buscaArvAlunoPai(PRaizArvAluno raiz, int chave, PRaizArvAluno pai);
//int remArvAluno(int aluno, PRaizArvAluno *raiz);

PRaizArvAlunoAVL criarArvoreDeListaAVL(TListAlunos *listaS);
