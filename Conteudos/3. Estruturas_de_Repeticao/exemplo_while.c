#include <stdio.h>

int main(){

    //Recebe e mostra a soma de 3 números
    int soma = 0, cont = 0, x = 0;

    while(cont < 3){
        printf("Digite um numero: \n");
        scanf("%d", &x);
        soma += x;    // += é umm operador de atribuição, soma += x é o mesmo que soma = soma + x;
        cont++;       // ++ é um operador de incremento, em cont++ o compilador primeiro verificará cont (cont = 0 no momento) e só após isso irá incrementar em 1.
    }

    printf("\nA soma dos numeros eh: %d", &soma);

    return 0;
}