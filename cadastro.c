#include <stdio.h>
#include <string.h>

#define MAX 100

struct Pessoa {
    int codigo;
    char nome[100];
    int idade;
    char telefone[20];
    char email[100];
};

int main() {
    struct Pessoa pessoas[MAX];

    int quantidade = 0;
    int i;
    char opcao = 'S';

    printf("SISTEMA DE CADASTRO\n");

    while (opcao == 'S' || opcao == 's') {
        printf("Cadastro %d\n", quantidade + 1);
        printf("Codigo: ");
        scanf("%d", &pessoas[quantidade].codigo);
        getchar();

        printf("Nome: ");
        fgets(pessoas[quantidade].nome, sizeof(pessoas[quantidade].nome), stdin);
        pessoas[quantidade].nome[strcspn(pessoas[quantidade].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &pessoas[quantidade].idade);
        getchar();

        printf("Telefone: ");
        fgets(pessoas[quantidade].telefone, sizeof(pessoas[quantidade].telefone), stdin);
        pessoas[quantidade].telefone[strcspn(pessoas[quantidade].telefone, "\n")] = '\0';

        printf("Email: ");
        fgets(pessoas[quantidade].email, sizeof(pessoas[quantidade].email), stdin);
        pessoas[quantidade].email[strcspn(pessoas[quantidade].email, "\n")] = '\0';

        quantidade++;

        if (quantidade == MAX) {
            printf("\nLimite maximo de cadastros atingidos!\n");
            break;
        }

        printf("\nDeseja cadastrar outra pessoa? (S/N): ");
        scanf(" %c", &opcao);
        getchar();
    }

    printf("\nRELATORIO GERAL\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nCadastro %d\n", i + 1);
        printf("Codigo: %d\n", pessoas[i].codigo);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("Email: %s\n", pessoas[i].email);
    }

    printf("Total de pessoas cadastradas: %d\n", quantidade);

    return 0;
}