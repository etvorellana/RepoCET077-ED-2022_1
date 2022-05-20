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
  int tam;
} TFilaEncAlunos;

typedef struct NoFila {
  char chave;
  struct NoFila *dir;
  struct NoFila *esq;
  TFilaEncAlunos *fila;
} NoFila;

typedef struct {
  NoFila *head; 
  int topo;  
} TPilhaEncDeFilas;

typedef DNoAluno *PNoAluno;
typedef NoFila *PNoFila;

PNoFila iniNoFila(void);
PNoAluno iniNoAluno(void);

//Filas Encadeadas
TFilaEncAlunos *iniFilaAlunosEnc();
int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos *fila);
int removeDaFilaEnc(TAluno *aluno, TFilaEncAlunos *fila);
void imprimeFila(TFilaEncAlunos *fila);
void liberaFila(TFilaEncAlunos *fila);

//Pilhas Encadeadas de Filas
TPilhaEncDeFilas *iniPilhaEncDeFilas(void);
int empilharFilaEnc(TFilaEncAlunos *fila, TPilhaEncDeFilas *pilha, char chave);
int desempilharFilaEnc(TFilaEncAlunos *fila, TPilhaEncDeFilas *pilha);
void imprimePilha(TPilhaEncDeFilas *pilha);
void liberaPilha(TPilhaEncDeFilas *pilha);

typedef struct {
  TAluno *lista;
  int cap;
  int tam;
  int eOrd;
} TListAlunos;

// Listas Lineares Sequenciais
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
