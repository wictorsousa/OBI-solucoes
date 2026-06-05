#include <stdio.h>

int main(){

    /* Em estruturas condicionais mostrei um exemplo de calculadora
       mostrei um exemplo de calculadora utilizando a estrutura switch,
       no cada vez que quiser fazer uma operação é necessário uma nova
       execução do programa, com a estrutura do/while é possível a criação
       de um laço e a criação de uma escolha de parada para quando necessário 
       encerrar o programa. */

    double num1, num2, resultado;
    char operador;

    do{
        printf("--- CALCULADORA ---");
        printf("Escolha o operador (+, -, *, /) ou 'S' para sair: ");
        scanf(" %c", &operador);

        if(operador == 'S' || operador == 's'){
            printf("Fechando a calculadora. \n");
            break;
        }
        
        printf("Digite o primeiro numero: ");
        scanf("%lf", &num1);

        printf("Digite o segundo numero: ");
        scanf("%lf", &num2);

        printf("\nResultado: ");

        switch(operador){
            case '+':
                resultado = num1 + num2;
                printf("%f.2 + %f.2 = %f.2\n", num1, num2, resultado);
                break;
            case '-':
                resultado = num1 - num2;
                printf("%f.2 - %f.2 = %f.2\n", num1, num2, resultado);
                break;
            case '*':
                resultado = num1 * num2;
                printf("%f.2 * %f.2 = %f.2\n", num1, num2, resultado);
                break;
            case '/':
                if(num2 != 0){
                    resultado = num1 / num2;
                    printf("%f.2 / %f.2 = %f.2\n", num1, num2, resultado);
                } else {
                    printf("Erro: Nao eh possivel dividir por zero.\n");
                }
                break;
        }
    }while(operador != 'S' || operador != 's');

    return 0;
}