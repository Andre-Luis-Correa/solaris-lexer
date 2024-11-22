#ifndef FILE_H
#define FILE_H

#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Abre um arquivo no modo especificado e retorna o ponteiro para o arquivo.
// Pré-condições:
//   - 'fileName' deve ser uma string válida representando o nome do arquivo.
//   - 'mode' deve ser uma string válida representando o modo de abertura do arquivo (por exemplo, "r", "w").
// Pós-condições: Retorna um ponteiro para o arquivo aberto ou encerra o programa caso o arquivo não possa ser aberto.
FILE * openFile(char * fileName, char * mode);

// Verifica se o ponteiro do arquivo é válido.
// Pré-condições: 'file' deve ser um ponteiro para um arquivo previamente aberto.
// Pós-condições: Exibe uma mensagem de erro e encerra o programa se o arquivo for inválido.
void verifyFile(FILE * file);

// Encerra o programa com uma mensagem genérica de erro.
// Pré-condições: Nenhuma.
// Pós-condições: Finaliza o programa com um código de saída de erro.
void closeProgram();

#endif // FILE_H
