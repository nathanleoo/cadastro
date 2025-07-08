#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100
#define TAM_NOME 100
#define ARQUIVO "cadastros.txt"

typedef struct {
    char nome[TAM_NOME];
    int idade;
} Pessoa;

Pessoa pessoas[MAX_PESSOAS];
int total = 0;

// Função para remover o \n do fgets
void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Carrega os dados do arquivo
void carregarDados() {
    FILE *f = fopen(ARQUIVO, "r");
    if (f == NULL) return;

    while (fscanf(f, " %[^\n]%d", pessoas[total].nome, &pessoas[total].idade) == 2) {
        total++;
    }
    fclose(f);
}

// Salva os dados no arquivo
void salvarDados() {
    FILE *f = fopen(ARQUIVO, "w");
    for (int i = 0; i < total; i++) {
        fprintf(f, "%s\n%d\n", pessoas[i].nome, pessoas[i].idade);
    }
    fclose(f);
}

// Exibe o menu principal
int mostrarMenu() {
    int opcao;
    printf("\n--- MENU ---\n");
    printf("1. Cadastrar pessoa\n");
    printf("2. Listar cadastros\n");
    printf("3. Buscar por nome\n");
    printf("4. Editar cadastro\n");
    printf("5. Excluir cadastro\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        return -1;
    }
    getchar();
    return opcao;
}

// Cadastra nova pessoa
void cadastrarPessoa() {
    if (total >= MAX_PESSOAS) {
        printf("Limite de cadastros atingido.\n");
        return;
    }

    printf("Digite o nome: ");
    fgets(pessoas[total].nome, TAM_NOME, stdin);
    removerNovaLinha(pessoas[total].nome);

    printf("Digite a idade: ");
    if (scanf("%d", &pessoas[total].idade) != 1) {
        printf("Idade inválida. Cadastro cancelado.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();
    total++;
    salvarDados();
    printf("Pessoa cadastrada com sucesso!\n");
}

// Lista todas as pessoas cadastradas
void listarPessoas() {
    if (total == 0) {
        printf("Nenhum cadastro ainda.\n");
        return;
    }

    printf("\n--- LISTA DE PESSOAS ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %s | Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }
}

// Busca pessoa pelo nome
void buscarPessoa() {
    char busca[TAM_NOME];
    printf("Digite o nome a buscar: ");
    fgets(busca, TAM_NOME, stdin);
    removerNovaLinha(busca);

    int encontrados = 0;
    for (int i = 0; i < total; i++) {
        if (strstr(pessoas[i].nome, busca) != NULL) {
            printf("Encontrado: %s | Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
            encontrados++;
        }
    }

    if (!encontrados) {
        printf("Nenhuma pessoa com esse nome encontrada.\n");
    }
}

// Edita uma pessoa cadastrada
void editarPessoa() {
    listarPessoas();
    int indice;
    printf("Digite o número do cadastro a editar: ");
    scanf("%d", &indice);
    getchar();

    if (indice < 1 || indice > total) {
        printf("Índice inválido.\n");
        return;
    }

    indice--; // converter para índice de array
    printf("Novo nome: ");
    fgets(pessoas[indice].nome, TAM_NOME, stdin);
    removerNovaLinha(pessoas[indice].nome);

    printf("Nova idade: ");
    scanf("%d", &pessoas[indice].idade);
    getchar();

    salvarDados();
    printf("Cadastro atualizado com sucesso!\n");
}

// Exclui uma pessoa cadastrada
void excluirPessoa() {
    listarPessoas();
    int indice;
    printf("Digite o número do cadastro a excluir: ");
    scanf("%d", &indice);
    getchar();

    if (indice < 1 || indice > total) {
        printf("Índice inválido.\n");
        return;
    }

    indice--;
    for (int i = indice; i < total - 1; i++) {
        pessoas[i] = pessoas[i + 1];
    }

    total--;
    salvarDados();
    printf("Cadastro excluído com sucesso!\n");
}

// Função principal
int main() {
    carregarDados();
    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 1:
                cadastrarPessoa();
                break;
            case 2:
                listarPessoas();
                break;
            case 3:
                buscarPessoa();
                break;
            case 4:
                editarPessoa();
                break;
            case 5:
                excluirPessoa();
                break;
            case 6:
                printf("Encerrando o programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 6);

    return 0;
}
