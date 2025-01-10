#include<stdio.h>

typedef struct{
	char nome[50];
	char categoria [30];
	char unidadeDeMedida [20];
	float quantidade;
}Insumo;

void cadastrarInsumo (){
	FILE *arquivo = fopen("insumos.txt", "a");
    if(arquivo == NULL){
        printf("ERRO ao abrir o arquivo\n");
        return;
    }

    Insumo insumo;
    printf("Nome do Produto: ");
    scanf(" %[^\n]", insumo.nome);
    printf("Categoria: ");
    scanf(" %[^\n]", insumo.categoria);
    printf("Unidade de Medida (kg, litros, unidades): ");
    scanf(" %[^\n]", insumo.unidadeDeMedida);
    printf("Quantidade: ");
    scanf("%f", &insumo.quantidade);

    fprintf(arquivo, "%s;%s;%s;%.2f\n", insumo.nome, insumo.categoria, insumo.unidadeDeMedida, insumo.quantidade);
    fclose(arquivo);

    printf("Cadastrado do insumo realizado com sucesso!\n");
}


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
