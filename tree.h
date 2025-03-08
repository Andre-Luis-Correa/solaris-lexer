#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um nó na árvore de sintaxe.
struct treeNode {
    char *label;                 // Rótulo do nó, geralmente representando o nome da regra ou tipo de token.
    char *value;                 // Valor associado ao nó, como o texto ou literal do token.
    struct treeNode **children;  // Ponteiro para a lista de filhos do nó.
    int childCount;              // Número de filhos que o nó possui.
};

// Define um tipo TREE_NODE para facilitar o uso da estrutura treeNode.
typedef struct treeNode TREE_NODE;

// Define um ponteiro do tipo TREE_NODE como `tree` para manipulação de árvores.
typedef TREE_NODE * tree;

// Declaração global da árvore sintática para armazenamento.
extern tree synTree;

// Cria e inicializa um nó da árvore com um rótulo e um valor associados.
// Pré-condições: 'label' e 'value' devem ser strings válidas ou NULL.
// Pós-condições: Retorna um ponteiro para o nó criado.
tree createNode(const char *label, const char *value);

// Adiciona um nó filho a um nó pai existente na árvore.
// Pré-condições: 'parent' e 'child' devem ser ponteiros válidos para nós.
// Pós-condições: O nó 'child' será adicionado à lista de filhos de 'parent'.
void addChild(tree parent, tree child);

// Escreve a árvore de sintaxe em um arquivo, com indentação para representar a hierarquia.
// Pré-condições: 'root' deve ser um ponteiro válido para a raiz da árvore, e 'file' deve estar aberto para escrita.
// Pós-condições: A árvore será escrita no arquivo em um formato legível.
void writeTreeToFile(tree root, FILE *file, int depth);

// Libera a memória associada a uma árvore, incluindo todos os seus nós filhos.
// Pré-condições: 'root' deve ser um ponteiro válido para a raiz da árvore ou NULL.
// Pós-condições: A memória de todos os nós será liberada.
void freeTree(tree root);

// Escreve a árvore de sintaxe em um arquivo de texto, criando ou sobrescrevendo o arquivo.
// Pré-condições: 'fileName' deve ser o caminho válido para um arquivo, e 'txtTree' deve ser um ponteiro válido para a árvore.
// Pós-condições: A árvore será salva no arquivo de texto especificado.
void writeTreeToTxtFile(char *fileName, tree txtTree);

// Conta a quantidade de parâmetros (identificadores) de um nó function_parameter
// Pré-condições: 'function_parameter' deve ser diferente de nulo.
// Pós-condições: Retorna a quantidade de parâmetros (identificadores) que foram encontrados no nó da árvore.
int countParameters(tree function_parameter);

#endif // TREE_H