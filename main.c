#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "solaris.tab.h"
#include "syntacticAnalysis.h"

// Variáveis externas
extern FILE *yyin;
extern int yylex();

int main() {
    char filename[256];

    printf("--> Digite o nome do arquivo para análise léxica e sintática: ");
    scanf("%[^\n]", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    yyin = file;

    // Realiza a análise léxica
    printf("Iniciando analise lexica:\n");
    while (yylex() != 0);  // Chama yylex() até terminar

    // Imprime os tokens após análise léxica
    printf("Tokens Identificados:\n");
    printTokens(reservedWordListHead, "Palavras Reservadas");
    printTokens(otherTokensListHead, "Outros Tokens");
    printSyntacticStructures(syntacticStructureListHead, "Estruturas Sintaticas Reconhecidas");

    // Realiza a análise sintática
    fseek(file, 0, SEEK_SET); // Reinicia o ponteiro do arquivo
    if (yyparse() == 0 && errorFlag == 0) {
        printf("Analise sintática bem-sucedida.\n");
    } else {
        printf("Erros encontrados durante a analise.\n");
    }

    freeTokenList(reservedWordListHead);
    freeTokenList(otherTokensListHead);
    fclose(file);

    return 0;
}
