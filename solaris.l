%{
#include "lexer.h"
// As variáveis globais são declaradas em lexer.h
%}

/* Definições de padrões */
DIGITO     [0-9]
LETRA      [a-zA-Z]
IDENTIFICADOR [a-zA-Z_][a-zA-Z0-9_]*

%%
    /* Regras de tokens */
"start"|"finish"|"loop"|"until"|"show"|"define"|"result"|"choose"|"otherwise"|"function"|"receive"|"execute"|"call"|"and"|"or"|"not" {
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

{DIGITO}+(\.{DIGITO}+)? {
    processToken(NUMBER, yytext);
}

\"([^\\\"]|\\.)*\"|\'([^\\\']|\\.)*\' {
    processToken(STRING, yytext);
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

. {
    printf("INVALID CHARACTER: %s\n", yytext);
    addToken(&otherTokensListHead, UNKNOWN, yytext);
}

%%

int yywrap() {
    return 1;
}