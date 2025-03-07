#ifndef SEMANTICANALYSIS_H
#define SEMANTICANALYSIS_H

#include "lexer.h"

// Verifica se uma variável já foi declarada na tabela de símbolos.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a variável já foi declarada anteriormente, imprime um erro semântico e encerra a execução.
void checkDeclarationExists(const char *str, int yylineno);

// Verifica se uma variável foi declarada antes de ser utilizada.
// Pré-condições:
//   - 'str' deve ser um identificador válido de variável.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se a variável **não foi declarada anteriormente**, imprime um erro semântico e encerra a execução.
void checkDeclarationNotExists(const char *str, int yylineno);

// Verifica se o tipo de dado atribuído a uma variável é compatível com o tipo declarado.
// Pré-condições:
//   - 'dataType' é o tipo esperado da variável que está recebendo a atribuição.
//   - 'str' é o nome do identificador cujo tipo será comparado.
// Pós-condições:
//   - Se o tipo do identificador não for compatível com o tipo esperado, imprime um erro semântico e encerra a execução.
void checkTypesOfAssignment(dataType dataType, const char *str);

// Verifica se dois operandos de uma expressão possuem tipos compatíveis.
// Pré-condições:
//   - 'dataTypeLeft' é o tipo de dado do operando esquerdo da expressão.
//   - 'dataTypeRight' é o tipo de dado do operando direito da expressão.
//   - 'yylineno' indica a linha do código onde a verificação ocorre.
// Pós-condições:
//   - Se os tipos dos operandos forem diferentes, imprime um erro semântico e encerra a execução.
void checkExpressionHasCompatibleTypes(dataType dataTypeLeft, dataType dataTypeRight, int yylineno);

#endif //SEMANTICANALYSIS_H
