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
%token <str> TOKEN_LOOP
%token <str> TOKEN_LOOP_UNTIL
%token <str> TOKEN_LOOP_WHILE
%token <str> TOKEN_DATA_TYPE
%token <str> TOKEN_DATA_TYPE_STRING
%token <str> TOKEN_COMMENT_LINE
%token <str> TOKEN_COMMENT_BLOCK
%token <str> TOKEN_SHOW
%token <str> TOKEN_READ
%token <str> TOKEN_FUNCTION
%token <str> TOKEN_FUNCTION_RECEIVE
%token <str> TOKEN_FUNCTION_RETURN
%token <str> TOKEN_USE

%token TOKEN_BOOLEAN
%token TOKEN_UNKNOWN

%type <str> variable_declaration
%type <str> assignment
%type <str> expression
%type <str> conditional
%type <str> possible_content
%type <str> loop
%type <str> loop_while
%type <str> loop_start
%type <str> loop_condition
%type <str> comment
%type <str> write_data
%type <str> read_data
%type <str> function_declaration
%type <str> function_return
%type <str> function_parameter
%type <str> library_inclusion

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
    | program loop '\n'
    | program loop_while '\n'
    | program comment '\n'
    | program write_data '\n'
    | program read_data '\n'
    | program function_declaration '\n'
    | program function_return '\n'
    | program library_inclusion '\n'
    | program '\n'
    |
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s%c", $1, $2, ';');
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_DATA_TYPE assignment {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_STRING_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_STRING_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
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
    TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c", $1, '(', $3, ')', '{', $6, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' TOKEN_CONDITIONAL_OTHERWISE '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c %s %c %s %c", $1, '(', $3, ')', '{', $6, '}', $8, '{', $10, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);
        $$ = strdup(buffer);
    }
    ;

possible_content:
    /* vazio */ {
        $$ = strdup("");
    }
    | possible_content '\n' {
        $$ = strdup("\n");
    }
    | possible_content variable_declaration {
        $$ = strdup($2);
    }
    | possible_content assignment {
        $$ = strdup($2);
    }
    | possible_content conditional {
        $$ = strdup($2);
    }
    | possible_content loop {
        $$ = strdup($2);
    }
    | possible_content loop_while {
        $$ = strdup($2);
    }
    | possible_content comment {
        $$ = strdup($2);
    }
    | possible_content read_data {
        $$ = strdup($2);
    }
    | possible_content write_data {
        $$ = strdup($2);
    }
    ;

loop:
    TOKEN_LOOP '(' loop_start ')' TOKEN_LOOP_UNTIL '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) %s ( %s ) { %s }", $1, $3, $5, $7, $10);
        processSyntacticStructure(SYN_LOOP, buffer);
        $$ = strdup(buffer);
    }
    ;

loop_while:
    TOKEN_LOOP_WHILE '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) { %s }", $1, $3, $6);
        processSyntacticStructure(SYN_LOOP_WHILE, buffer);
        $$ = strdup(buffer);
    }
    ;

loop_start:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_DATA_TYPE TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    ;

loop_condition:
    loop_condition TOKEN_RELATIONAL_OP loop_condition {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);
        $$ = strdup(buffer);
    }
    | loop_condition TOKEN_LOGICAL_OP loop_condition {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        $$ = strdup(buffer);
    }
    | '(' loop_condition ')' {
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

comment:
    TOKEN_COMMENT_LINE {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMMENT_LINE, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_COMMENT_BLOCK {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMMENT_BLOCK, buffer);
        $$ = strdup(buffer);
    }
    ;

write_data:
    TOKEN_SHOW TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_WRITE_DATA, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_SHOW TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_WRITE_DATA, buffer);
        $$ = strdup(buffer);
    }
    ;

read_data:
    TOKEN_READ TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_READ_DATA, buffer);
        $$ = strdup(buffer);
    }
    ;

function_declaration:
    TOKEN_FUNCTION '(' TOKEN_DATA_TYPE ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s; }", $1, $3, $6, $7, $9, $12);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '\n' '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s; }", $1, $3, $6, $7, $9, $12);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);
        $$ = strdup(buffer);
    }
    ;

function_parameter:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2);
        $$ = strdup(buffer);
    }
    | function_parameter ',' TOKEN_DATA_TYPE TOKEN_IDENTIFIER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s, %s %s", $1, $3, $4);
        $$ = strdup(buffer);
    }
    ;

function_return:
    TOKEN_FUNCTION_RETURN TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_FUNCTION_RETURN TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_FUNCTION_RETURN TOKEN_INTEGER_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        $$ = strdup(buffer);
    }
    | TOKEN_FUNCTION_RETURN TOKEN_FLOAT_NUMBER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        $$ = strdup(buffer);
    }
    ;

library_inclusion:
    TOKEN_USE TOKEN_STRING {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_LIBRARY_INCLUSION, buffer);
        $$ = strdup(buffer);
    }

%%

void yyerror(char *s){
    printf("Caracter invalido: %s\n", s);
}