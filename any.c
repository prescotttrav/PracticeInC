#include <stdio.h>
#include <string.h>

int test(int actual, int expected) {
  if (actual != expected) {
    printf("Expected: %d, Actual: %d\n", expected, actual);
    return 0;
  }
  else
    return 1;
}

int hasChar(char s[], char c) {
  int i;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c)
      return 1;
  }
  return 0;
}

int any(char s1[], char s2[]) {
  int c, i;
  for (i = 0; (c = s1[i]) != '\0'; ++i) {
    if (hasChar(s2, c))
      return i;
  }
  return -1;
}

int main() {
  int count, res;
  count = 0;

  res = any("Prescott", "Traversi");
  count += test(res, 1);

  res = any("abcdefghijklmno", "zoom");
  count += test(res, 12);

  res = any("foo", "bar");
  count += test(res, -1);

  printf("%d / 3 testcases passed\n", count);
  return 0;
}
