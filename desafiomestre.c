#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Função para calcular densidade demográfica
void calcularDensidade(struct Carta *c) {
    c->densidade = (c->area > 0) ? (c->populacao / c->area) : 0;
}

// Exibe as cartas
void exibirCarta(struct Carta c) {
    printf("\n--- %s ---\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidade);
}

// Função para obter valor numérico do atributo
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Exibe nome do atributo
void exibirNomeAtributo(int opcao) {
    switch (opcao) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

int main() {
    // Duas cartas pré-definidas
    struct Carta carta1 = {"Brasil", 214000000, 8515770.0, 1800.0, 25, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780000.0, 500.0, 10, 0};

    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    int atributo1 = 0, atributo2 = 0;

    // Primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // Validação
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Atributo inválido. Encerrando o programa.\n");
        return 1;
    }

    // Segundo atributo (sem repetir o primeiro)
    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - ", i);
            exibirNomeAtributo(i);
            printf("\n");
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Atributo inválido ou repetido. Encerrando o programa.\n");
        return 1;
    }

    // Obter valores
    float val1_c1 = obterValor(carta1, atributo1);
    float val2_c1 = obterValor(carta1, atributo2);
    float val1_c2 = obterValor(carta2, atributo1);
    float val2_c2 = obterValor(carta2, atributo2);

    // Comparação considerando exceção da Densidade
    float pontosC1 = 0, pontosC2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // Densidade: menor vence
        pontosC1 += (val1_c1 < val1_c2) ? val1_c1 : 0;
        pontosC2 += (val1_c2 < val1_c1) ? val1_c2 : 0;
    } else {
        pontosC1 += (val1_c1 > val1_c2) ? val1_c1 : 0;
        pontosC2 += (val1_c2 > val1_c1) ? val1_c2 : 0;
    }

    // Atributo 2
    if (atributo2 == 5) {
        pontosC1 += (val2_c1 < val2_c2) ? val2_c1 : 0;
        pontosC2 += (val2_c2 < val2_c1) ? val2_c2 : 0;
    } else {
        pontosC1 += (val2_c1 > val2_c2) ? val2_c1 : 0;
        pontosC2 += (val2_c2 > val2_c1) ? val2_c2 : 0;
    }

    // Soma total dos atributos (para determinar o vencedor)
    float somaC1 = val1_c1 + val2_c1;
    float somaC2 = val1_c2 + val2_c2;

    // Exibição
    printf("\nResultado da comparação:\n");

    printf("\n%s:\n", carta1.nome);
    printf("- ");
    exibirNomeAtributo(atributo1);
    printf(": %.2f\n", val1_c1);
    printf("- ");
    exibirNomeAtributo(atributo2);
    printf(": %.2f\n", val2_c1);
    printf("Soma: %.2f\n", somaC1);

    printf("\n%s:\n", carta2.nome);
    printf("- ");
    exibirNomeAtributo(atributo1);
    printf(": %.2f\n", val1_c2);
    printf("- ");
    exibirNomeAtributo(atributo2);
    printf(": %.2f\n", val2_c2);
    printf("Soma: %.2f\n", somaC2);

    // Determinar vencedor final
    if (somaC1 > somaC2) {
        printf("\nResultado final: %s venceu!\n", carta1.nome);
    } else if (somaC2 > somaC1) {
        printf("\nResultado final: %s venceu!\n", carta2.nome);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}
