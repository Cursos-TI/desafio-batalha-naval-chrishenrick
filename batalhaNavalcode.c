#include <stdio.h>

int main() {

    // Matriz do tabuleiro 10x10
    int tabuleiro[10][10];

    // Variáveis de controle
    int linha, coluna;

    // Letras das colunas
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // ==============================
    // INICIALIZAÇÃO DO TABULEIRO
    // ==============================

    // Preenche todo o tabuleiro com 0
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ==============================
    // NAVIOS
    // ==============================

    // Vetores dos navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 1;

    // ==============================
    // POSICIONA NAVIO HORIZONTAL
    // ==============================

    // Verifica se cabe no tabuleiro
    if (colunaHorizontal + 3 <= 10) {

        for (coluna = 0; coluna < 3; coluna++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + coluna] =
                navioHorizontal[coluna];
        }

    } else {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
    }

    // ==============================
    // POSICIONA NAVIO VERTICAL
    // ==============================

    // Verifica se cabe no tabuleiro
    if (linhaVertical + 3 <= 10) {

        int sobreposicao = 0;

        // Verifica sobreposição
        for (linha = 0; linha < 3; linha++) {

            if (tabuleiro[linhaVertical + linha][colunaVertical] == 3) {
                sobreposicao = 1;
            }
        }

        // Posiciona se não houver sobreposição
        if (sobreposicao == 0) {

            for (linha = 0; linha < 3; linha++) {

                tabuleiro[linhaVertical + linha][colunaVertical] =
                    navioVertical[linha];
            }

        } else {
            printf("Erro: os navios estão se sobrepondo.\n");
        }

    } else {
        printf("Erro: navio vertical fora do tabuleiro.\n");
    }

    // ==============================
    // EXIBE O TABULEIRO
    // ==============================

    printf("\n===== BATALHA NAVAL =====\n\n");

    // Mostra letras das colunas
    printf("   ");

    for (coluna = 0; coluna < 10; coluna++) {
        printf("%c ", letras[coluna]);
    }

    printf("\n");

    // Mostra linhas e conteúdo do tabuleiro
    for (linha = 0; linha < 10; linha++) {

        // Ajusta alinhamento do número 10
        printf("%2d ", linha + 1);

        for (coluna = 0; coluna < 10; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}




