#include <stdio.h>
#define MAX_CHAR 1000

int escape(int c, int i, char word[]) {
  switch (c) {
    case '\t':
      word[i++] = '\\';
      word[i++] = 't';
      break;
    case '\n':
      word[i++] = '\\';
      word[i++] = 'n';
      break;
    default:
      word[i++] = c;
      break;
  }
  return i;
}

int main() {
  int c, i;
  char newWord[MAX_CHAR];

  i = 0;
  while ((c = getchar()) != EOF) {
    i = escape(c, i, newWord);
  }
  newWord[i] = '\0';
  printf("updated: %s\n", newWord);
}
