#include <stdio.h>

int main(){

    //Verifica se o serviço militar é obrigatório
    //Informa se está livre do serviço militar

    int masculino, idade;

    printf("Sexo masculino? 1 - Sim ou 0 - Nao \n");
    scanf("%d", &masculino);

    printf("Qual a idade? \n");
    scanf("%d", &idade);

    if(masculino && idade >= 18){
        printf("Servico militar obrigatorio");
    }else{
        printf("\nLivre do servico militar \n");
    }

    //Verifica se o serviço militar é obrigatório
    //IF/ELSE encadeado

    /*
    int masculino, idade;

    printf("Sexo masculino? 1 - Sim ou 0 - Nao \n");
    scanf("%d", &masculino);

    if(masculino){
        printf("Qual a idade? \n");
        scanf("%d", &idade);

        if(idade >= 18){
            printf("Servico militar obrigatorio");
        }else{
            printf("\nIdade insulficiente para servico militar \n");
        }
    }else{
        printf("\nServico militar obrigatorio apenas para homens \n");
    }
    */
    return 0;
}