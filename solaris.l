%{
    #include "lexer.h"
    #include "solaris.tab.h"
%}

%option yylineno

%%
[0-9]+ {
    yylval = atoi(yytext);
    processToken(LEX_TOKEN_INTEGER_NUMBER, yytext);
    return TOKEN_INTEGER_NUMBER;
}

[-+\n]      { return *yytext; }

[ \t]       ;

.           { yyerror("Caracter invalido\n"); }

%%

int yywrap(void) {
    return 1;
}
