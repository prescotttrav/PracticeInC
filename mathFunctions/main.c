#include "test.h"
#include <stdio.h>
#include <stdlib.h>

_Bool silent = 0;

void quiet() {
  silent = 1;
}

void verbose() {
  silent = 0;
}

void throwNegativeIntError(char func[]) {
  fprintf(stderr, "Negatvie int supplied to positive-only arguments, in %s",
          func);
  exit(-1);
}

int gcd(int x, int y) {
  int temp;
  if (x < 0 || y < 0)
    throwNegativeIntError("gcd");
  while (y != 0) {
    temp = x % y;
    x = y;
    y = temp;
  }

  return x;
}

float absoluteValue(float x) {
  if (x < 0)
    x = -x;
  return x;
}

float squareRoot(float x) {
  float guess = 1.0;
  float epsilon = .00001;

  if (x < 0) {
    if (!silent)
      printf("Square root argument must be non-negative float.\n");
    return -1;
  }

  while (absoluteValue(guess * guess - x) >= epsilon)
    guess = (x / guess + guess) / 2;

  return guess;
}

int main() {
  test();
  verbose();
  int x, y, res;
  float z;

  printf("Enter two non-negative integers to obtain the greatest common "
         "divisor: ");
  scanf("%d %d", &x, &y);

  res = gcd(x, y);
  printf("Greatest common divisor: %d\n", res);

  printf(
      "Enter any positive or negative value, to be taken as absolute value: ");
  scanf("%f", &z);

  z = absoluteValue(z);
  printf("Absolute value: %0.2f\n", z);

  printf("Enter a positive value to be computed as square root: ");
  scanf("%f", &z);

  z = squareRoot(z);
  printf("Square root: %0.2f\n", z);

  return 0;
}
