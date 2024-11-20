#ifndef SYNTACTIC_ANALYSIS_H
#define SYNTACTIC_ANALYSIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros que indicam qual estrutura sintática foi reconhecida
#define SYN_VARIABLE_DECLARATION       1
#define SYN_ASSIGNMENT                 2
#define SYN_ARITHMETIC_OPERATION       3
#define SYN_RELATIONAL_OPERATION       4
#define SYN_LOGICAL_OPERATION          5
#define SYN_CONDITIONAL_CHOOSE         6
#define SYN_CONDITIONAL_CHOOSE_OTHERWISE      7
#define SYN_LOOP                     8
#define SYN_LOOP_WHILE               9
#define SYN_STRING_DECLARATION                    10
#define SYN_WRITE_DATA                11
#define SYN_READ_DATA                 12
#define SYN_LIBRARY_INCLUSION       13
#define SYN_FUNCTION_DECLARATION      14
#define SYN_COMMENT_LINE      15
#define SYN_COMMENT_BLOCK      16
#define SYN_FUNCTION_RETURN      17

// Estrutura para armazenar uma estrutura sintática reconhecidaa
typedef struct syntacticStructure {
    int type;               // Tipo da estrutura sintática
    char *value;            // Valor da estrutura sintática
    struct syntacticStructure *next;     // Ponteiro para o próximo token na lista
} syntacticStructureList;

extern int errorFlag;

extern syntacticStructureList *syntacticStructureListHead;  // Cabeça da lista de palavras reservadas

syntacticStructureList * createSyntacticStructure(int type, const char *value);

void addSyntacticStructure(syntacticStructureList **head, int type, const char *value);

void freeSyntacticStructureList(syntacticStructureList *head);

const char* getSyntacticStructureTypeName(int type);

void printSyntacticStructures(const syntacticStructureList *head, const char *listName);

void processSyntacticStructure(int type, const char *text);

#endif //SYNTACTIC_ANALYSIS_H