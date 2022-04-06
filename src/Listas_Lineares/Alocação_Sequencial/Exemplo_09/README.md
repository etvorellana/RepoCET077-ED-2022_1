# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

# Exemplo_09: Implementação de lista linear numa estrutura de alocação sequencial
* Implementação das funções otimizadas para trabalhar com a lista ordenada; 
* Foi modificada a função de busca para implementar uma versão recursivas da busca binária;
* Nesta implementação o tamanho do array é definido como sendo o tamanho máximo da lista. Não se faz mais necessário ter uma posição extra no array para copiar a chave procurada; 
* No algoritmo, começando com a lista original, em cada iteração posterior se trabalha com uma sub lista que têm metade do tamanho da lista atual;
* Em cada sub lista se procura o elemento i do meio, e se faz a comparação (operações básicas):
    * para verificar se o elemento i da sub lista tem atributo chave menor, maior ou igual que o procurado;
    ```
    int i = tam/2;
	if(lista[i].numMatricula < chave)
		...
	else if(lista[i].numMatricula > chave)
		...
		else
            ...
    ``` 
    * Caso seja uma das duas primeiras condições se faz uma chamada recursiva para continuar a busca na sub lista, com metade do tamanho a direita ou a esquerda do índice i;
    * A função de busca retorna o índice i do elemento onde parou a busca, caso encontre um elemento com a mesma chave procurada ou quando a sub lista resultando esteja vazia; 
* Com base na implementação recursiva da busca binária é possível afirmar então que esta função de busca tem Complexidade da ordem de log_2(n) (O(log_2(n)));
* No caso da função de inclusão, ela ainda envolve uma série de deslocamento que fazem que ela seja O(n). 
 