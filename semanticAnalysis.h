#ifndef SEMANTICANALYSIS_H
#define SEMANTICANALYSIS_H

#include "lexer.h"

void checkDeclarationExists(const char *str);
void checkDeclarationNotExists(const char *str);
void checkTypesOfAssignment(dataType dataType, const char *str);

#endif //SEMANTICANALYSIS_H
