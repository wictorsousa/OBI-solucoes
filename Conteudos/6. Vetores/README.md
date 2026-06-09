# Fundamentos de Programação: Vetores

Um **vetor** (ou *array* unidimensional) é uma estrutura de dados homogênea e estática que permite armazenar uma coleção de elementos do **mesmo tipo** sob um único nome.

* **Homogêneo:** Todos os elementos armazenados no vetor devem ser do mesmo tipo (por exemplo, apenas inteiros ou apenas números reais).
* **Estático:** O tamanho do vetor deve ser definido no momento da sua criação e não pode ser alterado durante a execução do programa.
* **Contíguo:** Os elementos são guardados na memória RAM de forma sequencial, um logo após o outro.

---

## Declaração

Para declarar um vetor em C, você precisa especificar o tipo de dado dos elementos, o nome do vetor e a quantidade de posições (tamanho) que ele terá entre colchetes `[ ]`.

### Sintaxe
```c
tipo nome_do_vetor[tamanho];
```

#### Exemplo

```c
int notas[5];       // Aloca espaço para 5 números inteiros na memória
float precos[10];   // Aloca espaço para 10 números de ponto flutuante
char letras[20];    // Aloca espaço para 20 caracteres
```

---

## Referência
O acesso ou referência a cada elemento do vetor é feito através de um **índice**.

Em C, os índices de um vetor sempre começam de **zero (0)** e vão até o **tamanho - 1**.

Se você declarar `int idades[4]`, as posições válidas na memória serão:
* `idade[0]` (Primeiro elemento)
* `idade[1]`
* `idade[2]`
* `idade[3]` (Quarto elemento)

### Relação com Ponteiros
Em C, o nome de um vetor é, na realidade, um ponteiro constante que aponta para o endereço de memória do seu primeiro elemento (`&vetor[0]`).

---

## Inicialização
Existem diferentes formas de inicializar um vetor em C:

#### Inicialização Direta (na Declaração)
Você pode preencher o vetor logo no momento em que o declara utilizando chaves `{}`.

```c
int números[5] = {10, 20, 30, 40, 50};
```

#### Inicialização sem Tamanho Definitivo
Se você fornecer os valores iniciais, o compilador do C consegue deduzir o tamanho do vetor automaticamente.

```c
float notas[] = {7.5, 8.0, 9.5}; // O compilador cria um vetor de tamanho 3
```

#### Inicialização Parcial
Se você definir um tamanho e passar menos elementos do que o total, as posições restantes serão preenchidas automaticamente com zero.

```c
int valores[5] = {1, 2}; // Posições [0]=1, [1]=2, [2]=0, [3]=0, [4]=0
```

---

## Percorrimento 
Como os vetores possuem uma estrutura sequencial, a forma mais eficiente de acessar, ler ou modificar seus dados é utilizando estruturas de repetição (laços). O laço `for` é o mais indicado, pois sabemos previamente o tamanho do vetor.

### Exemplo de Leitura e Exibição

```c
#include <stdio.h>

int main() {
    int idades[3] = {18, 25, 30};

    // Percorrendo o vetor para exibir os elementos
    for (int i = 0; i < 3; i++) {
        printf("Idade na posicao %d: %d\n", i, idades[i]);
    }

    return 0;
}
```

---

## Passagem de Vetores para Funções
Ao passar um vetor como parâmentro para uma função em C, ele é **sempre passado por referência** (através do endereço do seu primeiro elemento). Isso significa que qualquer alteração feita no vetor dentro da função irá modificar o vetor original.

*Boa prática:* Como a função não sabe o tamanho do vetor recebido, é altamente recomendado passar o **tamanho do vetor** como um segundo parâmetro.

### Exemplo Prático

```c
#include <stdio.h>

// Função que recebe um vetor e o seu tamanho
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int meusNumeros[4] = {5, 10, 15, 20};
    
    // Passamos apenas o nome do vetor e o seu tamanho
    imprimirVetor(meusNumeros, 4); 
    
    return 0;
}
```
