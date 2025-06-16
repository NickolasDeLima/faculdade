#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída para usar printf

// --- Protótipos das Funções Recursivas ---
// Declaramos as funções antes de usá-las para que o compilador as conheça.
void mover_torre_recursivo(int passos_restantes);
void mover_bispo_recursivo(int passos_restantes);
void mover_rainha_recursivo(int passos_restantes);

/**
 * @brief Move a Torre recursivamente para a direita.
 * @param passos_restantes O número de casas que ainda faltam mover.
 */
void mover_torre_recursivo(int passos_restantes) {
    // Condição de parada: Se não houver mais passos, a função retorna.
    if (passos_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento atual.
    printf("Direita\n");

    // Chamada Recursiva: Chama a si mesma com um passo a menos.
    mover_torre_recursivo(passos_restantes - 1);
}

/**
 * @brief Move o Bispo recursivamente na diagonal Cima-Direita.
 * * Utiliza loops aninhados triviais internamente apenas para
 * * cumprir o requisito de usar ambos (recursão e loops aninhados).
 * @param passos_restantes O número de casas que ainda faltam mover.
 */
void mover_bispo_recursivo(int passos_restantes) {
    // Condição de parada: Se não houver mais passos, a função retorna.
    if (passos_restantes <= 0) {
        return;
    }

    /**
     * Ação: Imprime o movimento usando loops aninhados.
     * Estes loops são 'triviais' (executam apenas uma vez por chamada)
     * para permitir que a recursão controle o número total de passos,
     * ao mesmo tempo que satisfaz a exigência de usar loops aninhados
     * (externo = vertical, interno = horizontal).
     */
    for (int v = 0; v < 1; v++) { // Simula o componente 'vertical' do passo (executa 1 vez)
        for (int h = 0; h < 1; h++) { // Simula o componente 'horizontal' do passo (executa 1 vez)
            printf("Cima, Direita\n");
        }
    }

    // Chamada Recursiva: Chama a si mesma com um passo a menos.
    mover_bispo_recursivo(passos_restantes - 1);
}

/**
 * @brief Move a Rainha recursivamente para a esquerda.
 * @param passos_restantes O número de casas que ainda faltam mover.
 */
void mover_rainha_recursivo(int passos_restantes) {
    // Condição de parada: Se não houver mais passos, a função retorna.
    if (passos_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento atual.
    printf("Esquerda\n");

    // Chamada Recursiva: Chama a si mesma com um passo a menos.
    mover_rainha_recursivo(passos_restantes - 1);
}

/**
 * @brief Função principal do programa.
 *
 * Coordena a simulação dos movimentos das peças, chamando as funções
 * recursivas e implementando os loops complexos para o Cavalo.
 */
int main() {

    // --- Definição das Variáveis ---
    // Define o número de casas que cada peça se moverá.
    int casas_torre = 5;
    int casas_bispo = 5;
    int casas_rainha = 8;
    int casas_cima_cavalo = 2;    // Novo movimento do cavalo
    int casas_direita_cavalo = 1; // Novo movimento do cavalo

    // --- Movimento da Torre (Recursivo) ---
    printf("--- Movimento da Torre (%d casas para Direita) ---\n", casas_torre);
    mover_torre_recursivo(casas_torre);
    printf("\n"); // Linha em branco para separar

    // --- Movimento do Bispo (Recursivo + Aninhado) ---
    printf("--- Movimento do Bispo (%d casas para Cima, Direita) ---\n", casas_bispo);
    mover_bispo_recursivo(casas_bispo);
    printf("\n"); // Linha em branco para separar

    // --- Movimento da Rainha (Recursivo) ---
    printf("--- Movimento da Rainha (%d casas para Esquerda) ---\n", casas_rainha);
    mover_rainha_recursivo(casas_rainha);
    printf("\n"); // Linha em branco para separar

    // --- Movimento do Cavalo (Loops Complexos: 2 Cima, 1 Direita) ---
    printf("--- Movimento do Cavalo (%d Cima, %d Direita) ---\n", casas_cima_cavalo, casas_direita_cavalo);
    /**
     * Loops aninhados para o Cavalo (2 Cima, 1 Direita).
     * O loop 'for' externo controla os passos para cima (v = vertical).
     * O loop 'for' interno controla os passos para a direita (h = horizontal).
     * 'continue' é usado para pular o passo para a direita até que
     * o cavalo tenha subido as duas casas.
     * 'break' é usado para garantir que ele mova apenas uma casa para a direita.
     */
    for (int v = 1; v <= casas_cima_cavalo; v++) {
        printf("Cima\n"); // Imprime o passo para cima

        // Loop interno para o movimento horizontal
        for (int h = 1; h <= casas_direita_cavalo; h++) {
            // Se ainda não deu os 2 passos para cima ('v' não é 2),
            // pula para a próxima iteração do loop externo usando 'continue'.
            // Como o loop interno só tem uma iteração, ele efetivamente
            // impede a impressão de "Direita" até que v == 2.
            if (v != casas_cima_cavalo) {
                continue; // Pula o resto do loop interno e vai para o próximo 'v'
            }

            // Se chegou aqui, significa que v == 2. Imprime o passo para a direita.
            printf("Direita\n");

            // Interrompe o loop interno (embora ele já fosse terminar).
            // Garante que apenas um passo para a direita seja dado.
            break;
        }
    }

    // Retorna 0 para indicar que o programa foi executado com sucesso.
    return 0;
}