#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"


// Manipulação de listas não ordenadas
int buscaAluno_NOrd(TAluno lista[], int tam, int chave){
    /*
        Utilizar a implementação proposta no Exemplo_06
        para busca em listas não ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
}
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap){
    /*
        Utilizar a implementação proposta no Exemplo_06
        para inclusão em listas não ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
}
int remAluno_NOrd(int chave, TAluno lista[], int *tam){
    /*
        Utilizar a implementação proposta no Exemplo_06
        para remoção em listas não ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
}

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave){
    /*
        Utilizar a implementação proposta no Exemplo_10
        para busca em listas ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
}
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap){
    /*
        Utilizar a implementação proposta no Exemplo_10
        para inclusão em listas ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho. 
        Em sala de aula foi proposta abrir
        espaço para o novo item da lista deslocando os 
        elementos no array da direita para esquerda. Esta
        modificação precisa ser implementada.
    */

}
int remAluno_Ord(int chave, TAluno lista[], int *tam){
    /*
        Utilizar a implementação proposta no Exemplo_10
        para remoção em listas ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
        Veja se a modificação feita na função de inclusão
        se aplica de alguma forma nesta função 
    */
}


// Utilizar isto aqui no projeto
//void iniListAlunos(TListAlunos* lista, int cap, int eOrd) 
//ou 
TListAlunos* iniListAlunos(int cap, int eOrd){
    /*
        Esta função aloca uma variável do tipo TListAluno
        contendo os atributos:
        * lista: Um array de tipo TAluno de tamanho definido em
        função da capacidade da lista (cap) e do tipo de 
        lista: ordenada (eOrd é verdadeiro) ou
        não ordenada (eOrd é falso);
        * cap: a capacidade da lista definida pelo parametro
        cap;
        * tam: o tamanho da lista inicializado como zero;
        * eOrd: o tipo de lista ordenada (eOrd é verdadeiro) ou
        não ordenada (eOrd é falso);
        Apresentamos duas versões
        do cabeçalho. Escolha a que achar mais apropriada. 
        Verifique se sua escolha bate com a definição do 
        ferramentas.h 
    */

}

int buscaChaveNaLista(int chave, TListAlunos *lista){

    /*
        Procurar uma chave na lista e retornar o índice
        no array em que a chave se encontra ou a posição em
        que um elemento com esta chave deveria ser incluído
        na lista. Lembre que as listas não possuem elementos
        com chave repetida.  
    */

}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista){
    /*
        Incluir um aluno na lista. A função retorna 
        verdadeiro se o item for incluído e falso 
        caso contrario. Um novo item não podera ser
        incluído na lista se já tiver um outro item
        nela com a mesma chave ou se a lista estiver 
        cheia. 
    */

}

int remAlunoDaLista(TAluno aluno, TListAlunos *lista){
    /*
        Remover um aluno na lista. A função retorna 
        verdadeiro se o item for removido e falso 
        caso contrario. Um novo item não podera ser
        removido da lista se não tiver um item
        nela com a chave do aluno que se deseja remover 
        ou se a lista estiver vazia. 
    */

}

TListAlunos* uniListas(TListAlunos *listaA, TListAlunos *listaB){
    /*
        Retorna uma nova lista formada pela união das duas
        listas (listaA e listaB). A nova lista deverá ser
        do mesmo tipo das listas de entrada (ordenada ou
        não ordenada) caso as duas listas sejam do mesmo 
        tipo. Escolha como definir o tipo da lista de saída
        caso as listas de entrada seja de tipos diferentes. 
        Como discutido em sala de aula, a capacidade da 
        lista de saída se calcula como a soma do tamanho da
        listaA e o tamanho da lista B. 
    */

}

TListAlunos* difListas(TListAlunos *listaA, TListAlunos *listaB){
    /*
        Retorna uma nova lista formada pela diferença da 
        listaA com a listaB, que representa os elementos 
        da listaA que não aparecem na listaB. A nova lista 
        deverá ser do mesmo tipo da listaA. Como discutido 
        em sala de aula, a capacidade da lista de saída se 
        calcula como o tamanho da listaA 
    */

}

TListAlunos* intListas(TListAlunos *listaA, TListAlunos *listaB){
    /*
        Retorna uma nova lista formada pela intersecção da 
        listaA com a listaB, que representa os elementos 
        da listaA que também estão na listaB. A nova lista 
        deverá ser do mesmo tipo das listas de entrada 
        (ordenada ou não ordenada) caso as duas listas sejam 
        do mesmo tipo. Escolha como definir o tipo da lista 
        de saída caso as listas de entrada seja de tipos 
        diferentes. Como discutido em sala de aula, a 
        capacidade da lista de saída se calcula como o 
        menor tamanho entre as listaA e listaB.
    */

}

void ordenaLista(TListAlunos *listaA){
    /*
        Casso a listaA seja uma lista não ordenada, muda
        a campo eOrd para verdadeiro e utiliza um 
        algoritmo apropriado para ordenar a lista em
        ordem crescente do campo chave. 
        Na aula do dia 12 de abril discutiremos em sala de
        aula os melhores algoritmos de ordenação. 

    */

}

void printLista(TAluno lista[], int tam){
    /*
        Utilizar a implementação ja disponível nos
        exemplos anteriores.
    */
}
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd){
    /*
        Retorna uma lista de alunos com capacidade cap de 
        tipo ordenada (eOrd verdadeiro) o não ordenada (eOrd
        falso) preenchida com tam itens com chaves geradas de 
        forma aleatória entre os anos 2000 e 2022. 
        * A chave tem que respeitar o número de 9 dígitos
        comecando com o ano seguido do semestre e do 
        sequencial de quatro dígitos;
        * As chaves geradas tem que ter itens de primeiro
        e segundo semestre;
        * Os campos nome e email dos itens podem ser
        preenchidos com um valor padrão qualquer.
    */
}

// Pilhas
void iniPilhaAlunos(TPilhaAlunos* pilha, int cap){
    pilha->cap = cap;
	pilha->topo = 0;
	pilha->pilha = (TAluno*) malloc(sizeof(TAluno)*cap);
} 

int empilharAluno(TAluno aluno, TPilhaAlunos* pilha) //push
{
    if(pilha->topo < pilha->cap)
	{
		pilha->pilha[pilha->topo].numMatricula = aluno.numMatricula;
		strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
		strcpy(pilha->pilha[pilha->topo].email, aluno.email);
		pilha->topo++;
		return TRUE;
	}else{
		return FALSE;
	}
}
int desempilharALuno(TAluno* aluno, TPilhaAlunos* pilha) //pop
{
    if(pilha->topo > 0)
	{
		pilha->topo--;
		aluno->numMatricula = pilha->pilha[pilha->topo].numMatricula;
		strcpy(aluno->nome, pilha->pilha[pilha->topo].nome);
		strcpy(aluno->email, pilha->pilha[pilha->topo].email);
		return TRUE;
	}else{
		return FALSE;
	}
} 

void iniFilaAlunos(TFilaAlunos* fila, int cap){
	fila->cap = cap;
	fila->ini = 0;
	fila->fim = 0;
	fila->fila = (TAluno*) malloc(sizeof(TAluno)*cap);
}

int insereNaFila(TAluno aluno, TFilaAlunos* fila){	
	if((fila->fim - fila->ini) < fila->cap){	
		int pos = fila->fim % fila->cap;
		fila->fila[pos].numMatricula = aluno.numMatricula;
		strcpy(fila->fila[pos].nome, aluno.nome);
		strcpy(fila->fila[pos].email, aluno.email);
		fila->fim++;
		return TRUE;
	}else{
		return FALSE;
	}
}

int removeDaFila(TAluno* aluno, TFilaAlunos* fila){
	if(fila->ini < fila->fim)
	{
		int pos = fila->ini%fila->cap;
		aluno->numMatricula = fila->fila[pos].numMatricula;
		strcpy(aluno->nome, fila->fila[pos].nome);
		strcpy(aluno->email, fila->fila[pos].email);
		fila->ini++;
		return TRUE;
	}else{
		return FALSE;
	}
}