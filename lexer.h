#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de macros para tipos de tokens
#define RESERVED_WORD 1
#define IDENTIFIER    2
#define NUMBER        3
#define STRING        4
#define ARITHMETIC_OP 5
#define RELATIONAL_OP 6
#define LOGICAL_OP    7
#define DELIMITER     8
#define ASSIGNMENT_OP 9
#define COMMENT_LINE  10
#define COMMENT_BLOCK 11
#define BOOLEAN       12
#define WHITESPACE    13
#define NEWLINE       14
#define UNKNOWN       15
#define DATA_TYPE     16  // Nova macro para tipos de dados

// Estrutura para um token
typedef struct token {
    int type;               // Tipo do token
    char *value;            // Valor do token
    struct token *next;     // Ponteiro para o próximo token na lista
} tokenList;

extern int errorFlag;
// Declarações das variáveis globais como extern
extern tokenList *reservedWordListHead;  // Cabeça da lista de palavras reservadas
extern tokenList *otherTokensListHead;   // Cabeça da lista de outros tokens

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

#endif // LEXER_H
