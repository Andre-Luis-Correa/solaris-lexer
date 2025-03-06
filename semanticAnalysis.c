#include <stdio.h>
#include <stdlib.h>
#include "semanticAnalysis.h"
#include "lexer.h"

void checkDeclarationExists(const char *str) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category != UNDEFINED && symbol->dataType != TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s ja foi declarada anteriormente\n", str);
        exit(EXIT_FAILURE);
    }
}

void checkDeclarationNotExists(const char *str) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category == UNDEFINED && symbol->dataType == TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s nao foi declarada anteriormente\n", str);
        exit(EXIT_FAILURE);
    }
}

void checkTypesOfAssignment(dataType dataType, const char *str) {
    tokenList const * symbol = findSymbol(symbolTable, str);

    if(symbol->dataType != dataType) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s esta sendo atribuida a uma variavel de tipo diferente\n", symbol->str);
        exit(EXIT_FAILURE);
    }
}