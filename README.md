
---

# Solaris Lexer

**Solaris Lexer** é um analisador léxico desenvolvido em C para a linguagem de programação Solaris. Este projeto define e identifica diversos tipos de tokens que podem ser encontrados no código-fonte escrito em Solaris. Ele é uma parte fundamental do processo de compilação, responsável por dividir o código em unidades lexicais (tokens) que serão usadas nas etapas subsequentes da análise e compilação.

## Índice

- [Funcionalidades](#funcionalidades)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Compilação e Execução](#compilação-e-execução)
- [Uso](#uso)

## Funcionalidades

- **Identificação de Tokens**: Reconhece e categoriza diversos tipos de tokens, incluindo palavras reservadas, identificadores, números, strings, operadores aritméticos, operadores relacionais, operadores lógicos, delimitadores, operadores de atribuição, comentários de linha, blocos de comentário, booleanos, espaços em branco, novas linhas e tipos de dados.
- **Processamento de Tokens**: Armazena tokens em listas encadeadas, separando palavras reservadas de outros tokens.
- **Impressão e Liberação de Memória**: Permite a impressão de todos os tokens identificados e libera a memória alocada para essas listas ao final do processo.

## Estrutura do Projeto

- **lexer.h**: Arquivo de cabeçalho que contém definições de macros para tipos de tokens, a estrutura de dados para os tokens, declarações de variáveis globais e protótipos de funções.
- **lexer.c**: Implementação das funções definidas em `lexer.h`, como a criação e adição de tokens, impressão dos tokens, liberação da memória, e processamento de tokens com base no tipo.

## Compilação e Execução

### Pré-requisitos

- Um compilador C (como `gcc`).
- Um ambiente de desenvolvimento compatível com C (Linux, macOS, Windows com Cygwin ou MinGW).

### Compilação

Para compilar o projeto, você pode usar o seguinte comando no terminal:

```bash
gcc -o solaris-lexer lexer.c
```

### Execução

Após compilar, execute o programa com:

```bash
./solaris-lexer
```

## Uso

O analisador léxico lê o código-fonte de entrada, que deve ser um arquivo `.txt` contendo código escrito em Solaris, e divide-o em tokens, armazenando-os em listas encadeadas para posterior processamento. Cada token é categorizado de acordo com seu tipo, que pode ser verificado usando a função `getTokenTypeName()`.

### Exemplo de Funções

- **createToken(int type, const char *value)**: Cria um novo token com o tipo e valor especificados.
- **addToken(tokenList **head, int type, const char *value)**: Adiciona um novo token ao final da lista de tokens.
- **freeTokenList(tokenList *head)**: Libera a memória alocada para a lista de tokens.
- **printTokens(const tokenList *head, const char *listName)**: Imprime todos os tokens de uma lista no console.
- **processToken(int type, const char *text)**: Armazena o token na lista apropriada com base no seu tipo.

---
