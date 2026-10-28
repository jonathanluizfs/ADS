# Guia de consulta, manutenção e registro

## Encontrar um trabalho

1. Abra [README.md](../README.md) para consultar a lista geral.
2. Use [CATALOGO.md](../CATALOGO.md) para pesquisar por atividade, descrição, origem ou data.
3. Acesse os códigos dentro de `programacao-c/` por assunto.
4. Para integração com uma interface web, leia [catalogo.json](../catalogo.json).

## Executar localmente

É necessário ter um compilador C, como GCC. Exemplo:

```bash
gcc -std=c11 -Wall -Wextra programacao-c/estruturas-de-dados/07_lista_simplesmente_encadeada.c -o lista
./lista
```

No Windows, execute `lista.exe`. A compilação em GCC não equivale à compilação para WebAssembly. Para rodar no navegador, é necessário um processo separado de compilação, arquivos de saída e configuração do site.

## Como cadastrar um novo trabalho

- Defina o assunto e a disciplina. Use `fundamentos/`, `estruturas-de-dados/` ou `projetos/`.
- Escolha um nome legível, preferencialmente `NN_descricao_curta.c`.
- Registre **o que o programa faz**, **como executar**, **data original confirmada ou fonte da data** e **origem** (original, reconstruído, revisado).
- Atualize a tabela do [README principal](../README.md), o [CATALOGO.md](../CATALOGO.md) e o [catalogo.json](../catalogo.json).
- Se houver links externos apontando para arquivos da raiz, não os remova sem primeiro migrar esses links.
- Se mantiver uma cópia na raiz por compatibilidade, sincronize seu conteúdo com o arquivo organizado.
- Prefira commits informativos, como `docs: documenta exercício de listas` ou `fix: valida entrada do controle de temperatura`.

## Segurança e privacidade

Não publique tokens, senhas, credenciais, dados pessoais de terceiros, projetos confidenciais ou configurações reais de sistemas de segurança sem autorização e revisão. Para documentação sensível, prefira um repositório privado com acesso restrito.

## Como reverter a reorganização

Uma referência à versão anterior foi criada na branch `backup-ads-2026-10-28`. Ela pode ser comparada com a branch `main` e usada para recuperar arquivos individuais sem apagar trabalhos posteriores.

## Atenção a exercícios com regras ilustrativas

O cálculo de horas extras demonstra uma regra didática de 40 horas e adicional de 50% definida no código. Ele não deve ser usado como folha de pagamento real sem revisar as regras jurídicas e contratuais aplicáveis.
