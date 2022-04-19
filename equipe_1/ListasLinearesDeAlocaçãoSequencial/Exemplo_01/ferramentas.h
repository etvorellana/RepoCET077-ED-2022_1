#define TRUE 1
#define FALSE 0
#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;


// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave); //Conlcuido
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap); //Concluido
int remAluno_NOrd(int chave, TAluno lista[], int *tam); //Concluido

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave); //Concluido
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap); //Concluido
int remAluno_Ord(int chave, TAluno lista[], int *tam); //Concluido

void printLista(TListAlunos *listas);