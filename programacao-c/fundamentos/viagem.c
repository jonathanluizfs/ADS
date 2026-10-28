#include <stdio.h>

 //Trabalho AVA 1 - INTRODUÇÃO À LÓGICA DE PROGRAMAÇÃO 
 //Aluno: Jonathan Luiz Ferradeiro da Silva

int main() {

    float distancia;
    float preco;
    float gasto_total;

    printf("Digite a distancia da viagem em km: ");
    scanf("%f", &distancia);

    printf("Digite o preco do litro do combustivel: ");
    scanf("%f", &preco);

    gasto_total = (distancia / 10) * preco;

    printf("O valor total gasto com combustivel sera: R$ %.2f\n", gasto_total);

    return 0;
}