%{
    #include <stdio.h>
    #include "syntacticAnalysis.h"
    #define MAXBUFFER 1000

    int yylex(void);
    void yyerror(char *s);
%}

%union {
    char *str;  // Para armazenar strings
    int intval; // Para armazenar inteiros, se necessário
}

%token TOKEN_RESERVED_WORD
%token <str> TOKEN_IDENTIFIER
%token <str> TOKEN_INTEGER_NUMBER
%token <str> TOKEN_FLOAT_NUMBER
%token <str> TOKEN_STRING
%token <str> TOKEN_ARITHMETIC_OP
%token <str> TOKEN_RELATIONAL_OP
%token <str> TOKEN_LOGICAL_OP
%token <str> TOKEN_DELIMITER
%token <str> TOKEN_ASSIGNMENT_OP
%token TOKEN_COMMENT_LINE
%token TOKEN_COMMENT_BLOCK
%token TOKEN_BOOLEAN
%token TOKEN_WHITESPACE
%token TOKEN_NEWLINE
%token TOKEN_UNKNOWN
%token <str> TOKEN_DATA_TYPE

%type <str> expression

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP

%%

program:
    program variable_declaration '\n'
    | program assignment '\n'
    | program expression '\n'
    | program '\n'
    |
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s%s", $1, $2, $3);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    ;

expression:
    expression TOKEN_ARITHMETIC_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_ARITHMETIC_OPERATION, buffer);
        $$ = strdup(buffer);
    }
    | expression TOKEN_RELATIONAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);
        $$ = strdup(buffer);
    }
    | expression TOKEN_LOGICAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_DELIMITER expression TOKEN_DELIMITER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER {
        $$ = strdup($1); // Identificadores
    }
    | TOKEN_INTEGER_NUMBER {
        $$ = strdup($1); // Números inteiros
    }
    | TOKEN_FLOAT_NUMBER {
        $$ = strdup($1); // Números flutuantes
    }
    ;

%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}