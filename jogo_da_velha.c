#include <stdio.h>   // Biblioteca para entrada e saída de dados (printf, scanf, etc.)
#include <stdlib.h>  // Biblioteca para funções de utilidade (como malloc, free, etc.)
#include <string.h>  // Biblioteca para manipulação de strings (fgets, strcspn, etc.)
#include <stdbool.h> // Biblioteca para o tipo booleano (true e false)

struct Jogador
{
    char nome1[30];  // Nome do jogador (máximo de 30 caracteres)
    char caractere;  // Caractere escolhido pelo jogador ('X' ou 'O')
};
typedef struct Jogador jogador; // Define 'jogador' como um alias para a estrutura 'Jogador'

// Funções declaradas no início
void ShowNumbers(); 
void ShowHash(char p[3][3]); 
bool IsEmpty(char p[3][3], int posi); 
void Mark(char p[3][3], int posi, char letter); 
int IsEnd(char p[3][3], char name1[30], char name2[30], int turns, jogador player[]); 
void WhoWin(char letter, char name1[30], char name2[30], int turns, jogador player[]);

int main() // Função principal
{
    jogador jogadores[2]; // Vetor para armazenar os dois jogadores
    int posi1, posi2, turno = 0; // Posições dos jogadores e variável de controle de turnos
    char hash[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Tabuleiro inicial (vazio)
    int op; // Variável para armazenar a escolha de 'X' ou 'O'
    
    printf("-----------------JOGO DA VELHA-----------------\n"); // Exibe título do jogo
    printf("Nome do primeiro jogador: \n"); // Solicita o nome do primeiro jogador
    fgets(jogadores[0].nome1, 30, stdin); // Lê o nome do primeiro jogador
    jogadores[0].nome1[strcspn(jogadores[0].nome1, "\n")] = 0; // Remove o '\n' da string
    
    do
    {
        printf("Deseja ser X ou O?\n1 - para X\n2 - para O:\n"); // Pergunta se o jogador quer 'X' ou 'O'
        scanf("%d", &op); // Lê a opção do jogador
        getchar(); // Limpa o buffer de entrada (para evitar problemas com fgets)
        
        if (op == 1) // Se escolher 'X'
        {
            jogadores[0].caractere = 'X'; // O primeiro jogador será 'X'
            jogadores[1].caractere = 'O'; // O segundo jogador será 'O'
        }
        else // Se escolher 'O'
        {
            jogadores[0].caractere = 'O'; // O primeiro jogador será 'O'
            jogadores[1].caractere = 'X'; // O segundo jogador será 'X'
        }
    } while (op != 1 && op != 2); // Loop até que o jogador escolha uma opção válida
    
    printf("Nome do segundo jogador: \n"); // Solicita o nome do segundo jogador
    fgets(jogadores[1].nome1, 30, stdin); // Lê o nome do segundo jogador
    jogadores[1].nome1[strcspn(jogadores[1].nome1, "\n")] = 0; // Remove o '\n' da string
    
    while (true) // Loop principal do jogo
    {
        turno++; // Incrementa o número de turnos
        ShowNumbers(); // Exibe os números das posições do tabuleiro
        ShowHash(hash); // Exibe o estado atual do tabuleiro
        
        do
        {
            printf("Player 1 - Digite uma posição para marcar: \n"); // Solicita a posição para o primeiro jogador
            scanf("%d", &posi1); // Lê a posição escolhida
        } while (IsEmpty(hash, posi1)); // Se a posição estiver ocupada, solicita novamente
        
        Mark(hash, posi1, jogadores[0].caractere); // Marca a posição no tabuleiro com o caractere do primeiro jogador
        
        if (IsEnd(hash, jogadores[0].nome1, jogadores[1].nome1, turno, jogadores)) // Verifica se o jogo terminou
        {
            break; // Se o jogo terminou (vitória ou empate), sai do loop
        }
        
        do
        {
            printf("Player 2 - Digite uma posição para marcar: \n"); // Solicita a posição para o segundo jogador
            scanf("%d", &posi2); // Lê a posição escolhida
        } while (IsEmpty(hash, posi2)); // Se a posição estiver ocupada, solicita novamente
        
        Mark(hash, posi2, jogadores[1].caractere); // Marca a posição no tabuleiro com o caractere do segundo jogador
        
        if (IsEnd(hash, jogadores[0].nome1, jogadores[1].nome1, turno, jogadores)) // Verifica se o jogo terminou
        {
            break; // Se o jogo terminou (vitória ou empate), sai do loop
        }
    };
    return 0; // Fim da função principal
}

void ShowNumbers() // Função que exibe os números das posições do tabuleiro
{
    int cont = 1; // Contador para as posições
    for (int x = 0; x < 3; x++) // Laço para percorrer as linhas do tabuleiro
    {
        for (int y = 0; y < 3; y++) // Laço para percorrer as colunas do tabuleiro
        {
            printf(" [%d] ", cont); // Exibe o número da posição
            cont++; // Incrementa a posição
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

void ShowHash(char p[3][3]) // Função que exibe o estado atual do tabuleiro
{
    for (int x = 0; x < 3; x++) // Laço para percorrer as linhas do tabuleiro
    {
        for (int y = 0; y < 3; y++) // Laço para percorrer as colunas do tabuleiro
        {
            printf(" [%c] ", p[x][y]); // Exibe o caractere da posição
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

bool IsEmpty(char p[3][3], int posi) // Função que verifica se uma posição está vazia
{
    if (posi < 1 || posi > 9) // Verifica se a posição é válida (1 a 9)
    {
        return false; // Posição inválida
    }
    int cont = 1; // Contador para percorrer as posições
    for (int x = 0; x < 3; x++) // Laço para percorrer as linhas do tabuleiro
    {
        for (int y = 0; y < 3; y++) // Laço para percorrer as colunas do tabuleiro
        {
            if (cont == posi) // Se a posição encontrada for a escolhida
            {
                if (p[x][y] != ' ') // Verifica se a posição está ocupada
                {
                    return true; // Posição ocupada
                }
                else
                {
                    return false; // Posição vazia
                }
            }
            cont++; // Incrementa a posição
        }
    }
    return false; // Caso não encontre a posição, retorna 'false'
}

void Mark(char p[3][3], int posi, char letter) // Função que marca uma posição no tabuleiro
{
    int cont = 1; // Contador para percorrer as posições
    for (int x = 0; x < 3; x++) // Laço para percorrer as linhas do tabuleiro
    {
        for (int y = 0; y < 3; y++) // Laço para percorrer as colunas do tabuleiro
        {
            if (cont == posi) // Se a posição encontrada for a escolhida
            {
                p[x][y] = letter; // Marca a posição com o caractere do jogador
            }
            cont++; // Incrementa a posição
        }
    }
}

int IsEnd(char p[3][3], char name1[30], char name2[30], int turns, jogador player[]) // Função que verifica se o jogo terminou
{
    // Verifica se há vitória nas linhas ou colunas
    for (int x = 0; x < 3; x++) 
    {
        if ((p[x][0] == p[x][1] && p[x][1] == p[x][2]) && (p[x][0] != ' ')) // Linha vencedora
        {
            WhoWin(p[x][0], name1, name2, turns, player); // Chama a função que exibe o vencedor
            return 1; // Retorna 1 indicando vitória
        }
        if ((p[0][x] == p[1][x] && p[1][x] == p[2][x]) && (p[0][x] != ' ')) // Coluna vencedora
        {
            WhoWin(p[0][x], name1, name2, turns, player); // Chama a função que exibe o vencedor
            return 1; // Retorna 1 indicando vitória
        }
    }
    // Verifica se há vitória nas diagonais
    if ((p[0][0] == p[1][1] && p[1][1] == p[2][2]) && (p[0][0] != ' ')) 
    {
        WhoWin(p[0][0], name1, name2, turns, player); // Chama a função que exibe o vencedor
        return 1; // Retorna 1 indicando vitória
    }
    else if ((p[0][2] == p[1][1] && p[1][1] == p[2][0]) && (p[0][2] != ' ')) 
    {
        WhoWin(p[1][1], name1, name2, turns, player); // Chama a função que exibe o vencedor
        return 1; // Retorna 1 indicando vitória
    }
    
    // Verifica se o jogo terminou em empate
    int cont = 0; // Contador de posições ocupadas
    for (int x = 0; x < 3; x++) // Laço para percorrer o tabuleiro
    {
        for (int y = 0; y < 3; y++) // Laço para percorrer o tabuleiro
        {
            if (p[x][y] == 'X' || p[x][y] == 'O') // Conta as posições ocupadas
            {
                cont++;
            }
        }
    }
    if (cont == 9) // Se o tabuleiro estiver cheio
    {
        printf("DEU EMPATE!"); // Exibe mensagem de empate
        return 1; // Retorna 1 indicando empate
    }
    return 0; // Retorna 0, indicando que o jogo ainda não terminou
}

void WhoWin(char letter, char name1[30], char name2[30], int turns, jogador player[]) // Função que exibe o vencedor
{
    if (letter == player[0].caractere) // Se o vencedor for o primeiro jogador
    {
        printf("%s Ganhou! Quantidade de turnos: %d Pontuação: %d\n", player[0].nome1,
               turns, 50 - turns * 2); // Exibe o nome, turnos e pontuação do primeiro jogador
    }
    else // Se o vencedor for o segundo jogador
    {
        printf("%s Ganhou! Quantidade de turnos: %d Pontuação: %d\n", player[1].nome1,
               turns, 50 - turns * 2); // Exibe o nome, turnos e pontuação do segundo jogador
    }
}

