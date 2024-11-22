#include <stdio.h>
#include "syntacticAnalysis.h"

syntacticStructureList *syntacticStructureListHead = NULL;

// Cria uma nova estrutura sintática e inicializa seus atributos.
// Pré-condições: 'type' deve ser um valor válido, e 'value' deve ser uma string ou NULL.
// Pós-condições: Retorna um ponteiro para a nova estrutura sintática criada.
syntacticStructureList* createSyntacticStructure(int type, const char *value) {
    syntacticStructureList *newStructure = (syntacticStructureList *)malloc(sizeof(syntacticStructureList));
    newStructure->type = type;
    newStructure->value = strdup(value);
    newStructure->next = NULL;
    return newStructure;
}

// Adiciona uma nova estrutura sintática à lista encadeada.
// Pré-condições: 'head' deve ser um ponteiro para a lista, e 'value' deve ser uma string válida ou NULL.
// Pós-condições: Um novo elemento será adicionado à lista com os valores especificados.
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

// Libera a memória de todos os elementos na lista de estruturas sintáticas.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL.
// Pós-condições: A memória de todos os elementos será liberada.
void freeSyntacticStructureList(syntacticStructureList *head) {
    syntacticStructureList *current = head;
    while (current != NULL) {
        syntacticStructureList *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

// Retorna o nome do tipo de estrutura sintática com base em seu valor enumerado.
// Pré-condições: 'type' deve ser um valor válido de tipo de estrutura sintática.
// Pós-condições: Retorna uma string que representa o nome do tipo.
const char* getSyntacticStructureTypeName(int type) {
    switch (type) {
        case SYN_VARIABLE_DECLARATION:         return "VARIABLE_DECLARATION";
        case SYN_ASSIGNMENT:                   return "ASSIGNMENT";
        case SYN_ARITHMETIC_OPERATION:         return "ARITHMETIC_OPERATION";
        case SYN_RELATIONAL_OPERATION:         return "RELATIONAL_OPERATION";
        case SYN_LOGICAL_OPERATION:            return "LOGICAL_OPERATION";
        case SYN_CONDITIONAL_CHOOSE:           return "CONDITIONAL_CHOOSE";
        case SYN_CONDITIONAL_CHOOSE_OTHERWISE: return "CONDITIONAL_CHOOOSE_OTHERWISE";
        case SYN_LOOP:                         return "LOOP";
        case SYN_LOOP_WHILE:                   return "LOOP_WHILE";
        case SYN_STRING_DECLARATION:           return "STRING_DECLARATION";
        case SYN_WRITE_DATA:                   return "WRITE_DATA";
        case SYN_READ_DATA:                    return "READ_DATA";
        case SYN_LIBRARY_INCLUSION:            return "LIBRARY_INCLUSION";
        case SYN_FUNCTION_DECLARATION:         return "FUNCTION_DECLARATION";
        case SYN_COMMENT_LINE:                 return "COMMENT_LINE";
        case SYN_COMMENT_BLOCK:                return "COMMENT_BLOCK";
        case SYN_FUNCTION_RETURN:              return "FUNCTION_RETURN";
        default:                               return "INVALID";
    }
}

// Imprime as estruturas sintáticas em uma lista, com um rótulo para identificação.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL, e 'listName' deve ser uma string válida.
// Pós-condições: As estruturas serão exibidas no console.
void printSyntacticStructures(const syntacticStructureList *head, const char *listName) {
    const syntacticStructureList *current = head;
    printf("\nEstruturas Sintaticas na lista %s:\n", listName);
    printf("-------------------------------------------------------\n");
    printf("| %-25s %-25s |\n", "Tipo", "Valor");
    printf("-------------------------------------------------------\n");
    while (current != NULL) {
        printf("%-25s %-50s \n", getSyntacticStructureTypeName(current->type), current->value);
        current = current->next;
    }
}

// Processa uma estrutura sintática adicionando-a à lista global e manipulando informações associadas.
// Pré-condições: 'type' deve ser um valor válido, e 'text' deve ser uma string válida.
// Pós-condições: A estrutura será adicionada à lista global.
void processSyntacticStructure(int type, const char *text) {
    if(type == SYN_ERROR) {
        fprintf(stderr,"\nERRO SINTATICO -> %s\n", text);
    } else {
        addSyntacticStructure(&syntacticStructureListHead, type, text);
    }
}

// Imprime os elementos da lista de estruturas sintáticas global.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL.
// Pós-condições: A lista será exibida no console.
void printSyntacticStructuresList(const syntacticStructureList *head) {
    printf("\n\nEstruturas Sintaticas Identificadas:\n");
    printSyntacticStructures(head, "Estruturas Sintaticas Reconhecidas");
}