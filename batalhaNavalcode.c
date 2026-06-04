#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define PARTE_NAVIO 3

int main() {

    // Tabuleiro 10x10 inicializado com água
    int tabuleiro[TAM][TAM] = {0};

    int erro = 0;

    // ==========================
    // NAVIO HORIZONTAL
    // ==========================
    int linhaH = 1;
    int colunaH = 2;

    if (colunaH + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {

            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                erro = 1;
            }
        }

        if (!erro) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = PARTE_NAVIO;
            }
        }
    }

    // ==========================
    // NAVIO VERTICAL
    // ==========================
    int linhaV = 4;
    int colunaV = 7;

    erro = 0;

    if (linhaV + NAVIO <= TAM) {

        for (int i = 0; i < NAVIO; i++) {

            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                erro = 1;
            }
        }

        if (!erro) {

            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = PARTE_NAVIO;
            }
        }
    }

    // ==========================
    // NAVIO DIAGONAL PRINCIPAL
    // ==========================
    int linhaD1 = 2;
    int colunaD1 = 0;

    erro = 0;

    if (linhaD1 + NAVIO <= TAM &&
        colunaD1 + NAVIO <= TAM) {

        for (int i = 0; i < NAVIO; i++) {

            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
                erro = 1;
            }
        }

        if (!erro) {

            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = PARTE_NAVIO;
            }
        }
    }

    // ==========================
    // NAVIO DIAGONAL SECUNDÁRIA
    // ==========================
    int linhaD2 = 0;
    int colunaD2 = 9;

    erro = 0;

    if (linhaD2 + NAVIO <= TAM &&
        colunaD2 - (NAVIO - 1) >= 0) {

        for (int i = 0; i < NAVIO; i++) {

            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
                erro = 1;
            }
        }

        if (!erro) {

            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = PARTE_NAVIO;
            }
        }
    }

    // ==========================
    // EXIBIÇÃO DO TABULEIRO
    // ==========================
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int linha = 0; linha < TAM; linha++) {

        for (int coluna = 0; coluna < TAM; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}