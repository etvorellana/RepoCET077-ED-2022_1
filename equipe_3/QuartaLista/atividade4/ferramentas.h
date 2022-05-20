#define TRUE 1
#define FALSE 0
#define LSIZE 10

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

typedef DNoAluno *PNoAluno;

PNoAluno iniNoAluno();

//Filas Encadeadas
TFilaEncAlunos *iniFilaAlunosEnc(void);
int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos *fila);
int removeDaFilaEnc(TAluno *aluno, TFilaEncAlunos *fila);
void imprimeFila(TFilaEncAlunos *fila);
void liberaFila(TFilaEncAlunos *fila);

//Listas Lineares Sequenciais
typedef struct {
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