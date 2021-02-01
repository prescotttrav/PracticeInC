#include "main.h"
#include <stdio.h>
#include <stdlib.h>

const int expected[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

void matchExpectedValues(int actual[], int range) {
  for (int i = 0; expected[i] < range; ++i) {
    if (actual[i] != expected[i]) {
      fprintf(stderr, "Error in testing findPrimeNumbers utility.\n");
      printf("Expected: %d, received: %d\n", expected[i], actual[i]);
      exit(-1);
    }
  }
}

void test() {
  int prime[100];

  findPrimeNumbers(prime, 3);
  matchExpectedValues(prime, 3);

  findPrimeNumbers(prime, 10);
  matchExpectedValues(prime, 10);

  findPrimeNumbers(prime, 50);
  matchExpectedValues(prime, 50);

  findPrimeNumbers(prime, 100);
  matchExpectedValues(prime, 100);
}
