#include <stdio.h>

char tabuleiro[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char jogador1, jogador2;
int escolha;
int rodada = 0;

// Função para desenhar o tabuleiro
void desenhaTabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// Função para verificar se algum jogador venceu
int verificarVitoria() {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1;
    }
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1;

    return 0;
}

// Função para verificar se o jogo deu empate
int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Se alguma posição não estiver ocupada pelos jogadores, ainda há espaço para jogar
            if (tabuleiro[i][j] != jogador1 && tabuleiro[i][j] != jogador2)
                return 0;
        }
    }
    return 1;
}

// Função principal para controlar o fluxo do jogo
void jogar() {
    int linha, coluna;
    while (1) {
        // Desenha o tabuleiro após cada jogada
        desenhaTabuleiro();
        
        // Determina o jogador atual baseado no número da rodada
        printf("Jogador %c, escolha uma posição (1-9): ", (rodada % 2 == 0) ? jogador1 : jogador2);
        scanf("%d", &escolha);

        // Valida se a escolha está dentro dos limites
        if (escolha < 1 || escolha > 9) {
            printf("Escolha inválida! Tente novamente.\n");
            continue;
        }

        // Converte a escolha para coordenadas do tabuleiro (linha, coluna)
        linha = (escolha - 1) / 3;
        coluna = (escolha - 1) % 3;

        // Verifica se a posição já está ocupada
        if (tabuleiro[linha][coluna] == jogador1 || tabuleiro[linha][coluna] == jogador2) {
            printf("Posição já ocupada! Tente novamente.\n");
            continue;
        }

        // Atribui o símbolo do jogador à posição escolhida
        tabuleiro[linha][coluna] = (rodada % 2 == 0) ? jogador1 : jogador2;
        rodada++;

        // Verifica se algum jogador venceu
        if (verificarVitoria()) {
            desenhaTabuleiro();
            printf("Jogador %c venceu!\n", (rodada % 2 == 0) ? jogador2 : jogador1);
            break;
        }

        // Verifica se deu empate
        if (verificarEmpate()) {
            desenhaTabuleiro();
            printf("Empate!\n");
            break;
        }
    }
}

int main() {
    // Solicita aos jogadores que escolham seus símbolos
    printf("Escolha o símbolo do Jogador 1: ");
    scanf(" %c", &jogador1);
    printf("Escolha o símbolo do Jogador 2: ");
    scanf(" %c", &jogador2);

    // Inicia o jogo
    jogar();
    return 0;
}
