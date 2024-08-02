#include "lexer.h"

// Função para criar um novo token
tokenList* createToken(int type, const char *value) {
    tokenList *newToken = (tokenList *)malloc(sizeof(tokenList));
    newToken->type = type;
    newToken->value = strdup(value); // Duplicar a string de valor
    newToken->next = NULL;
    return newToken;
}

// Função para adicionar um token à lista encadeada
void addToken(tokenList **head, int type, const char *value) {
    tokenList *newToken = createToken(type, value);
    if (*head == NULL) {
        *head = newToken;
    } else {
        tokenList *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newToken;
    }
}

// Função para liberar a memória da lista de tokens
void freeTokenList(tokenList *head) {
    tokenList *current = head;
    while (current != NULL) {
        tokenList *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

// Função para obter o nome do tipo de token
const char* getTokenTypeName(int type) {
    switch (type) {
        case RESERVED_WORD: return "RESERVED_WORD";
        case IDENTIFIER:    return "IDENTIFIER";
        case NUMBER:        return "NUMBER";
        case STRING:        return "STRING";
        case ARITHMETIC_OP: return "ARITHMETIC_OP";
        case RELATIONAL_OP: return "RELATIONAL_OP";
        case LOGICAL_OP:    return "LOGICAL_OP";
        case DELIMITER:     return "DELIMITER";
        case ASSIGNMENT_OP: return "ASSIGNMENT_OP";
        case COMMENT_LINE:  return "COMMENT_LINE";
        case COMMENT_BLOCK: return "COMMENT_BLOCK";
        case BOOLEAN:       return "BOOLEAN";
        case WHITESPACE:    return "WHITESPACE";
        case NEWLINE:       return "NEWLINE";
        case DATA_TYPE:     return "DATA_TYPE";
        case UNKNOWN:       return "UNKNOWN";
        default:            return "INVALID";
    }
}

// Função para imprimir a lista de tokens
void printTokens(const tokenList *head) {
    const tokenList *current = head;
    printf("\nTokens encontrados:\n");
    printf("%-15s %-20s\n", "Tipo", "Valor");
    printf("------------------------------\n");
    while (current != NULL) {
        printf("%-15s %-20s\n", getTokenTypeName(current->type), current->value);
        current = current->next;
    }
    printf("------------------------------\n");
}
