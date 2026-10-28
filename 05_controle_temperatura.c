#include <stdio.h>

#define TEMP_MINIMA 18.0
#define TEMP_MAXIMA 25.0

// Funcao responsavel por ler a temperatura
float lerTemperatura() {
    float temperatura;
    printf("\nDigite a temperatura atual do ambiente: ");
    scanf("%f", &temperatura);
    return temperatura;
}

// Funcao responsavel por analisar a temperatura
int analisarTemperatura(float temperatura) {
    if (temperatura < TEMP_MINIMA) {
        return 1;
    }
    else if (temperatura > TEMP_MAXIMA) {
        return 2;
    }
    else {
        return 0;
    }
}

// Funcao responsavel por exibir o resultado
void exibirResultado(int resultado) {
    if (resultado == 1) {
        printf("Aquecendo...\n");
    }
    else if (resultado == 2) {
        printf("Resfriando...\n");
    }
    else {
        printf("Temperatura estavel.\n");
    }
}

int main() {
    float temperatura;
    int resultado;
    int opcao;

    printf("====================================\n");
    printf(" SISTEMA DE CONTROLE DE TEMPERATURA\n");
    printf("====================================\n");
    printf("Faixa ideal: %.1f C a %.1f C\n",
           TEMP_MINIMA, TEMP_MAXIMA);

    do {
        temperatura = lerTemperatura();
        resultado = analisarTemperatura(temperatura);
        exibirResultado(resultado);

        printf("\nDeseja inserir uma nova temperatura?\n");
        printf("1 - Sim\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    printf("\nSistema encerrado.\n");
    return 0;
}
