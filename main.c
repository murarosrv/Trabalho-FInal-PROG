#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct{
	char nome[50];
	char categoria [30];
	char unidadeDeMedida [20];
	float quantidade;
}Insumo;

char* getDateTime() {
    time_t now;
    struct tm *timeinfo;
    static char dateTime[20];

    time(&now);
    timeinfo = localtime(&now);

    strftime(dateTime, sizeof(dateTime), "%d/%m/%Y %H:%M:%S", timeinfo);
    return dateTime;
}

void registrarLog(char* operacao) {
    FILE *logFile = fopen("logs.txt", "a");
    if(logFile == NULL) {
        printf("ERRO ao abrir arquivo de log\n");
        return;
    }

    char *dataHora = getDateTime();
    fprintf(logFile, "Operação:%s feita %s horas.\n", operacao, dataHora);
    fclose(logFile);
}

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
    registrarLog("Cadastro de insumo");
    printf("Cadastrado do insumo realizado com sucesso!\n");
}

void alterarInsumo() {
    FILE *arquivo = fopen("insumos.txt", "r");
    if(arquivo == NULL) {
        printf("ERRO ao abrir o arquivo\n");
        return;
    }

    Insumo insumos[100];
    int numInsumos = 0;
    char linha[200];


    while(fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%f",
            insumos[numInsumos].nome,
            insumos[numInsumos].categoria,
            insumos[numInsumos].unidadeDeMedida,
            &insumos[numInsumos].quantidade
        );
        numInsumos++;
    }
    fclose(arquivo);

    printf("\nInsumos cadastrados:\n");
    for(int i = 0; i < numInsumos; i++) {
        printf("%d - %s\n", i+1, insumos[i].nome);
    }


    int escolha;
    printf("\nEscolha o numero do insumo para alterar (1-%d): ", numInsumos);
    scanf("%d", &escolha);
    escolha--;

    if(escolha < 0 || escolha >= numInsumos) {
        printf("Opcao invalida!\n");
        return;
    }


    int opcaoMod;
    printf("\nO que deseja alterar?\n");
    printf("1 - Nome\n");
    printf("2 - Categoria\n");
    printf("3 - Unidade de Medida\n");
    printf("4 - Quantidade\n");
    printf("5 - Todos os campos\n");
    printf("Escolha: ");
    scanf("%d", &opcaoMod);

    char nomeAntigo[50];
    strcpy(nomeAntigo, insumos[escolha].nome);

    switch(opcaoMod) {
        case 1:
            printf("Novo nome: ");
            scanf(" %[^\n]", insumos[escolha].nome);
            break;
        case 2:
            printf("Nova categoria: ");
            scanf(" %[^\n]", insumos[escolha].categoria);
            break;
        case 3:
            printf("Nova unidade de medida: ");
            scanf(" %[^\n]", insumos[escolha].unidadeDeMedida);
            break;
        case 4:
            printf("Nova quantidade: ");
            scanf("%f", &insumos[escolha].quantidade);
            break;
        case 5:
            printf("Novo nome: ");
            scanf(" %[^\n]", insumos[escolha].nome);
            printf("Nova categoria: ");
            scanf(" %[^\n]", insumos[escolha].categoria);
            printf("Nova unidade de medida: ");
            scanf(" %[^\n]", insumos[escolha].unidadeDeMedida);
            printf("Nova quantidade: ");
            scanf("%f", &insumos[escolha].quantidade);
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }


    arquivo = fopen("insumos.txt", "w");
    for(int i = 0; i < numInsumos; i++) {
        fprintf(arquivo, "%s;%s;%s;%.2f\n",
            insumos[i].nome,
            insumos[i].categoria,
            insumos[i].unidadeDeMedida,
            insumos[i].quantidade
        );
    }
    fclose(arquivo);
    registrarLog("Alteracao do insumo");
    printf("Insumo alterado com sucesso!\n");
}

void excluirInsumo() {
    FILE *arquivo = fopen("insumos.txt", "r");
    if(arquivo == NULL) {
        printf("ERRO ao abrir o arquivo\n");
        return;
    }

    Insumo insumos[100];
    int numInsumos = 0;
    char linha[200];

    
    while(fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%f", 
            insumos[numInsumos].nome,
            insumos[numInsumos].categoria,
            insumos[numInsumos].unidadeDeMedida,
            &insumos[numInsumos].quantidade
        );
        numInsumos++;
    }
    fclose(arquivo);

    
    printf("\nInsumos cadastrados:\n");
    for(int i = 0; i < numInsumos; i++) {
        printf("%d - %s\n", i+1, insumos[i].nome);
    }

    
    int escolha;
    printf("\nEscolha o numero do insumo para excluir (1-%d): ", numInsumos);
    scanf("%d", &escolha);
    escolha--;

    if(escolha < 0 || escolha >= numInsumos) {
        printf("Opcao invalida!\n");
        return;
    }

    char nomeExcluido[50];
    strcpy(nomeExcluido, insumos[escolha].nome);

    
    for(int i = escolha; i < numInsumos - 1; i++) {
        insumos[i] = insumos[i + 1];
    }
    numInsumos--;

   
    arquivo = fopen("insumos.txt", "w");
    for(int i = 0; i < numInsumos; i++) {
        fprintf(arquivo, "%s;%s;%s;%.2f\n",
            insumos[i].nome,
            insumos[i].categoria,
            insumos[i].unidadeDeMedida,
            insumos[i].quantidade
        );
    }
    fclose(arquivo);

    char logMsg[100];
    sprintf(logMsg, "Exclusao do insumo %s", nomeExcluido);
    registrarLog(logMsg);
    printf("Insumo excluido com sucesso!\n");
}

void listarInsumos() {
    FILE *arquivo = fopen("insumos.txt", "r");
    if(arquivo == NULL) {
        printf("ERRO ao abrir o arquivo\n");
        return;
    }

    char linha[200];
    Insumo insumo;
    int contador = 0;

    printf("\n=== LISTA DE INSUMOS ===\n");
    printf("%-30s %-20s %-15s %-10s\n", "Nome", "Categoria", "Unidade", "Quantidade");
    printf("----------------------------------------------------------------\n");

    while(fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%f", 
            insumo.nome,
            insumo.categoria,
            insumo.unidadeDeMedida,
            &insumo.quantidade
        );
        printf("%-30s %-20s %-15s %.2f\n",
            insumo.nome,
            insumo.categoria,
            insumo.unidadeDeMedida,
            insumo.quantidade
        );
        contador++;
    }

    printf("----------------------------------------------------------------\n");
    printf("Total de insumos: %d\n", contador);
    
    fclose(arquivo);
    registrarLog("Listagem de insumos");
}

int main(){
    int opcao;

    do{
        printf("1 - Cadastrar Insumo\n");
        printf("2 - Alterar Cadastro de Insumo\n");
        printf("3 - Excluir Cadastro de Insumo\n");
        printf("4 - Listar Insumos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarInsumo();
                break;
            case 2:
                alterarInsumo();
                break;
            case 3:
                excluirInsumo();
                break;
            case 4:
                listarInsumos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 0);


    return 0;
}
