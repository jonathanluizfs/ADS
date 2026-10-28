#include <stdio.h>
#include <string.h>
 
// Jonathan Luiz Ferradeiro da Silva
// Funcao responsavel pelo calculo do salario
float calcularSalario(float horas, float valorHora) {
    float salario;
 
    if (horas > 40) {
        float horasExtras = horas - 40;
        salario = (40 * valorHora) + (horasExtras * valorHora * 1.5);
    } else {
        salario = horas * valorHora;
    }
 
    return salario;
}
 
int main() {
    char nome[100];
    float horasTrabalhadas;
    float valorHora;
    float salarioTotal;
    char continuar;
 
    do {
        printf("\n===== CALCULO DE SALARIO =====\n");
 
        printf("Digite o nome do funcionario: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
 
        printf("Digite o numero de horas trabalhadas na semana: ");
        scanf("%f", &horasTrabalhadas);
 
        printf("Digite o valor da hora (R$): ");
        scanf("%f", &valorHora);
 
        salarioTotal = calcularSalario(horasTrabalhadas, valorHora);
 
        printf("\n===== RESULTADO =====\n");
        printf("Funcionario: %s\n", nome);
        printf("Horas trabalhadas: %.2f\n", horasTrabalhadas);
        printf("Valor da hora: R$ %.2f\n", valorHora);
 
        if (horasTrabalhadas > 40) {
            printf("Horas extras: %.2f\n", horasTrabalhadas - 40);
            printf("Adicional das horas extras: 50%%\n");
        } else {
            printf("Horas extras: 0.00\n");
        }
 
        printf("Salario total: R$ %.2f\n", salarioTotal);
 
        printf("\nDeseja calcular o salario de outro funcionario? (S/N): ");
        scanf(" %c", &continuar);
 
        while (getchar() != '\n');
 
    } while (continuar == 'S' || continuar == 's');
 
    printf("\nPrograma encerrado.\n");
    return 0;
}
