# Fundamentos de Programação: Operadores

---

## Operadores vs Operandos

Para que o processador execute qualquer intrução, ele precisa de uma **expressão**. Uma expressão é composta por:

* **Operador:** O símbolo que instrui o processador a realizar uma operação matemática, lógica ou de atribuição (ex: `+`, `>`, `&&`).
* **Operador:** Os dados (literais ou variáveis) que sofrem a ação do operador.

### Classificação quanto ao número de operadores:
1. **Unários:** Atuam sobre um único operando. Ex: `-a` (inversão de sinal) ou `!ativo`(negação lógica).
2. **Binário:** Requerem dois operandos. Ex: `x + y` ou `a > b`.
3. **Ternários;** C possui um único operador ternário, usado como atalho para estruturas condicionais: `condicao ? valor_se_verdade : valor_se_falso` (operador condicional).
    * O operador funciona avaliando a **condição**; se for verdadeira, o resultado da expressão é o **valor_se_verdade**, caso contrário, é o **valor_se_falso**. É crucial que os dois valores de retorno sejam do **mesmo tipo de dados**.
       
---

## Operadores Aritméticos

Os operadores aritméticos realizam computações matemáticos. 

| Operador | Operação | Descrição |
| :---: | :---: | :---: |
| `+` | Adição | Soma aritmética de inteiros ou pontos flutuantes (`float`/`double`). |
| `-` | Subtração | Diferença entre dois valores ou inversão de sinal (unário). |
| `*` | Multiplicação | Produto dos operandos. |
| `/` | Divisão real | Divisão matemática exata. Se os operandos forem inteiros, algumas linguagens (como o C) forçam uma divisão inteira truncada (ex: `5 / 2` resulta em `2`). Para obter o valor real (`2.5`), pelo menos um dos números deve ser `float` ou `double` (`5.0 / 2`). |
| `%` | Resto (Módulo) | Retorna o **resto da divisão inteira**. Crucial para algoritmos de divisibilidade (ex: verificar se um número é par: `x % 2 == 0`). **Nota:** Em C, o operador `%` só pode ser aplicado estritamente a tipos inteiros (`int`, `char`, `short`, `long`). |

---

## Precedência Completa e Associativa

Quando múltiplos operadores estão na mesma linha de código, o compilador do C os resolve aplicando regras estritas de **Precedência** (prioridade) e **Associatividade** (direção da leitura: da esquerda para a direita ou vice-versa).

### Tabela de Precedência em C (DO maior para o menor grau)

| Grau | Tipo de Operador | Direção da Associação | Símbolos comuns em C |
| :---: | :--- | :--- | :--- |
| **1º** | Parênteses | Esquerda para a Direita | `()` |
| **2º** | Incrementos / Unários | Direita para a Esquerda | `++`, `--`, `!`, `-` (unário) |
| **3º** | Multiplicativos | Esquerda para a Direita | `*`, `/`, `%` |
| **4º** | Aditivos | Esquerda para a Direita | `+`, `-` |
| **5º** | Relacionais | Esquerda para a Direita | `<`, `>`, `<=`, `>=` |
| **6º** | Igualdade | Esquerda para a Direita | `==`, `!=` |
| **7º** | Lógico AND | Esquerda para a Direita | `&&` |
| **8º** | Lógico OR | Esquerda para a Direita | `\|\|` |
| **9º** | Ternário | Direita para a Esquerda | `? :` |
| **10º** | Atribuição | Direita para a Esquerda | `=`, `+=`, `-=`, `*=`, `/=` |

> **Exemplo de Análise:**
> ```c
> int resultado = 5 + 3 * 2 > 10 && !0;
> ```
> 1. `!0` é avaliado primeiro (Unário) → resulta em `1`( Verdadeiro em C).
> 2. `3 * 2` é avaliado (Multiplicativo) → resulta em `6`.
> 3. `5 + 6` é avaliado (Aditivo) → resulta em `11`.
> 4. `11 > 10` é avaliado (Relacional) → resulta em `1` (Verdadeiro).
> 5. `1 && 1` é avaliado (Lógica E (AND)) → resulta em `1`.
> 6. O valor `1` é atribuído à variável `resultado`.

Quando o compilador de C encontra a expressão `!0`, ele executa o seguinte raciocínio:
1. O compilador isola o operando à direita: o número `0`.
2. Ele avalia o significado de `0`: "O número 0 representa o estado FALSO".
3. O operador `!` entra em ação para inverter esse estado: O oposto de FALSO é VERDADEIRO.
4. Como C precisa devolver um número inteiro para representar esse novo estado "Verdadeiro", ele adota por padrão o número 1.

---

### Operadores Relacionais

Os operadores relacionais comparam a magnitude ou igualdade de dois operandos.

**Conceito Chave em C:** Originalmente, a linguagem C (padrão C89) não possui um tipo `bool` nativo.
* **`0` (Zero):** Representa o valor **FALSO**.
* **Qualquer valor diferente de `0` (geralmente `1`):** Representa o valor **VERDADEIRO**.

*Nota: A partir do padrão C99, é possível usar o tipo `bool`, `true` e `false` incluindo a biblioteca `<stdbool.h>`.*

Um exemplo de código utilizando a biblioteca `<stdbool.h>`.
```c
#include <stdio.h>
#include <stdbool.h>

int main(){
    bool a = true;
    bool b = false;

    // Operação E (AND)
    printf("a && b: %d\n", a && b); // Saída: 0

    // Operação OU (OR)
    printf("a || b: %d\n", a || b); // Saída: 1

    // Operação NÃO (NOT)
    printf("!a: %d\n", !a); // Saída: 0

    // Expressão composta
    printf("(a && !b) || false: %d\n", (a && !b) || false); // Saída: 1

    return 0
}
```

| Operador | Significado | 
| :---: | :--- | 
| `==` | Igual a | 
| `!=` | Diferente de | 
| `>` | Maior que |
| `<` | Menor que | 
| `>=` | Maior ou igual a | 
| `<=` | Menor ou igual a | 

---

## Operadores Lógicos

Servem para combinar subexpressões lógicas/relacionais atráves da álgebra booleada.

| Operador | Tipo Lógico | Comportamento |
| :---: | :--- | :--- |
| `&&` | **AND** (E) | Retorna `1` apenas se **ambas** as condições forem verdadeiras (diferentes de zero). |
| `\|\|` | **OR** (OU) | Retorna `1` se **pelo menos uma** das condições for verdadeira. |
| `!` | **NOT** (NÃO) | Inverte o estado lógico. `!0` vira `1`. `!5` vira `0`. |

### Tabela Verdade dos Operadores Binários: `&&` (AND) e `||` (OR)

Estes operadores avaliam duas subexpressões simultaneamente para gerar um único resultado lógico (`0` ou `1`).

| Entrada A | Entrada B | Expressão `A && B` (E) | Expressão `A \|\| B` (OU) |
| :---: | :---: | :---: | :---: |
| **`0`** *(Falso)* | **`0`** *(Falso)* | `0 && 0` → **`0`** *(Falso)* | `0 \|\| 0` → **`0`** *(Falso)* |
| **`0`** *(Falso)* | **`1`** *(Verdade)* | `0 && 1` → **`0`** *(Falso)* | `0 \|\| 1` → **`1`** *(Verdade)* |
| **`1`** *(Verdade)* | **`0`** *(Falso)* | `1 && 0` → **`0`** *(Falso)* | `1 \|\| 0` → **`1`** *(Verdade)* |
| **`1`** *(Verdade)* | **`1`** *(Verdade)* | `1 && 1` → **`1`** *(Verdade)* | `1 \|\| 1` → **`1`** *(Verdade)* |

#### Regras de Avaliação:
* **Operador `&&` (AND / E):** O resultado só será **`1`** se **todas** as condições forem verdadeiras. Se houver pelo menos um zero (`0`), o resultado é imediatamente anulado para `0`.
* **Operador `||` (OR / OU):** Basta que **uma única** condição seja verdadeira para o resultado ser **`1`**. Ele só retornará `0` se todas as entradas forem simultaneamente zero.

---

### Tabela Verdade do Operador Unário: `!` (NOT / Negação)

O operador `!` atua sobre um único operando posicionado à sua direita, invertendo o seu estado lógico atual.

| Entrada A | Estado Lógico | Expressão `!A` | Resultado Final |
| :---: | :--- | :---: | :---: |
| **`0`** | Representa **Falso** | `!0` | **`1`** *(Verdadeiro)* |
| **`1`** | Representa **Verdadeiro** | `!1` | **`0`** *(Falso)* |


