#include "tree.h"

tree synTree = NULL;

// Cria um nó da árvore
tree createNode(const char *label, const char *value) {
    tree node = (tree)malloc(sizeof(TREE_NODE));
    if (!node) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }
    node->label = strdup(label);
    node->value = strdup(value);
    if (!node->label) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o rótulo do nó\n");
        exit(EXIT_FAILURE);
    }
    node->children = NULL;
    node->childCount = 0;
    return node;
}

// Adiciona um filho a um nó
void addChild(tree parent, tree child) {
    if (!parent || !child) {
        fprintf(stderr, "Erro: Ponteiro nulo em addChild\n");
        exit(EXIT_FAILURE);
    }

    parent->childCount++;
    tree *temp = (tree *)realloc(parent->children, parent->childCount * sizeof(tree));
    if (!temp) {
        fprintf(stderr, "Erro: Falha ao realocar memória para os filhos\n");
        exit(EXIT_FAILURE);
    }

    parent->children = temp;
    parent->children[parent->childCount - 1] = child;
}

// Grava a árvore no arquivo
void writeTreeToFile(tree root, FILE *file, int depth) {
    int i;

    if (!root || !file) {
        fprintf(stderr, "Erro: Ponteiro nulo em writeTreeToFile\n");
        return;
    }

    // Indentação baseada na profundidade
    for (i = 0; i < depth; i++) {
        fprintf(file, "  ");
    }

    if (root->value) {
        fprintf(file, "%s: %s\n", root->label, root->value);
    } else {
        fprintf(file, "%s\n", root->label);
    }

    // Recursivamente escreve os filhos
    for (i = 0; i < root->childCount; i++) {
        writeTreeToFile(root->children[i], file, depth + 1);
    }
}

// Libera a memória da árvore
void freeTree(tree root) {
    if (!root) return;

    int i;

    // Libera os filhos recursivamente
    for (i = 0; i < root->childCount; i++) {
        freeTree(root->children[i]);
    }

    // Libera o rótulo e os filhos
    free(root->label);
    free(root->children);
    free(root);
}

// Constrói uma descrição para um nó da árvore
char *buildTreeNodeDescription(const char *ruleName, const char *details) {
    char treeNodeDescription[1000];
    snprintf(treeNodeDescription, sizeof(treeNodeDescription), "%s : [ %s ]", ruleName, details);

    char *result = strdup(treeNodeDescription);
    if (!result) {
        fprintf(stderr, "Erro: Falha ao alocar memória para a descrição do nó\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void createProgramTree(tree child) {
    if (!synTree) {
        if(child) {
            synTree = createNode("program", child->value);
        } else {
            synTree = createNode("program", " ");
        }
    }
    addChild(synTree, child);
}