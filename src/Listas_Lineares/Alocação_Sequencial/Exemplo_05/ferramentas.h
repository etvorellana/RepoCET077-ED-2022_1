#define TRUE 1
#define FALSE 0
#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int buscaAluno(TAluno lista[], int tam, int chave);
int incAluno(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno(int chave, TAluno lista[], int *tam);
void printLista(TAluno lista[], int tam);



