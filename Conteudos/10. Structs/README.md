# Fundamentos de Programação: Struct

Até o momento, vimos que os vetores e matrizes agrupam vários dados do **mesmo tipo** (apenas inteiros, apenas caracteres...). Mas e se precisarmos representar algo que possui características variadas?
Imagine que precisamos modelar um  **Evento Acadêmico**. Ele possui um ID (número inteiro), um nome (string) e um número máximo de participantes (número inteiro). Manter essas três variáveis separadas no código seria desorganizado e propenso a erros.
A **Struct** resolve isso. Ela nos permite criar um **pacote** que agrupa variáveis de tipos diferentes.

### Sintaxe Básica
Para acessar os elementos (também chamados de campos) de uma struct comum, utilizamos o **operador ponto (`.`)**.
```c
#include <stdio.h>
#include <string.h>

// Definição da estrutura
struct Evento {
    int id;
    char titulo[50];
    int capacidade;
};

int main() {
    // Declarando uma variável do tipo 'struct Evento'
    struct Evento palestra;

    // Atribuindo valores usando o operador ponto (.)
    palestra.id = 1;
    strcpy(palestra.titulo, "Inovacao Tecnologica");
    palestra.capacidade = 150;

    printf("O evento '%s' possui %d vagas.\n", palestra.titulo, palestra.capacidade);

    return 0;
}
```

---

## Criação de Novos Tipos (`typedef`) 

Escrever `struct NomeDaStruct` toda vez que formos declarar uma variável pode deixar o código repetitivo. A linguagem C nos fornece o comando `typedef` (*Type Definition*), que permite criar um "apelido" ou um novo nome oficial para os nossos tipos de dados.

É uma convenção muito forte em C combinar o `typedef` diretamente com a definição da estrutura:
```c
// Criando um novo tipo chamado 'Evento'
typedef struct {
    int id;
    char titulo[50];
    int capacidade;
} Evento;

int main() {
    // Agora podemos declarar variáveis diretamente com o novo tipo!
    Evento hackathon;
    hackathon.id = 2;
    // ...
    return 0;
}
```

---

## Vetores de Estruturas

Exatamente como criamos vetores de `int` ou `float`, podemos criar um vetor onde cada posição armazena uma `Struct` completa. Isso é fundamental para criar listas de dados, como um cronograma de vários eventos.
```c
#include <stdio.h>

typedef struct {
    int id;
    char titulo[50];
} Evento;

int main() {
    // Cria um vetor capaz de armazenar 3 eventos
    Evento cronograma[3];

    // Acessando os campos do primeiro evento (índice 0)
    cronograma[0].id = 1;
    snprintf(cronograma[0].titulo, 50, "Workshop de C");

    printf("Primeiro evento: %s\n", cronograma[0].titulo);

    return 0;
}
```

---

## Ponteiros para Estruturas

Assim como podemos ter ponteiros apontando para variáveis comuns, podemos ter ponteiros que guardam o endereço de memória de uma estrutura.
A grande diferença aqui está na sintaxe de acesso aos dados. Quando lidamos com um ponteiro para uma struct, o operador ponto (`.`) é substituido pelo **operador seta (`->`)**.
```c
#include <stdio.h>

typedef struct {
    int id;
    int vagas_disponiveis;
} Evento;

int main() {
    Evento meuEvento;
    meuEvento.id = 1;
    meuEvento.vagas_disponiveis = 50;

    // Criando um ponteiro que aponta para a estrutura
    Evento *ptrEvento = &meuEvento;

    // Acessando os dados através do PONTEIRO usando a seta (->)
    printf("Vagas iniciais: %d\n", ptrEvento->vagas_disponiveis);

    // Modificando os dados através do ponteiro
    ptrEvento->vagas_disponiveis -= 1;

    printf("Vagas apos reserva: %d\n", meuEvento.vagas_disponiveis);

    return 0;
}
```

---

## Passando Estruturas para Funções

Existem duas formas principais de enviar uma estrutura para uma função. **Por Valor e Por Referência**.

### **Por Valor (Cópia)**
Neste modelo, a função recebe uma cópia inteira da estrutura.
* **Vantagem:** É seguro, a estrutura original não pode ser modificada por acidente.
* **Desvantagem:** Se a struct for muito grande, o processo de copiar todos os dados consome muita memória e processamento.

### **Por Referência (Usando Ponteiros)**
É o método padrão na indústria. Em vez de copiar toda a struct, enviamos apenas o endereço de memória (ponteiro) de onde ela está.
* **Vantagem:** É extremamente rápido e consome pouca memória, independentemente do tamanho da struct. Permite que a função modifique os dados originais.
* **Desvantagem:** Exige o uso correto do operador `->`.
```c
#include <stdio.h>

typedef struct {
    int id;
    char titulo[50];
    int participantes;
} Evento;

// A função recebe um ponteiro para a estrutura
void registrarParticipante(Evento *ev) {
    // Usamos a seta (->) para acessar o campo, pois 'ev' é um ponteiro
    ev->participantes += 1;
    printf("Novo participante registrado no evento '%s'. Total: %d\n", ev->titulo, ev->participantes);
}

int main() {
    // Inicialização direta de uma struct
    Evento simposio = {1, "Simposio de Redes", 0};

    // Passamos o endereço da variável para a função
    registrarParticipante(&simposio);
    registrarParticipante(&simposio);

    return 0;
}
```
