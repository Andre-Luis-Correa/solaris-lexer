%{
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

// As variáveis globais são declaradas em lexer.h
char errorMessage[256];
%}

%option yylineno

/* Definições de padrões */
DIGITO     [0-9]
LETRA      [a-zA-Z]
IDENTIFICADOR [a-zA-Z_][a-zA-Z0-9_]*

%%

    /* Regras de tokens */
"loop"|"until"|"show"|"define"|"result"|"choose"|"otherwise"|"function"|"receive"|"execute"|"call"|"and"|"or"|"not" {
    processToken(RESERVED_WORD, yytext);  // Identifica palavras reservadas
}

"integer"|"float"|"double"|"char"|"string"|"boolean" {
    processToken(DATA_TYPE, yytext);
}

"true"|"false" {
    processToken(BOOLEAN, yytext);
}

{IDENTIFICADOR} {
    processToken(IDENTIFIER, yytext);
}

    /* Números inteiros ou decimais com apenas um ponto decimal */
{DIGITO}+(\.{DIGITO}+)? {
    processToken(NUMBER, yytext);
}

\"([^\"\n\\]|\\.)*\" {  // Captura strings bem formadas
    processToken(STRING, yytext);
}

\'([^\\\']|\\.)*\' {  // Captura caracteres char bem formados
    processToken(STRING, yytext); // Você pode usar um token diferente para chars
}

"+"|"-"|"*"|"/"|"%" {
    processToken(ARITHMETIC_OP, yytext);
}

"=="|"!="|"<="|">="|"<"|">" {
    processToken(RELATIONAL_OP, yytext);
}

"=" {
    processToken(ASSIGNMENT_OP, yytext);
}

":"|";"|","|"("|")"|"{"|"}"|"["|"]" {
    processToken(DELIMITER, yytext);
}

    /* Comentário de linha: começa com '#' e vai até o final da linha */
"#"[^\n]* {
    processToken(COMMENT_LINE, yytext);
}

    /* Comentário de bloco: começa com '##' e termina com '##' */
"##"([^#]|\#[^#])*"##" {
    processToken(COMMENT_BLOCK, yytext);
}

[ \t]+ {
    processToken(WHITESPACE, yytext); // Ignorar espaços em branco
}

\n {
    processToken(NEWLINE, yytext); // Contabilizar nova linha
}

    /* Tratamento de Erros Léxicos */
\"([^\"\n\\]|\\.)*\n {
    sprintf(errorMessage, "String malformada '%s' na linha %d\n", yytext, yylineno);
    processToken(UNKNOWN, errorMessage);
    return -1;  // Interrompe o processamento após detectar um erro
}

##[^#]* {  // Comentário de bloco não fechado
    sprintf(errorMessage, "Comentario de bloco nao fechado na linha %d\n", yylineno);
    processToken(UNKNOWN, errorMessage);
    return -1;
}

{DIGITO}*\.[^0-9]+|\.[^0-9]+|{DIGITO}+\.[^0-9.]*\.|{DIGITO}+\.{DIGITO}*\.[0-9.]* {
    sprintf(errorMessage, "Numero malformado '%s' na linha %d\n", yytext, yylineno);
    processToken(UNKNOWN, errorMessage);
    return -1;
}

\'[^\'\\\n]{2,}\'|\'[^\'\\\n]* {  // Caracter inválido
    sprintf(errorMessage, "Caracter inválido '%s' na linha %d\n", yytext, yylineno);
    processToken(UNKNOWN, errorMessage);
    return -1;
}

. {
    sprintf(errorMessage, "INVALID CHARACTER: %s na linha %d\n", yytext, yylineno);
    processToken(UNKNOWN, errorMessage);
    return -1;
}

%%

int yywrap() {
    return 1;
}