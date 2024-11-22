#include "file.h"

FILE * openFile(char * fileName, char * mode) {
    FILE *file = fopen(fileName, mode);
    verifyFile(file);
    return file;
}

void verifyFile(FILE * file) {
    if (!file) {
        closeProgram();
    }
}

void closeProgram() {
    perror("Erro ao abrir o arquivo");
    exit(1);
}