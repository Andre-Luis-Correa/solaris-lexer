%{
    #include <stdio.h>
    #include "syntacticAnalysis.h"
    #include "tree.h"

    #define MAXBUFFER 1000

    int yylex(void);
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char *s);

    char synErrorMessage[MAXBUFFER];
%}

%union {
    char * str;
    struct treeNode * synTree;
}

%token TOKEN_RESERVED_WORD
%token <str> TOKEN_IDENTIFIER
%token TOKEN_INTEGER_NUMBER
%token TOKEN_FLOAT_NUMBER
%token TOKEN_STRING
%token TOKEN_ARITHMETIC_OP
%token TOKEN_RELATIONAL_OP
%token TOKEN_LOGICAL_OP
%token TOKEN_DELIMITER
%token <str> TOKEN_ASSIGNMENT_OP
%token  TOKEN_CONDITIONAL_CHOOSE
%token  TOKEN_CONDITIONAL_OTHERWISE
%token  TOKEN_LOOP
%token  TOKEN_LOOP_UNTIL
%token  TOKEN_LOOP_WHILE
%token <str> TOKEN_DATA_TYPE
%token  TOKEN_DATA_TYPE_STRING
%token  TOKEN_COMMENT_LINE
%token  TOKEN_COMMENT_BLOCK
%token  TOKEN_SHOW
%token  TOKEN_READ
%token  TOKEN_FUNCTION
%token  TOKEN_FUNCTION_RECEIVE
%token  TOKEN_FUNCTION_RETURN
%token  TOKEN_USE

%token TOKEN_BOOLEAN
%token TOKEN_UNKNOWN

%type<synTree> program
%type<synTree> variable_declaration
%type<synTree> assignment

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP
%right TOKEN_ASSIGNMENT_OP

%%

program:
    program variable_declaration '\n' {
        if (!synTree) {
            synTree = createNode("program", $2->value);
        }
        addChild(synTree, $2);
    }
    | /* vazio */ {
        if (!synTree) {
            printf("Árvore criada em empty!\n");
            synTree = createNode("program", "empty");  // Inicializa a raiz
        }
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE assignment {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2->value);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE", $1));
        addChild(variableDeclaration, $2);
        $$ = variableDeclaration;
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
