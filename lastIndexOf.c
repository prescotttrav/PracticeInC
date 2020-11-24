#include <stdio.h>

int runs = 0;
int flags = 0;

void assert(int actual, int expected) {
  extern int runs, flags;
  ++runs;

  if (actual != expected) {
    ++flags;
    printf("Expected: %d, Actual: %d\n", expected, actual);
  }
}

int lastIndexOf(char s[], int c) {
  int i, res;
  res = -1;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c)
      res = i;
  }
  return res;
}

int main() {
  extern int flags, runs;
  int res;

  assert(lastIndexOf("totem", 't'), 2);
  assert(lastIndexOf("supercalifragilistic", 'i'), 18);
  assert(lastIndexOf("hello", 'w'), -1);
  
  printf("%d / %d testcases passed\n", runs - flags, runs);
  return 0;
}
