#include <stdio.h>

#define MAX_LINE 1000

int getLine(char s[]) {
  int i, c;
  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return i;
}

void reverseLine(char from[], int size) {
  int i = 0;
  int j = size - 1;
  char rev[size];

  while (j >= 0 && i < size) {
    rev[i++] = from[j--];
  }
  rev[i++] = '\n';
  rev[i] = '\0';
  printf("%s", rev);
}

int main() {
  int len;
  char line[MAX_LINE];

  while ((len = getLine(line)) != 0) {
    reverseLine(line, len);
  }

  return 0;
}
