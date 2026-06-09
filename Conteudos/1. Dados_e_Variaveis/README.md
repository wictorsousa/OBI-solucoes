# Fundamentos de Programação: Dados e Variáveis em C

---

## O que são Dados?

Na computação, **dados** são a matéria-prima da informação. Eles representam fatos brutos, símbolos ou valores isolados que, por si só, não possuem um significado completo até que sejam processados por um algoritmo.

---

## Principais Tipos de Dados em C

A linguaguem C é **estaticamente tipada**, o que significa que o compilador precisa saber exatamente que tipo de dado uma variável irá armazenar para reservar o espaço correto na memória.

| Tipo | Descrição | Tamanho |
| :---: | :---: | :---: |
| `int` | Números inteiros (positivos ou negativos) | 4 bytes |
| `float` | Números reais (ponto flutuante) | 4 bytes |
| `double` | Números reais de dupla precisão | 8 bytes |
| `char` | Um único caracter (letras, símbolos) | 1 byte |

---

## Dados Numéricos vs Literais

#### **Dados Numéricos**
São valores utilizados para cálculos matemáticos.
* **Inteiros:** `10`, `-5`, `100`.
* **Decimais:** `3.14`, `2.09`, `-0.05`.

#### **Dados Literais (Cadeias de Caracteres)**
Representam textos. Em C, um literal de caractere único é delimitado por aspas simples (`A`), enquanto uma "String" (conjunto de caracteres) é delimitada por aspas duplas (`"Olá Mundo"`).

---

## Dados Lógicos
Pense em um **dados lógico** como um **interruptor de luz**. Ele só pode estar em um de dois estados possíveis: ou está **ligado** ou está **desligado**. Não existe meio-termo.

Na programação, usamos esse tipo de dado para responder a perguntas que só possuem duas respostas possíveis: **Sim** ou **Não**, **Verdadeiro** ou **Falso**.
* **Verdadeiro (True):** Representa que uma condição foi atendida (o interruptor está desligado / valor `1` na computação).
* **Falso (False):** Representa que uma condição não foi atendida (o interruptor está desligado / valor `0`na computação).

**Exemplos:**
* O usuário digitou a senha correta? **Sim** (Verdadeiro).
 Choveu ontem? **Não** (Falso).

---

## Variáveis
Uma **Variável** é um espaço nomeado na memória RAM do computador onde podemos armazenar um dado temporariamente durante a execução do programa. Imagine-a como uma caixa com uma etiqueta (nome) e com um conteúdo (valor).

---

## Construção e Declaração
Para criar uma variável em C, seguimos a sintaxe:
`tipo nome_da_variavel = valor_inicial;`

**Exemplos:**

```c
int idade = 25;
float altura = 1.76;
char inicial = 'F';
```

---

## Regras de Nomeclatura e Boas Práticas
Para que o compilador aceite o nome da sua variável e seu código seja legível:
* **Início:** Deve começar com uma letra ou sublinhado(`_`). Nunca comece com números.
* **Caracteres Aceitos:** Apenas letras, números e *underscores*. Não use espaços ou síbolos especiais(`@`,`#`,`%`).
* **Case Sensitive:** C diferencia maiúsculas de minúsculas. `Idade` e `idade` são variáveis diretentes.
* **Palavras Reservadas:** Não use termos da linguagem (`int`, `return`, `if`, `for`).
* **Semântica:** Use nomes que expliquem a função da variável. Em vez de `x`, use `preco_produto`. 
