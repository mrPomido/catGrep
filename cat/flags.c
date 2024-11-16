#include "flags.h"

int processFlags(int argc, char** argv, int* index, int* options) {
  int flArgs = 1;
  for (int i = 1; flArgs == 1 && i < argc; i++) {
    if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '-') ||
        !strcmp(argv[i], "-")) {
      flArgs = 0;
      *index = i;
    } else {
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        options[numberNonEmptyLines] = 1;
      } else if (strcmp(argv[i], "--number") == 0) {
        options[payOffInOrder] = 1;
      } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
        options[squeeze] = 1;
      } else {
        for (int j = 1; (size_t)j < strlen(argv[i]) && flArgs != -1; j++) {
          if (argv[i][j] == 'b') {
            options[numberNonEmptyLines] = 1;
          } else if (argv[i][j] == 'E') {
            options[hereComesAMoney] = 1;
          } else if (argv[i][j] == 'n') {
            options[payOffInOrder] = 1;
          } else if (argv[i][j] == 's') {
            options[squeeze] = 1;
          } else if (argv[i][j] == 'T') {
            options[tabuNizya] = 1;
          } else if (argv[i][j] == 'v') {
            options[showMeTheWayMyQueen] = 1;
          } else if (argv[i][j] == 'e') {
            options[hereComesAMoney] = 1;
            options[showMeTheWayMyQueen] = 1;
          } else if (argv[i][j] == 't') {
            options[tabuNizya] = 1;
            options[showMeTheWayMyQueen] = 1;
          } else {
            flArgs = -1;
          }
        }
      }
      if (options[numberNonEmptyLines] && options[payOffInOrder])
        options[payOffInOrder] = 0;
    }
  }
  return flArgs;
}