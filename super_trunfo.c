int main() {
    // Declaração das variáveis para a Carta 1
    char estado1;
    char codigo1[5];
    char nome1[50];
    unsigned long int populacao1; // Alterado para unsigned long int
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pib_per_capita1;
    float super_poder1;           // Nova variável: Super Poder

    // Declaração das variáveis para a Carta 2
    char estado2;
    char codigo2[5];
    char nome2[50];
    unsigned long int populacao2; // Alterado para unsigned long int
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pib_per_capita2;
    float super_poder2;           // Nova variável: Super Poder

    // Declaração das variáveis para os resultados das comparações
    int pop_vence;
    int area_vence;
    int pib_vence;
    int pt_vence;
    int dens_vence;
    int pibpc_vence;
    int sp_vence;

    // --- Leitura dos dados da Carta 1 ---
    printf("--- Cadastro da Carta 1 ---\n");

    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome1);

    printf("Digite a População: ");
    scanf("%lu", &populacao1); // Usa %lu para unsigned long int

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Leitura dos dados da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");

    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome2);

    printf("Digite a População: ");
    scanf("%lu", &populacao2); // Usa %lu para unsigned long int

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos para a Carta 1 ---
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    // Calcula o Super Poder somando os atributos (convertendo para float)
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pib_per_capita1 + (1.0f / densidade1);

    // --- Cálculos para a Carta 2 ---
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    // Calcula o Super Poder somando os atributos (convertendo para float)
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pib_per_capita2 + (1.0f / densidade2);

    // --- Comparações (1 se Carta 1 vence, 0 se Carta 2 vence) ---
    pop_vence = populacao1 > populacao2;
    area_vence = area1 > area2;
    pib_vence = pib1 > pib2;
    pt_vence = pontosTuristicos1 > pontosTuristicos2;
    dens_vence = densidade1 < densidade2; // Menor densidade vence
    pibpc_vence = pib_per_capita1 > pib_per_capita2;
    sp_vence = super_poder1 > super_poder2;

    // --- Exibição dos Resultados das Comparações ---
    printf("\nComparação de Cartas:\n");

    // Usa o operador ternário para decidir qual número de carta (1 ou 2) exibir
    printf("População: Carta %d venceu (%d)\n", pop_vence ? 1 : 2, pop_vence);
    printf("Área: Carta %d venceu (%d)\n", area_vence ? 1 : 2, area_vence);
    printf("PIB: Carta %d venceu (%d)\n", pib_vence ? 1 : 2, pib_vence);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", pt_vence ? 1 : 2, pt_vence);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", dens_vence ? 1 : 2, dens_vence);
    printf("PIB per Capita: Carta %d venceu (%d)\n", pibpc_vence ? 1 : 2, pibpc_vence);
    printf("Super Poder: Carta %d venceu (%d)\n", sp_vence ? 1 : 2, sp_vence);

    return 0; // Indica que o programa terminou com sucesso
}