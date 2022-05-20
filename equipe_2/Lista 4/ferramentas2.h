#define TRUE 1
#define FALSE 0
#define LSIZE 10

// Armazenando as informações de um aluno
typedef struct{
  int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
  char nome[100];   // nome com até 99 caracteres
  char email[100];  // eMail com até 99 caracteres
} TAluno;

// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap);

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap);
  
typedef struct{
	TAluno* lista;
	int cap; 
	int tam;
    int eOrd;
} TListAlunos;

TListAlunos* iniListAlunos(int cap, int eOrd);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);

TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd);
  

// Nó lista encadeada
struct SNoALuno{
	int numMatricula;        //chave com 9 dígitos (INT_MAX	+2147483647)
  char nome[100];         // nome com até 99 caracteres
  char email[100];        // eMail com até 99 caracteres
	struct SNoALuno *prox;  // Endereço do próximo elemento
};

typedef struct SNoALuno TNoAluno;
typedef TNoAluno *PNoAluno;

// Criar e inicializar um no 
PNoAluno iniNoAluno(void);


// Nó lista duplamente encadeada
struct DnoALuno{
	int numMatricula;        //chave com 9 dígitos (INT_MAX	+2147483647)
  char nome[100];         // nome com até 99 caracteres
  char email[100];        // eMail com até 99 caracteres
	struct DNoALuno *dir;  // Endereço do próximo elemento
  struct DNoALuno *esq;  // Endereço do elemento anterior
};
typedef struct DnoALuno TNoAlunoD;
typedef TNoAlunoD *PNoAlunoD;
PNoAlunoD iniNoAlunoD(void);

/*
typedef struct{
  PNoAlunoD pilha;
  PNoAlunoD topo;
  int tam;
}TPilhaAlunoEnc;
*/

typedef struct{
  PNoAluno pilha;
  PNoAluno topo;
  int tam;
}TPilhaAlunoEnc;

void iniPilhaEncAlunos(TPilhaAlunoEnc* pilha);
int empilharAlunoEnc(TAluno aluno, TPilhaAlunoEnc* pilha);
int desempilharAlunoEnc(TAluno* aluno, TPilhaAlunoEnc* pilha);
void imprimePilha(TPilhaAlunoEnc* pilha);
void liberaPilha(TPilhaAlunoEnc* pilha);//desempilha e libera toda a pilha

typedef struct{
  PNoAluno fila;
  PNoAluno ini;
  PNoAluno fim;
  int tam;
}TFilaAlunoEnc;

void iniFilaAlunosEnc(TFilaAlunoEnc* fila);
int insereNaFilaEnc(TAluno aluno, TFilaAlunoEnc* fila);
int removeDaFilaEnc(TAluno* aluno, TFilaAlunoEnc* fila);
void imprimeFila(TFilaAlunoEnc* fila);
void liberaFila(TFilaAlunoEnc* fila);//desempilha e libera toda a fila

struct TNoPilha{
  TPilhaAlunoEnc* pilha;
  struct TNoPilha *prox;
};

typedef struct TNoPilha TNoPilha;
typedef TNoPilha *PNoPilha;
PNoPilha iniNoPilha(void);

typedef struct{
  PNoPilha pilha;
  PNoPilha fim;
  PNoPilha ini;
  int pilhas;
}TFilaDePilha;



void iniFilaDePilhas(TFilaDePilha* fp);
int inserePilha(TPilhaAlunoEnc* pilhaOrg, TFilaDePilha* fp);
int removePilha(TPilhaAlunoEnc* popPilha, TFilaDePilha* fp);
int insereEmPiha(int indice, TAluno aluno, TFilaDePilha* fp);
int removeEmPilha(int indice, TAluno* aluno, TFilaDePilha* fp);
void imprimeFilaDePilhasAll(TFilaDePilha fp);
int imprimeFilaDePilha(int indice, TFilaDePilha fp);
void liberaFilaDePilhasAll(TFilaDePilha* fp);
int liberaFilaDePilha(int indice, TFilaDePilha* fp);
