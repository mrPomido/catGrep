#include "files.h"
#include "flags.h"

int main(int argc, char** argv) {
  int options[6] = {0, 0, 0, 0, 0, 0};
  int index = 1;
  if (processFlags(argc, argv, &index, options) == -1)
    printf("WRONG FLAGS!!!");
  else {
    for (int i = index; i < argc; i++) {
      // printf("%d ", index);
      FILE* file = NULL;
      file = fopen(argv[i], "r");
      if (file == NULL)
        printf("No such file or dir");
      else {
        processFiles(file, options);
        fclose(file);
      }
    }
  }
  return 0;
}