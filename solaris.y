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
%type <synTree> library_inclusion

%left TOKEN_LOGICAL_OP
%left TOKEN_RELATIONAL_OP
%left TOKEN_ARITHMETIC_OP
%right TOKEN_ASSIGNMENT_OP

%%

program:
    program variable_declaration '\n' {
        createProgramTree($2);
    }
    | program assignment '\n' {
        createProgramTree($2);
    }
    | program expression '\n' {
        createProgramTree($2);
    }
    | program conditional '\n' {
        createProgramTree($2);
    }
    | program loop '\n' {
        createProgramTree($2);
    }
    | program loop_while '\n' {
        createProgramTree($2);
    }
    | program comment '\n' {
        createProgramTree($2);
    }
    | program write_data '\n' {
        createProgramTree($2);
    }
    | program read_data '\n' {
        createProgramTree($2);
    }
    | program function_declaration '\n' {
        createProgramTree($2);
    }
    | program function_return '\n' {
        createProgramTree($2);
    }
    | program library_inclusion '\n' {
        createProgramTree($2);
    }
    | program '\n' {
        createProgramTree(NULL);
    }
    | /* vazio */ {
        createProgramTree(NULL);
    }
    ;

variable_declaration:
    TOKEN_DATA_TYPE TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, ";\n");
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE assignment {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2->value);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE", $1));
        addChild(variableDeclaration, $2);
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, ";\n");
        $$ = variableDeclaration;
    }
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", $1, $2, $3, $4);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", $1));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", $2));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", $3));
        addChild(variableDeclaration, createNode("TOKEN_STRING", $4));
        addChild(variableDeclaration, ";\n");
        $$ = variableDeclaration;
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE TOKEN_IDENTIFIER {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_DATA_TYPE {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
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
    | TOKEN_DATA_TYPE_STRING TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", $2, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $1));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(assignment, createNode("TOKEN_IDENTIFIER", $3));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        $$ = assignment;
    }
    | TOKEN_IDENTIFIER TOKEN_ASSIGNMENT_OP TOKEN_STRING ';' {
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
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2, $3->value, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

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
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);
        $$ = expression;
    }
    | expression TOKEN_RELATIONAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);
        $$ = expression;
    }
    | expression TOKEN_LOGICAL_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1->value, $2, $3->value);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, $1);
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", $2));
        addChild(expression, $3);
        $$ = expression;
    }
    | '(' expression ')' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", $1, $2->value, $3);
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, createNode("(", $1));
        addChild(expression, $2);
        addChild(expression, createNode(")", $3));
        $$ = expression;
    }
    | TOKEN_IDENTIFIER {
        tree expression = createNode("expression", $1);
        addChild(expression, createNode("TOKEN_IDENTIFIER", $1));
        $$ = expression;
    }
    | TOKEN_INTEGER_NUMBER {
        tree expression = createNode("expression", $1);
        addChild(expression, createNode("TOKEN_INTEGER_NUMBER", $1));
        $$ = expression;
    }
    | TOKEN_FLOAT_NUMBER {
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
        sprintf(buffer, "( %s", $2);
        sprintf(synErrorMessage, "Erro: Operacao com fechamento de parenteses incompleto '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    /* Tratamento de erro */
    | TOKEN_ARITHMETIC_OP expression {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", $1, $2);
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
        sprintf(buffer, "%s %c %s %c %c %s %c", $1, '(', $3, ')', '{', $6, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", $1));
        addChild(conditional, createNode("(", $2));
        addChild(conditional, $3);
        addChild(conditional, createNode(")", $4));
        addChild(conditional, createNode("{", $5));
        addChild(conditional, $6);
        addChild(conditional, createNode("}", $7));
        $$ = conditional;
    }
    | TOKEN_CONDITIONAL_CHOOSE '(' expression ')' '{' possible_content '}' TOKEN_CONDITIONAL_OTHERWISE '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c %s %c %s %c", $1, '(', $3, ')', '{', $6, '}', $8, '{', $10, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", $1));
        addChild(conditional, createNode("(", $2));
        addChild(conditional, $3);
        addChild(conditional, createNode(")", $4));
        addChild(conditional, createNode("{", $5));
        addChild(conditional, $6);
        addChild(conditional, createNode("}", $7));
        addChild(conditional, createNode("TOKEN_CONDITIONAL_OTHERWISE", $8));
        addChild(conditional, createNode("{", $9));
        addChild(conditional, $10);
        addChild(conditional, createNode("}", $11));
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
        addChild(possible_content, createNode("empty", " "));
        $$ = possible_content;
    }
    | possible_content '\n' {
        tree contentNode = createNode("possible_content", $1->value);
        $$ = contentNode;
    }
    | possible_content variable_declaration {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content assignment {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content conditional {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content loop {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content loop_while {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content comment {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content read_data {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    | possible_content write_data {
        tree contentNode = createNode("possible_content", $1->value);
        addChild(contentNode, $2);
        $$ = contentNode;
    }
    ;

loop:
    TOKEN_LOOP '(' loop_start ')' TOKEN_LOOP_UNTIL '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) %s ( %s ) { %s }", $1, $3, $5, $7, $10);
        processSyntacticStructure(SYN_LOOP, buffer);

        tree loop = createNode("loop", buffer);
        addChild(loop, createNode("TOKEN_LOOP", $1));
        addChild(loop, createNode("(", $2));
        addChild(loop, $3);
        addChild(loop, createNode(")", $4));
        addChild(loop, createNode("TOKEN_LOOP_UNTIL", $5));
        addChild(loop, createNode("(", $6));
        addChild(loop, $7);
        addChild(loop, createNode(")", $8));
        addChild(loop, createNode("{", $9));
        addChild(loop, $10);
        addChild(loop, createNode("}", $11));
        $$ = loop;
    }
    ;

loop_while:
    TOKEN_LOOP_WHILE '(' loop_condition ')' '{' possible_content '}' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) { %s }", $1, $3, $6);
        processSyntacticStructure(SYN_LOOP_WHILE, buffer);

        tree loop_while = createNode("loop_while", buffer);
        addChild(loop, createNode("TOKEN_LOOP_WHILE", $1));
        addChild(loop, createNode("(", $2));
        addChild(loop, $3);
        addChild(loop, createNode(")", $4));
        addChild(loop, createNode("{", $5));
        addChild(loop, $6);
        addChild(loop, createNode("}", $7));
        $$ = loop;
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
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition,$1);
        addChild(loop_condition, createNode("TOKEN_RELATIONAL_OP", $2));
        addChild(loop_condition, $3);
        $$ = loop_condition;
    }
    | loop_condition TOKEN_LOGICAL_OP loop_condition {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", $1, $2, $3);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition,$1);
        addChild(loop_condition, createNode("TOKEN_LOGICAL_OP", $2));
        addChild(loop_condition, $3);
        $$ = loop_condition;
    }
    | '(' loop_condition ')' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', $2, ')');

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition, createNode("(", $1));
        addChild(loop_condition, $2);
        addChild(loop_condition, createNode(")", $3));
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
        addChild(comment, createNode("TOKEN_COMMENT_LINE", $1));
        $$ = comment;
    }
    | TOKEN_COMMENT_BLOCK {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", $1);
        processSyntacticStructure(SYN_COMMENT_BLOCK, buffer);

        tree comment = createNode("comment", buffer);
        addChild(comment, createNode("TOKEN_COMMENT_BLOCK", $1));
        $$ = comment;
    }
    ;

write_data:
    TOKEN_SHOW TOKEN_IDENTIFIER ';' {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", $1, $2);
        processSyntacticStructure(SYN_WRITE_DATA, buffer);
        $$ = strdup(buffer);

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

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
