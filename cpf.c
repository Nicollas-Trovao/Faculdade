#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Aguarda o usuário pressionar Enter antes de fechar.
static void aguardar_enter(void) {
    int c;

    // Limpa o buffer de entrada deixado pelo scanf
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }

    printf("\nPressione Enter para sair...");
    getchar(); // Aguarda o usuário pressionar Enter
}

int validarCPF(char cpf[]) {
    int numeros[11];
    int j = 0;

    // Extrai apenas os números do CPF
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            numeros[j] = cpf[i] - '0';
            j++;
        }
    }

    // CPF precisa ter 11 números
    if (j != 11) {
        return 0;
    }

    // Verifica se todos os números são iguais
    int todosIguais = 1;

    for (int i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            todosIguais = 0;
            break;
        }
    }

    if (todosIguais) {
        return 0;
    }

    // ------------------------
    // Calcula o primeiro dígito
    // ------------------------
    int soma = 0;
    int peso = 10;

    for (int i = 0; i < 9; i++) {
        soma += numeros[i] * peso;
        peso--;
    }

    int resto = soma % 11;
    int digito1;

    if (resto < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - resto;
    }

    // Verifica primeiro dígito
    if (digito1 != numeros[9]) {
        return 0;
    }

    // ------------------------
    // Calcula o segundo dígito
    // ------------------------
    soma = 0;
    peso = 11;

    for (int i = 0; i < 10; i++) {
        soma += numeros[i] * peso;
        peso--;
    }

    resto = soma % 11;

    int digito2;

    if (resto < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - resto;
    }

    // Verifica segundo dígito
    if (digito2 != numeros[10]) {
        return 0;
    }

    return 1;
}

int main() {
    char cpf[20];

    printf("=== VALIDADOR DE CPF ===\n\n");

    printf("Digite o CPF: ");
    if (scanf("%19s", cpf) != 1) {
        printf("\nEntrada inválida.\n");
        return 1;
    }

    if (validarCPF(cpf)) {
        printf("\nCPF VALIDO!\n");
    } else {
        printf("\nCPF INVALIDO!\n");
    }

    aguardar_enter();

    return 0;
}