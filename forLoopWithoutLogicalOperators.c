#include <stdio.h>

#define MAX_LINE 1000

/* Replicating:
 * for (i=0; i < lim-1 && (c=getchar()) != ’\n’ && c != EOF; ++i)
 * without && or ||
 */

int getLine(char s[]) {
  int i, c;
  i = 0;

  while (i < MAX_LINE - 1) {
    c = getchar();
    if (c == EOF)
      break;
    else 
      s[i++] = c;
    if (c == '\n') 
      break;
  }
  s[i] = '\0';
  
  return i;
}

int main() {
  int len, count;
  char line[MAX_LINE];
  count = 0;

  while ((len = getLine(line)) > 0) {
    ++count;
  }

  printf("Valid lines: %d\n", count);

  return 0;
}
