#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *f;

  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    exit(1);
  }

  f = fopen(argv[1], "w");

  if (f == 0) {
    puts("hit this");
    perror(argv[1]);
    exit(2);
  }

  fputs("hello, world", f);
  putc('\n', f);

  fclose(f);

  return 0;
}
