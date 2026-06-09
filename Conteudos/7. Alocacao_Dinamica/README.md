# Fundamentos de Programação: Alocação Dinâmica de Memória

Quando criamos variáveis e vetores de forma convencional, o compilador precisa saber o tamanho exato deles antes mesmo do programa rodar.

Imagine a seguinte declaração
```c
int listaDeDevedores[100];
```
Essa abordagem, chamada de **Alocação Estática**, traz duas grandes limitações:
1. *O Desperdício:** Se a empresa tiver apenas 5 ddevedores, o programa continuará ocupando o espaço de 100 na memória RAM, desperdiçãondo recursos do sistema.
2. **A Rigidez:** Se a empresa crescer e pessar a ter 101 devedores, o programa irá falhar ou travar, pois não há espaço reservado para esse novo dado.

A **Alocação Dinâmica** surge para resolver isso. Ela permite que o programa pergunte ao usuário: *"Quantos dados você precisa armazenar hoje?"* e, em tempo de execução, reserve exatamente essa quantidade na memória.

### Stack vs Heap
Para entender a alocação dinâmica, precisamos visualizar a memória RAM dividida em duas áreas principais:
* **Stack*:* É a memória onde vivem as variáveis locais automáticas. Ela é extremamente rápida, mas um tamanho limitado e fixo. Tudo o que é criado nela é destruído automaticamente assim que a função termina.
* **Heap*:* É um grande espaço de memória livre administrado pelo sistema operacional. Na alocação dinâmica, nós pedimos um pedaço desse espaço para nós. Essa memória permanece viva até que o programador decida devolvê-la explicitamente.

---

## Ferramentas de Alocaçao em C
Para gerenciar o espaço no **Heap**, a linguagem C disponibiliza quatro funções fundamentais através da biblioteca padrão `<stdlib.h>`.

Toda vez que solicitamos memória no Heap, o sistema operacional nos devolve um **ponteiro** apontando para o primeiro byte desse bloco reservado.

| Função | O que faz? |
| :---: | :---: |
| `malloc()` | (*Memory Allocation*) Reserva a quantidade exata de bytes solicitada. O espaço vem com "lixo de memória". |
| `calloc()` | (*Clear Allocation*) Reserva o espaço necessário e limpa o bloco, definindo todos os bits para zero. |
| `realloc()` | (*Re-allocation*) Redimensiona um bloco de memória que já foi alocado, expandindo-o ou encolhendo-o. |
| `free()` | (*Deallocation*) Devolve a memória reservada de volta para o sistema operacional. |

### Exemplo Prático
Usamos o operador `sizeof` para garantir que o programa peça o tamanho exato do tipo de dado em bytes(um ìnt`geralmente ocupa 4 bytes).
```c
#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para usar malloc e free

int main() {
    int quantidade;
    int *vetor;

    printf("Quantos elementos tera o seu vetor dinamico? ");
    scanf("%d", &quantidade);

    // Solicitando espaço no Heap: (quantidade de itens) * (tamanho de 1 inteiro)
    vetor = (int *) malloc(quantidade * sizeof(int));

    //  estar se o sistema operacional cedeu a memória
    if (vetor == NULL) {
        printf("Erro: Memória RAM insuficiente no sistema!\n");
        return 1; // Encerra o programa indicando falha
    }

    // Utilizando o espaço alocado exatamente como um vetor comum
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = (i + 1) * 10;
        printf("Posição [%d] no Heap = %d\n", i, vetor[i]);
    }

    // Liberar a memória após a utilização
    free(vetor);
    
    // Boa prática: anular o ponteiro para evitar acessos acidentais a memória
    vetor = NULL; 

    return 0;
}
```

* Sempre teste se o retorno do `malloc`/`calloc` é `NULL` antes de usar o ponteiro.
* Cada bloco de memória alocado dinamicamente precisa receber um `free()`. Esquecer de liberar a memória gera o bug chamado *Memory Leak*, que consome a RAM do computado até travar o sistema.
