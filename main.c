#include <stdio.h>
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
    scanf("%[^\n]%*c", inputFileName);
    sprintf(fileName, "%s.txt", inputFileName);

    FILE *file = openFile(fileName, "r");
    yyin = file;

    while (yylex() != 0);
    if (errorFlag == 0) {
        printTokenLists(reservedWordListHead, symbolTable);
    } else {
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    if (yyparse() == 0) {
        printSyntacticStructuresList(syntacticStructureListHead);
        printTokens(symbolTable, "Tabela de Simbolos");
        writeTreeToTxtFile(inputFileName, synTree);
    } else {
        fclose(file);
        return 0;
    }

    if(reservedWordListHead) freeTokenList(reservedWordListHead);
    if(symbolTable) freeTokenList(symbolTable);
    if(syntacticStructureListHead) freeSyntacticStructureList(syntacticStructureListHead);
    if(synTree) freeTree(synTree);

    fclose(file);
    return 0;
}
