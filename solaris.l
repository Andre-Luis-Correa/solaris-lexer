%{
    #include "lexer.h"
    #include "solaris.tab.h"

    char errorMessage[256];
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

"loop"|"until"|"show"|"define"|"result"|"function"|"receive"|"execute"|"call"|"and"|"or"|"not" {
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_RESERVED_WORD;
}

"integer"|"float"|"double"|"char"|"string"|"boolean" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE;
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

\"([^\"\n\\]|\\.)*\" {
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

";"|"("|")"|"{"|"}" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DELIMITER, yytext);
    return * yytext;
}

":"|","|"{"|"}"|"["|"]" {
    yylval.str = strdup(yytext);
    processToken(LEX_TOKEN_DELIMITER, yytext);
    return TOKEN_DELIMITER;
}

[ \t]+ {}

\n {
    return *yytext;
}

. {
    yyerror("Caracter invalido\n");
}

%%

int yywrap(void) {
    return 1;
}
