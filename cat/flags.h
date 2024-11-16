#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum options {
  numberNonEmptyLines,
  hereComesAMoney,
  payOffInOrder,
  squeeze,
  tabuNizya,
  showMeTheWayMyQueen
};

int processFlags(int argc, char** argv, int* index, int* options);
