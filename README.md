# Jogo da Velha em C
Este é um simples jogo da velha (Tic-Tac-Toe) implementado em C para dois jogadores. O jogo permite que dois jogadores alternem suas jogadas e escolham entre os caracteres 'X' e 'O'. O jogo termina quando um dos jogadores vence ou quando o jogo empata.

- Funcionalidades
   - Entrada de nomes dos jogadores: O jogo solicita os nomes de dois jogadores.
   - Escolha de caractere: O primeiro jogador escolhe entre 'X' ou 'O' e o segundo jogador recebe o caractere oposto.
   - Tabuleiro interativo: O tabuleiro é exibido a cada turno, mostrando as posições disponíveis para marcação.
   - Verificação de vitória: O jogo verifica automaticamente se algum jogador venceu após cada jogada, verificando as linhas, colunas e diagonais.
   - Empate: Caso todas as posições sejam preenchidas e não haja vencedor, o jogo termina em empate.
   - Pontuação: A pontuação do jogador vencedor é calculada com base no número de turnos usados para vencer.

- Como Jogar
   - O primeiro jogador digita seu nome.
   - O primeiro jogador escolhe se quer jogar com o 'X' ou 'O'.
   - O segundo jogador digita seu nome e recebe o caractere oposto ao escolhido pelo primeiro jogador.
   - O jogo alterna entre os jogadores, pedindo que escolham uma posição no tabuleiro para marcar seu caractere.
   - O tabuleiro é mostrado a cada turno, assim como os números das posições.
   - O jogo termina quando um jogador vence ou quando todas as posições do tabuleiro são preenchidas (empate).
   - O vencedor é informado junto com o número de turnos e sua pontuação.

- Estrutura do Código
   - Funções principais:
      - ShowNumbers(): Exibe os números das posições no tabuleiro.
      - ShowHash(char p[3][3]): Exibe o estado atual do tabuleiro.
      - IsEmpty(char p[3][3], int posi): Verifica se uma posição está ocupada.
      - Mark(char p[3][3], int posi, char letter): Marca uma posição no tabuleiro com o caractere do jogador.
      - IsEnd(char p[3][3], char name1[30], char name2[30], int turns, jogador player[]): Verifica se o jogo terminou, seja por vitória ou empate.
      - WhoWin(char letter, char name1[30], char name2[30], int turns, jogador player[]): Exibe o vencedor e sua pontuação.
      - Estrutura Jogador: Armazena o nome e o caractere de cada jogador.
