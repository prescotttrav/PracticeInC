#include <stdio.h>

#define MAX_LENGTH 13

void copy(char to[], char from[]) {
  int i;
  for (i = 0; i < MAX_LENGTH - 1 && from[i] != '\0'; ++i)
    to[i] = from[i];
  to[i] = '\0';
}

void toLowerCase(char s[]) {
  int i, c;
  i = 0;

  while ((c = s[i]) != '\0') {
    if (c >= 'A' && c <= 'Z')
      c = c + 'a' - 'A';
    s[i++] = c;
  }
}

int main() {
  char word[MAX_LENGTH];

  copy(word, "PRESCOTT");
  toLowerCase(word);
  printf("Expected: prescott, Actual: %s\n", word);

  copy(word, "prescott");
  toLowerCase(word);
  printf("Expected: prescott, Actual: %s\n", word);

  copy(word, "Hello, World");
  toLowerCase(word);
  printf("Expected: hello, world, Actual: %s\n", word);

  return 0;
}
