#include <stdio.h>

int main(){

    int i = 0; // inicializar a variavel contador evita a atribuição de um possivel lixo de memoria

    for(i = 1; i <= 10; i++){
        printf("5 x %d = %d\n", i, 5 * i);
    }

    return 0;
}