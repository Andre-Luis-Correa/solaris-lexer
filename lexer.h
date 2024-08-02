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

// Declarações de funções
tokenList* createToken(int type, const char *value);
void addToken(tokenList **head, int type, const char *value);
void freeTokenList(tokenList *head);
void printTokens(const tokenList *head);
const char* getTokenTypeName(int type);

#endif // LEXER_H
