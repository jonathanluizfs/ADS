/* Reconstituido com base no exercicio de IMC de 20/03/2026. */
#include <stdio.h>

int main(void) {
    float peso, altura, resultado_imc;

    printf("Digite seu peso em kg (use ponto para decimais): ");
    if (scanf("%f", &peso) != 1 || peso <= 0) {
        puts("Peso invalido.");
        return 1;
    }

    printf("Digite sua altura em metros (use ponto para decimais): ");
    if (scanf("%f", &altura) != 1 || altura <= 0) {
        puts("Altura invalida.");
        return 1;
    }

    resultado_imc = peso / (altura * altura);
    printf("Seu IMC e: %.2f\n", resultado_imc);
    return 0;
}
