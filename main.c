#include "lexer.h"

// Flex gera essas variáveis
extern FILE *yyin;        // Variável externa para o arquivo de entrada do Flex
extern int yylex();       // Função gerada pelo Flex que realiza a análise léxica

int main() {
    char filename[256];  // Buffer para armazenar o nome do arquivo

    printf("--> Digite o nome do arquivo para analise lexica: ");
    scanf("%[^\n]", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    yyin = file;
    yylex();
    printTokens(reservedWordListHead, "Palavras Reservadas");
    printTokens(otherTokensListHead, "Outros Tokens");
    freeTokenList(reservedWordListHead);
    freeTokenList(otherTokensListHead);

    fclose(file);
    return 0;
}
