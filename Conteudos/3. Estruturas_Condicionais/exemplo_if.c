#include <stdio.h>

int main(){

    // Verifica se o usuário é maior de idade
    // Uma condição

    int idade;

    scanf("%d", &idade);

    if(idade >= 18){
        printf("Maior de idade \n");
    }


    // Verifica se o serviço militar é obrigatório
    // Mais de uma condição

    /*
    int masculino, idade;

    printf("Sexo masculino? 1 - Sim ou 0 - Nao \n");
    scanf("%d", &masculino);

    printf("Qual a idade? \n");
    scanf("%d", &idade);

    if(masculino && idade >= 18){
        printf("Servico militar obrigatorio");
    }
    */

    return 0;
}