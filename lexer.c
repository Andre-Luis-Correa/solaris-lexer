#include "lexer.h"

// Definições das variáveis globais
int errorFlag = 0;
tokenList *reservedWordListHead = NULL;  // Cabeça da lista de palavras reservadas
tokenList *symbolTable = NULL;   // Cabeça da lista de outros tokens

// Cria um token e inicializa seus valores.
// Pré-condições: 'value' deve ser uma string válida.
// Pós-condições: Retorna um novo token com o tipo e valor especificados.
tokenList* createToken(int type, const char *value) {
    tokenList *newToken = (tokenList *)malloc(sizeof(tokenList));
    newToken->lexTokenType = type;
    newToken->str = strdup(value);
    newToken->category = UNDEFINED;
    newToken->dataType = TYPE_UNDEFINED;
    newToken->hasValue = 0;
    newToken->next = NULL;
    return newToken;
}

// Busca um token na lista encadeada de tokens.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Retorna 1 se o token for encontrado, caso contrário retorna 0.
int findToken(tokenList *head, int type, const char *value) {
    tokenList *current = head;
    while (current != NULL) {
        if (strcmp(current->str, value) == 0) {
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
        free(current->str);
        free(current);
        current = next;
    }
}

// Retorna o nome do tipo de token com base em seu valor enumerado.
// Pré-condições: 'type' deve ser um valor válido de enumeração de tipo de token.
// Pós-condições: Retorna a string correspondente ao tipo de token.
const char* getTokenTypeName(int type) {
    switch (type) {
        case LEX_TOKEN_RESERVED_WORD:       return "RESERVED_WORD";
        case LEX_TOKEN_IDENTIFIER:          return "IDENTIFIER";
        case LEX_TOKEN_INTEGER_NUMBER:      return "INTEGER_NUMBER";
        case LEX_TOKEN_FLOAT_NUMBER:        return "FLOAT_NUMBER";
        case LEX_TOKEN_STRING:              return "STRING";
        case LEX_TOKEN_ARITHMETIC_OP:       return "ARITHMETIC_OP";
        case LEX_TOKEN_RELATIONAL_OP:       return "RELATIONAL_OP";
        case LEX_TOKEN_LOGICAL_OP:          return "LOGICAL_OP";
        case LEX_TOKEN_DELIMITER:           return "DELIMITER";
        case LEX_TOKEN_ASSIGNMENT_OP:       return "ASSIGNMENT_OP";
        case LEX_TOKEN_CONDITIONAL_CHOOSE:  return "CONDITIONAL_CHOOSE";
        case LEX_TOKEN_CONDITIONAL_OTHERWISE: return "CONDITIONAL_OTHERWISE";
        case LEX_TOKEN_LOOP:                return "LOOP";
        case LEX_TOKEN_LOOP_UNTIL:          return "LOOP_UNTIL";
        case LEX_TOKEN_LOOP_WHILE:          return "LOOP_WHILE";
        case LEX_TOKEN_DATA_TYPE_STRING:    return "DATA_TYPE_STRING";
        case LEX_TOKEN_DATA_TYPE_INTEGER:   return "DATA_TYPE_INTEGER";
        case LEX_TOKEN_DATA_TYPE_FLOAT:     return "DATA_TYPE_FLOAT";
        case LEX_TOKEN_DATA_TYPE_DOUBLE:    return "DATA_TYPE_DOUBLE";
        case LEX_TOKEN_DATA_TYPE_BOOLEAN:   return "DATA_TYPE_BOOLEAN";
        case LEX_TOKEN_COMMENT_LINE:        return "COMMENT_LINE";
        case LEX_TOKEN_COMMENT_BLOCK:       return "COMMENT_BLOCK";
        case LEX_TOKEN_SHOW:                return "SHOW";
        case LEX_TOKEN_READ:                return "READ";
        case LEX_TOKEN_FUNCTION:            return "FUNCTION";
        case LEX_TOKEN_FUNCTION_RECEIVE:    return "FUNCTION_RECEIVE";
        case LEX_TOKEN_FUNCTION_RETURN:     return "FUNCTION_RETURN";
        case LEX_TOKEN_USE:                 return "USE";
        case LEX_TOKEN_WHITESPACE:          return "WHITESPACE";
        case LEX_TOKEN_NEWLINE:             return "NEWLINE";
        case LEX_TOKEN_UNKNOWN:             return "UNKNOWN";
        case LEX_TOKEN_DATA_TYPE:           return "DATA_TYPE";
        default:                            return "INVALID";
    }
}

char* getCategoryName(category cat) {
    switch (cat) {
        case VARIABLE: return "VARIABLE";
        case FUNCTION: return "FUNCTION";
        case CONSTANT: return "CONSTANT";
        default: return "UNDEFINED";
    }
}

char* getDataTypeName(dataType type) {
    switch (type) {
        case TYPE_INTEGER: return "INTEGER";
        case TYPE_FLOAT: return "FLOAT";
        case TYPE_STRING: return "STRING";
        case TYPE_IDENTIFIER: return "IDENTIFIER";
        default: return "UNDEFINED";
    }
}

char* getTokenValue(tokenList *token) {
    static char buffer[20];

    if (token->hasValue) {

        switch (token->dataType) {
            case TYPE_INTEGER:
                snprintf(buffer, sizeof(buffer), "%d", token->value.intValue);
                return buffer;
            case TYPE_FLOAT:
                snprintf(buffer, sizeof(buffer), "%.2f", token->value.floatValue);
                return buffer;
            case TYPE_STRING:
                return token->value.stringValue ? token->value.stringValue : "N/A";
            case TYPE_IDENTIFIER:
                return token->value.identifierValue ? token->value.identifierValue : "N/A";
            default:
                return "N/A";
        }
    }
    return "N/A";
}

// Imprime todos os tokens da lista fornecida.
// Pré-condições: 'head' deve ser o ponteiro para a cabeça da lista de tokens.
// Pós-condições: Todos os tokens da lista são impressos no console.
void printTokens(tokenList *head, const char *listName) {
    tokenList *current = head;
    printf("\nTokens na lista %s:\n", listName);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-25s | %-25s | %-15s | %-15s | %-20s |\n", "Tipo", "Cadeia", "Categoria", "DataType", "Valor");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-25s | %-25s | %-15s | %-15s | %-20s |\n",
               getTokenTypeName(current->lexTokenType),
               current->str ? current->str : "NULL",
               getCategoryName(current->category),
               getDataTypeName(current->dataType),
               getTokenValue(current));
        current = current->next;
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
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

        if (type == LEX_TOKEN_UNKNOWN) {
            fprintf(stderr,"\nERRO LEXICO -> %s\n", text); // Imprime erro léxico
            errorFlag = 1; // Seta a flag de erro
        }

        if (type == LEX_TOKEN_IDENTIFIER || type == LEX_TOKEN_FLOAT_NUMBER ||
            type == LEX_TOKEN_INTEGER_NUMBER || type == LEX_TOKEN_STRING) {
            addToken(&symbolTable, type, text);   // Adiciona à tabela de símbolos
        } else {
            addToken(&reservedWordListHead, type, text);  // Adiciona à lista de palavras reservadas
        }

    }
}

// Imprime as listas de tokens reservados e outros tokens em formato organizado.
// Pré-condições:
//   - 'reservedWordTokens' deve ser o ponteiro para a lista de tokens reservados ou NULL.
//   - 'otherTokens' deve ser o ponteiro para a lista de outros tokens ou NULL.
// Pós-condições:
//   - Todos os tokens das listas são impressos no console em formato tabular ou estruturado.
void printTokenLists(tokenList *reservedWordTokens, tokenList *symbolTable) {
    printf("\n\nTokens Identificados:\n");
    printTokens(reservedWordTokens, "Tabela de Palavras Reservadas");
    printTokens(symbolTable, "Tabela de Simbolos");
}

tokenList * findSymbol(tokenList * head, const char * str) {
    tokenList *current = head;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

tokenList * updateSymbolTableItem(const char *str, int lexTokenType, category category, dataType dataType, int hasValue, int intValue, float floatValue,const char *stringValue) {
    tokenList *newNode = (tokenList*) malloc(sizeof(symbolTable));
    newNode->str = strdup(str);
    newNode->lexTokenType = lexTokenType;
    newNode->category = category;
    newNode->dataType = dataType;
    newNode->hasValue = hasValue;

    if(hasValue == 1) {
        insertValue(newNode, dataType, intValue, floatValue, stringValue);
    }

    newNode->next = NULL;
    return newNode;
}

void insertValue(tokenList * newNode, dataType dataType, int intValue, float floatValue, const char *stringValue) {
    switch (dataType) {
        case TYPE_INTEGER:
            newNode->value.intValue = intValue;
            break;
        case TYPE_FLOAT:
            newNode->value.floatValue = floatValue;
            break;
        case TYPE_STRING:
            if (stringValue) {
                newNode->value.stringValue = strdup(stringValue);
            } else {
                newNode->value.stringValue = NULL;
            }
            break;
        default:
            break;
    }
}

void updateSymbolCategoryAndDataType(const char *str, category category, dataType dataType){
    tokenList *current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            current->category = category;
            current->dataType = dataType;
        }
        current = current->next;
    }
}

void updateSymbolValue(const char *str, const char *value, dataType dataType) {
    tokenList *current = symbolTable;

    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            if (value != NULL) {
                current->hasValue = 1;
            } else {
                current->hasValue = 0;
            }

            char *endptr;

            switch (dataType) {
                case TYPE_INTEGER:
                    current->value.intValue = strtol(value, &endptr, 10);
                    break;
                case TYPE_FLOAT:
                    current->value.floatValue = strtof(value, &endptr);
                    break;
                case TYPE_STRING:
                    if (value) {
                        current->value.stringValue = strdup(value);
                    } else {
                        current->value.stringValue = NULL;
                    }
                    break;
                case TYPE_IDENTIFIER:
                    if (value) {
                        current->value.identifierValue = strdup(value);
                    } else {
                        current->value.identifierValue = NULL;
                    }
                default:
                    break;
            }

        }
        current = current->next;
    }
}

dataType getSymbolDataType(const char *str) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    return symbol->dataType;
}
