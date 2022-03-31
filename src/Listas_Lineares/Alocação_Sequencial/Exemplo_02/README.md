# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

## Exemplo_02: Implementação de lista linear numa estrutura de alocação sequencial
* Modificação do Exemplo_01 com base na utilização de função específica para busca de um elemento na lista com base no atributo chave;

* Implementação recursiva
```
int buscaAlunoR(TAluno lista[], int tam, int chave)
{
    ...
}

* Caso a sub lista não seja uma lista vazia, ou o primeiro elemento da sub lista não tenha chave igual à procurada, se faz uma chamada recursiva passando a sub lista menor (tam - 1), começando no segundo elemento (&lista[1]).    
* Com base na implementação recursiva é possível determinar que a função de busca tem Complexidade da ordem de n (O(n));

```
* Implementação não recursiva
```
int buscaAluno(TAluno lista[], int tam, int chave)
{
    ...
}

```
