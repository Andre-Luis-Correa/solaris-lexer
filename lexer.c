#include "lexer.h"

// Definições das variáveis globais
int errorFlag = 0;
tokenList *reservedWordListHead = NULL;  // Cabeça da lista de palavras reservadas
tokenList *otherTokensListHead = NULL;   // Cabeça da lista de outros tokens

// Cria um token e inicializa seus valores.
// Pré-condições: 'value' deve ser uma string válida.
// Pós-condições: Retorna um novo token com o tipo e valor especificados.
tokenList* createToken(int type, const char *value) {
    tokenList *newToken = (tokenList *)malloc(sizeof(tokenList));
    newToken->type = type;
    newToken->value = strdup(value); // Duplicar a string de valor
    newToken->next = NULL;
    return newToken;
}

// Busca um token na lista encadeada de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Retorna 1 se o token for encontrado, caso contrário retorna 0.
int findToken(tokenList *head, int type, const char *value) {
    tokenList *current = head;
    while (current != NULL) {
        if (current->type == type && strcmp(current->value, value) == 0) {
            return 1; // Token já existe
        }
        current = current->next;
    }
    return 0; // Token não encontrado
}


// Adiciona um novo token ao final da lista encadeada de tokens, se ainda não estiver presente.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: O novo token é adicionado ao final da lista se não for um duplicado.
void addToken(tokenList **head, int type, const char *value) {
    // Verifica se o token já existe na lista
    if (findToken(*head, type, value)) {
        return; // Token já existe, não adicionar novamente
    }

    // Cria um novo token e o adiciona ao final da lista
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
        case LEX_TOKEN_RESERVED_WORD:               return "RESERVED_WORD";
        case LEX_TOKEN_IDENTIFIER:     return "IDENTIFIER";
        case LEX_TOKEN_INTEGER_NUMBER: return "INTEGER_NUMBER";
        case LEX_TOKEN_FLOAT_NUMBER:   return "FLOAT_NUMBER";
        case LEX_TOKEN_STRING:         return "STRING";
        case LEX_TOKEN_ARITHMETIC_OP:  return "ARITHMETIC_OP";
        case LEX_TOKEN_RELATIONAL_OP:  return "RELATIONAL_OP";
        case LEX_TOKEN_LOGICAL_OP:     return "LOGICAL_OP";
        case LEX_TOKEN_DELIMITER:      return "DELIMITER";
        case LEX_TOKEN_ASSIGNMENT_OP:  return "ASSIGNMENT_OP";
        case LEX_TOKEN_COMMENT_LINE:   return "COMMENT_LINE";
        case LEX_TOKEN_COMMENT_BLOCK:  return "COMMENT_BLOCK";
        case LEX_TOKEN_BOOLEAN:        return "BOOLEAN";
        case LEX_TOKEN_WHITESPACE:                return "WHITESPACE";
        case LEX_TOKEN_NEWLINE:                   return "NEWLINE";
        case LEX_TOKEN_DATA_TYPE:                 return "DATA_TYPE";
        case LEX_TOKEN_UNKNOWN:                   return "UNKNOWN";
        default:                   return "INVALID";
    }
}

// Imprime todos os tokens da lista fornecida.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Todos os tokens da lista são impressos no console.
void printTokens(const tokenList *head, const char *listName) {
    const tokenList *current = head;
    printf("\nTokens na lista %s:\n", listName);
    printf("----------------------------------------\n");
    printf("| %-20s %-15s |\n", "Tipo", "Valor");
    printf("----------------------------------------\n");
    while (current != NULL) {
        printf("%-20s %-30s\n", getTokenTypeName(current->type), current->value);
        current = current->next;
    }
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
    if (type != LEX_TOKEN_WHITESPACE && type != LEX_TOKEN_NEWLINE) {
        if (type == LEX_TOKEN_RESERVED_WORD || type == LEX_TOKEN_DATA_TYPE||
            type == LEX_TOKEN_ARITHMETIC_OP || type == LEX_TOKEN_RELATIONAL_OP ||
            type == LEX_TOKEN_ASSIGNMENT_OP || type == LEX_TOKEN_DELIMITER ||
            type == LEX_TOKEN_LOGICAL_OP) {
            addToken(&reservedWordListHead, type, text);  // Adiciona à lista de palavras reservadas

        } else if (type == LEX_TOKEN_UNKNOWN) {
            fprintf(stderr,"\nERRO LEXICO -> %s\n", text); // Imprime erro léxico
            errorFlag = 1; // Seta a flag de erro

        } else {
            addToken(&otherTokensListHead, type, text);   // Adiciona à lista de outros tokens
        }
    }
}

// Imprime as listas de tokens reservados e outros tokens em formato organizado.
// Pré-condições:
//   - 'reservedWordTokens' deve ser o ponteiro para a lista de tokens reservados ou NULL.
//   - 'otherTokens' deve ser o ponteiro para a lista de outros tokens ou NULL.
// Pós-condições:
//   - Todos os tokens das listas são impressos no console em formato tabular ou estruturado.
void printTokenLists(const tokenList *reservedWordTokens, const tokenList *otherTokens) {
    printf("\n\nTokens Identificados:\n");
    printTokens(reservedWordTokens, "Tabela de Palavras Reservadas");
    printTokens(otherTokens, "Tabela de Símbolos");
}

