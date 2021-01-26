#include <stdio.h>

#define MAX_LINE 10

int getLine(char s[], int limit) {
  int c, i;
  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int main() {
  int len, max, over;
  max = over = 0;
  char line[MAX_LINE];
  char longest[MAX_LINE];
  char overflow[MAX_LINE * MAX_LINE];

  while ((len = getLine(line, MAX_LINE)) != 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    if (line[len - 2] != '\n') {
      char buffer[MAX_LINE * MAX_LINE];
      len = getLine(buffer, MAX_LINE * MAX_LINE);
      if (len > over) {
        over = len;
        copy(longest, line);
        copy(overflow, buffer);
      }
    }
  }
  if (max > 0)
    printf("Longest: %s", longest);
  if (overflow > 0)
    printf("%s", overflow);

  return 0;
}
