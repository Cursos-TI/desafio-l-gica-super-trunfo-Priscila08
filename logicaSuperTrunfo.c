#include <stdio.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[4];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular os indicadores derivados
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir uma carta
void exibirCarta(struct Carta carta) {
    printf("\n--- Carta %s (%s) ---\n", carta.cidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f mil reais\n", carta.pibPerCapita);
}

// Função principal
int main() {
    // Cadastro fixo das duas cartas
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.11, 800.0, 15};
    struct Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1182.3, 411.0, 12};

    // Cálculo dos indicadores derivados
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe ambas as cartas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparação com base em PIB per capita
    printf("\n>>> Comparação de Cartas (Atributo: PIB per capita)\n");
    printf("Carta 1 - %s (%.2f mil reais)\n", carta1.cidade, carta1.pibPerCapita);
    printf("Carta 2 - %s (%.2f mil reais)\n", carta2.cidade, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
