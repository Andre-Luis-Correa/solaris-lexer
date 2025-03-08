#include "tree.h"
#include "file.h"

tree synTree = NULL;

// Cria e inicializa um nó da árvore com um rótulo e um valor associados.
// Pré-condições: 'label' e 'value' devem ser strings válidas ou NULL.
// Pós-condições: Retorna um ponteiro para o nó criado.
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

// Adiciona um nó filho a um nó pai existente na árvore.
// Pré-condições: 'parent' e 'child' devem ser ponteiros válidos para nós.
// Pós-condições: O nó 'child' será adicionado à lista de filhos de 'parent'.
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

// Escreve a árvore de sintaxe em um arquivo, com indentação para representar a hierarquia.
// Pré-condições: 'root' deve ser um ponteiro válido para a raiz da árvore, e 'file' deve estar aberto para escrita.
// Pós-condições: A árvore será escrita no arquivo em um formato legível.
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

// Libera a memória associada a uma árvore, incluindo todos os seus nós filhos.
// Pré-condições: 'root' deve ser um ponteiro válido para a raiz da árvore ou NULL.
// Pós-condições: A memória de todos os nós será liberada.
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

// Escreve a árvore de sintaxe em um arquivo de texto, criando ou sobrescrevendo o arquivo.
// Pré-condições: 'fileName' deve ser o caminho válido para um arquivo, e 'txtTree' deve ser um ponteiro válido para a árvore.
// Pós-condições: A árvore será salva no arquivo de texto especificado.
void writeTreeToTxtFile(char * fileName, tree txtTree) {
    char outputFileName[256];
    snprintf(outputFileName, sizeof(outputFileName), "arvores_%s.txt", fileName);

    FILE * outputFile = openFile(outputFileName, "w");

    if (txtTree) {
        writeTreeToFile(txtTree, outputFile, 0);
    } else {
        printf("Nenhuma árvore sintática gerada.\n");
    }

    fclose(outputFile);
    printf("\n\nArvore sintatica salva com sucesso em %s.\n\n", outputFileName);
}

// Conta a quantidade de parâmetros (identificadores) de um nó function_parameter
// Pré-condições: 'function_parameter' deve ser diferente de nulo.
// Pós-condições: Retorna a quantidade de parâmetros (identificadores) que foram encontrados no nó da árvore.
int countParameters(tree function_parameter) {
    if (function_parameter == NULL) {
        return 0;
    }

    if (strcmp(function_parameter->label, "TOKEN_IDENTIFIER") == 0) {
        return 1;
    }

    int count = 0;
    int i;
    for (i = 0; i < function_parameter->childCount; i++) {
        count += countParameters(function_parameter->children[i]);
    }

    return count;
}
