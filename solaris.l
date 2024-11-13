%{
    #include <stdio.h>
    #include "solaris.tab.h"
%}

%%
[0-9]+ {
    yylval = atoi(yytext);
    return TOKEN_INTEGER_NUMBER;
}

[-+\n]      { return *yytext; }

[ \t]       ;

.           { yyerror("Caracter invalido\n"); }

%%

int yywrap(void) {
    return 1;
}
