#define TRUE 1
#define FALSE 0
#define LSIZE 5

// Armazenando as informações de um aluno
typedef struct {
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

typedef struct {
	TAluno* lista;
	int cap;
	int tam;
    int eOrd;
} TListAlunos;


// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno *lista, int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno *lista, int *tam, int cap);
int remAluno_NOrd(int chave, TAluno *lista, int *tam);

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno *lista, int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno *lista, int *tam, int cap);
int remAluno_Ord(int chave, TAluno *lista, int *tam);

// Utilizar isto aqui no projeto 
TListAlunos* iniListAlunos(int cap, int eOrd);
int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);
void uniaoListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3);
void diferenListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3);
void interListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3);
void ordenaLista(TListAlunos *listaA);

void printLista(TListAlunos *lista);
TListAlunos* geraListAlunos(int tam, int cap, int eOrd);