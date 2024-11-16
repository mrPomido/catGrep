#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkFiles(char* flag, FILE* result) {
  char catFileName[80] = "cat";
  char s21FileName[80] = "s21";
  FILE* cat = fopen(strcat(catFileName, flag), "r");
  FILE* s21 = fopen(strcat(s21FileName, flag), "r");
  int catChar = getc(cat);
  int s21Char = getc(s21);
  int success = 1;
  while (catChar != EOF && success && s21Char != EOF) {
    if (catChar != s21Char) {
      success = 0;
    }
    catChar = getc(cat);
    s21Char = getc(s21);
  }
  if (success) {
    fputs(flag, result);
    fputs(":: SUCCESS\n", result);
  } else {
    fputs(flag, result);
    fputs(":: FAIL\n", result);
  }
  fclose(cat);
  fclose(s21);
  return success;
}

int main(int argc, char** argv) {
  int i = 0;
  FILE* result = fopen("RESULT", "w+t");
  i = system("cat -b test >cat-b");
  i = system("./s21_cat -b test >s21-b");
  checkFiles("-b", result);
  i = system("rm -rf cat-b s21-b");
  i = system("cat -e test >cat-e");
  i = system("./s21_cat -e test >s21-e");
  checkFiles("-e", result);
  i = system("rm -rf cat-e s21-e");
  i = system("cat -n test >cat-n");
  i = system("./s21_cat -n test >s21-n");
  checkFiles("-n", result);
  i = system("rm -rf cat-n s21-n");
  i = system("cat -s test >cat-s");
  i = system("./s21_cat -s test >s21-s");
  checkFiles("-s", result);
  i = system("rm -rf cat-s s21-s");
  i = system("cat -t test >cat-t");
  i = system("./s21_cat -t test >s21-t");
  checkFiles("-t", result);
  i = system("rm -rf cat-t s21-t");
  i = system("cat -v test >cat-v");
  i = system("./s21_cat -v test >s21-v");
  checkFiles("-v", result);
  i = system("rm -rf cat-v s21-v");
}