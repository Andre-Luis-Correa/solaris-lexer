#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de macros para tipos de tokens
#define LEX_TOKEN_RESERVED_WORD  1
#define LEX_TOKEN_IDENTIFIER     2
#define LEX_TOKEN_INTEGER_NUMBER 3
#define LEX_TOKEN_FLOAT_NUMBER   4
#define LEX_TOKEN_STRING         5
#define LEX_TOKEN_ARITHMETIC_OP  6
#define LEX_TOKEN_RELATIONAL_OP  7
#define LEX_TOKEN_LOGICAL_OP     8
#define LEX_TOKEN_DELIMITER      9
#define LEX_TOKEN_ASSIGNMENT_OP 10
#define LEX_TOKEN_COMMENT_LINE  11
#define LEX_TOKEN_COMMENT_BLOCK 12
#define LEX_TOKEN_BOOLEAN       13
#define LEX_TOKEN_WHITESPACE    14
#define LEX_TOKEN_NEWLINE       15
#define LEX_TOKEN_UNKNOWN       16
#define LEX_TOKEN_DATA_TYPE     17

// Estrutura para um token
typedef struct token {
    int type;               // Tipo do token
    char *value;            // Valor do token
    struct token *next;     // Ponteiro para o próximo token na lista
} tokenList;

// Declarações das variáveis globais como extern
extern int errorFlag;

// Cabeça da lista de palavras reservadas
extern tokenList *reservedWordListHead;

// Cabeça da lista de outros tokens
extern tokenList *otherTokensListHead;

// Cria um novo token e inicializa seus valores.
// Pré-condições: 'value' deve ser uma string válida.
// Pós-condições: Retorna um novo token com o tipo e valor especificados.
tokenList* createToken(int type, const char *value);

// Adiciona um novo token ao final da lista encadeada de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: O novo token é adicionado ao final da lista.
void addToken(tokenList **head, int type, const char *value);

// Libera a memória alocada para a lista de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Toda a memória alocada para a lista é liberada.
void freeTokenList(tokenList *head);

// Retorna o nome do tipo de token com base em seu valor enumerado.
// Pré-condições: 'type' deve ser um valor válido de enumeração de tipo de token.
// Pós-condições: Retorna a string correspondente ao tipo de token.
const char* getTokenTypeName(int type);

// Imprime todos os tokens da lista fornecida.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Todos os tokens da lista são impressos no console.
void printTokens(const tokenList *head, const char *listName);

// Função auxiliar para armazenar o token na lista apropriada
// Pré-condições:
//   - 'type' deve ser um valor válido de tipo de token definido pelo sistema (por exemplo, RESERVED_WORD, IDENTIFIER).
//   - 'text' deve ser uma string não nula que representa o valor do token identificado.
// Pós-condições:
//   - O token é adicionado à lista de palavras reservadas se 'type' for RESERVED_WORD.
//   - Caso contrário, o token é adicionado à lista de outros tokens.
void processToken(int type, const char *text);

// Imprime as listas de tokens reservados e outros tokens em formato organizado.
// Pré-condições:
//   - 'reservedWordTokens' deve ser o ponteiro para a lista de tokens reservados ou NULL.
//   - 'otherTokens' deve ser o ponteiro para a lista de outros tokens ou NULL.
// Pós-condições:
//   - Todos os tokens das listas são impressos no console em formato tabular ou estruturado.
void printTokenLists(const tokenList *reservedWordTokens, const tokenList *otherTokens);

#endif // LEXER_H
