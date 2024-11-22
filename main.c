#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "file.h"
#include "tree.h"
#include "syntacticAnalysis.h"
#include "solaris.tab.h"

extern FILE *yyin;
extern int yylex();

int main() {
    char inputFileName[256];
    char fileName[256];

    printf("\n\n--> Digite o nome do arquivo para analise LEXICA e SINTATICA sem extensao (.txt): ");
    scanf("%[^\n]%", inputFileName);
    sprintf(fileName, "%s.txt", inputFileName);

    FILE *file = openFile(fileName, "r");
    yyin = file;

    while (yylex() != 0);
    if (errorFlag == 0) {
        printf("\n\nTokens Identificados:\n");
        printTokens(reservedWordListHead, "Palavras Reservadas");
        printTokens(otherTokensListHead, "Outros Tokens");
    } else {
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    if (yyparse() == 0) {
        printf("\n\nEstruturas Sintaticas Identificadas:\n");
        printSyntacticStructures(syntacticStructureListHead, "Estruturas Sintaticas Reconhecidas");

        char outputFileName[256];
        snprintf(outputFileName, sizeof(outputFileName), "arvores_%s.txt", inputFileName);

        FILE * outputFile = openFile(outputFileName, "w");

        if (synTree) {
            writeTreeToFile(synTree, outputFile, 0);
        } else {
            printf("Nenhuma árvore sintática gerada.\n");
        }

        fclose(outputFile);
        printf("\n\nArvore sintatica salva com sucesso em %s.\n\n", outputFileName);

    } else {
        fclose(file);
        return 0;
    }

    if(reservedWordListHead) freeTokenList(reservedWordListHead);
    if(otherTokensListHead) freeTokenList(otherTokensListHead);
    if(syntacticStructureListHead) freeSyntacticStructureList(syntacticStructureListHead);
    if(synTree) freeTree(synTree);

    fclose(file);
    return 0;
}
