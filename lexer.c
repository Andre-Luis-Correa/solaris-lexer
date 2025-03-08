#include "lexer.h"

// Definições das variáveis globais
int errorFlag = 0;
tokenList *reservedWordListHead = NULL;  // Cabeça da lista de palavras reservadas
tokenList *symbolTable = NULL;   // Cabeça da lista de outros tokens

// Cria um token e inicializa seus valores.
// Pré-condições: 'value' deve ser uma string válida.
// Pós-condições: Retorna um novo token com o tipo e valor especificados.
tokenList *createToken(int type, const char *value) {
    tokenList *newToken = (tokenList *) malloc(sizeof(tokenList));
    newToken->lexTokenType = type;
    newToken->str = strdup(value);
    newToken->category = UNDEFINED;
    newToken->dataType = TYPE_UNDEFINED;
    newToken->value.identifierValue = NULL;
    newToken->value.stringValue = NULL;
    newToken->value.intValue = 0;
    newToken->value.floatValue = 0;
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
const char *getTokenTypeName(int type) {
    switch (type) {
        case LEX_TOKEN_RESERVED_WORD:
            return "RESERVED_WORD";
        case LEX_TOKEN_IDENTIFIER:
            return "IDENTIFIER";
        case LEX_TOKEN_INTEGER_NUMBER:
            return "INTEGER_NUMBER";
        case LEX_TOKEN_FLOAT_NUMBER:
            return "FLOAT_NUMBER";
        case LEX_TOKEN_STRING:
            return "STRING";
        case LEX_TOKEN_ARITHMETIC_OP:
            return "ARITHMETIC_OP";
        case LEX_TOKEN_RELATIONAL_OP:
            return "RELATIONAL_OP";
        case LEX_TOKEN_LOGICAL_OP:
            return "LOGICAL_OP";
        case LEX_TOKEN_DELIMITER:
            return "DELIMITER";
        case LEX_TOKEN_ASSIGNMENT_OP:
            return "ASSIGNMENT_OP";
        case LEX_TOKEN_CONDITIONAL_CHOOSE:
            return "CONDITIONAL_CHOOSE";
        case LEX_TOKEN_CONDITIONAL_OTHERWISE:
            return "CONDITIONAL_OTHERWISE";
        case LEX_TOKEN_LOOP:
            return "LOOP";
        case LEX_TOKEN_LOOP_UNTIL:
            return "LOOP_UNTIL";
        case LEX_TOKEN_LOOP_WHILE:
            return "LOOP_WHILE";
        case LEX_TOKEN_DATA_TYPE_STRING:
            return "DATA_TYPE_STRING";
        case LEX_TOKEN_DATA_TYPE_INTEGER:
            return "DATA_TYPE_INTEGER";
        case LEX_TOKEN_DATA_TYPE_FLOAT:
            return "DATA_TYPE_FLOAT";
        case LEX_TOKEN_DATA_TYPE_DOUBLE:
            return "DATA_TYPE_DOUBLE";
        case LEX_TOKEN_DATA_TYPE_BOOLEAN:
            return "DATA_TYPE_BOOLEAN";
        case LEX_TOKEN_COMMENT_LINE:
            return "COMMENT_LINE";
        case LEX_TOKEN_COMMENT_BLOCK:
            return "COMMENT_BLOCK";
        case LEX_TOKEN_SHOW:
            return "SHOW";
        case LEX_TOKEN_READ:
            return "READ";
        case LEX_TOKEN_FUNCTION:
            return "FUNCTION";
        case LEX_TOKEN_FUNCTION_RECEIVE:
            return "FUNCTION_RECEIVE";
        case LEX_TOKEN_FUNCTION_RETURN:
            return "FUNCTION_RETURN";
        case LEX_TOKEN_USE:
            return "USE";
        case LEX_TOKEN_WHITESPACE:
            return "WHITESPACE";
        case LEX_TOKEN_NEWLINE:
            return "NEWLINE";
        case LEX_TOKEN_UNKNOWN:
            return "UNKNOWN";
        case LEX_TOKEN_DATA_TYPE:
            return "DATA_TYPE";
        case LEX_TOKEN_CALL:
            return "CALL";
        default:
            return "INVALID";
    }
}

// Retorna o nome da categoria de um símbolo como uma string legível.
// Pré-condições:
//   - 'cat' deve ser um valor válido da enumeração 'category'.
// Pós-condições:
//   - Retorna uma string representando a categoria do símbolo.
char *getCategoryName(category cat) {
    switch (cat) {
        case VARIABLE:
            return "VARIABLE";
        case FUNCTION:
            return "FUNCTION";
        case CONSTANT:
            return "CONSTANT";
        default:
            return "UNDEFINED";
    }
}

// Retorna o nome do tipo de dado de um símbolo como uma string legível.
// Pré-condições:
//   - 'type' deve ser um valor válido da enumeração 'dataType'.
// Pós-condições:
//   - Retorna uma string representando o tipo de dado do símbolo.
char *getDataTypeName(dataType type) {
    switch (type) {
        case TYPE_INTEGER:
            return "INTEGER";
        case TYPE_FLOAT:
            return "FLOAT";
        case TYPE_STRING:
            return "STRING";
        case TYPE_IDENTIFIER:
            return "IDENTIFIER";
        default:
            return "UNDEFINED";
    }
}

// Retorna o valor armazenado em um token na tabela de símbolos.
// Pré-condições:
//   - 'token' deve ser um ponteiro válido para um token na tabela de símbolos.
// Pós-condições:
//   - Retorna uma string representando o valor do token.
//   - Se o token não tiver um valor associado, retorna "N/A".
char *getTokenValue(tokenList *token) {
    static char buffer[64];

    if (!token || !token->hasValue) {
        return "N/A";
    }

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
            fprintf(stderr, "\nERRO LEXICO -> %s\n", text); // Imprime erro léxico
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

tokenList *findSymbol(tokenList *head, const char *str) {
    tokenList *current = head;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Atualiza a categoria e o tipo de dado de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
//   - 'category' define se o identificador é uma variável, função ou constante.
//   - 'dataType' define o tipo de dado do identificador.
// Pós-condições:
//   - O identificador na tabela de símbolos será atualizado com a nova categoria e tipo de dado.
void updateSymbolCategoryAndDataType(const char *str, category category, dataType dataType) {
    tokenList *current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            current->category = category;
            current->dataType = dataType;
        }
        current = current->next;
    }
}

// Define o valor de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'symbol' deve ser um identificador válido presente na tabela de símbolos.
//   - 'value' é a string contendo o valor a ser atribuído.
//   - 'dataType' define o tipo de dado do valor atribuído.
// Pós-condições:
//   - O identificador recebe o valor correspondente ao seu tipo de dado.
void setSymbolValue(tokenList *symbol, const char *value, dataType dataType) {
    if (!symbol) return;

    char *endptr;

    switch (dataType) {
        case TYPE_INTEGER:
            symbol->value.intValue = strtol(value, &endptr, 10);
            break;

        case TYPE_FLOAT:
            symbol->value.floatValue = strtof(value, &endptr);
            break;

        case TYPE_STRING:
            free(symbol->value.stringValue); // Libera memória anterior se necessário
            symbol->value.stringValue = value ? strdup(value) : NULL;
            break;

        default:
            break;
    }

    symbol->hasValue = (value != NULL);
}

// Copia o valor de um identificador da tabela de símbolos para outro identificador.
// Pré-condições:
//   - 'target' deve ser um identificador válido presente na tabela de símbolos.
//   - 'identifier' deve ser um identificador previamente declarado na tabela de símbolos.
// Pós-condições:
//   - O identificador alvo recebe o valor e o tipo do identificador de origem.
void copyIdentifierValue(tokenList *target, const char *identifier) {
    if (!target || !identifier) return;

    tokenList *symbolInTable = findSymbol(symbolTable, identifier);
    if (!symbolInTable) {
        fprintf(stderr, "Erro semântico: Identificador '%s' não declarado.\n", identifier);
        exit(EXIT_FAILURE);
    }

    target->dataType = symbolInTable->dataType;

    switch (symbolInTable->dataType) {
        case TYPE_INTEGER:
            target->value.intValue = symbolInTable->value.intValue;
            break;
        case TYPE_FLOAT:
            target->value.floatValue = symbolInTable->value.floatValue;
            break;
        case TYPE_STRING:
            free(target->value.stringValue);
            target->value.stringValue = symbolInTable->value.stringValue ? strdup(symbolInTable->value.stringValue) : NULL;
            break;
        default:
            break;
    }

    target->hasValue = symbolInTable->hasValue;
}

// Atualiza o valor de um símbolo na tabela de símbolos, verificando se é um identificador ou um valor literal.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
//   - 'value' é a string contendo o valor a ser atribuído.
//   - 'dataType' define o tipo de dado do valor atribuído.
// Pós-condições:
//   - O identificador recebe o valor correspondente ao seu tipo de dado ou o valor de outro identificador.
void updateSymbolValue(const char *str, const char *value, dataType dataType) {
    tokenList *current = symbolTable;

    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            if (dataType == TYPE_IDENTIFIER) {
                copyIdentifierValue(current, value);
            } else {
                setSymbolValue(current, value, dataType);
            }
            return;
        }
        current = current->next;
    }
}

// Retorna o tipo de dado de um símbolo na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido presente na tabela de símbolos.
// Pós-condições:
//   - Retorna o tipo de dado do identificador encontrado na tabela de símbolos.
dataType getSymbolDataType(const char *str) {
    tokenList const *symbol = findSymbol(symbolTable, str);
    return symbol->dataType;
}
