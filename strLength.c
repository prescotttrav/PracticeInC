#include <stdio.h>

int strLength(char s[]) {
  int i, len;
  i = len = 0;
  while (s[i++] != '\0')
    ++len;

  return len;
}

int main() {
  printf("Expected: 20, Actual: %d\n", strLength("Prescott J. Traversi"));
  printf("Expected: 12, Actual: %d\n", strLength("Hello, world"));
  return 0;
}
