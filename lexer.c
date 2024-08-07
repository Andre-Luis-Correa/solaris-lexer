#include "lexer.h"

// Definições das variáveis globais
int errorFlag = 0;
tokenList *reservedWordListHead = NULL;  // Cabeça da lista de palavras reservadas
tokenList *otherTokensListHead = NULL;   // Cabeça da lista de outros tokens

// Cria um novo token e inicializa seus valores.
// Pré-condições: 'value' deve ser uma string válida.
// Pós-condições: Retorna um novo token com o tipo e valor especificados.
tokenList* createToken(int type, const char *value) {
    tokenList *newToken = (tokenList *)malloc(sizeof(tokenList));
    newToken->type = type;
    newToken->value = strdup(value); // Duplicar a string de valor
    newToken->next = NULL;
    return newToken;
}

// Adiciona um novo token ao final da lista encadeada de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: O novo token é adicionado ao final da lista.
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

// Libera a memória alocada para a lista de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Toda a memória alocada para a lista é liberada.
void freeTokenList(tokenList *head) {
    tokenList *current = head;
    while (current != NULL) {
        tokenList *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

// Retorna o nome do tipo de token com base em seu valor enumerado.
// Pré-condições: 'type' deve ser um valor válido de enumeração de tipo de token.
// Pós-condições: Retorna a string correspondente ao tipo de token.
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

// Imprime todos os tokens da lista fornecida.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Todos os tokens da lista são impressos no console.
void printTokens(const tokenList *head, const char *listName) {
    const tokenList *current = head;
    printf("\nTokens na lista %s:\n", listName);
    printf("%-15s %-20s\n", "Tipo", "Valor");
    printf("------------------------------\n");
    while (current != NULL) {
        printf("%-15s %-20s\n", getTokenTypeName(current->type), current->value);
        current = current->next;
    }
    printf("------------------------------\n");
}

// Função auxiliar para armazenar o token na lista apropriada
// Pré-condições:
//   - 'type' deve ser um valor válido de tipo de token definido pelo sistema (por exemplo, RESERVED_WORD, IDENTIFIER).
//   - 'text' deve ser uma string não nula que representa o valor do token identificado.
// Pós-condições:
//   - Token do tipo WHITESPACE e NEWLINE não adicionados a nenhuma lista
//   - O token é adicionado à lista de palavras reservadas se 'type' for RESERVED_WORD.
//   - Caso contrário, o token é adicionado à lista de outros tokens.
void processToken(int type, const char *text) {
    if (type != WHITESPACE && type != NEWLINE) {
        if (type == RESERVED_WORD) {
            addToken(&reservedWordListHead, type, text);  // Adiciona à lista de palavras reservadas
        } else if (type == UNKNOWN) {
            printf("\nERRO LEXICO -> %s\n", text); // Imprime erro léxico
            errorFlag = 1; // Seta a flag de erro
        } else {
            addToken(&otherTokensListHead, type, text);   // Adiciona à lista de outros tokens
        }
    }
}
