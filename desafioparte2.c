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

// Função que calcula a densidade populacional
void calcularDensidade(struct Carta *carta) {
    if (carta->area > 0) {
        carta->densidade = carta->populacao / carta->area;
    } else {
        carta->densidade = 0;
    }
}

// Exibe uma carta
void exibirCarta(struct Carta carta) {
    printf("\n--- País: %s ---\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade);
}

// Função principal
int main() {
    // Duas cartas cadastradas
    struct Carta carta1 = {"Brasil", 214000000, 8515770.0, 1800.0, 25, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780000.0, 500.0, 10, 0};

    // Cálculo das densidades
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    // Exibe cartas antes da comparação
    exibirCarta(carta1);
    exibirCarta(carta2);

    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s vs %s\n", carta1.nome, carta2.nome);

    // Switch para lidar com a escolha do usuário
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (menor vence!)\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente com um número entre 1 e 5.\n");
    }

    return 0;
}
