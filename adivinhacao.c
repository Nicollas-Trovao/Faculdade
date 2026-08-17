#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aguarda o usuário pressionar Enter antes de fechar.
static void aguardar_enter(void) {
    int c;

    printf("\nPressione Enter para sair...");
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

int main(void) {
	int numeroSorteado;
	int palpite;
	int tentativas = 0;
	int pontos = 100;

	// Inicializa o gerador de números aleatórios.
	srand((unsigned int) time(NULL));

	// Gera um número entre 1 e 100.
	numeroSorteado = rand() % 100 + 1;

	printf("Jogo de Adivinhação\n");
	printf("Estou pensando em um número de 1 a 100.\n");

	do {
		printf("Digite seu palpite: ");

		if (scanf("%d", &palpite) != 1) {
			printf("Entrada inválida. Digite um numero inteiro.\n");
			while (getchar() != '\n') {
				// Limpa a entrada inválida.
			}
			continue;
		}

		tentativas++;

		if (palpite < numeroSorteado) {
			printf("Muito baixo! Tente um numero maior.\n");
		} else if (palpite > numeroSorteado) {
			printf("Muito alto! Tente um numero menor.\n");
		} else {
			if (pontos < 0) {
				pontos = 0;
			}

			printf("Parabens, voce acertou!\n");
			printf("Numero secreto: %d\n", numeroSorteado);
			printf("Tentativas: %d\n", tentativas);
			printf("Pontuacao: %d\n", pontos);
			break;
		}

		pontos -= 10;
		if (pontos < 0) {
			pontos = 0;
		}
		printf("Pontuacao atual: %d\n\n", pontos);
	} while (1);

aguardar_enter();

	return 0;
}

