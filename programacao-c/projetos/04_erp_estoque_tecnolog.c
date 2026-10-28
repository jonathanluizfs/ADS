/* Reconstituido a partir dos requisitos do ERP de estoque TecnoLog,
   discutido em 05/06/2026. Estrutura, ponteiros, memoria dinamica,
   aritmetica de ponteiros e funcao independente de calculo. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int quantidade;
    float preco;
} Produto;

float calcularEstoque(const Produto *produtos, int quantidadeProdutos) {
    float total = 0.0f;
    for (int i = 0; i < quantidadeProdutos; ++i) {
        const Produto *produto = produtos + i;
        total += produto->quantidade * produto->preco;
    }
    return total;
}

static void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int n;
    Produto *produtos;

    puts("===== CONTROLE DE ESTOQUE TECNOLOG =====");
    printf("Quantos produtos deseja cadastrar? ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10000) {
        puts("Quantidade de produtos invalida.");
        return 1;
    }
    limparEntrada();

    produtos = malloc((size_t)n * sizeof(*produtos));
    if (produtos == NULL) {
        puts("Nao foi possivel reservar memoria.");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        Produto *atual = produtos + i;
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        if (fgets(atual->nome, sizeof(atual->nome), stdin) == NULL) {
            puts("Falha ao ler nome.");
            free(produtos);
            return 1;
        }
        if (strchr(atual->nome, '\n') == NULL) limparEntrada();
        atual->nome[strcspn(atual->nome, "\n")] = '\0';

        printf("Quantidade: ");
        if (scanf("%d", &atual->quantidade) != 1 || atual->quantidade < 0) {
            puts("Quantidade invalida.");
            free(produtos);
            return 1;
        }
        printf("Preco unitario (R$): ");
        if (scanf("%f", &atual->preco) != 1 || atual->preco < 0) {
            puts("Preco invalido.");
            free(produtos);
            return 1;
        }
        limparEntrada();
    }

    puts("\n===== RELATORIO DE ESTOQUE =====");
    for (int i = 0; i < n; ++i) {
        const Produto *atual = produtos + i;
        printf("%d. %s | Quantidade: %d | Preco: R$ %.2f | Subtotal: R$ %.2f\n",
               i + 1, atual->nome, atual->quantidade, atual->preco,
               atual->quantidade * atual->preco);
    }
    printf("Valor total do estoque: R$ %.2f\n", calcularEstoque(produtos, n));

    free(produtos);
    return 0;
}
