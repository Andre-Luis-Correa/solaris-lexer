#include "tree.h"

treeNode * tree = NULL;

// Cria um nó da árvore
treeNode *createNode(const char *label) {
    treeNode *node = (treeNode *)malloc(sizeof(treeNode));
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
void addChild(treeNode *parent, treeNode *child) {
    if (!parent || !child) {
        fprintf(stderr, "Erro: Ponteiro nulo em addChild\n");
        exit(EXIT_FAILURE);
    }
    parent->childCount++;
    treeNode **temp = (treeNode **)realloc(parent->children, parent->childCount * sizeof(treeNode *));
    if (!temp) {
        fprintf(stderr, "Erro: Falha ao alocar memória para os filhos\n");
        exit(EXIT_FAILURE);
    }
    parent->children = temp;
    parent->children[parent->childCount - 1] = child;
}

// Grava a árvore no arquivo
void writeTreeToFile(treeNode *root, FILE *file, int depth) {
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
void freeTree(treeNode *root) {
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