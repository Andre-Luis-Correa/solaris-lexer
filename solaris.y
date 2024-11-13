%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *s);
%}

%token TOKEN_INTEGER_NUMBER

%%

//program -> program exp \n  | lambda
program:
    program exp '\n'{
                        $$ = $2;
                        printf("O valor de exp (%d) subiu para o pai program(%d)\n", $2, $$);
                    }
    |               //lambda
    ;

//expr -> expr + expr  | expr - expr  |  INTEGER
exp:
      exp '+' exp   {
                        $$ = $1 + $3;
                        printf("O resultado de exp(%d) + exp(%d) subiu para o pai exp(%d)\n", $1, $3, $$);
                    }
    | exp '-' exp   {
                        $$ = $1 - $3;
                        printf("O resultado de exp(%d) - exp(%d) subiu para o pai exp(%d)\n", $1, $3, $$);
                    }
    | TOKEN_INTEGER_NUMBER       {
                        printf("Achei um inteiro: %d\n", $1);
                        $$ = $1;
                        printf("O inteiro %d subiu para o pai exp(%d)\n", $1, $$);
                    }
    ;

%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}