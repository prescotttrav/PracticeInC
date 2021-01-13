#include <stdio.h>

int main() {
  int c, i, nwhite, nother, ndigit[10];

  nother = nwhite = 0;
  for (i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        ++ndigit[c - '0'];
	break;
      case ' ':
      case '\t':
      case '\n':
        ++nwhite;
        break;
      default:
        ++nother;
        break;
    }
  }

  printf("Number of digits: ");
  for (i = 0; i < 10; i++) {
    int value = ndigit[i];
    if (value > 0) {
      printf("%d: %d, ", i, value);
    }
  }
  printf("Number of whitespace: %d, Number of other: %d\n", nwhite, nother);
}
