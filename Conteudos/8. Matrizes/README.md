# Fundamentos de Programação: Matrizes

Uma **matriz** é um array multidimensional (um array de arrays).Enquanto um vetor comum representa uma única linha de dados (unidimensional), uma matriz organiza os dados em **linhas e colunas** (bidimensional), formando uma grade ou tabela.

Assim como os vetores, as matrizes em C possuem três características fundamentais:
* **Homogêneas:** Todos os elementos da matriz obrigatoriamente possuem o mesmo tipo de dado.
* **Estáticas:** O tamanho (quantidade de linhas e colunas) precisa ser definido na criação e não muda durante a execução.
* **Contíguas na memória:** O computador armazena os elementos sequencialmente na memória RAM, linha por linha (padrão conhecido como *Row-Major Order*).

---

## Declaração

Para declarar uma matriz em C, especificamos o tipo de dado, o nome da matriz e, dentro de colchetes separados, a quantidade de **linhas** e a quantidade de **colunas**.

### Sintaxe
```c
tipo_de_dado nome_da_matriz[quantidade_linhas][quantidade_colunas];
```

### Exemplo
```c
int grade[3][3]; // Cria uma matriz de inteiros com 3 linhas e 3 colunas (9 elementos no total)
float mapa[5][5]; // Cria uma matriz de números reais com 5 linhas e 5 colunas (25 elementos no total)
```

Assim como nos vetores, a contagem dos índices das linhas e das colunas sempre **começa em 0**. Portanto, uma matriz 3x3 possui linhas indexadas de 0 a 2, e colunas indexadas de 0 a 2.

## Inicialização da Matriz

Exitem várias formas de atribuir valores iniciais para uma matriz no momento da declaração:

#### **Inicialização Completa**
A forma mais legível e recomendada é agrupar os elementos de cada linha dentro de chaves `{}` internas;
```c
int matriz[2][3] = {
    {1, 2, 3},  // Linha 0
    {4, 5, 6}   // Linha 1
};
```

#### **Inicialização Linear**
Você também pode passar todos os valores em sequência. O compilador preencherá a primeira linha inteira antes de passar para a próxima.
```c
int matriz[2][3] = {1, 2, 3, 4, 5, 6}; // Tem o mesmo resultado do exemplo anterior
```

#### **Inicialização Parcial**
Se você fornecer menos elementos do que o tamanho total da matriz, as posições restantes serão preenchidas automaticamente com o valor zero.
```c
int matriz[3][3] = {{1}, {2}, {3}}; 
// Linha 0: 1, 0, 0
// Linha 1: 2, 0, 0
// Linha 2: 3, 0, 0
```

---

## Percorrimento da Matriz

Para acessar, ler ou modificar todos os elementos de uma matriz de forma eficiente, precisamos utilizar **laços de repetição encadeados** (um `for` dentro de outro `for`).
* O laço **externo** controla o índice das **linhas**.
* O laço **interno** controla o índice das **colunas**.

### Exemplo Prático
```c
#include <stdio.h>

int main() {
    int matriz[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    // Percorrendo a matriz
    for (int i = 0; i < 2; i++) {       // 'i' controla as linhas
        for (int j = 0; j < 3; j++) {   // 'j' controla as colunas
            printf("Elemento na posicao [%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }

    return 0;
}
```

---

## Passagem de Matrizes para Funções

Assim como os vetores, as matrizes são passadas para as funções **por referência** (o endereço de memória é enviado, logo, alterações na função afetam a matriz original).

No entanto, há uma regra sintática crucial em C: **a definição da função exige que o tamanho da segunda dimensão (coluna) seja informado explicitamente**.

O tamanho da primeira dimensão (linhas) pode ficar vazio, mas o número de colunas é obrigatório para que o compilador consiga calcular corretamente a matemática de endereços na memória RAM para localizar cada elemento.

### Exemplo Prático
```c
#include <stdio.h>

// Obrigatório informar o número de colunas (neste caso, 3) nos colchetes
void exibirMatriz(int mat[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }
}

int main() {
    int minhaMatriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Passamos o nome da matriz e a quantidade de linhas
    exhibirMatriz(minhaMatriz, 2);

    return 0;
}
```
