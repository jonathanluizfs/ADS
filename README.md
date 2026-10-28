# ADS — Trabalhos e estudos de programação

Repositório de exercícios, atividades acadêmicas e projetos de estudo em linguagem C. A organização prioriza **consulta rápida**, identificação da origem dos trabalhos e compatibilidade com links antigos.

## Acesso rápido

- [Catálogo de atividades (com datas e descrições)](CATALOGO.md)
- [Catálogo JSON para integração com o site](catalogo.json)
- [Guia de consulta e execução](docs/GUIA-DE-CONSULTA.md)
- [Organização da área de programação em C](programacao-c/README.md)

## Trabalhos em C

| Atividade | Disciplina / área | Data citada no código | Origem |
| --- | --- | --- | --- |
| [Custo de viagem](programacao-c/fundamentos/01_custo_viagem.c) | Introdução à Lógica de Programação | 12/03/2026 | reconstruido |
| [Cálculo de IMC](programacao-c/fundamentos/02_calculo_imc.c) | Programação em C | 20/03/2026 | reconstruido |
| [Apuração eleitoral](programacao-c/fundamentos/03_apuracao_eleitoral.c) | Programação em C | 28/05/2026 | reconstruido |
| [ERP de estoque TecnoLog](programacao-c/projetos/04_erp_estoque_tecnolog.c) | Programação em C | 05/06/2026 | reconstruido a partir de requisitos |
| [Controle de temperatura](programacao-c/fundamentos/05_controle_temperatura.c) | Programação em C | A confirmar | versao armazenada |
| [Salário e horas extras](programacao-c/fundamentos/06_calculo_salario_horas_extras.c) | Programação em C | A confirmar | versao armazenada |
| [Lista simplesmente encadeada](programacao-c/estruturas-de-dados/07_lista_simplesmente_encadeada.c) | Estrutura de Dados | A confirmar | versao armazenada |
| [Viagem (versão original armazenada)](programacao-c/fundamentos/viagem.c) | Introdução à Lógica de Programação | A confirmar | trabalho ava armazenado |

> **Datas:** as datas acima vêm de comentários existentes nos códigos, quando disponíveis. Não equivalem necessariamente às datas de entrega, criação ou publicação no GitHub. Campos sem comprovação ficam “A confirmar”.

## Organização

```text
ADS/
├── README.md
├── CATALOGO.md
├── catalogo.json
├── docs/
│   └── GUIA-DE-CONSULTA.md
└── programacao-c/
    ├── README.md
    ├── fundamentos/
    │   ├── 01_custo_viagem.c
    │   ├── 02_calculo_imc.c
    │   ├── 03_apuracao_eleitoral.c
    │   ├── 05_controle_temperatura.c
    │   ├── 06_calculo_salario_horas_extras.c
    │   └── viagem.c
    ├── estruturas-de-dados/
    │   └── 07_lista_simplesmente_encadeada.c
    └── projetos/
        └── 04_erp_estoque_tecnolog.c
```

## Compatibilidade e preservação

Os **oito arquivos `.c` originais na raiz continuam disponíveis sem alteração de conteúdo** para não quebrar possíveis links usados pelo laboratório do site ou por outros locais. Os caminhos em `programacao-c/` são cópias de organização dos mesmos códigos, não versões novas ou corrigidas.

Até que os links antigos sejam migrados, mudanças futuras em um código devem ser refletidas **nos dois caminhos** para evitar divergências.

`viagem.c` e `01_custo_viagem.c` são versões diferentes relacionadas à mesma atividade. Mantemos as duas para consulta histórica.

## Como executar

Com o GCC instalado:

```bash
gcc -std=c11 -Wall -Wextra programacao-c/fundamentos/01_custo_viagem.c -o custo_viagem
./custo_viagem
```

No Windows, o executável gerado pode ser `custo_viagem.exe`; execute-o pelo terminal. Os programas solicitam entrada de dados, conforme cada exercício. Os arquivos são disponibilizados como **código-fonte em C**: não há executáveis WebAssembly publicados aqui.

## Sobre a integração com o site

O arquivo [`catalogo.json`](catalogo.json) contém títulos, descrições, datas informadas, categoria, caminho organizado e caminho antigo de cada atividade. É destinado à leitura pelo site, mas **não executa nem compila C automaticamente**.

Para novas atividades, consulte o [guia](docs/GUIA-DE-CONSULTA.md) e atualize tanto o catálogo em Markdown quanto o JSON.

---
Última reorganização documental: 28/10/2026. Os códigos-fonte preexistentes foram preservados.
