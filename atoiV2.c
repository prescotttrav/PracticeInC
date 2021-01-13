#include <stdio.h>

#define MAX_INPUT 100

int isSpace(char x) {
  if (x == ' ' || x == '\t' || x == '\n')
    return 1;
  else
    return 0;
}

int isDigit(char x) {
  if (x >= '0' && x <= '9')
    return 1;
  else
    return 0;
}

int atoi(char s[]) {
  int i, n, sign;
  for (i = 0; isSpace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (n = 0; isDigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}

int main() {
  int c;
  char input[MAX_INPUT];

  for (int i = 0; i < MAX_INPUT && (c = getchar()) != EOF; i++) {
    input[i] = c;
  }

  int convertedValue = atoi(input);
  printf("input: %s, output: %d\n", input, convertedValue);
}
