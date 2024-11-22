#include "tree.h"

tree_t * tree = NULL;

// Cria um nó da árvore
tree_t *createNode(const char *label) {
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    if (!node) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }
    node->label = strdup(label);
    node->children = NULL;
    node->childCount = 0;
    return node;
}

// Adiciona um filho a um nó
void addChild(tree_t *parent, tree_t *child) {
    if (!parent || !child) {
        fprintf(stderr, "Erro: Ponteiro nulo em addChild\n");
        exit(EXIT_FAILURE);
    }
    parent->childCount++;
    tree_t **temp = (tree_t **)realloc(parent->children, parent->childCount * sizeof(tree_t *));
    if (!temp) {
        fprintf(stderr, "Erro: Falha ao alocar memória para os filhos\n");
        exit(EXIT_FAILURE);
    }
    parent->children = temp;
    parent->children[parent->childCount - 1] = child;
}

// Grava a árvore no arquivo
void writeTreeToFile(tree_t *root, FILE *file, int depth) {
    int i;

    for (i = 0; i < depth; i++) {
        fprintf(file, "  "); // Indentação
    }

    if(strstr(root->label, "FIM")) {
        fprintf(file, "\n");
    } else {
        fprintf(file, "%s\n", root->label);
    }

    for (i = 0; i < root->childCount; i++) {
        writeTreeToFile(root->children[i], file, depth + 1);
    }
}

// Libera a memória da árvore
void freeTree(tree_t *root) {
    int i;

    for (i=0; i < root->childCount; i++) {
        freeTree(root->children[i]);
    }
    free(root->label);
    free(root->children);
    free(root);
}

char * buildTreeNodeDescription(const char *ruleName, const char *details) {
    char treeNodeDescription[1000];
    sprintf(treeNodeDescription, "%s : [ %s ]", ruleName, details);

    char *result = strdup(treeNodeDescription);
    if (!result) {
        fprintf(stderr, "Erro: Falha ao alocar memória para a descrição do nó\n");
        exit(EXIT_FAILURE);
    }
    return result;
}