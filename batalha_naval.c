#include <stdio.h>  // Biblioteca para entrada/saída (printf)
#include <stdlib.h> // Biblioteca para a função abs() (valor absoluto)
#include <math.h>   // Necessário para abs() em alguns compiladores C mais antigos, embora stdlib.h seja o padrão.

// --- Constantes ---
#define TAM_TABULEIRO 10  // Tamanho do tabuleiro principal (10x10)
#define TAM_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

// --- Definição dos Marcadores ---
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

// --- Protótipos das Funções ---
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void criar_matriz_cone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void criar_matriz_cruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void criar_matriz_octaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicar_habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_lin, int origem_col);
void exibir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

/**
 * @brief Preenche o tabuleiro inicial com água (0) e alguns navios (3).
 * @param tabuleiro A matriz 10x10 a ser inicializada.
 */
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Inicializando tabuleiro...\n");
    for (int l = 0; l < TAM_TABULEIRO; l++) {
        for (int c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro[l][c] = AGUA; // Preenche tudo com água
        }
    }
    // Adiciona alguns navios (3)
    tabuleiro[1][1] = NAVIO; tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO;
    tabuleiro[6][6] = NAVIO; tabuleiro[7][6] = NAVIO; tabuleiro[8][6] = NAVIO;
    tabuleiro[4][8] = NAVIO;
    tabuleiro[4][4] = NAVIO; // Navio no centro (potencial ponto de origem)
    printf("Tabuleiro inicializado.\n\n");
}

/**
 * @brief Cria a matriz de habilidade em forma de Cone (apontando para baixo).
 * * A matriz é 5x5, e o cone tem 3 níveis, com a ponta em [1][2].
 * @param matriz A matriz 5x5 a ser preenchida com 0s e 1s.
 */
void criar_matriz_cone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2; // = 2
    for (int l = 0; l < TAM_HABILIDADE; l++) {
        for (int c = 0; c < TAM_HABILIDADE; c++) {
            // Condição para formar um cone de 3 níveis com ponta em [1][2]
            if (l >= 1 && l <= 3 && c >= centro - (l - 1) && c <= centro + (l - 1)) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

/**
 * @brief Cria a matriz de habilidade em forma de Cruz.
 * * A matriz é 5x5, com o centro em [2][2].
 * @param matriz A matriz 5x5 a ser preenchida com 0s e 1s.
 */
void criar_matriz_cruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2; // = 2
    for (int l = 0; l < TAM_HABILIDADE; l++) {
        for (int c = 0; c < TAM_HABILIDADE; c++) {
            // Condição para formar uma cruz no centro [2][2]
            if (l == centro || c == centro) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

/**
 * @brief Cria a matriz de habilidade em forma de Octaedro (Losango).
 * * A matriz é 5x5, com o centro em [2][2].
 * @param matriz A matriz 5x5 a ser preenchida com 0s e 1s.
 */
void criar_matriz_octaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2; // = 2
    for (int l = 0; l < TAM_HABILIDADE; l++) {
        for (int c = 0; c < TAM_HABILIDADE; c++) {
            // Condição para formar um losango (distância de Manhattan <= 2)
            if (abs(l - centro) + abs(c - centro) <= centro) {
                matriz[l][c] = 1;
            } else {
                matriz[l][c] = 0;
            }
        }
    }
}

/**
 * @brief Sobrepõe uma matriz de habilidade ao tabuleiro principal.
 * @param tabuleiro O tabuleiro principal 10x10.
 * @param habilidade A matriz de habilidade 5x5 (0s e 1s).
 * @param origem_lin A linha do tabuleiro onde o centro da habilidade será aplicado.
 * @param origem_col A coluna do tabuleiro onde o centro da habilidade será aplicado.
 */
void aplicar_habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_lin, int origem_col) {
    int centro_hab = TAM_HABILIDADE / 2; // Ponto central da matriz de habilidade (2)

    printf("Aplicando habilidade em (%d, %d)...\n", origem_lin, origem_col);

    // Percorre a matriz de habilidade
    for (int l_hab = 0; l_hab < TAM_HABILIDADE; l_hab++) {
        for (int c_hab = 0; c_hab < TAM_HABILIDADE; c_hab++) {

            // Se a posição atual da matriz de habilidade faz parte do efeito (== 1)
            if (habilidade[l_hab][c_hab] == 1) {

                // Calcula a posição correspondente no tabuleiro principal.
                // Ajusta para que o centro da habilidade coincida com o ponto de origem.
                int lin_tab = origem_lin - centro_hab + l_hab;
                int col_tab = origem_col - centro_hab + c_hab;

                // Verifica se a posição calculada está dentro dos limites do tabuleiro.
                if (lin_tab >= 0 && lin_tab < TAM_TABULEIRO &&
                    col_tab >= 0 && col_tab < TAM_TABULEIRO)
                {
                    // Marca a posição no tabuleiro como afetada pela habilidade (5).
                    tabuleiro[lin_tab][col_tab] = EFEITO;
                }
            }
        }
    }
     printf("Habilidade aplicada.\n\n");
}

/**
 * @brief Exibe o tabuleiro 10x10 no console.
 * @param tabuleiro A matriz 10x10 a ser exibida.
 */
void exibir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("--- Tabuleiro Batalha Naval ---\n");
    printf("  0 1 2 3 4 5 6 7 8 9 \n"); // Cabeçalho das colunas
    printf("-----------------------\n");
    for (int l = 0; l < TAM_TABULEIRO; l++) {
        printf("%d|", l); // Cabeçalho das linhas
        for (int c = 0; c < TAM_TABULEIRO; c++) {
            // Imprime o valor da célula seguido de um espaço.
            printf("%d ", tabuleiro[l][c]);
        }
        printf("|\n"); // Fim da linha
    }
     printf("-----------------------\n");
     printf("Legenda: %d = Água | %d = Navio | %d = Efeito\n\n", AGUA, NAVIO, EFEITO);
}


/**
 * @brief Função principal do programa.
 */
int main() {
    // Declaração das matrizes
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade_cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidade_cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidade_octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // --- Preparação ---
    inicializar_tabuleiro(tabuleiro);
    criar_matriz_cone(habilidade_cone);
    criar_matriz_cruz(habilidade_cruz);
    criar_matriz_octaedro(habilidade_octaedro);

    // Exibe o tabuleiro inicial
    printf("--- Tabuleiro Inicial ---\n");
    exibir_tabuleiro(tabuleiro);

    // --- Aplicação e Exibição (Exemplo com Octaedro no centro) ---
    // Define o ponto de origem (centro do tabuleiro)
    int origem_l = 4;
    int origem_c = 4;

    // Aplica a habilidade Octaedro no tabuleiro
    aplicar_habilidade(tabuleiro, habilidade_octaedro, origem_l, origem_c);

    // Exibe o tabuleiro com a habilidade aplicada
    printf("--- Tabuleiro com Habilidade (Octaedro em %d,%d) ---\n", origem_l, origem_c);
    exibir_tabuleiro(tabuleiro);

    /*
    // --- Exemplo com Cruz (Descomente para testar) ---
    inicializar_tabuleiro(tabuleiro); // Reseta o tabuleiro
    origem_l = 7;
    origem_c = 2;
    aplicar_habilidade(tabuleiro, habilidade_cruz, origem_l, origem_c);
    printf("--- Tabuleiro com Habilidade (Cruz em %d,%d) ---\n", origem_l, origem_c);
    exibir_tabuleiro(tabuleiro);

    // --- Exemplo com Cone (Descomente para testar) ---
    inicializar_tabuleiro(tabuleiro); // Reseta o tabuleiro
    origem_l = 2; // Lembre-se que o cone é 5x5, mas a ponta está em [1][2]
                  // Aplicar em [2][5] significa que o *centro* [2][2] da matriz 5x5
                  // ficará em [2][5] do tabuleiro. A ponta [1][2] ficará em [1][5].
    origem_c = 5;
    aplicar_habilidade(tabuleiro, habilidade_cone, origem_l, origem_c);
    printf("--- Tabuleiro com Habilidade (Cone em %d,%d) ---\n", origem_l, origem_c);
    exibir_tabuleiro(tabuleiro);
    */


    return 0; // Indica que o programa terminou com sucesso.
}