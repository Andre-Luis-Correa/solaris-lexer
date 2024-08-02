#include "lexer.h"

// Flex gera essas variáveis
extern FILE *yyin;
extern int yylex();
extern tokenList *tokenListHead;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    yyin = file;
    yylex();
    printTokens(tokenListHead);
    freeTokenList(tokenListHead);

    fclose(file);
    return 0;
}
