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
   int i = 0;
	while (i < tam)
	{
		if (lista[i].numMatricula == chave)
			return i; //achou retorna o índice  
		i++;
	}
	return tam; //não achou, retorna tamLista
}
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap){
    /*
        Utilizar a implementação proposta no Exemplo_06
        para inclusão em listas não ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
   if (*tam == cap)
        return FALSE; //lista cheia
	if (buscaAluno(lista, *tam, aluno.numMatricula) == *tam){
		lista[*tam].numMatricula = aluno.numMatricula;
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}else
        return FALSE;
}
int remAluno_NOrd(int chave, TAluno lista[], int *tam){
    /*
        Utilizar a implementação proposta no Exemplo_06
        para remoção em listas não ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno(lista, *tam, chave);
    if (pos < *tam){
        *tam -= 1;
        lista[pos].numMatricula = lista[*tam].numMatricula;
        strcpy(lista[pos].nome, lista[*tam].nome);
        strcpy(lista[pos].email, lista[*tam].email);
        //se o cara que for removido for o ultimo o elemento continua na memoria
        return TRUE;
    }else
        return FALSE;
}

// Manipulação de listas ordenadas
int buscaAluno_Ord(TAluno lista[], int tam, int chave){
    /*
        Utilizar a implementação proposta no Exemplo_10
        para busca em listas ordenadas. Você pode
        propor modificações no código visando melhorias
        no desempenho.
    */
    int min = 0, max = tam, i;
    while (min != max)      {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i;
        else
            if (lista[i].numMatricula > chave)
                max = i;
            else
                return i;
    }
    return i;
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
   if (*tam == cap)
        return FALSE; //lista cheia
    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
	if ( pos == *tam){
        // nao existe na lista
        lista[*tam].numMatricula = aluno.numMatricula; 
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}else{
        // existe na lista
        if(lista[pos].numMatricula != aluno.numMatricula){
            TAluno troca;
            for(int i = pos; i < *tam; i++){
                troca.numMatricula = lista[i].numMatricula;
                strcpy(troca.nome, lista[i].nome);
                strcpy(troca.email, lista[i].email);
                
                lista[i].numMatricula = aluno.numMatricula;
                strcpy(lista[i].nome, aluno.nome);
                strcpy(lista[i].email, aluno.email);

                aluno.numMatricula = troca.numMatricula;
                strcpy(aluno.nome, troca.nome);
                strcpy(aluno.email, troca.email);
            }
            lista[*tam].numMatricula = aluno.numMatricula;
            strcpy(lista[*tam].nome, aluno.nome);
            strcpy(lista[*tam].email, aluno.email);
            *tam += 1;
            return TRUE;
        }else
            return FALSE;
    }   

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
    if(*tam == 0)
        return FALSE; //lista vazia
    int pos = buscaAluno(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave){
        for(int i = pos; i < *tam - 1 ; i++){
            lista[i].numMatricula = lista[i+1].numMatricula;
            strcpy(lista[i].nome, lista[i+1].nome);
            strcpy(lista[i].email, lista[i+1].email);
        }
        *tam -= 1;
        return TRUE;
    }else
        return FALSE;
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
    TListAlunos *list = malloc (sizeof (TListAlunos));
    list->tam = 0;
    list->cap = cap;
    list->eOrd = eOrd;
    list->lista = malloc (cap * sizeof (TAluno));
    return list;
}

int buscaChaveNaLista(int chave, TListAlunos *lista){

    /*
        Procurar uma chave na lista e retornar o índice
        no array em que a chave se encontra ou a posição em
        que um elemento com esta chave deveria ser incluído
        na lista. Lembre que as listas não possuem elementos
        com chave repetida.  
    */
   return buscaAluno_Ord(lista->lista, lista->tam, chave);
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
   return incAluno_Ord(aluno, lista->lista, lista->tam, lista->cap);
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
   return remAluno_Ord(aluno.numMatricula, lista->lista, lista->tam);
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
    //criar uma nova lista com tamanho e cap = tamanho Lista A + tamanho Lista B
    // juntar elementos Lista A + elementos Lista B
    int tam = listaA->tam + listaB->tam;
    int eOrd = FALSE;
    if (listaA->eOrd == listaB->eOrd) {
        eOrd = listaA->eOrd;
    }
    TListAlunos* resultado = iniListAlunos(tam, eOrd);
    int i;
    for (i = 0; i < listaA->tam; i++) {
        resultado->lista[i] = listaA->lista[i];
    }
    for (i = 0; i < listaB->tam; i++) {
        if (eOrd) {
            incAluno_Ord(listaB->lista[i], resultado->lista, resultado->tam, resultado->cap);
        } else {
            incAluno_NOrd(listaB->lista[i], resultado->lista, resultado->tam, resultado->cap);
        }
    }
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
   // A[1,2,4,6,8] - B[1,4,5,7,8]
   //Resultado[2,6]
   

}

void intListas(TListAlunos *listaA, TListAlunos *listaB, TListAlunos *listaC){
    for(int i = 0; i < listaA->tam; i++){
        if(buscaChaveNaLista(listaA->lista[i].numMatricula, listaB)){
            incAlunoNaLista(listaA->lista[i], listaC);
        }
    }
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
   // A[1,2,4,6,8] - B[1,4,5,7,8]
   //Resultado[1,4,8]
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
    printf("[ \n ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d, ", lista[i].numMatricula);
        printf("%s, ", lista[i].nome);
        printf("%s;\n ", lista[i].email);
    }
    printf(" ]\n");
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
   TListAlunos *lAlunos = iniListAlunos(cap, eOrd);
    for (int i = 0; i < tam;)
    {
        TAluno aluno;
        // matricula = ano + semestre + sequencia aleatoria
        aluno.numMatricula = ((2000 + random()%22)* 100000) + ((1 + random()%2)* 10000) + random()%900; 
        strcpy(aluno.nome, "Nome Sobrenome UltimoNome");
        strcpy(aluno.email,"NSUn@gmail.com");

        if (incAlunoNaLista(aluno, lAlunos))
            i++;
    }
    return lAlunos;
}
