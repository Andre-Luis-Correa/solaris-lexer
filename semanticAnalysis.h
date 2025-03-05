#ifndef SEMANTICANALYSIS_H
#define SEMANTICANALYSIS_H

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_BOOLEAN,
    TYPE_UNDEFINED
} dataType;

typedef enum {
    VARIABLE,
    FUNCTION,
    UNDEFINED
} category;

typedef struct symbolTable {
    char * str;
    int lexTokenType;
    category category;
    dataType dataType;
    union {
        int    intValue;
        float  floatValue;
        char * stringValue;
    } value;
    struct symbolTable * next;
} symbolTable;

// Cabeça da lista de outros tokens
extern symbolTable * symbolTableList;

symbolTable * createSymbolTableNode(const char *str, int lexTokenType, category category, dataType dataType, int intValue, float floatValue,const char *stringValue);
void insertValue(symbolTable * newNode, dataType type, int intValue, float floatValue, const char *stringValue);
int findSymbol(symbolTable * head, const char *str);
void addSymbol(symbolTable **head, const char *str, int lexTokenType, category category, dataType dataType, int intValue, float floatValue, const char *stringValue);
void check_declaration_exists(const char *str);

#endif //SEMANTICANALYSIS_H
