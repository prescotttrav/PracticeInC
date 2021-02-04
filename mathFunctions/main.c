#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void throwNegativeIntError(char func[]) {
  fprintf(stderr, "Negatvie int supplied to positive-only arguments, in %s",
          func);
  exit(-1);
}

// TODO update to recursion
int gcd(int x, int y) {
  if (x < 0 || y < 0)
    throwNegativeIntError("gcd");
  int divisor = x < y ? x : y;
  for (int n = divisor; n > 0; --n) {
    if (x % n == 0 && y % n == 0)
      return n;
  }
}

float absoluteValue(float x) {
  if (x < 0)
    x = -x;
  return x;
}

float squareRoot(float x) {
  return x;
}

int main() {
  test();
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
