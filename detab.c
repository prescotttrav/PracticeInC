#include <stdio.h>

#define MAX_LINE 1000
#define SPACES 8

int detab(int start, char line[]) {
  int end;
  int mod = start % SPACES;
  if (mod == 0)
    end = start + SPACES;
  else 
    end = SPACES - mod + start;

  for (int i = start; i < end; ++i)
    line[i] = ' ';

  return end;
}

int getLine(char line[]) {
  int c;
  int i = 0;

  while (i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n') {
    if (c == '\t')
      i = detab(i, line);
    else
      line[i++] = c;
  }
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';

  return i; 
}

int main() {
  int len;
  char line[MAX_LINE];

  while ((len = getLine(line)) != 0) 
    printf("%s", line);

  return 0;
}
