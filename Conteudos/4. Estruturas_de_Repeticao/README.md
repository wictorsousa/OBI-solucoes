# Estruturas de Repetição

Estruturas de Repetição (ou laços/loops) são utilizados para executar o mesmo bloco de códigos repetidamente atpe que uma condição especifica se torne falsa.

Na linguagem C, trabalhamos principalmente com três estruturas: `while`, `do/while` e `for`.

---

## 1. Estrutura `while` (Enquanto)
O bloco de código interno é repetido enquanto a condição testada for verdadeira. A checagem da condição ocorre **antes** de entrar no bloco de execução.

### Sintaxe do `while`

```c
while( condição ){
      instrução1;
      instrução2;
      ...
}
```

* **Controle:** Frequentemente, utiliza-se uma variável contadora (`cont`) para gerenciar o número de iterações do laço e evitar loops infinitos.

---

## Estrutura `do/while` (Faça Enquanto)
Funciona de forma semelhante ao `while`, mas com uma diferença crucial: a condição é testada no **final** do bloco.

* **Garantia:** Isso assegura que o bloco de comandos seja executado **pelo menos uma vez**, independentemente da condição ser incialmente verdadeira ou falsa.

### Sintaxe do `do/while`

```c
do{
      instrução1;
      instrução2;
} while ( condição ); //Ponto e vírgula obrigatório.
```

---

## Estrutura `for` (Para) 
É a estrutura mais compacta e ideal quando já sabemos previamente o número de iterações ou intervalo exato que queremos cobrir. Ela agrupa a **incialização**, a **condição de parada** e a **atualização** em uma única linha.

### Sintaxe do `for`

```c
for( iniciaContador; condição; atualizaContador ){
      instruções;
}
```
