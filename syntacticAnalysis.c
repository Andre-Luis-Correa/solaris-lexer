#include <stdio.h>
#include "syntacticAnalysis.h"

// Cabeça da lista de estruturas sintáticas
syntacticStructureList *syntacticStructureListHead = NULL;

// Cria uma nova estrutura sintática
syntacticStructureList* createSyntacticStructure(int type, const char *value) {
    syntacticStructureList *newStructure = (syntacticStructureList *)malloc(sizeof(syntacticStructureList));
    newStructure->type = type;
    newStructure->value = strdup(value);
    newStructure->next = NULL;
    return newStructure;
}

// Adiciona uma nova estrutura sintática à lista
void addSyntacticStructure(syntacticStructureList **head, int type, const char *value) {
    syntacticStructureList *newStructure = createSyntacticStructure(type, value);
    if (*head == NULL) {
        *head = newStructure;
    } else {
        syntacticStructureList *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStructure;
    }
}

// Libera a memória da lista de estruturas sintáticas
void freeSyntacticStructureList(syntacticStructureList *head) {
    syntacticStructureList *current = head;
    while (current != NULL) {
        syntacticStructureList *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

// Retorna o nome da estrutura sintática
const char* getSyntacticStructureTypeName(int type) {
    switch (type) {
        case SYN_VARIABLE_DECLARATION:       return "VARIABLE_DECLARATION";
        case SYN_ASSIGNMENT:                 return "ASSIGNMENT";
        case SYN_ARITHMETIC_OPERATION:       return "ARITHMETIC_OPERATION";
        case SYN_RELATIONAL_OPERATION:       return "RELATIONAL_OPERATION";
        case SYN_LOGICAL_OPERATION:          return "LOGICAL_OPERATION";
        case SYN_CONDITIONAL_CHOOSE:                    return "CONDITIONAL_CHOOSE";
        case SYN_CONDITIONAL_OTHERWISE:                    return "CONDITIONAL_OTHERWISE";
        case SYN_LOOP_UNTIL:                 return "LOOP_UNTIL";
        case SYN_LOOP_FOREACH:               return "LOOP_FOREACH";
        case SYN_STRING:                     return "STRING";
        case SYN_WRITE_DATA:                 return "WRITE_DATA";
        case SYN_READ_DATA:                  return "READ_DATA";
        case SYN_LIBRARIES_INCLUSION:        return "LIBRARIES_INCLUSION";
        case SYN_FUNCTION_DECLARATION:       return "FUNCTION_DECLARATION";
        default:                             return "INVALID";
    }
}

// Imprime todas as estruturas sintáticas da lista
void printSyntacticStructures(const syntacticStructureList *head, const char *listName) {
    const syntacticStructureList *current = head;
    printf("\nEstruturas Sintaticas na lista %s:\n", listName);
    printf("------------------------------\n");
    printf("| %-20s %-10s |\n", "Tipo", "Valor");
    printf("------------------------------\n");
    while (current != NULL) {
        printf("| %-20s %-10s |\n", getSyntacticStructureTypeName(current->type), current->value);
        current = current->next;
    }
}

// Processa uma estrutura sintática e adiciona à lista
void processSyntacticStructure(int type, const char *text) {
    addSyntacticStructure(&syntacticStructureListHead, type, text);
}