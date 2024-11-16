#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flags.h"

void itsAMatch(regex_t *re, char *line);
void proccesFile(arguments arg, char *path, regex_t *reg);
void output(arguments arg, int argc, char **argv);
void outputStr(char *line, int n);
