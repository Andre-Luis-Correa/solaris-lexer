#include <stdio.h>
#include <stdlib.h>
#include "semanticAnalysis.h"
#include "lexer.h"

// Verifica se uma variável já foi declarada na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a variável já foi declarada anteriormente, imprime um erro semântico e encerra a execução.
void checkDeclarationExists(const char *str, int yylineno) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category != UNDEFINED && symbol->dataType != TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s ja foi declarada anteriormente na linha %d\n", str, yylineno + 1);
        exit(EXIT_FAILURE);
    }
}

// Verifica se uma função já foi declarada na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a função já foi declarada anteriormente, imprime um erro semântico e encerra a execução.
void checkFunctionDeclarationExists(const char *str, int yylineno) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category != UNDEFINED && symbol->dataType != TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A funcao %s ja foi declarada anteriormente na linha %d\n", str, yylineno + 1);
        exit(EXIT_FAILURE);
    }
}

// Verifica se uma variável foi declarada antes de ser utilizada.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a variável **não foi declarada anteriormente**, imprime um erro semântico e encerra a execução.
void checkDeclarationNotExists(const char *str, int yylineno) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category == UNDEFINED && symbol->dataType == TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s nao foi declarada anteriormente. Erro na linha %d\n", str, yylineno + 1);
        exit(EXIT_FAILURE);
    }
}

// Verifica se uma função foi declarada antes de ser utilizada.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a função não foi declarada anteriormente, imprime um erro semântico e encerra a execução.
void checkFunctionDeclarationNotExists(const char *str, int yylineno) {
    tokenList const * symbol = findSymbol(symbolTable, str);
    if(symbol && symbol->category == UNDEFINED && symbol->dataType == TYPE_UNDEFINED) {
        fprintf(stderr, "\nERRO SEMANTICO -> A funcao %s nao foi declarada anteriormente. Erro na linha %d\n", str, yylineno + 1);
        exit(EXIT_FAILURE);
    }
}

// Verifica se o tipo de dado atribuído a uma variável é compatível com o tipo declarado.
// Pré-condições:
//   - 'dataType' é o tipo esperado da variável que está recebendo a atribuição.
//   - 'str' é o nome do identificador cujo tipo será comparado.
// Pós-condições:
//   - Se o tipo do identificador não for compatível com o tipo esperado, imprime um erro semântico e encerra a execução.
void checkTypesOfAssignment(dataType dataType, const char *str) {
    tokenList const * symbol = findSymbol(symbolTable, str);

    if(symbol->dataType != dataType) {
        fprintf(stderr, "\nERRO SEMANTICO -> A variavel %s esta sendo atribuida a uma variavel de tipo diferente\n", symbol->str);
        exit(EXIT_FAILURE);
    }
}

// Verifica se dois operandos de uma expressão possuem tipos compatíveis.
// Pré-condições:
//   - 'dataTypeLeft' é o tipo de dado do operando esquerdo da expressão.
//   - 'dataTypeRight' é o tipo de dado do operando direito da expressão.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se os tipos dos operandos forem diferentes, imprime um erro semântico e encerra a execução.
void checkExpressionHasCompatibleTypes(dataType dataTypeLeft, dataType dataTypeRight, int yylineno) {
    if(dataTypeLeft != dataTypeRight) {
        fprintf(stderr, "\nERRO SEMANTICO -> Os lados da expressao possuem tipos de dados diferentes na linha %d\n", yylineno + 1);
        exit(EXIT_FAILURE);
    }
}

// Verifica se o tipo de retorno coincide com o tipo da função.
// Pré-condições:
//   - 'functionDataType' é o tipo de dado da função.
//   - 'returnDataType' é o tipo de dado do retorno da função.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se os tipos não forem iguais, imprime um erro semântico e encerra a execução.
void checkFunctionReturnType(dataType functionDataType, dataType returnDataType, int yylineno) {
    if(functionDataType != returnDataType) {
        fprintf(stderr, "\nERRO SEMANTICO -> O tipo de retorno da funcao nao coincide com o tipo da funcao na linha %d\n", yylineno);
        exit(EXIT_FAILURE);
    }
}

// Verifica se a categoria de um dado identificador é do tipo função.
// Pré-condições:
//   - 'identifierCategory' é a categoria do identificador a ser analisado.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a categoria não for FUNCTION, imprime um erro semântico e encerra a execução.
void verifyFunctionCategory(category identifierCategory, int yylineno) {
    if(identifierCategory != FUNCTION) {
        fprintf(stderr, "\nERRO SEMANTICO -> O identificador nao representa uma funcao na linha %d\n", yylineno);
        exit(EXIT_FAILURE);
    }
}

// Verifica se o número de parâmetros passados para uma função corresponde ao número declarado.
// Pré-condições:
//   - 'str' é o nome da função a ser verificada.
//   - 'paramCount' é o número de parâmetros passados na chamada da função.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se o número de parâmetros não coincidir com a declaração da função, imprime um erro semântico e encerra a execução.
void verifyNumberOfParameters(const char *str, int paramCount, int yylineno) {
    tokenList const * symbol = findSymbol(symbolTable, str);

    if(symbol->numberOfParameters != paramCount) {
        fprintf(stderr, "\nERRO SEMANTICO -> O numero de parametros da funcao %s nao coincide com a declaracao na linha %d.\n", symbol->str, yylineno + 1);
        exit(EXIT_FAILURE);
    }
}