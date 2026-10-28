/* Reconstituido com base no exercicio viagem.c de 12/03/2026.
   Consumo considerado: 10 km por litro. */
#include <stdio.h>

int main(void) {
    float distancia, precoLitro, custoTotal;

    printf("Informe a distancia da viagem (km): ");
    if (scanf("%f", &distancia) != 1 || distancia < 0) {
        puts("Distancia invalida.");
        return 1;
    }

    printf("Informe o preco do combustivel por litro (R$): ");
    if (scanf("%f", &precoLitro) != 1 || precoLitro < 0) {
        puts("Preco invalido.");
        return 1;
    }

    custoTotal = (distancia / 10.0f) * precoLitro;
    printf("Custo estimado de combustivel: R$ %.2f\n", custoTotal);
    return 0;
}
