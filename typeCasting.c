#include <stdio.h>

int integerAddition(double x, double y) {
  int res;
  res = (int) x + (int) y;
  printf("input: %.2lf, %.2lf; result: %d\n", x, y, res);
  return res;
}

float preciseDivision(int numerator, int denominator) {
  float res;
  res = numerator / (float) denominator;
  printf("input: %d, %d; result: %f\n", numerator, denominator, res);
  return res;
}

int main() {
  double a, b;
  int c, d;

  a = 12.2;
  b = 15.6;

  c = integerAddition(a, b);
  d = 15;

  preciseDivision(c, d);

  return 0;
}
