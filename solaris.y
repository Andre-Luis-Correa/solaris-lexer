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
            printf("Árvore criada em program variable_declaration!\n");
            synTree = createNode("program");
        }
        addChild(synTree, $2);
    }
    | /* vazio */ {
        if (!synTree) {
            printf("Árvore criada em empty!\n");
            synTree = createNode("program");  // Inicializa a raiz
        }
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE assignment {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2->label);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        char * treeNodeDescription = buildTreeNodeDescription("variable_declaration", buffer);
        tree variableDeclaratioan = createNode(treeNodeDescription);
        free(treeNodeDescription);

        addChild(variableDeclaratioan, createNode("TOKEN_DATA_TYPE")); // Adiciona o tipo de dado
        addChild(variableDeclaratioan, $2);                            // Adiciona o nó assignment como filho

        $$ = variableDeclaratioan; // Retorna o nó criado para a regra
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        char * treeNodeDescription = buildTreeNodeDescription("assignment", buffer);
        tree assignment = createNode(treeNodeDescription);
        free(treeNodeDescription);

        tree assign = createNode("assignment");
        addChild(assignment, createNode("TOKEN_IDENTIFIER"));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP"));
        addChild(assignment, createNode("TOKEN_IDENTIFIER"));
        addChild(assignment, createNode("TOKEN_DELIMITER"));

        $$ = assignment; // Retorna o nó criado para a regra
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
