#include "test.h"
#include <stdio.h>

void findPrimeNumbers(int prime[], int range) {
  int index = 0;
  prime[0] = 2;

  for (int num = 3; num < range + 1; ++num) {
    int j = index + 1;
    for (int k = 0; k < j; ++k) {
      if (num % prime[k] == 0)
        break;
      else if (k == index)
        prime[++index] = num;
    }
  }
}

char *getSeparator(int index) {
  char *separator = index > 0 ? ", " : "";
  return separator;
}

void printValidElements(int elements[], int n) {
  for (int i = 0; i < n; ++i) {
    if (elements[i] == 0)
      break;
    printf("%s%d", getSeparator(i), elements[i]);
  }
  printf("\n");
}

int main() {
  test();
  int range = 100;
  int primeNumbers[range];

  findPrimeNumbers(primeNumbers, range);
  printValidElements(primeNumbers, range);

  return 0;
}
