#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semanticAnalysis.h"

symbolTable * symbolTableList = NULL;

symbolTable * createSymbolTableNode(const char *str, int lexTokenType, category category, dataType dataType, int intValue, float floatValue,const char *stringValue) {
    symbolTable *newNode = (symbolTable*) malloc(sizeof(symbolTable));
    newNode->str = strdup(str);
    newNode->lexTokenType = lexTokenType;
    newNode->category = category;
    newNode->dataType = dataType;
    insertValue(newNode, dataType, intValue, floatValue, stringValue);
    newNode->next = NULL;
    return newNode;
}

void insertValue(symbolTable * newNode, dataType dataType, int intValue, float floatValue, const char *stringValue) {
    switch (dataType) {
        case TYPE_INT:
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

int findSymbol(symbolTable * head, const char * str) {
    symbolTable *current = head;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void addSymbol(symbolTable **head, const char *str, int lexTokenType, category category, dataType dataType, int intValue, float floatValue, const char *stringValue) {
    if (findSymbol(*head, str)) {
        return;
    }

    symbolTable *newNode = createSymbolTableNode(str, lexTokenType, category, dataType, intValue, floatValue, stringValue);

    if(*head == NULL) {
        *head = newNode;
    } else {
        symbolTable * current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void processSemanticStructure(const char *str, int lexTokenType, category category, dataType dataType, int intValue, float floatValue, const char *stringValue) {
    addSymbol(&symbolTableList, str, lexTokenType, category, dataType, intValue, floatValue, stringValue);
}

// Funções auxiliares para identificação de erros semânticos

void check_declaration_exists(const char *str) {
    int isDeclared = findSymbol(symbolTableList, str);
    if(isDeclared) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s ja foi declarada anteriormente\n", str);
        exit(EXIT_FAILURE);
    }
}