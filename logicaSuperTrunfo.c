#include <stdio.h>

int main() {

    // Identificadores dos estados
    char estados[8] = {'A','B','C','D','E','F','G','H'};

    // Dados das cartas
    int populacao[8][4];
    float area[8][4];
    float pib[8][4];
    int pontos[8][4];

    // Dados calculados (Nível Aventureiro)
    float densidade[8][4];
    float pibPerCapita[8][4];

    printf("=== SUPER TRUNFO - PAISES (NIVEIS: NOVATO + AVENTUREIRO + MESTRE) ===\n");

    // ================================
    // CADASTRO DAS CARTAS (Nível Novato)
    // ================================
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {

            printf("\n--- Cadastro da carta %c0%d ---\n", estados[i], j + 1);

            printf("Populacao: ");
            scanf("%d", &populacao[i][j]);

            printf("Area (km2): ");
            scanf("%f", &area[i][j]);

            printf("PIB (em bilhoes): ");
            scanf("%f", &pib[i][j]);

            printf("Pontos turisticos: ");
            scanf("%d", &pontos[i][j]);

            // ================================
            // CALCULOS (Nível Aventureiro)
            // ================================
            densidade[i][j] = populacao[i][j] / area[i][j];
            pibPerCapita[i][j] = pib[i][j] * 1e9 / populacao[i][j]; 
            // Multiplica PIB por 1e9 p/ converter bilhões → unidades reais
        }
    }

    // ================================
    // EXIBIÇÃO DAS CARTAS
    // ================================
    printf("\n\n=== CARTAS CADASTRADAS ===\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {

            printf("\n--- Carta %c0%d ---\n", estados[i], j + 1);
            printf("Populacao: %d\n", populacao[i][j]);
            printf("Area: %.2f km2\n", area[i][j]);
            printf("PIB: %.2f bilhoes\n", pib[i][j]);
            printf("Pontos turisticos: %d\n", pontos[i][j]);

            // Dados calculados (Aventureiro)
            printf("Densidade Populacional: %.2f hab/km2\n", densidade[i][j]);
            printf("PIB per Capita: %.2f\n", pibPerCapita[i][j]);
        }
    }

    // ================================
    // NÍVEL MESTRE: COMPARAÇÃO ENTRE CARTAS
    // ================================

    int estado1, cidade1, estado2, cidade2;

    printf("\n\n=== NIVEL MESTRE: COMPARACAO ENTRE CARTAS ===\n");
    printf("Digite o numero do estado da primeira carta (0=A,...,7=H): ");
    scanf("%d", &estado1);

    printf("Digite o numero da cidade da primeira carta (0=1,...,3=4): ");
    scanf("%d", &cidade1);

    printf("Digite o numero do estado da segunda carta: ");
    scanf("%d", &estado2);

    printf("Digite o numero da cidade da segunda carta: ");
    scanf("%d", &cidade2);

    // Super Poder (soma das propriedades principais)
    float super1 = populacao[estado1][cidade1] + area[estado1][cidade1] +
                   pib[estado1][cidade1] + pontos[estado1][cidade1];
    float super2 = populacao[estado2][cidade2] + area[estado2][cidade2] +
                   pib[estado2][cidade2] + pontos[estado2][cidade2];

    printf("\n\n=== RESULTADO DA COMPARACAO ===\n");

    // População
    printf("\nPopulacao: ");
    if (populacao[estado1][cidade1] > populacao[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (populacao[estado2][cidade2] > populacao[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // Área
    printf("\nArea: ");
    if (area[estado1][cidade1] > area[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (area[estado2][cidade2] > area[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // PIB
    printf("\nPIB: ");
    if (pib[estado1][cidade1] > pib[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (pib[estado2][cidade2] > pib[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // Pontos turísticos
    printf("\nPontos Turisticos: ");
    if (pontos[estado1][cidade1] > pontos[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (pontos[estado2][cidade2] > pontos[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // Densidade populacional (MENOR vence)
    printf("\nDensidade Populacional (menor vence): ");
    if (densidade[estado1][cidade1] < densidade[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (densidade[estado2][cidade2] < densidade[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // PIB per capita
    printf("\nPIB per Capita: ");
    if (pibPerCapita[estado1][cidade1] > pibPerCapita[estado2][cidade2])
        printf("Carta 1 venceu!");
    else if (pibPerCapita[estado2][cidade2] > pibPerCapita[estado1][cidade1])
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    // Super Poder
    printf("\nSuper Poder (soma das propriedades): ");
    if (super1 > super2)
        printf("Carta 1 venceu!");
    else if (super2 > super1)
        printf("Carta 2 venceu!");
    else
        printf("Empate!");

    printf("\n");

    return 0;
}
