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

%%

program:
    program variable_declaration '\n'
    | program assignment '\n'
    | program operators '\n'
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

operators:
    TOKEN_ARITHMETIC_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_ARITHMETIC_OPERATION, buffer);
    }
    | TOKEN_RELATIONAL_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);
    }
    | TOKEN_LOGICAL_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMBINED_LOGICAL_OPERATION, buffer);
    }
    ;
%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}