#include "flags.h"

arguments argParser(int argc, char *argv[]) {
  arguments arg = {0};
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        arg.e = 1;
        patternAdd(&arg, optarg);
        break;
      case 'i':
        arg.i = REG_ICASE;
        break;
      case 'v':
        arg.v = 1;
        break;
      case 'c':
        arg.c = 1;
        break;
      case 'l':
        arg.c = 1;
        arg.l = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 'h':
        arg.h = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'f':
        arg.f = 1;
        regFromFile(&arg, optarg);
        break;
      case 'o':
        arg.o = 1;
        break;
    }
  }
  if (arg.len_pattern == 0) {
    patternAdd(&arg, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    arg.h = 1;
  }
  return arg;
}

void patternAdd(arguments *arg, char *pattern) {
  if (arg->len_pattern != 0) {
    strcat(arg->pattern + arg->len_pattern, "|");
    arg->len_pattern++;
  }
  arg->len_pattern += sprintf(arg->pattern + arg->len_pattern, "(%s)", pattern);
}

void regFromFile(arguments *arg, char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    if (!arg->s) perror(filepath);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = getline(&line, &memlen, f);
  while (read != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    patternAdd(arg, line);
    read = getline(&line, &memlen, f);
  }
  free(line);
  fclose(f);
}