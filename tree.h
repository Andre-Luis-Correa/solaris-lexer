#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_t {
    char *label;
    struct tree_t **children;
    int childCount;
} tree_t;

extern tree_t * tree;

tree_t * createNode(const char *label);
void addChild(tree_t *parent, tree_t *child);
void writeTreeToFile(tree_t *root, FILE *file, int depth);
void freeTree(tree_t *root);
char * buildTreeNodeDescription(const char *ruleName, const char *details);

#endif // TREE_H
