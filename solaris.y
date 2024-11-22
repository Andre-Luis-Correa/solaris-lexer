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
    char * str;
    tree_t *_C_treeRoot;
%}

%union tree_t {}
%union str {}

%start program

%token TOKEN_IDENTIFIER
%token TOKEN_INTEGER_NUMBER
%token TOKEN_FLOAT_NUMBER
%token TOKEN_STRING
%token TOKEN_ARITHMETIC_OP
%token TOKEN_RELATIONAL_OP
%token TOKEN_LOGICAL_OP
%token TOKEN_DELIMITER
%token TOKEN_ASSIGNMENT_OP
%token  TOKEN_CONDITIONAL_CHOOSE
%token  TOKEN_CONDITIONAL_OTHERWISE
%token  TOKEN_LOOP
%token  TOKEN_LOOP_UNTIL
%token  TOKEN_LOOP_WHILE
%token  TOKEN_DATA_TYPE
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

%type <tree> program
%type <tree> variable_declaration
%type <tree> assignment

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP
%right TOKEN_ASSIGNMENT_OP

%%

program:
    program variable_declaration '\n' {
        if (!tree) {
            printf("Árvore criada em program variable_declaration!\n");
            tree = createNode("program");
        }
        addChild(tree, createNode("FIM"));
    }
    | /* vazio */ {
        if (!tree) {
            printf("Árvore criada em empty!\n");
            tree = createNode("program");  // Inicializa a raiz
        }
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE assignment {
        // Constrói a descrição para o nó
        char buffer[MAXBUFFER];
        snprintf(buffer, MAXBUFFER, "");

        // Cria o nó da variável
        treeNode *varDecl = createNode("variable_declaration");
        addChild(varDecl, createNode("TOKEN_DATA_TYPE")); // Adiciona o tipo de dado
        addChild(varDecl, $2);                            // Adiciona o nó assignment como filho

        $$ = varDecl; // Retorna o nó criado para a regra
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        // Constrói a descrição para o nó
        char buffer[MAXBUFFER];
        snprintf(buffer, MAXBUFFER, "");

        // Cria o nó da atribuição
        treeNode *assign = createNode("assignment");
        addChild(assign, createNode("TOKEN_IDENTIFIER"));
        addChild(assign, createNode("TOKEN_ASSIGNMENT_OP"));
        addChild(assign, createNode("TOKEN_IDENTIFIER"));
        addChild(assign, createNode("TOKEN_DELIMITER"));

        $$ = assign; // Retorna o nó criado para a regra
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
