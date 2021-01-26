#include <stdio.h>

#define MAX_LINE 1000
#define SPACES 8

void entab(char to[], char from[]) {
  char whitespace;
  int c, k, n;
  int i = n = 0;
  int j = i + 1;

  while ((c = from[i]) != '\0') {
    if (c == ' ') {
      while (from[j] == ' ') {
        ++j;
      }
      if (j % SPACES == 0) {
        k = (j - i) / SPACES;
        if ((j - i) % SPACES != 0)
          k += 1;
        whitespace = '\t';
      } else {
        k = j - i;
        whitespace = ' ';
      }
      while (k > 0) {
        to[n++] = whitespace;
        --k;
      }
      i = j;
    } else {
      to[n++] = c;
      ++i;
    }
    j = i + 1;
  }
  to[n] = '\0';
}

int getLine(char line[]) {
  int c, i;
  for (i = 0; i < MAX_LINE && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';

  return i;
}

int main() {
  int len;
  char line[MAX_LINE];
  char entabbedLine[MAX_LINE];

  while ((len = getLine(line)) > 0) {
    entab(entabbedLine, line);
    printf("%s", entabbedLine);
  }

  return 0;
}
