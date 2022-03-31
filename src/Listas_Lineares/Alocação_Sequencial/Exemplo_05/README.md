# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

## Exemplo_05: Implementação de lista linear numa estrutura de alocação sequencial
* Modificação da função de busca, do Exemplo_04, com a utilização de uma versão recursiva otimizada para diminuir uma comparação por iteração no algoritmo de busca;
* Nesta implementação o tamanho do array é definido como sendo o tamanho máximo da lista mais um. Isto se faz necessário para garantir que, mesmo com a lista cheia, sempre exista uma posição extra no array para copiar a chave procurada. 
* Em cada iteração é avaliado o primeiro elemento de uma sub lista da lista original (lista[0]); 
* Se realiza uma única comparações (operação básica):
    * para verificar se o primeiro elemento da sub lista analisada tem atributo chave igual ao procurado;
    ```
    lista[0].numMatricula == chave
    ``` 
    * não é necessário verificar se é último elemento porque o algoritmo sempre para antes;  
* Caso o primeiro elemento da sub lista não tenha chave igual à procurada, se faz uma chamada recursiva passando a sub lista menor (tam - 1), começando no segundo elemento (&lista[1]).    
* Com base na implementação recursiva é possível determinar que a função de busca ainda tem Complexidade da ordem de n (O(n));