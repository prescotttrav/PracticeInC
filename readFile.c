#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *f;
  int x;
  int sum;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  f = fopen(argv[1], "r");

  if (f == 0) {
    perror(argv[1]);
    exit(2);
  }

  sum = 0;

  while (fscanf(f, "%d", &x) == 1)
    sum += x;

  printf("sum: %d\n", sum);

  fclose(f);

  return 0;
}
