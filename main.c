#include<stdio.h>

void cadastrarInsumo();


int main(){
    int opcao;

    do{
        printf("1 - Cadastrar Insumo\n");
        printf("2 - Alterar Cadastro de Insumo\n");
        printf("3 - Excluir Cadastro de Insumo\n");
        printf("4 - Listar Insumos\n");
        printf("0 - Sair\n");
    }while(opcao != 0);


    return 0;
}
