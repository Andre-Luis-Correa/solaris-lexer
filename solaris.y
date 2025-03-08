%{
    #include <stdio.h>
    #include "lexer.h"
    #include "syntacticAnalysis.h"
    #include "semanticAnalysis.h"
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
%token <str> TOKEN_DATA_TYPE_INTEGER
%token <str> TOKEN_DATA_TYPE_FLOAT
%token <str> TOKEN_DATA_TYPE_DOUBLE
%token <str> TOKEN_DATA_TYPE_BOOLEAN
%token <str> TOKEN_COMMENT_LINE
%token <str> TOKEN_COMMENT_BLOCK
%token <str> TOKEN_SHOW
%token <str> TOKEN_READ
%token <str> TOKEN_FUNCTION
%token <str> TOKEN_FUNCTION_RECEIVE
%token <str> TOKEN_FUNCTION_RETURN
%token <str> TOKEN_USE
%token <str> TOKEN_CALL

%token TOKEN_BOOLEAN
%token TOKEN_UNKNOWN

%type <synTree> program
%type <synTree> variable_declaration
%type <synTree> assignment
%type <synTree> expression
%type <synTree> conditional
%type <synTree> possible_content
%type <synTree> loop
%type <synTree> loop_while
%type <synTree> loop_start
%type <synTree> loop_condition
%type <synTree> comment
%type <synTree> write_data
%type <synTree> read_data
%type <synTree> function_declaration
%type <synTree> function_return
%type <synTree> function_parameter
%type <synTree> function_call
%type <synTree> library_inclusion

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP
%right TOKEN_ASSIGNMENT_OP

%%

program:
    program variable_declaration '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program assignment '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program expression '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program conditional '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program loop '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program loop_while '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program comment '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program write_data '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program read_data '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program function_declaration '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program function_return '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program function_call '\n' {
        if (!synTree) synTree = createNode("function_call", $2->value);
        addChild(synTree, $2);
    }
    | program library_inclusion '\n' {
        if (!synTree) synTree = createNode("program", $2->value);
        addChild(synTree, $2);
    }
    | program '\n' {

    }
    | /* vazio */ {
        if (!synTree) synTree = createNode("program", " ");
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER ';' {
        // Análise semântica: verifica se a variável está na tabela de símbolos e atualiza a categoria e tipo de dado
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_INTEGER);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_INTEGER", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER ';' {
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_FLOAT);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_FLOAT", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER ';' {
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_STRING);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER ';' {
            // Análise semântica
            checkDeclarationExists($2, yylineno);
            updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_INTEGER);
            updateSymbolValue($2, $4, TYPE_INTEGER);
            updateSymbolCategoryAndDataType($4, CONSTANT, TYPE_INTEGER);
            updateSymbolValue($4, $4, TYPE_INTEGER);

            // Análise sintática
            char buffer[MAXBUFFER];
            sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
            processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

            // Criação do nó da árvore sintática
            tree variableDeclaration = createNode("variable_declaration", buffer);
            addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_INTEGER", $1));
            addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
            addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
            addChild(variableDeclaration, createNode("TOKEN_INTEGER_NUMBER", $4));
            addChild(variableDeclaration, createNode(";", ";\n"));
            $$ = variableDeclaration;
        }
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER ';' {
            // Análise semântica: define a categoria, tipo de dado e valor associado ao 1° identificador da regra
            checkDeclarationExists($2, yylineno);
            updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_FLOAT);
            updateSymbolValue($2, $4, TYPE_FLOAT);
            updateSymbolCategoryAndDataType($4, CONSTANT, TYPE_FLOAT);
            updateSymbolValue($4, $4, TYPE_FLOAT);

            // Análise sintática
            char buffer[MAXBUFFER];
            sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
            processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

            // Criação do nó da árvore sintática
            tree variableDeclaration = createNode("variable_declaration", buffer);
            addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_FLOAT", $1));
            addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
            addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
            addChild(variableDeclaration, createNode("TOKEN_FLOAT_NUMBER", $4));
            addChild(variableDeclaration, createNode(";", ";\n"));
            $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        // Análise semântica: define a categoria, tipo de dado e valor associado ao 1° identificador da regra
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_STRING);
        updateSymbolValue($2, $4, TYPE_STRING);
        updateSymbolCategoryAndDataType($4, CONSTANT, TYPE_STRING);
        updateSymbolValue($4, $4, TYPE_STRING);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, createNode("TOKEN_STRING", $4));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        // Análise semântica
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_INTEGER);
        checkDeclarationNotExists($2, yylineno);
        checkDeclarationNotExists($4, yylineno);
        dataType dataTypeLeft = getSymbolDataType($2);
        dataType dataTypeRight = getSymbolDataType($4);
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($2, $4, TYPE_IDENTIFIER);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_INTEGER", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $4));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        // Análise semântica
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_FLOAT);
        checkDeclarationNotExists($2, yylineno);
        checkDeclarationNotExists($4, yylineno);
        dataType dataTypeLeft = getSymbolDataType($2);
        dataType dataTypeRight = getSymbolDataType($4);
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($2, $4, TYPE_IDENTIFIER);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_FLOAT", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $4));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        // Análise semântica
        checkDeclarationExists($2, yylineno);
        updateSymbolCategoryAndDataType($2, VARIABLE, TYPE_STRING);
        checkDeclarationNotExists($2, yylineno);
        checkDeclarationNotExists($4, yylineno);
        dataType dataTypeLeft = getSymbolDataType($2);
        dataType dataTypeRight = getSymbolDataType($4);
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($2, $4, TYPE_IDENTIFIER);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $4));
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression ';' {
        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4->value);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_INTEGER", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, $4);
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression ';' {
        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4->value);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        // Criação do nó da árvore sintática
        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_FLOAT", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, $4);
        addChild(variableDeclaration, createNode(";", ";\n"));
        $$ = variableDeclaration;
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_INTEGER {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_FLOAT {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_STRING {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_INTEGER TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_FLOAT TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        checkDeclarationNotExists($1, yylineno);
        checkDeclarationNotExists($3, yylineno);
        dataType dataTypeLeft = getSymbolDataType($1);
        dataType dataTypeRight = getSymbolDataType($3);
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($1, $3, TYPE_IDENTIFIER);

        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        // Criação do nó da árvore sintática
        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        checkDeclarationNotExists($1, yylineno);
        dataType dataTypeLeft = getSymbolDataType($1);
        dataType dataTypeRight = TYPE_STRING;
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($1, $3, TYPE_STRING);
        updateSymbolValue($3, $3, TYPE_STRING);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_STRING", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER ';' {
        checkDeclarationNotExists($1, yylineno);
        dataType dataTypeLeft = getSymbolDataType($1);
        dataType dataTypeRight = TYPE_INTEGER;
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($1, $3, TYPE_INTEGER);
        updateSymbolValue($3, $3, TYPE_INTEGER);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_INTEGER_NUMBER", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));
        $$ = assignment;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER ';' {
        checkDeclarationNotExists($1, yylineno);
        dataType dataTypeLeft = getSymbolDataType($1);
        dataType dataTypeRight = TYPE_FLOAT;
        checkExpressionHasCompatibleTypes(dataTypeLeft, dataTypeRight, yylineno);
        updateSymbolValue($1, $3, TYPE_FLOAT);
        updateSymbolValue($3, $3, TYPE_FLOAT);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_FLOAT_NUMBER", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression ';' {
        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3->value, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        // Ciração do nó da árvore sintática
        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, $3);
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_FLOAT_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2);
        sprintf(synErrorMessage, "Erro: Atribuicao incompleta [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    ;

expression:
    expression TOKEN_ARITHMETIC_OP expression {
        // Análise sintática
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_ARITHMETIC_OPERATION, buffer);

        // Criação do nó da árvore sintática
        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);

        $$ = expression;
    }
    | expression TOKEN_RELATIONAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);
        $$ = expression;
    }
    | expression TOKEN_LOGICAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);
        $$ = expression;
    }
    | '(' expression ')' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "( %s )", $2->value);
        processSyntacticStructure(SYN_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, createNode("(", "("));
        addChild(expression, $2);
        addChild(expression, createNode(")", ")"));
        $$ = expression;
    }
    | TOKEN_IDENTIFIER {
        // Análise semântica: atualiza a categoria, tipo do valor e valor
        // checkDeclarationNotExists($1, yylineno);

        // Criação do nó da árvore sintática
        tree expression = createNode("expression", $1);
        addChild(expression, createNode("TOKEN_IDENTIFIER", $1));
        $$ = expression;
    }
    | TOKEN_INTEGER_NUMBER {
        // Análise semântica: atualiza a categoria, tipo do valor e valor
        // updateSymbolCategoryAndDataType($1, CONSTANT, TYPE_INTEGER);
        // updateSymbolValue($1, $1, TYPE_INTEGER);

        // Criação do nó da árvore sintática
        tree expression = createNode("expression", $1);
        addChild(expression, createNode("TOKEN_INTEGER_NUMBER", $1));
        $$ = expression;
    }
    | TOKEN_FLOAT_NUMBER {
        // Análise semântica: atualiza a categoria, tipo do valor e valor
        // updateSymbolCategoryAndDataType($1, CONSTANT, TYPE_FLOAT);
        // updateSymbolValue($1, $1, TYPE_FLOAT);

        // Criação do nó da árvore sintática
        tree expression = createNode("expression", $1);
        addChild(expression, createNode("TOKEN_FLOAT_NUMBER", $1));
        $$ = expression;
    }
    /* Tratamento de erro */
    | expression TOKEN_ARITHMETIC_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2);
        sprintf(synErrorMessage, "Erro: Operacao incompleta apos operador '%s' na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | '(' ')' {
        sprintf(synErrorMessage, "Erro: Operacao incompleta entre parenteses na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | '(' expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "( %s", $2->value);
        sprintf(synErrorMessage, "Erro: Operacao com fechamento de parenteses incompleto '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_ARITHMETIC_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2->value);
        sprintf(synErrorMessage, "Erro: Operacao incompleta '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_ARITHMETIC_OP {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        sprintf(synErrorMessage, "Erro: Operacao '%s' sem operandos na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    ;

conditional:
    TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c", $1, '(', $3->value, ')', '{', $6->value, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", $1));
        addChild(conditional, createNode("(", "("));
        addChild(conditional, $3);
        addChild(conditional, createNode(")", ")"));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, $6);
        addChild(conditional, createNode("}", "}\n"));
        $$ = conditional;
    }
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' TOKEN_CONDITIONAL_OTHERWISE '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c %s %c %s %c", $1, '(', $3->value, ')', '{', $6->value, '}', $8, '{', $10->value, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", $1));
        addChild(conditional, createNode("(", "("));
        addChild(conditional, $3);
        addChild(conditional, createNode(")", ")"));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, $6);
        addChild(conditional, createNode("}", "}"));
        addChild(conditional, createNode("TOKEN_CONDITIONAL_OTHERWISE", $8));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, $10);
        addChild(conditional, createNode("}", "}\n"));
        $$ = conditional;
    }
    /* Tratamento de erro */
    | TOKEN_CONDITIONAL_CHOOSE '(' expression {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de parenteses no condicional na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_CONDITIONAL_CHOOSE '(' ')' {
        sprintf(synErrorMessage, "Erro: Condicional sem expressao na linha %d\n", yylineno +1 );
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' {
        sprintf(synErrorMessage, "Erro: Falta de abertura de bloco '{' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' TOKEN_CONDITIONAL_OTHERWISE {
        sprintf(synErrorMessage, "Erro: Bloco 'otherwise' incompleto na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de bloco '}' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    ;

possible_content:
    /* vazio */ {
        tree possible_content = createNode("possible_content", " ");
        $$ = possible_content;
    }
    | possible_content '\n' {
        addChild($1, createNode("\\n", "\\n"));
        $$ = $1;
    }
    | possible_content variable_declaration {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content assignment {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content conditional {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content loop {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content loop_while {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content comment {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content read_data {
        addChild($1, $2);
        $$ = $1;
    }
    | possible_content write_data {
        addChild($1, $2);
        $$ = $1;
    }
    ;

loop:
    TOKEN_LOOP '(' loop_start ')' TOKEN_LOOP_UNTIL '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) %s ( %s ) { %s }", $1, $3->value, $5, $7->value, $10->value);
        processSyntacticStructure(SYN_LOOP, buffer);

        tree loop = createNode("loop", buffer);
        addChild(loop, createNode("TOKEN_LOOP", $1));
        addChild(loop, createNode("(", "("));
        addChild(loop, $3);
        addChild(loop, createNode(")", ")"));
        addChild(loop, createNode("TOKEN_LOOP_UNTIL", $5));
        addChild(loop, createNode("(", "("));
        addChild(loop, $7);
        addChild(loop, createNode(")", ")"));
        addChild(loop, createNode("{", "{"));
        addChild(loop, $10);
        addChild(loop, createNode("}", "}\n"));
        $$ = loop;
    }
    ;

loop_while:
    TOKEN_LOOP_WHILE '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) { %s }", $1, $3->value, $6->value);
        processSyntacticStructure(SYN_LOOP_WHILE, buffer);

        tree loop_while = createNode("loop_while", buffer);
        addChild(loop_while, createNode("TOKEN_LOOP_WHILE", $1));
        addChild(loop_while, createNode("(", "("));
        addChild(loop_while, $3);
        addChild(loop_while, createNode(")", ")"));
        addChild(loop_while, createNode("{", "{"));
        addChild(loop_while, $6);
        addChild(loop_while, createNode("}", "}\n"));
        $$ = loop_while;
    }
    ;

loop_start:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", $1));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(loop_start, createNode("TOKEN_INTEGER_NUMBER", $3));
        $$ = loop_start;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", $1));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", $3));
        $$ = loop_start;
    }
    | TOKEN_DATA_TYPE TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_INTEGER_NUMBER {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_DATA_TYPE", $1));
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", $2));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(loop_start, createNode("TOKEN_INTEGER_NUMBER", $4));
        $$ = loop_start;
    }
    ;

loop_condition:
    loop_condition TOKEN_RELATIONAL_OP loop_condition {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition,$1);
        addChild(loop_condition, createNode("TOKEN_RELATIONAL_OP", $2));
        addChild(loop_condition, $3);
        $$ = loop_condition;
    }
    | loop_condition TOKEN_LOGICAL_OP loop_condition {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition, $1);
        addChild(loop_condition, createNode("TOKEN_LOGICAL_OP", $2));
        addChild(loop_condition, $3);
        $$ = loop_condition;
    }
    | '(' loop_condition ')' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', $2->value, ')');

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition, createNode("(", "("));
        addChild(loop_condition, $2);
        addChild(loop_condition, createNode(")", ")"));
        $$ = loop_condition;
    }
    | TOKEN_IDENTIFIER {
        tree loop_condition = createNode("loop_condition", $1);
        addChild(loop_condition, createNode("TOKEN_IDENTIFIER", $1));
        $$ = loop_condition;
    }
    | TOKEN_INTEGER_NUMBER {
        tree loop_condition = createNode("loop_condition", $1);
        addChild(loop_condition, createNode("TOKEN_INTEGER_NUMBER", $1));
        $$ = loop_condition;
    }
    | TOKEN_FLOAT_NUMBER {
        tree loop_condition = createNode("loop_condition", $1);
        addChild(loop_condition, createNode("TOKEN_FLOAT_NUMBER", $1));
        $$ = loop_condition;
    }
    ;

comment:
    TOKEN_COMMENT_LINE {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMMENT_LINE, buffer);

        tree comment = createNode("comment", buffer);
        addChild(comment, createNode("TOKEN_COMMENT_LINE", strcat($1, "\n")));
        $$ = comment;
    }
    | TOKEN_COMMENT_BLOCK {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMMENT_BLOCK, buffer);

        tree comment = createNode("comment", buffer);
        addChild(comment, createNode("TOKEN_COMMENT_BLOCK", strcat($1, "\n")));
        $$ = comment;
    }
    ;

write_data:
    TOKEN_SHOW TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_WRITE_DATA, buffer);

        tree write_data = createNode("write_data", buffer);
        addChild(write_data, createNode("TOKEN_SHOW", $1));
        addChild(write_data, createNode("TOKEN_IDENTIFIER", $2));
        addChild(write_data, createNode(";", ";\n"));
        $$ = write_data;
    }
    | TOKEN_SHOW TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_WRITE_DATA, buffer);

        tree write_data = createNode("write_data", buffer);
        addChild(write_data, createNode("TOKEN_SHOW", $1));
        addChild(write_data, createNode("TOKEN_STRING", $2));
        addChild(write_data, createNode(";", ";\n"));
        $$ = write_data;
    }
    ;

read_data:
    TOKEN_READ TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_READ_DATA, buffer);

        tree read_data = createNode("read_data", buffer);
        addChild(read_data, createNode("TOKEN_READ", $1));
        addChild(read_data, createNode("TOKEN_IDENTIFIER", $2));
        addChild(read_data, createNode(";", ";\n"));
        $$ = read_data;
    }
    ;

function_declaration:
    TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_INTEGER ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_INTEGER);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_INTEGER, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_INTEGER", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_INTEGER ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '\n' '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_INTEGER);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_INTEGER, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_INTEGER", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_FLOAT ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_FLOAT);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_FLOAT, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_FLOAT", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_FLOAT ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '\n' '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_FLOAT);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_FLOAT, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_FLOAT", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_STRING ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_STRING);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_STRING, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_STRING", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    | TOKEN_FUNCTION '(' TOKEN_DATA_TYPE_STRING ')' ':' TOKEN_IDENTIFIER TOKEN_FUNCTION_RECEIVE '(' function_parameter ')' '{' possible_content function_return '\n' '}' {
        checkFunctionDeclarationExists($6, yylineno);
        updateSymbolCategoryAndDataType($6, FUNCTION, TYPE_STRING);
        dataType returnDataType = getSymbolDataType($13->children[1]->value);
        checkFunctionReturnType(TYPE_STRING, returnDataType, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", $1, $3, $6, $7, $9->value, $12->value, $13->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", $1));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE_STRING", $3));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", $6));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", $7));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, $9);
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, $12);
        addChild(function_declaration, $13);
        addChild(function_declaration, createNode("}", "}"));
        $$ = function_declaration;
    }
    ;

function_parameter:
    /* vazio */ {
        tree function_parameter = createNode("function_parameter", " ");
        $$ = function_parameter;
    }
    | TOKEN_IDENTIFIER {
        checkDeclarationNotExists($1, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);

        tree function_parameter = createNode("function_parameter", buffer);
        addChild(function_parameter, createNode("TOKEN_IDENTIFIER", $1));
        $$ = function_parameter;
    }
    | function_parameter ',' TOKEN_IDENTIFIER {
        checkDeclarationNotExists($3, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s, %s", $1->value, $3);

        tree function_parameter = createNode("function_parameter", buffer);
        addChild(function_parameter, $1);
        addChild(function_parameter, createNode(",", ","));
        addChild(function_parameter, createNode("TOKEN_IDENTIFIER", $3));
        $$ = function_parameter;
    }
    ;

function_return:
    TOKEN_FUNCTION_RETURN TOKEN_IDENTIFIER ';' {
        checkDeclarationNotExists($2, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", $1));
        addChild(function_return, createNode("TOKEN_IDENTIFIER", $2));
        addChild(function_return, createNode(";", ";\n"));
        $$ = function_return;
    }
    | TOKEN_FUNCTION_RETURN TOKEN_STRING ';' {
        updateSymbolCategoryAndDataType($2, CONSTANT, TYPE_STRING);
        updateSymbolValue($2, $2, TYPE_STRING);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", $1));
        addChild(function_return, createNode("TOKEN_STRING", $2));
        addChild(function_return, createNode(";", ";\n"));
        $$ = function_return;
    }
    | TOKEN_FUNCTION_RETURN TOKEN_INTEGER_NUMBER ';' {
        updateSymbolCategoryAndDataType($2, CONSTANT, TYPE_INTEGER);
        updateSymbolValue($2, $2, TYPE_INTEGER);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", $1));
        addChild(function_return, createNode("TOKEN_INTEGER_NUMBER", $2));
        addChild(function_return, createNode(";", ";\n"));
        $$ = function_return;
    }
    | TOKEN_FUNCTION_RETURN TOKEN_FLOAT_NUMBER ';' {
        updateSymbolCategoryAndDataType($2, CONSTANT, TYPE_FLOAT);
        updateSymbolValue($2, $2, TYPE_FLOAT);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", $1));
        addChild(function_return, createNode("TOKEN_FLOAT_NUMBER", $2));
        addChild(function_return, createNode(";", ";\n"));
        $$ = function_return;
    }
    ;

function_call:
    TOKEN_CALL TOKEN_IDENTIFIER '(' function_parameter ')' ';' {
        checkFunctionDeclarationNotExists($2, yylineno);
        category identifierCategory = getSymbolCategory($2);
        verifyFunctionCategory(identifierCategory, yylineno);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s ( %s ) ;", $1, $2, $4->value);
        processSyntacticStructure(SYN_FUNCTION_CALL, buffer);

        tree function_call = createNode("function_call", buffer);
        addChild(function_call, createNode("TOKEN_CALL", $1));
        addChild(function_call, createNode("TOKEN_IDENTIFIER", $2));
        addChild(function_call, createNode("(", "("));
        addChild(function_call, $4);
        addChild(function_call, createNode(")", ")"));
        addChild(function_call, createNode(";", ";\n"));

        $$ = function_call;
    };

library_inclusion:
    TOKEN_USE TOKEN_STRING {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_LIBRARY_INCLUSION, buffer);

        tree library_inclusion = createNode("library_inclusion", buffer);
        addChild(library_inclusion, createNode("TOKEN_USE", $1));
        addChild(library_inclusion, createNode("TOKEN_STRING", $2));
        addChild(library_inclusion, createNode(";", ";\n"));
        $$ = library_inclusion;
    }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
