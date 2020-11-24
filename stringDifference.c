#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 13

int test(char actual[], char expected[]) {
  int diff = strcmp(actual, expected);
  if (diff) {
    printf("Expected: %s, Actual: %s\n", expected, actual);
    return 0;
  }
  else
    return 1;
}

int hasChar(char s[], int c) {
  int i;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c)
      return 1;
  }
  return 0;
}

void stringDifference(char s1[], char s2[]) {
  int c, i, j;
  
  for (i = j = 0; (c = s1[i]) != '\0'; ++i) {
    if (!hasChar(s2, c))
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}

int main() {
  int count = 0;
  char word[MAX_LENGTH];

  strcpy(word, "Prescott");
  stringDifference(word, "prescott");
  count += test(word, "P");

  strcpy(word, "hello, world");
  stringDifference(word, "o,a");
  count += test(word, "hell wrld");

  strcpy(word, "hello");
  stringDifference(word, "olleh");
  count += test(word, "");

  printf("%d / 3 testcases passed\n", count);
  return 0;
}
