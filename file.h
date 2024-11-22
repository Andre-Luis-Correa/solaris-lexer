#ifndef FILE_H
#define FILE_H

#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * openFile(char * fileName, char * mode);
void verifyFile(FILE * file);
void closeProgram();


#endif // FILE_H
