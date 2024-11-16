#include "files.h"

#include "flags.h"

void processFiles(FILE* fileName, int* options) {
  int curr = fgetc(fileName);
  int prev = 9999;
  int emp = 0;
  int strCounter = 1;
  int isFirst = 1;

  while (curr != EOF) {
    if (options[squeeze]) {
      if (curr == '\n') emp += 1;
      if (curr != '\n') emp = 0;
    }
    if ((!options[squeeze] || emp < 3) && curr == '\n') {
      if (options[payOffInOrder] && (prev == '\n' || isFirst)) {
        printf("%6d\t", strCounter);
        strCounter += 1;
      }
      if (options[hereComesAMoney]) {
        printf("$");
      }
      printf("%c", curr);
    }
    if (curr != '\n') {
      if ((prev == '\n' || isFirst) &&
          (options[numberNonEmptyLines] || options[payOffInOrder])) {
        printf("%6d\t", strCounter);
        strCounter += 1;
      }
      if (curr < 32 && curr != '\t' && curr != '\n' &&
          options[showMeTheWayMyQueen]) {
        printf("^%c", (curr + 64));
      } else if (curr == 127 && options[showMeTheWayMyQueen])
        printf("^?");
      else if (curr == '\t' && options[tabuNizya])
        printf("^I");
      else
        printf("%c", curr);
    }
    prev = curr;
    curr = fgetc(fileName);
    isFirst = 0;
  }
}
