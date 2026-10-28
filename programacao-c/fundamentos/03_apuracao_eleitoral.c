/* Reconstituido com base no exercicio de apuracao eleitoral de 28/05/2026.
   1, 2 e 3: candidatos; 4: branco; 0: finalizar; demais: nulos. */
#include <stdio.h>

int main(void) {
    int voto;
    int candidato1 = 0, candidato2 = 0, candidato3 = 0;
    int brancos = 0, nulos = 0, totalEleitores = 0;
    int maior;

    printf("===== APURACAO DE ELEICAO =====\n");
    printf("1 - Candidato 1\n2 - Candidato 2\n3 - Candidato 3\n");
    printf("4 - Voto em branco\n0 - Encerrar votacao\n");

    while (1) {
        printf("\nDigite o voto: ");
        if (scanf("%d", &voto) != 1) {
            puts("Entrada invalida. Encerrando a apuracao.");
            return 1;
        }
        if (voto == 0) {
            break;
        }

        totalEleitores++;
        switch (voto) {
            case 1: candidato1++; break;
            case 2: candidato2++; break;
            case 3: candidato3++; break;
            case 4: brancos++; break;
            default: nulos++; break;
        }
    }

    printf("\n===== RESULTADO DA ELEICAO =====\n");
    printf("Candidato 1: %d voto(s)\n", candidato1);
    printf("Candidato 2: %d voto(s)\n", candidato2);
    printf("Candidato 3: %d voto(s)\n", candidato3);
    printf("Brancos: %d\n", brancos);
    printf("Nulos: %d\n", nulos);
    printf("Total de eleitores: %d\n", totalEleitores);

    maior = candidato1;
    if (candidato2 > maior) maior = candidato2;
    if (candidato3 > maior) maior = candidato3;

    if (maior == 0) {
        puts("Nenhum candidato recebeu votos validos.");
    } else if ((candidato1 == maior) + (candidato2 == maior) +
               (candidato3 == maior) > 1) {
        printf("Empate na primeira colocacao, com %d voto(s).\n", maior);
    } else if (candidato1 == maior) {
        puts("Eleito: Candidato 1");
    } else if (candidato2 == maior) {
        puts("Eleito: Candidato 2");
    } else {
        puts("Eleito: Candidato 3");
    }

    return 0;
}
