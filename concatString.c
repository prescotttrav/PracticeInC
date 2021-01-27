#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25

int test(char actual[], char expected[]) {
  int diff = strcmp(actual, expected);
  if (diff) {
    printf("Expected: %s, Actual: %s\n", expected, actual);
    return 0;
  } else
    return 1;
}

void copy(char to[], char from[]) {
  int i;

  for (i = 0; from[i] != '\0'; ++i)
    to[i] = from[i];
  to[i] = '\0';
}

void concatString(char s1[], char s2[]) {
  int i, j;
  i = j = 0;

  while (s1[i] != '\0')
    ++i;

  while ((s1[i++] = s2[j]) != '\0')
    ++j;
}

int main() {
  int count = 0;
  char word[MAX_LENGTH];

  copy(word, "Prescott ");
  concatString(word, "J. ");
  concatString(word, "Traversi");
  count += test(word, "Prescott J. Traversi");

  copy(word, "Hello");
  concatString(word, ", ");
  concatString(word, "world");
  count += test(word, "Hello, world");

  copy(word, "super");
  concatString(word, "cala");
  concatString(word, "fragi");
  concatString(word, "listic");
  count += test(word, "supercalafragilistic");

  printf("%d / 3 testcases passed\n", count);
  return 0;
}
