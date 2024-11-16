#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char pattern[1024];
  int len_pattern;

} arguments;

void patternAdd(arguments *arg, char *pattern);
arguments argParser(int argc, char *argv[]);
void regFromFile(arguments *arg, char *filepath);
