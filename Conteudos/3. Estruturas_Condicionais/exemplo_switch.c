#include <stdio.h>

int main(){

    //Exemplo de menu com switch - Calculadora
    double num1, num2, resultado;
    char operador;

    printf("--- CALCULADORA ---\n");

    // Recebe os números
    printf("Digite o primeiro numero: ");
    scanf("%lf", &num1);

    printf("Digite o segundo numero: ");
    scanf("%lf", &num2);

    // Recebe os operadores
    // O espaço antes do %c serve para limpar o "Enter" (buffer) do teclado
    printf("Escolha a operacao (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("--- RESULTADO ---");

    // O switch avalia qual caractere foi digitado
    switch(operador){
        case '+':
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Nao eh possivel dividir por zero!\n");
            }
            break;

        default:
            printf("Erro: Operador '%c' eh invalido.\n", operador);
            break;
    }
    return 0;
}