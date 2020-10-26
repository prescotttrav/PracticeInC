#include <stdio.h>

int main() {
  long nc = 0;

  while(getchar() != EOF)
    ++nc;
  printf("Num. chars: %ld\n", nc);
  return 0;
}

