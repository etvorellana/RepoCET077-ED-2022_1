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
	struct DNoAluno* head;
	int topo;
} TPilhaEncAlunos; 

typedef struct {
    struct DNoAluno *head;
    int tam;               
} TFilaEncAlunos;

typedef DNoAluno *PNoAluno;

PNoAluno iniNoAluno();

//Pilhas Encadeadas
TPilhaEncAlunos *iniPilhaEncAlunos(void);
int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos *pilha);
int desempilharAlunoEnc(TAluno *aluno, TPilhaEncAlunos *pilha);
void imprimePilha(TPilhaEncAlunos *pilha);
void liberaPilha(TPilhaEncAlunos *pilha);

//Filas Encadeadas
TFilaEncAlunos *iniFilaAlunosEnc(void);
int insereNaFilaEnc(TAluno aluno, TFilaEncAlunos *fila);
int removeDaFilaEnc(TAluno *aluno, TFilaEncAlunos *fila);
void imprimeFila(TFilaEncAlunos *fila);
void liberaFila(TFilaEncAlunos *fila);