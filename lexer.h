#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de macros para tipos de tokens
#define LEX_TOKEN_RESERVED_WORD          1
#define LEX_TOKEN_IDENTIFIER             2
#define LEX_TOKEN_INTEGER_NUMBER         3
#define LEX_TOKEN_FLOAT_NUMBER           4
#define LEX_TOKEN_STRING                 5
#define LEX_TOKEN_ARITHMETIC_OP          6
#define LEX_TOKEN_RELATIONAL_OP          7
#define LEX_TOKEN_LOGICAL_OP             8
#define LEX_TOKEN_DELIMITER              9
#define LEX_TOKEN_ASSIGNMENT_OP         10
#define LEX_TOKEN_CONDITIONAL_CHOOSE    11
#define LEX_TOKEN_CONDITIONAL_OTHERWISE 12
#define LEX_TOKEN_LOOP                  13
#define LEX_TOKEN_LOOP_UNTIL            14
#define LEX_TOKEN_LOOP_WHILE            15
#define LEX_TOKEN_DATA_TYPE_STRING      16
#define LEX_TOKEN_DATA_TYPE_INTEGER     17
#define LEX_TOKEN_DATA_TYPE_FLOAT       18
#define LEX_TOKEN_DATA_TYPE_DOUBLE      19
#define LEX_TOKEN_DATA_TYPE_BOOLEAN     20
#define LEX_TOKEN_COMMENT_LINE          21
#define LEX_TOKEN_COMMENT_BLOCK         22
#define LEX_TOKEN_SHOW                  23
#define LEX_TOKEN_READ                  24
#define LEX_TOKEN_FUNCTION              25
#define LEX_TOKEN_FUNCTION_RECEIVE      26
#define LEX_TOKEN_FUNCTION_RETURN       27
#define LEX_TOKEN_USE                   28
#define LEX_TOKEN_WHITESPACE            29
#define LEX_TOKEN_NEWLINE               30
#define LEX_TOKEN_UNKNOWN               31
#define LEX_TOKEN_DATA_TYPE             32
#define LEX_TOKEN_CALL                  33

typedef enum {
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_IDENTIFIER,
    TYPE_UNDEFINED
} dataType;

typedef enum {
    VARIABLE,
    FUNCTION,
    CONSTANT,
    UNDEFINED
} category;

// Estrutura para um token
typedef struct token {
    int lexTokenType;
    char *str;
    category category;
    dataType dataType;
    int hasValue;
    int numberOfParameters;
    union {
        int    intValue;
        float  floatValue;
        char * stringValue;
        char * identifierValue;
    } value;
    struct token *next;
} tokenList;

// Declarações das variáveis globais como extern
extern int errorFlag;

// Cabeça da lista de palavras reservadas
extern tokenList *reservedWordListHead;

// Cabeça da lista de outros tokens
extern tokenList *symbolTable;

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

// Retorna o nome da categoria de um símbolo como uma string legível.
// Pré-condições:
//   - 'cat' deve ser um valor válido da enumeração 'category'.
// Pós-condições:
//   - Retorna uma string representando a categoria do símbolo.
char* getCategoryName(category cat);

// Retorna o nome do tipo de dado de um símbolo como uma string legível.
// Pré-condições:
//   - 'type' deve ser um valor válido da enumeração 'dataType'.
// Pós-condições:
//   - Retorna uma string representando o tipo de dado do símbolo.
char* getDataTypeName(dataType type);

// Retorna o valor armazenado em um token na tabela de símbolos.
// Pré-condições:
//   - 'token' deve ser um ponteiro válido para um token na tabela de símbolos.
// Pós-condições:
//   - Retorna uma string representando o valor do token.
//   - Se o token não tiver um valor associado, retorna "N/A".
char* getTokenValue(tokenList *token);

// Imprime todos os tokens da lista fornecida.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Todos os tokens da lista são impressos no console.
void printTokens(tokenList *head, const char *listName);

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
void printTokenLists(tokenList *reservedWordTokens, tokenList *symbolTable);

tokenList * findSymbol(tokenList * head, const char * str);

// Atualiza a categoria e o tipo de dado de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
//   - 'category' define se o identificador é uma variável, função ou constante.
//   - 'dataType' define o tipo de dado do identificador.
// Pós-condições:
//   - O identificador na tabela de símbolos será atualizado com a nova categoria e tipo de dado.
void updateSymbolCategoryAndDataType(const char *str, category category, dataType dataType);

// Define o valor de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'symbol' deve ser um identificador válido presente na tabela de símbolos.
//   - 'value' é a string contendo o valor a ser atribuído.
//   - 'dataType' define o tipo de dado do valor atribuído.
// Pós-condições:
//   - O identificador recebe o valor correspondente ao seu tipo de dado.
void setSymbolValue(tokenList *symbol, const char *value, dataType dataType);

// Copia o valor de um identificador da tabela de símbolos para outro identificador.
// Pré-condições:
//   - 'target' deve ser um identificador válido presente na tabela de símbolos.
//   - 'identifier' deve ser um identificador previamente declarado na tabela de símbolos.
// Pós-condições:
//   - O identificador alvo recebe o valor e o tipo do identificador de origem.
void copyIdentifierValue(tokenList *target, const char *identifier);

// Atualiza o valor de um símbolo na tabela de símbolos, verificando se é um identificador ou um valor literal.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
//   - 'value' é a string contendo o valor a ser atribuído.
//   - 'dataType' define o tipo de dado do valor atribuído.
// Pós-condições:
//   - O identificador recebe o valor correspondente ao seu tipo de dado ou o valor de outro identificador.
void updateSymbolValue(const char *str, const char *value, dataType dataType);

// Retorna o tipo de dado de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
// Pós-condições:
//   - Retorna o tipo de dado do identificador encontrado na tabela de símbolos.
dataType getSymbolDataType(const char *str);

// Retorna a categoria de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
// Pós-condições:
//   - Retorna a categoria do token encontrado na tabela de símbolos.
category getSymbolCategory(const char *str);

// Atualiza o número de parâmetros de uma função na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
//   - 'paramCount' é a quantidade de parâmetros de um identificador na categoria FUNCTION.
// Pós-condições:
//   - O identificador na tabela de símbolos será atualizado com a quantidade de parâmetros.
void updateSymbolNumberOfParameters(const char *str, int paramCount);

#endif // LEXER_H
