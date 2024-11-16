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
    statement_list
    ;

statement_list:
    statement_list statement '\n'
    | /* empty */
    ;

statement:
    variable_declaration
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER ';' {
                                processSyntacticStructure(SYN_VARIABLE_DECLARATION, "int");
                                printf("Declaracao de variavel: int %s\n", $2);
                             }
    ;

%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}