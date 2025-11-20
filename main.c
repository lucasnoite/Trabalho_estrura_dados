#include <stdio.h>
#include "engine.h"

int main() {
    char infixa[100], posfixa[100];
    float valores[26];
    int opcao;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Definir expressão\n");
        printf("2. Definir valores das variáveis\n");
        printf("3. Avaliar expressão\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite a expressão infixa: ");
            scanf("%s", infixa);

            if (infix_to_postfix(infixa, posfixa))
                printf("Pós-fixa gerada: %s\n", posfixa);
        }

        else if (opcao == 2) {
            for (int i = 0; posfixa[i] != '\0'; i++) {
                if (posfixa[i] >= 'A' && posfixa[i] <= 'Z') {
                    int id = posfixa[i] - 'A';
                    printf("Valor de %c: ", posfixa[i]);
                    scanf("%f", &valores[id]);
                }
            }
        }

        else if (opcao == 3) {
            float resultado = avaliar_posfixa(posfixa, valores);
            printf("Resultado = %.2f\n", resultado);
        }

        else if (opcao == 4) break;
    }

    return 0;
} 
