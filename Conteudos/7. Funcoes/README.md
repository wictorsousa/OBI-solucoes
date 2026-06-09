# Fundamentos de Programação: Funções

Uma **função** é um bloco de código independente projetado para realizar uma tarefa especifica. A utilização de funções permite modularizar o código, evitando a repetição desnecessária e facilitando a manutenção.

Em C, uma função precisa ser declarada antes de ser utilizada. Ela possui um tipo de retorno, um nome, parâmentros (opcionais) e um escopo.

### Sintaxe Básica
```c
tipo_de_retorno nomeDaFuncao(tipo_parametro1 parametro1, tipo_parametro2 parametro2){
    // Corpo da função (aqui ficará o código a ser executado)
    return valor; // Se a função for do tipo void o retorno de valor é opcional
}
```
#### Exemplo
```c
#include <stdio.h>
// Definição da função
int somar(int a, int b){
    return a + b;
}

int main(){
    int resultado = somar(5, 7); // Chamada da função
    printf("Resultado: %d\n", resultado);
    return 0;
}
```

---

## 1. Pilha de Execução
A **Pilha de Execução** é a estrutura de memória (do tipo LIFO - *Last In, First Out*) que o sistema operacional utiliza para gerenciar as chamadas de funções de um programa.

Cada vez que uma função é chamada:
1. Um **Frame de Pilha** é empilhado. Esse frame guarda os parâmentros da função, suas variáveis locais e o endereço de retorno (para onde o programa deve voltar quando a função acabar).
2. O programa desvia a execução para essa função.
3. Quando a função encontra um `return` ou chega ao fim, seu Stack Frame é **desempilhado** e a memória usada por ela é liberada.

Se uma função chamar muitas outras sem liberar memória (como uma recursão infinita), ocorre o erro de **Stack Overflow** (estouro de pilha).

---

## 2. Ponteiros
Um **ponteiro** é uma variável especial que, em vez de armazenar um valor comum (como um número ou texto), armazena um **endereço de memória** de outra variável.
Os ponteiros são fundamentais em C para permitir a manipulação direta da memória e a passagem de parâmetros por referência.

#### **Operadores Fundamentais**
* `&`(Operador de Endereço): Retorna o endereço de memória de uma variável.
* `*`(Operador de Desreferenciação): Acessa o *conteúdo* guardado no endereço para o qual o ponteiro aponta.

#### **Exemplo Prático**
```c
#include <stdio.h>

int main(){
    int numero = 50;
    int *ponteiro = &numero; // O ponteiro recebe o endereço da variável 'numero'

    printf("Valor de numero: %d\n", numero);
    printf("Endereço de numero: %p\n", (void*)&numero);
    printf("Valor armazenado no ponteiro (endereço): %p\n", (void*)ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);

    return 0;
}
```
## 3. Escopo de Variáveis
O **escopo** determina a visibilidade e o tempo de vida de uma variável dentro do programa. Em C, o escopo é delimitado por chaves `{}`.

#### Variáveis Locais
* São declaradas dentro de uma função ou bloco `{}`.
* Só existem enquanto aquele bloco estiver sendo executado (vivem no Stack Frame da função).
* Não podem ser acessadas de fora desse bloco.

#### Variáveis Globais
* São declaradas fora de qualquer função (geralmente no topo do arquivo).
* Ficam visíveis para todo o código a partir do ponto de sua declaração até o fim do programa.

```c
#include <stdio.h>

int global = 100; // Escopo global

void funcaoExemplo(){
    int local = 5; // Escopo local da função funcaoExemplo
    printf("Local: %d, Global: %d\n", local, global);
}

int main(){
    funcaoExemplo();
    //printf("%d", local); // 'local' não existe na main, logo ocorrerá um erro.
    return 0;
}
```

---

## 4. Recursividade
A **recursividade** ocorre quando uma função chama a si mesma para resolver subproblemas de um problema maior. Para que uma função recursiva funcione corretamente e não trave o computador, ela precisa obrigatoriamente de dois componentes:

1. **Caso Base (Condição de Parada):** Uma condição simples que interrompe as chamadas sucessivas e inicia o retorno da pilha.
2. **Caso Recursivo:** A chamada da própria função, aproximando-se progressivamente do caso base.

#### Exemplo Clássivo: Fatorial
O fatorial de um numero o $N$ é definido com é definido como $N \times (N-1)!$, sendo que o fatorial de 0 ou 1 é igual a 1.

```c
#include <stdio.h>

int fatorial(int n) {
    // Caso Base
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso Recursivo
    return n * fatorial(n - 1);
}

int main() {
    int num = 5;
    printf("O fatorial de %d eh: %d\n", num, fatorial(num)); // Saída: 120
    return 0;
}
```
