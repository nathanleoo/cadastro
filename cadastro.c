#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int idade;
} Pessoa;

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int total = 0;
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Listar cadastros\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar o buffer do teclado

        switch (opcao) {
            case 1:
                if (total < MAX_PESSOAS) {
                    printf("Digite o nome: ");
                    fgets(pessoas[total].nome, TAM_NOME, stdin);
                    pessoas[total].nome[strcspn(pessoas[total].nome, "\n")] = '\0'; // remover \n

                    printf("Digite a idade: ");
                    scanf("%d", &pessoas[total].idade);
                    getchar(); // limpar buffer
                    total++;

                    printf("Pessoa cadastrada com sucesso!\n");
                } else {
                    printf("Limite de cadastros atingido.\n");
                }
                break;

            case 2:
                printf("\n--- LISTA DE CADASTROS ---\n");
                for (int i = 0; i < total; i++) {
                    printf("%d. Nome: %s | Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
                }
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);

    return 0;
}
