#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
    char *label;
    char *value;
    struct treeNode **children;
    int childCount;
};

typedef struct treeNode TREE_NODE;
typedef TREE_NODE * tree;
extern tree synTree;

tree createNode(const char *label, const char *value);
void addChild(tree parent, tree child) ;
void writeTreeToFile(tree root, FILE *file, int depth);
void freeTree(tree root);
char * buildTreeNodeDescription(const char *ruleName, const char *details);

#endif // TREE_H
