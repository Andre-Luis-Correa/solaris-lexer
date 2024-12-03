#ifndef SYNTACTIC_ANALYSIS_H
#define SYNTACTIC_ANALYSIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros que indicam qual estrutura sintática foi reconhecida.
#define SYN_VARIABLE_DECLARATION          1  // Declaração de variável.
#define SYN_ASSIGNMENT                    2  // Atribuição.
#define SYN_ARITHMETIC_OPERATION          3  // Operação aritmética.
#define SYN_RELATIONAL_OPERATION          4  // Operação relacional.
#define SYN_LOGICAL_OPERATION             5  // Operação lógica.
#define SYN_CONDITIONAL_CHOOSE            6  // Estrutura condicional "choose".
#define SYN_CONDITIONAL_CHOOSE_OTHERWISE  7  // Estrutura condicional "otherwise".
#define SYN_LOOP                          8  // Estrutura de repetição "loop".
#define SYN_LOOP_WHILE                    9  // Estrutura de repetição "while".
#define SYN_STRING_DECLARATION           10  // Declaração de string.
#define SYN_WRITE_DATA                   11  // Operação "write".
#define SYN_READ_DATA                    12  // Operação "read".
#define SYN_LIBRARY_INCLUSION            13  // Inclusão de biblioteca.
#define SYN_FUNCTION_DECLARATION         14  // Declaração de função.
#define SYN_COMMENT_LINE                 15  // Comentário de linha.
#define SYN_COMMENT_BLOCK                16  // Comentário de bloco.
#define SYN_FUNCTION_RETURN              17  // Retorno de função.
#define SYN_ERROR                        18  // Indica um erro sintático.
#define SYN_OPERATION                    19  // Indica uma operação

// Estrutura para armazenar uma estrutura sintática reconhecida.
typedef struct syntacticStructure {
    int type;                            // Tipo da estrutura sintática.
    char *value;                         // Valor associado à estrutura.
    struct syntacticStructure *next;     // Ponteiro para o próximo elemento na lista.
} syntacticStructureList;

// Variável global para indicar a presença de erros.
extern int errorFlag;

// Ponteiro global para a cabeça da lista de estruturas sintáticas.
extern syntacticStructureList *syntacticStructureListHead;

// Cria uma nova estrutura sintática e inicializa seus atributos.
// Pré-condições: 'type' deve ser um valor válido, e 'value' deve ser uma string ou NULL.
// Pós-condições: Retorna um ponteiro para a nova estrutura sintática criada.
syntacticStructureList * createSyntacticStructure(int type, const char *value);

// Adiciona uma nova estrutura sintática à lista encadeada.
// Pré-condições: 'head' deve ser um ponteiro para a lista, e 'value' deve ser uma string válida ou NULL.
// Pós-condições: Um novo elemento será adicionado à lista com os valores especificados.
void addSyntacticStructure(syntacticStructureList **head, int type, const char *value);

// Libera a memória de todos os elementos na lista de estruturas sintáticas.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL.
// Pós-condições: A memória de todos os elementos será liberada.
void freeSyntacticStructureList(syntacticStructureList *head);

// Retorna o nome do tipo de estrutura sintática com base em seu valor enumerado.
// Pré-condições: 'type' deve ser um valor válido de tipo de estrutura sintática.
// Pós-condições: Retorna uma string que representa o nome do tipo.
const char* getSyntacticStructureTypeName(int type);

// Imprime as estruturas sintáticas em uma lista, com um rótulo para identificação.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL, e 'listName' deve ser uma string válida.
// Pós-condições: As estruturas serão exibidas no console.
void printSyntacticStructures(const syntacticStructureList *head, const char *listName);

// Processa uma estrutura sintática adicionando-a à lista global e manipulando informações associadas.
// Pré-condições: 'type' deve ser um valor válido, e 'text' deve ser uma string válida.
// Pós-condições: A estrutura será adicionada à lista global.
void processSyntacticStructure(int type, const char *text);

// Imprime os elementos da lista de estruturas sintáticas global.
// Pré-condições: 'head' deve ser um ponteiro válido para a lista ou NULL.
// Pós-condições: A lista será exibida no console.
void printSyntacticStructuresList(const syntacticStructureList *head);

#endif // SYNTACTIC_ANALYSIS_H
