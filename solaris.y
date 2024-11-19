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
%token <str> TOKEN_CONDITIONAL_CHOOSE
%token <str> TOKEN_CONDITIONAL_OTHERWISE

%token TOKEN_BOOLEAN

%token TOKEN_UNKNOWN
%token <str> TOKEN_DATA_TYPE

%type <str> expression
%type <str> conditional

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP
%right TOKEN_ASSIGNMENT_OP

%%

program:
    program variable_declaration '\n'
    | program assignment '\n'
    | program expression '\n'
    | program conditional '\n'
    | program '\n'
    |
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s%c", $1, $2, ';');
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
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
        $$ = strdup(buffer);
    }
    | '(' expression ')' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', $2, ')');
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER {
        $$ = strdup($1);
    }
    | TOKEN_INTEGER_NUMBER {
        $$ = strdup($1);
    }
    | TOKEN_FLOAT_NUMBER {
        $$ = strdup($1);
    }
    ;

conditional:
    TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %c", $1, '(', $3, ')', '{', '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);
        $$ = strdup(buffer);
    }
    ;

%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}