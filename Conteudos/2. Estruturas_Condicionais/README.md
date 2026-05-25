# Estruturas Condicionais em C

Estruturas condicionais (também conhecidas como estruturas de seleção) são um mecanismo de seleção usado para escolher um dentre os caminhos disponíveis para a sequência de execução do programa. Através de uma condição lógica, o sistema define qual bloco de código será processado e qual será ignorado.

Na linguagem C, as principais estruturas de seleção são: `if`, `if/else` e `switch`.

---

## 1. Estrutura `if`
A instrução `if` (se) avalia uma condição simples. Se o resultado for verdadeiro, o bloco de código interno é executado.

### Sintaxe do IF
```c 
if( condição ){
  instrução1;
  instrução2;
  ...
}
```

---

## 2. Estrutura `if/else`
O bloco `if/else` (se/senão) é utilizado quando deseja-se executar instruções caso a condição IF seja falsa. Ele divide o fluxo em duas vias mutualmente exclusivas.

### Sintaxe do IF/ELSE
```c
if( condição ){
  instrução1;
  instrução2;
  ...
}
else{
  instrução1;
  ...
}
```
* **Encadeamento (`if/else`):** Se o código precisar de várias verificações em sequência (como, por exemplo, validar os diferentes status da incrição de um aluno em um sistema de eventos da faculdade), você pode encadear as condições. Isso evita colocar vários `ifs`um dentro do outro:
```c
if (status == 1){
    // Inscrito
} else if (status == 2){
    // Fila de espera
} else {
    // Cancelado
}
```

### Operador Ternário (`? :`)
Para situações onde você precisa de um `if/else` muito simples apenas atribui um valor a uma variável, o C oferece o **operador condicional ternário**. Ele permite escrever a condição em uma única linha.

**Sintaxe:**

`variavel = (condição) ? valor_se_verdadeiro : valor_se_falso;` 

**Exemplo:**
```c
  int idade = 20;
  // Em vez de usar 4 linhas para um if/else tradicional:
  char categoria = (idade >= 18) ? 'A' : 'J';

  printf("Categoria do participante: %c\n", categoria); // Imprime 'A' (Adulto)
```

---

## Estrutura `switch`
O `switch` avalia uma única expressão e pula diretamente para o `case` correspondente, funcionando como um "menu". Ele é mais eficiente que vários `else if` encadeados.

**Restrições:** Apenas tipos inteiros (`int`, `char`, `enum`) podem ser avaliados em um `switch`.

### **O comportamento de "Fall-Through"**
Se você não colocar o comando `break;` ao final de um `case`, o programa não sai do `switch`. Ele continuará executando todos os `casos`abaixo delem ignorando as condições , até encontrar um `break`ou o final do bloco.

```c
#include <stdio.h>

int main(){
    int opcao;

    printf("--- BANCO ---\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Saque\n");
    printf("3 - Deposito\n");
    printf("Escolha uma opcao\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("Seu saldo é de R$ 1.000,00.\n");
            break;
        case 2:
            printf("Digite o valor do saque: \n");
            break;
        case 3:
            printf("SDigite o valor do deposito: \n");
            break;
        default:
            printf("Opção invalida! Tente novamente.\n);
    }
    return 0;
}
```

O `default` funciona como uma rede de segurança para tratar entradas insperadas (se o usuário digitar 4, 5 ou qualquer outro número que não esteja nos casos).
