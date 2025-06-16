#include <stdio.h>  // Biblioteca para entrada/saída (printf, scanf)


int main() {
    // --- Declaração e Inicialização Direta das Variáveis ---

    // Atributos da Carta 1 (Brasil)
    char nome_pais1[50] = "Brasil";
    unsigned long int populacao1 = 215000000;
    float area1 = 8515767.0f;
    float pib_bilhoes1 = 1900.0f;
    int pontosTuristicos1 = 100;
    float densidade1 = 0.0f;

    // Atributos da Carta 2 (Argentina)
    char nome_pais2[50] = "Argentina";
    unsigned long int populacao2 = 46000000;
    float area2 = 2780400.0f;
    float pib_bilhoes2 = 630.0f;
    int pontosTuristicos2 = 70;
    float densidade2 = 0.0f;

    // Array com os nomes dos atributos para exibição
    char *nomes_atributos[] = {
        "", // Índice 0 não usado
        "População",
        "Área (km²)",
        "PIB (Bilhões)",
        "Pontos Turísticos",
        "Densidade Demográfica (hab/km²)"
    };

    // Variáveis de controle e cálculo
    int escolha1 = 0, escolha2 = 0;
    float valor1_c1 = 0.0f, valor2_c1 = 0.0f;
    float valor1_c2 = 0.0f, valor2_c2 = 0.0f;
    float soma1 = 0.0f;
    float soma2 = 0.0f;

    // --- Cálculos Iniciais ---
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // --- Menu 1: Escolha do Primeiro Atributo (Sem Loop) ---
    printf("\n--- Escolha o PRIMEIRO Atributo (1-5) ---\n");
    printf("1. População\n");
    printf("2. Área (km²)\n");
    printf("3. PIB (Bilhões)\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica (hab/km²)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha1); // Lê a primeira escolha

    // --- Menu 2: Escolha do Segundo Atributo (Hardcoded via Switch, Sem Loop) ---
    printf("\n--- Escolha o SEGUNDO Atributo ---\n");

    // Usa 'switch' para exibir o menu dinâmico de forma "hardcoded"
    switch (escolha1) {
        case 1:
            printf("2. Área (km²)\n");
            printf("3. PIB (Bilhões)\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Demográfica (hab/km²)\n");
            break;
        case 2:
            printf("1. População\n");
            printf("3. PIB (Bilhões)\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Demográfica (hab/km²)\n");
            break;
        case 3:
            printf("1. População\n");
            printf("2. Área (km²)\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Demográfica (hab/km²)\n");
            break;
        case 4:
            printf("1. População\n");
            printf("2. Área (km²)\n");
            printf("3. PIB (Bilhões)\n");
            printf("5. Densidade Demográfica (hab/km²)\n");
            break;
        case 5:
            printf("1. População\n");
            printf("2. Área (km²)\n");
            printf("3. PIB (Bilhões)\n");
            printf("4. Pontos Turísticos\n");
            break;
        default:
            // Se a primeira escolha foi inválida, informa e sai.
            printf("\nERRO: Primeira escolha (%d) é inválida. O programa será encerrado.\n", escolha1);
            return 1; // Retorna 1 para indicar erro.
    }
    printf("Digite sua escolha: ");
    scanf("%d", &escolha2); // Lê a segunda escolha

    // --- Validação Mínima (Sem Loop) ---
    // Verifica se a segunda escolha é igual à primeira ou inválida.
    if (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 5) {
         printf("\nERRO: Segunda escolha (%d) é inválida ou igual à primeira. O programa será encerrado.\n", escolha2);
         return 1; // Retorna 1 para indicar erro.
    }


    // --- Obtenção dos Valores Escolhidos ---
    switch (escolha1) {
        case 1: valor1_c1 = (float)populacao1; valor1_c2 = (float)populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib_bilhoes1; valor1_c2 = pib_bilhoes2; break;
        case 4: valor1_c1 = (float)pontosTuristicos1; valor1_c2 = (float)pontosTuristicos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
    }

    switch (escolha2) {
        case 1: valor2_c1 = (float)populacao1; valor2_c2 = (float)populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib_bilhoes1; valor2_c2 = pib_bilhoes2; break;
        case 4: valor2_c1 = (float)pontosTuristicos1; valor2_c2 = (float)pontosTuristicos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
    }

    // --- Cálculo da Soma ---
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    // --- Exibição dos Resultados ---
    printf("\n\n--- Resultado da Comparação ---\n");
    printf("Países: %s vs %s\n", nome_pais1, nome_pais2);
    printf("Atributos: %s e %s\n", nomes_atributos[escolha1], nomes_atributos[escolha2]);
    printf("----------------------------------\n");
    printf("%s:\n", nome_pais1);
    printf("  %s: %.2f\n", nomes_atributos[escolha1], valor1_c1);
    printf("  %s: %.2f\n", nomes_atributos[escolha2], valor2_c1);
    printf("  Soma: %.2f\n", soma1);
    printf("----------------------------------\n");
    printf("%s:\n", nome_pais2);
    printf("  %s: %.2f\n", nomes_atributos[escolha1], valor1_c2);
    printf("  %s: %.2f\n", nomes_atributos[escolha2], valor2_c2);
    printf("  Soma: %.2f\n", soma2);
    printf("----------------------------------\n");

    // --- Determinação do Vencedor (usando operador ternário) ---
    printf("Resultado Final: ");
    printf("%s\n", (soma1 > soma2) ? "Carta 1 (Brasil) venceu!" :
                   (soma2 > soma1) ? "Carta 2 (Argentina) venceu!" :
                   "Empate!");

    // --- Fim do programa ---
    return 0; // Indica que o programa terminou com sucesso.
}