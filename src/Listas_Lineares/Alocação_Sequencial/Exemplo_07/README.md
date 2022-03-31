# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

## Exemplo_07: Implementação de lista linear numa estrutura de alocação sequencial
* Implementação das funções para trabalhar com a lista ordenada; 
* São incluídas uma nova função recursivas que faz busca em uma lista ordenada pelo atributo chave;
```
int buscaAluno(TAluno lista[], int tam, int chave)
{
    ...
}
```
* As funções de inclusão e remoção foram modificadas para manter a lista ordenada.
* Nesta implementação o tamanho do array é definido como sendo o tamanho máximo da lista mais um. Isto se faz necessário para garantir que, mesmo com a lista cheia, sempre exista uma posição extra no array para copiar a chave procurada. 
* No algoritmo de busca se faz, em cada iteração, uma única comparações (operação básica):
    * para verificar se o primeiro elemento da lita é maior igual à chave procurada;
    ```
    lista[i].numMatricula < chave
    ``` 
    * não é necessário verificar se se atinge o fim da lista porque o algoritmo sempre para antes;
    * A função de busca retorna o índice i do elemento onde parou a busca, caso encontre um elemento com a mesma chave procurada ou quando encontrar um elemento com chave maior que a procurada.
* No algoritmo de inclusão se chama a função de busca: 
    * Caso o índice retornado seja igual ao tamanho da lista, o que significa que não existe elemento com a mesma chave e ela é maior que a maior chave da lista, os restantes atributos são copiados para o final da lista, onde já tinha sido copiado a chave durante a busca;
    * Caso o índice retornado seja menor que o tamanho da lista teremos então que isso acontece porque foi achado um elemento com a chave procurada, ou porque esta é a posição onde deve ser inserido o novo elemento. Neste último caso todos os elementos, desta posição em diante devem ser deslocados para a direita para abrir espaço para o novo elemento;
* No algoritmo de remoção se chama a função de busca: 
    * Caso o índice retornado seja igual ao tamanho da lista, o que significa que não existe elemento com a mesma chave e ela é maior que a maior chave da lista, nada precisa ser removido;
    * Caso o índice retornado seja menor que o tamanho da lista teremos então que isso acontece porque não foi encontrado nenhum item com essa chave na lista ou porque foi achado um elemento com a chave procurada. Neste último caso todos os elementos posteriores posição devem ser deslocados uma posição para a esquerda para excluir o elemento;  
* Ainda que, de forma geral, o algoritmo de busca pode parar antes que no caso da lista não ordenada, o pior casso, aquele em que o elemento procurado não está na lista e é maior que o último elemento, continua tendo a mesma complexidade.
* Com base na implementação recursiva da busca em listas não ordenadas é possível afirmar então que esta função de busca tem Complexidade da ordem de n (O(n));
* No caso da função de inclusão, ainda que, quando o elemento que se deseja inserir seja menor que o primeiro elemento da lista (melhor caso para o algoritmo de busca), a necessidade de deslocar todos os elementos da lista para a direita faz deste o pior caso de algoritmo de inclusão. 
 