#include <stdio.h>

#define MAX_LINE 1000

int max;
char longest[MAX_LINE];
char line[MAX_LINE];

int getLine() {
  int i, c;
  extern char line[];
  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

void copy() {
  int i = 0;
  extern char longest[], line[];
  while ((longest[i] = line[i]) != '\0')
    ++i;
}

int main() {
  int len;
  extern int max;
  extern char longest[];
  while ((len = getLine()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0)
    printf("%s", longest);

  return 0;
}
