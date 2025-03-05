%{
    #include "lexer.h"
    #include "solaris.tab.h"

    char lexErrorMessage[1000];
%}

%option yylineno

%%

"choose" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_CONDITIONAL_CHOOSE;
}

"otherwise" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_CONDITIONAL_OTHERWISE;
}

"loop" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_LOOP;
}

"until" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_LOOP_UNTIL;
}

"while" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_LOOP_WHILE;
}

"show" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_SHOW;
}

"read" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_READ;
}

"function" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_FUNCTION;
}

"return" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_FUNCTION_RETURN;
}

"receive" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_FUNCTION_RECEIVE;
}

"use" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_USE;
}

"define"|"execute"|"call"|"and"|"or"|"not" {
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_RESERVED_WORD;
}

"string" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE_STRING;
}

"integer" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE_INTEGER;
}

"float" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE_FLOAT;
}

"double" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE_DOUBLE;
}

"boolean" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE_BOOLEAN;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_IDENTIFIER, yytext);
    return TOKEN_IDENTIFIER;
}

[0-9]+\.[0-9]+ {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_FLOAT_NUMBER, yytext);
    return TOKEN_FLOAT_NUMBER;
}

[0-9]+ {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_INTEGER_NUMBER, yytext);
    return TOKEN_INTEGER_NUMBER;
}

\"([^\"\\\n]|\\.)*\" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_STRING, yytext);
    return TOKEN_STRING;
}

"+"|"-"|"*"|"/"|"%" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_ARITHMETIC_OP, yytext);
    return TOKEN_ARITHMETIC_OP;
}

"=="|"!="|"<="|">="|"<"|">" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_RELATIONAL_OP, yytext);
    return TOKEN_RELATIONAL_OP;
}

"&&"|"||"|"!" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_LOGICAL_OP, yytext);
    return TOKEN_LOGICAL_OP;
}

"=" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_ASSIGNMENT_OP, yytext);
    return TOKEN_ASSIGNMENT_OP;
}

","|":"|";"|"("|")"|"{"|"}" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DELIMITER, yytext);
    return * yytext;
}

"["|"]" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DELIMITER, yytext);
    return TOKEN_DELIMITER;
}

"#"[^\n]* {
    yylval.str = strdup(yytext);
    return TOKEN_COMMENT_LINE;
}

"##"([^#]|\#[^#])*"##" {
    yylval.str = strdup(yytext);
    return TOKEN_COMMENT_BLOCK;
}

[ \t]+ {}

\n {
    return *yytext;
}

<<EOF>> {
    yylineno = 0;
    return 0;
}

    /* Tratamento de Erros Léxicos */
\"([^\"\\\n]|\\.)*\n {
    int current_line = yylineno - 1;
    sprintf(lexErrorMessage, "String mal formada na linha %d: [ %s ]\n", current_line, yytext);
    processToken(LEX_TOKEN_UNKNOWN, lexErrorMessage);
    return -1;
}

##[^#]* {
    int current_line = yylineno - 1;
    sprintf(lexErrorMessage, "Comentario de bloco nao fechado na linha %d\n", current_line);
    processToken(LEX_TOKEN_UNKNOWN, lexErrorMessage);
    return -1;
}

[0-9]*\.[0-9]*[a-zA-Z]+|[0-9]*\.[0-9]*\.[0-9.]*|\.[0-9]+|[0-9]+\.[^0-9]+ {
    int current_line = yylineno;
    sprintf(lexErrorMessage, "Numero malformado na linha %d: [ %s ]\n", current_line, yytext);
    processToken(LEX_TOKEN_UNKNOWN, lexErrorMessage);
    return -1;
}

. {
    int current_line = yylineno;
    sprintf(lexErrorMessage, "Token nao reconhecido linha %d: [ %s ]\n", current_line, yytext);
    processToken(LEX_TOKEN_UNKNOWN, lexErrorMessage);
    return -1;
}

%%

int yywrap(void) {
    return 1;
}
