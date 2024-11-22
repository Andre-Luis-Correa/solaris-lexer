#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
    char *label;
    struct treeNode **children;
    int childCount;
} treeNode;

extern treeNode * tree;

treeNode * createNode(const char *label);
void addChild(treeNode *parent, treeNode *child);
void writeTreeToFile(treeNode *root, FILE *file, int depth);
void freeTree(treeNode *root);
char * buildTreeNodeDescription(const char *ruleName, const char *details);

#endif // TREE_H
