#ifndef SEMANTICANALYSIS_H
#define SEMANTICANALYSIS_H

#include "lexer.h"

typedef enum {
    ARITHMETIC_OP,
    RELATIONAL_OP
} expressionType;

void checkDeclarationExists(const char *str, int yylineno);
void checkDeclarationNotExists(const char *str, int yylineno);
void checkTypesOfAssignment(dataType dataType, const char *str);
void checkExpressionHasCompatibleTypes(dataType dataTypeLeft, dataType dataTypeRight, int yylineno);

#endif //SEMANTICANALYSIS_H
