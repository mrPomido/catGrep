#include "files.h"

int main(int argc, char **argv) {
  arguments arg = argParser(argc, argv);
  output(arg, argc, argv);
  return 0;
}