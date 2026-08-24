#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Pessoa {
    int codigo;
    char nome[100];
    int idade;
    char telefone[20];
    char email[100];
};

static void ler_texto(const char *rotulo, char *destino, size_t tamanho) {
    printf("%s", rotulo);
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    destino[strcspn(destino, "\n")] = '\0';
}

static int ler_inteiro(const char *rotulo, int *valor) {
    char entrada[32];
    char *fim;
    long convertido;

    printf("%s", rotulo);
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 0;
    }

    convertido = strtol(entrada, &fim, 10);
    if (fim == entrada || (*fim != '\n' && *fim != '\0')) {
        return 0;
    }

    *valor = (int) convertido;
    return 1;
}

int main(void) {
    struct Pessoa pessoas[MAX];

    int quantidade = 0;
    int i;
    char opcao = 'S';
    char resposta[8];

    printf("SISTEMA DE CADASTRO\n");

    while (opcao == 'S' || opcao == 's') {
        printf("Cadastro %d\n", quantidade + 1);
        if (!ler_inteiro("Codigo: ", &pessoas[quantidade].codigo)) {
            printf("Codigo invalido. Cadastro cancelado.\n");
            break;
        }

        ler_texto("Nome: ", pessoas[quantidade].nome, sizeof(pessoas[quantidade].nome));

        if (!ler_inteiro("Idade: ", &pessoas[quantidade].idade) || pessoas[quantidade].idade < 0) {
            printf("Idade invalida. Cadastro cancelado.\n");
            break;
        }

        ler_texto("Telefone: ", pessoas[quantidade].telefone, sizeof(pessoas[quantidade].telefone));

        ler_texto("Email: ", pessoas[quantidade].email, sizeof(pessoas[quantidade].email));

        quantidade++;

        if (quantidade == MAX) {
            printf("\nLimite maximo de cadastros atingidos!\n");
            break;
        }

        printf("\nDeseja cadastrar outra pessoa? (S/N): ");
        if (fgets(resposta, sizeof(resposta), stdin) == NULL) {
            break;
        }
        opcao = resposta[0];
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