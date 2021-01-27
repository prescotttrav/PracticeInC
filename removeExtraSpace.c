#include <stdio.h>

int main() {
  int c, cur;
  cur = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (cur < 1)
        putchar(c);
      ++cur;
    } else {
      cur = 0;
      putchar(c);
    }
  }
  return 0;
}
