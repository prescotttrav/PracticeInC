#include <stdio.h>

#define MAX_LENGTH 13

void copy(char to[], char from[]) {
  int i;

  for (i = 0; from[i] != '\0'; ++i)
    to[i] = from[i];
  to[i] = '\0';
}

void removeChar(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c)
      s[j++] = s[i];
  }
  s[j] = '\0';
}

int main() {
  char word[MAX_LENGTH];

  copy(word, "abcdea");
  removeChar(word, 'a');
  printf("Expected: bcde, Actual: %s\n", word);

  copy(word, "hello, world");
  removeChar(word, 'z');
  printf("Expected: hello, world, Actual: %s\n", word);

  copy(word, "Sssss");
  removeChar(word, 's');
  printf("Expected: S, Actual: %s\n", word);

  return 0;
}
