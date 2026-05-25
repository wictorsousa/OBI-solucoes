// O objetivo da questão é encontrar o valor do meio entre três números (x, y, z).

#include <stdio.h>

int main(){

    int x, y, z;     
    int resposta = 0;

    scanf("%d %d %d", &x, &y, &z);

    // Para a solução do problema temos três situalções

    // x é o valor do meio
    if(x >= y && x <= z || x >= z && x >= y){
        resposta = x;
    }
    
    // y é o valor do meio
    if(y >= x && y <= z || y >= z && y <= x){
        resposta = y;
    }

    // z é o valor do meio
    if(z >= x && z <= y || z >= y && z <= x){
        resposta = z;
    }

    printf("%d\n", resposta);

    return 0;
}