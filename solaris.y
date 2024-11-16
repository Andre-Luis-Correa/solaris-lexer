%{
    #include <stdio.h>
    #include "syntacticAnalysis.h"

    int yylex(void);
    void yyerror(char *s);
%}

%token TOKEN_RESERVED_WORD
%token TOKEN_IDENTIFIER
%token TOKEN_INTEGER_NUMBER
%token TOKEN_FLOAT_NUMBER
%token TOKEN_STRING
%token TOKEN_ARITHMETIC_OP
%token TOKEN_RELATIONAL_OP
%token TOKEN_LOGICAL_OP
%token TOKEN_DELIMITER
%token TOKEN_ASSIGNMENT_OP
%token TOKEN_COMMENT_LINE
%token TOKEN_COMMENT_BLOCK
%token TOKEN_BOOLEAN
%token TOKEN_WHITESPACE
%token TOKEN_NEWLINE
%token TOKEN_UNKNOWN
%token TOKEN_DATA_TYPE

%%

program:
    statement_list {
        printf("Entrou na regra 'program'.\n");
    }
    ;

statement_list:
    statement_list statement '\n' {
        printf("Entrou na regra 'statement_list' com uma nova statement.\n");
    }
    | /* empty */ {
        printf("Entrou na regra 'statement_list' vazia.\n");
    }
    ;

statement:
    variable_declaration {
        printf("Entrou na regra 'statement' com uma declaracao de variavel.\n");
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER ';' {
        // Define um buffer de tamanho fixo para a string concatenada
        char buffer[256];

        // Formata e concatena as strings $1 e $2 no buffer
        sprintf(buffer, "%s %s;", $1, $2);

        // Processa a estrutura sintática com a string concatenada
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Imprime a string concatenada para depuração
        printf("Reconheceu uma declaracao de variavel: %s\n", buffer);
    }
    ;


%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}