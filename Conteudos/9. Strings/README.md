# Fundamentos de Programação: Strings

Na computação, quase todas as informações com o usuário envolvem texto: ler um nome, exibir uma mensagem de erro ou processar uma senha.
Enquanto um dado do tipo `char` consegue armazenar apenas uma única letra ou símbolo por vez, uma **String** é uma estrutura que nos permiteagrupar vários caracteres em sequência para formar palavras ou frases completas.

---

## O que é uma String em C?

Diferente de linguagens modernas, a linguagem C não possui um tipo de dado nativo chamado `string`. Em C, uma string é conceitualmente definida como **um vetor de tipo `char` que termina obrigatoriamente com o caractere nulo `\0`**.

### O Caractere Nulo (`\0`)
O caractere `\0` serve como um "sinal de parada" para o computador. Como um vetor tem tamanho fixo, o `\0` avisa às funções do sistema exatamente onde o texto termina, impedindo que o programa leia lixo de memória além do final da palavra.

> Ao planejar o tamanho de uma string, você deve sempre reservar **um espaço a mais** no vetor para acomodar o `\0`. Por exemplo, a palavra `"Gato"` possui 4 letras, mas precisa de um vetor de tamanho 5 para ser armazenada corretamente.

---

## Inicialização de Strings

Existem diferentes maneiras de declarar e inicializar uma string em C. Veja as formas mais comuns:

### Inicialização Direta (Com Aspas Duplas)
Esta é a forma mais prática. Quando usamos aspas duplas, o compilador adiciona o caractere `\0` automaticamente ao final do texto.
```c
char nome1[6] = "Maria"; // Tamanho explicito (5 letras + '\0')
char nome2[] = "João";   // O compilador calcula o tamanho automaticamente (5 posições)
```
### Inicialização Elemento por Elemento
Embora menos comum no dia a dia, esta forma evidencia que uma string é um vetor. Aqui, o \0 precisa ser colocado explicitamente.

## Funções que Manipulam Strings

Para facilitar o trabalho com textos, a linguagem C possui uma biblioteca padrão dedicada chamada <string.h>. Ela traz uma série de funções prontas para realizar operações que seriam complexas de se fazer manualmente.

As quatro funções mais importantes e utilizadas são:

### `strlen` (Tamanho da String)
Calcula e retorna a quantidade de caracteres que existem na string, desconsiderando o caractere \0.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char texto[] = "Programacao";
    int tamanho = strlen(texto);
    
    printf("A palavra tem %d letras.\n", tamanho); // Saída: 11
    return 0;
}
```

### `strcpy` (Copiar String)
Como não podemos atribuir um texto diretamente a um vetor usando o operador de igualdade (`string1 = string2`), usamos a `strcpy` para copiar o conteúdo de uma string de origem para uma de destino.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char origem[] = "C Linguagem";
    char destino[20];

    // Sintaxe: strcpy(destino, origem);
    strcpy(destino, origem);

    printf("Destino: %s\n", destino); // Saída: C Linguagem
    return 0;
}
```

### `strcat` (Concatenar/Juntar Strings)
Une o conteúdo de duas strings, anexando a segunda string ao final da primeira.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char saudacao[30] = "Olá, ";
    char nome[] = "Mundo!";

    // Junta 'nome' ao final de 'saudacao'
    strcat(saudacao, nome);

    printf("%s\n", saudacao); // Saída: Olá, Mundo!
    return 0;
}
```

### `strcmp` (Comparar Strings)
Compara duas strings caractere por caractere (baseado na tabela ASCII). Ela retorna:
* `0` se as duas strings forem exatamente **iguais**.
* Um valor **menor que 0** se a primeira string for alfabeticamente menor.
* Um valor **maior que 0** se a primeira string for alfabeticamente maior.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char senhaCorreta[] = "1234";
    char senhaDigitada[] = "1234";

    // Verifica se o retorno é igual a 0
    if (strcmp(senhaDigitada, senhaCorreta) == 0) {
        printf("Acesso liberado!\n");
    } else {
        printf("Senha incorreta!\n");
    }

    return 0;
}
```
