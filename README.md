# Jogo da Velha em C

Este é um código simples de Jogo da Velha (Tic-Tac-Toe) desenvolvido em C, permitindo que dois jogadores escolham seus símbolos personalizados e joguem alternadamente até que um vença ou ocorra empate.

## Instruções de Compilação e Execução

### Requisitos
- Um compilador C (por exemplo, GCC).
- Sistema operacional: Funciona em qualquer sistema operacional com suporte para C (Linux, Windows, macOS).

### Compilação
1. Abra um terminal ou prompt de comando.
2. Navegue até o diretório onde o arquivo do código fonte (por exemplo, `jogo_da_velha.c`) está salvo.
3. Execute o comando de compilação. Se você estiver usando o GCC, o comando será:

   ```bash
   gcc jogo_da_velha.c -o jogo_da_velha

Isso criará um arquivo executável chamado jogo_da_velha.

- Execução:
Para rodar o jogo, digite o seguinte comando no terminal:
./jogo_da_velha

Como Jogar:
1. Ao iniciar o jogo, o programa pedirá para o Jogador 1 e o Jogador 2 escolherem os seus símbolos (por exemplo, X e O).
2. Cada jogador alterna a vez, escolhendo a posição no tabuleiro numerada de 1 a 9.
3. O jogo termina quando um dos jogadores vence ou quando ocorre um empate.

- Descrição do Código:
- Funções:
   - desenhaTabuleiro(): Exibe o tabuleiro na tela.
   - verificarVitoria(): Verifica se algum jogador venceu, verificando linhas, colunas e diagonais.
   - verificarEmpate(): Verifica se o jogo acabou em empate, ou seja, quando todas as posições estão ocupadas.
   - jogar(): Controla o fluxo do jogo, alternando as jogadas entre os jogadores, verificando vitória ou empate após cada jogada.

- Lógica do Jogo:
   - O jogo é alternado entre os jogadores, que escolhem um símbolo personalizado (pode ser qualquer caractere).
   - O jogador faz suas jogadas digitando um número de 1 a 9, representando as posições no tabuleiro.
   - Após cada jogada, o tabuleiro é reexibido, e o jogo verifica se algum jogador venceu ou se deu empate.


Esse README inclui as instruções detalhadas de como compilar e executar o código, além de fornecer uma explicação sobre as funções e a lógica do jogo no código C.
