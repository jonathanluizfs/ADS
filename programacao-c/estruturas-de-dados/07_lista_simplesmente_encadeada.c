/*
 * Estrutura de Dados - Atividade 1 (AVA 1)
 * Tema: Lista simplesmente encadeada em linguagem C
 * Operacoes: inclusao, consulta, alteracao, remocao e listagem.
 *
 * Cada registro possui codigo, nome e idade.
 * O campo "proximo" liga um no ao seguinte; o ultimo aponta para NULL.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define TAM_NOME 60
#define TAM_ENTRADA 128

typedef struct No {
    int codigo;
    char nome[TAM_NOME];
    int idade;
    struct No *proximo;
} No;

/* Le uma linha de texto sem deixar caracteres pendentes no teclado. */
void lerTexto(const char *mensagem, char *destino, size_t tamanho) {
    char entrada[TAM_ENTRADA];

    for (;;) {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            puts("\nEntrada encerrada.");
            exit(EXIT_SUCCESS);
        }

        size_t comprimento = strlen(entrada);
        if (comprimento > 0 && entrada[comprimento - 1] == '\n') {
            entrada[comprimento - 1] = '\0';
        } else {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                /* Descarta o excesso de caracteres. */
            }
        }

        if (entrada[0] == '\0') {
            puts("O texto nao pode ficar vazio.");
        } else if (strlen(entrada) >= tamanho) {
            printf("Digite no maximo %zu caracteres.\n", tamanho - 1);
        } else {
            strcpy(destino, entrada);
            return;
        }
    }
}

/* Garante que o usuario informe um numero inteiro dentro do intervalo. */
int lerInteiro(const char *mensagem, int minimo, int maximo) {
    char entrada[TAM_ENTRADA];
    char *fim;
    long numero;

    for (;;) {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            puts("\nEntrada encerrada.");
            exit(EXIT_SUCCESS);
        }

        if (strchr(entrada, '\n') == NULL) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                /* Descarta o excesso de caracteres. */
            }
            puts("Entrada muito longa. Tente novamente.");
            continue;
        }

        numero = strtol(entrada, &fim, 10);
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == entrada || *fim != '\0' || numero < minimo || numero > maximo) {
            printf("Informe um numero inteiro entre %d e %d.\n", minimo, maximo);
        } else {
            return (int)numero;
        }
    }
}

/* Procura um registro pelo seu codigo. */
No *buscar(No *inicio, int codigo) {
    No *atual = inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

/* Inclui um novo registro no final da lista. */
void incluir(No **inicio) {
    int codigo = lerInteiro("Codigo do registro: ", 1, INT_MAX);

    if (buscar(*inicio, codigo) != NULL) {
        puts("Ja existe um registro com esse codigo.");
        return;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        puts("Erro: memoria insuficiente para a inclusao.");
        return;
    }

    novo->codigo = codigo;
    lerTexto("Nome: ", novo->nome, sizeof(novo->nome));
    novo->idade = lerInteiro("Idade: ", 0, 120);
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    puts("Registro incluido com sucesso!");
}

/* Consulta um registro especifico pelo codigo. */
void consultar(No *inicio) {
    int codigo = lerInteiro("Codigo para consulta: ", 1, INT_MAX);
    No *registro = buscar(inicio, codigo);

    if (registro == NULL) {
        puts("Registro nao encontrado.");
    } else {
        printf("Codigo: %d\nNome: %s\nIdade: %d\n",
               registro->codigo, registro->nome, registro->idade);
    }
}

/* Altera o nome e a idade de um registro existente. */
void alterar(No *inicio) {
    int codigo = lerInteiro("Codigo para alteracao: ", 1, INT_MAX);
    No *registro = buscar(inicio, codigo);

    if (registro == NULL) {
        puts("Registro nao encontrado.");
        return;
    }

    printf("Registro encontrado: %s (%d anos)\n", registro->nome, registro->idade);
    lerTexto("Novo nome: ", registro->nome, sizeof(registro->nome));
    registro->idade = lerInteiro("Nova idade: ", 0, 120);
    puts("Registro alterado com sucesso!");
}

/* Remove um registro, religando os nos restantes. */
void remover(No **inicio) {
    int codigo = lerInteiro("Codigo para remocao: ", 1, INT_MAX);
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        puts("Registro nao encontrado.");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;  /* Remove o primeiro no. */
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    puts("Registro removido com sucesso!");
}

/* Percorre e exibe todos os registros da lista. */
void listar(No *inicio) {
    if (inicio == NULL) {
        puts("A lista esta vazia.");
        return;
    }

    puts("\n--- REGISTROS ARMAZENADOS ---");
    int quantidade = 0;

    for (No *atual = inicio; atual != NULL; atual = atual->proximo) {
        printf("Codigo: %d | Nome: %s | Idade: %d\n",
               atual->codigo, atual->nome, atual->idade);
        quantidade++;
    }
    printf("Total de registros: %d\n", quantidade);
}

/* Devolve toda a memoria alocada antes de encerrar. */
void liberarLista(No *inicio) {
    while (inicio != NULL) {
        No *proximo = inicio->proximo;
        free(inicio);
        inicio = proximo;
    }
}

int main(void) {
    No *lista = NULL;
    int opcao;

    do {
        puts("\n===== RENALF MEGA DATA =====");
        puts("1 - Incluir registro");
        puts("2 - Consultar registro");
        puts("3 - Alterar registro");
        puts("4 - Remover registro");
        puts("5 - Listar todos os registros");
        puts("0 - Sair");

        opcao = lerInteiro("Escolha uma opcao: ", 0, 5);

        switch (opcao) {
            case 1: incluir(&lista); break;
            case 2: consultar(lista); break;
            case 3: alterar(lista); break;
            case 4: remover(&lista); break;
            case 5: listar(lista); break;
            case 0: puts("Encerrando o programa..."); break;
        }
    } while (opcao != 0);

    liberarLista(lista);
    return 0;
}
