#define TRUE 1
#define FALSE 0
#define LSIZE 30

typedef struct {
    int numMatricula;
    char nome[100];
    char email[100];
} TAluno;

typedef struct DNoAluno {
    TAluno aluno;
    struct DNoAluno *dir;
    struct DNoAluno *esq;
} DNoAluno;

typedef struct {
    struct DNoAluno *head;
    int topo;
} TPilhaEncAlunos;

typedef struct NoFila {
    char chave;
    struct NoFila *dir;
    struct NoFila *esq;
    TPilhaEncAlunos *pilha;
} NoFila;

typedef struct {
    struct NoFila *head;
    int tam;
} TFilaEncDePilhas;

typedef DNoAluno *PNoAluno;
typedef NoFila *PNoPilha;

PNoPilha iniNoPilha();
PNoAluno iniNoAluno();

// Fila de Pilhas Encadeadas
TFilaEncDePilhas *iniFilaAlunosEnc(void);
int insereNaFilaEnc(TPilhaEncAlunos *pilha, TFilaEncDePilhas *fila, char chave);
int removeDaFilaEnc(TPilhaEncAlunos *pilha, TFilaEncDePilhas *fila);
void imprimeFila(TFilaEncDePilhas *fila);
void liberaFila(TFilaEncDePilhas *fila);

// Pilhas Encadeadas
TPilhaEncAlunos *iniPilhaEncDeFilas(void);
int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos *pilha);
int desempilharAlunoEnc(TAluno *aluno, TPilhaEncAlunos *pilha);
void imprimePilha(TPilhaEncAlunos *pilha);
void liberaPilha(TPilhaEncAlunos *pilha);

// Listas Lineares Sequenciais
typedef struct
{
    TAluno *lista;
    int cap;
    int tam;
    int eOrd;
} TListAlunos;

TListAlunos *iniListAlunos(int cap, int eOrd);
TListAlunos *geraListaDeAlunos(int tam, int cap, int eOrd);
void liberaLista(TListAlunos *lista);

int buscaAluno_NOrd(TAluno lista[], int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_NOrd(int chave, TAluno lista[], int *tam);

int buscaAluno_Ord(TAluno lista[], int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_Ord(int chave, TAluno lista[], int *tam);

int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);