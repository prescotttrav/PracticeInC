#include <stdio.h>

int main(int argc, char *argv[]) {
  int numberOfArgs = argc;
  char *argument1 = argv[0];
  char *argument2 = argv[1];

  printf("Number of arguments: %d, argument 1: %s, argument 2: %s\n", numberOfArgs, argument1, argument2);

  return 0;
}
