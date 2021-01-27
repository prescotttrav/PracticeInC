#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
  int i, j, c;

  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}

int main() {
  char string[] = "Prescott";
  reverse(string);
  
  printf("%s\n", string);
  return 0;
}
