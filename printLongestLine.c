#include <stdio.h>

#define MAX_LINE 1000

int getLine(char s[], int limit) {
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
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
  int len;
  int max = 0;
  char line[MAX_LINE];
  char longest[MAX_LINE];
  
  while ((len = getLine(line, MAX_LINE)) != 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("longest: %s", longest);
  } 
 
  return 0;
}
