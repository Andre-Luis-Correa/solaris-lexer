%{
    #include "lexer.h"
    #include "solaris.tab.h"

    char errorMessage[256];
%}

%option yylineno

%%

"loop"|"until"|"show"|"define"|"result"|"choose"|"otherwise"|"function"|"receive"|"execute"|"call"|"and"|"or"|"not" {
    processToken(LEX_TOKEN_RESERVED_WORD, yytext);
    return TOKEN_RESERVED_WORD;
}

"integer"|"float"|"double"|"char"|"string"|"boolean" {
    processToken(LEX_TOKEN_DATA_TYPE, yytext);
    return TOKEN_DATA_TYPE;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    processToken(LEX_TOKEN_IDENTIFIER, yytext);
    return TOKEN_IDENTIFIER;
}

[0-9]+ {
    yylval = atoi(yytext);
    processToken(LEX_TOKEN_INTEGER_NUMBER, yytext);
    return TOKEN_INTEGER_NUMBER;
}

":"|";"|","|"("|")"|"{"|"}"|"["|"]" {
    processToken(LEX_TOKEN_DELIMITER, yytext);
}

[ \t]+ {
    processToken(LEX_TOKEN_WHITESPACE, yytext); // Ignorar espaços em branco
}

\n {
    processToken(LEX_TOKEN_NEWLINE, yytext); // Contabilizar nova linha
}

. {
    sprintf(errorMessage, "INVALID CHARACTER: %s na linha %d\n", yytext, yylineno);
    processToken(LEX_TOKEN_UNKNOWN, errorMessage);
    return -1;
}

%%

int yywrap(void) {
    return 1;
}
