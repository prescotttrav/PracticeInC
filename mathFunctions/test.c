#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool floatComparison(float expected, float actual) {
  int precision = 5;
  char expectedStr[precision], actualStr[precision];

  gcvt(expected, precision, expectedStr);
  gcvt(actual, precision, actualStr);

  return strcmp(expectedStr, actualStr) == 0 ? 1 : 0;
}

void testGcd() {
  int actual, expected;

  expected = 1;
  actual = gcd(5, 6);
  if (actual != expected) {
    fprintf(stderr, "Error in testing gcd utility\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }

  expected = 2;
  actual = gcd(100, 2);
  if (actual != expected) {
    fprintf(stderr, "Error in testing gcd utility\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }

  expected = 6;
  actual = gcd(24, 18);
  if (actual != expected) {
    fprintf(stderr, "Error in testing gcd utility\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }

  /* TODO exit -1
  expected = err;
  actual = gcd(24, -18);
  if (actual != expected) {
    fprintf(stderr, "Error in testing gcd utility\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }
  */
}

void testAbs() {
  float actual, expected;

  expected = 0.0;
  actual = absoluteValue(0);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing abs utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 5.0;
  actual = absoluteValue(5);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing abs utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 100.50;
  actual = absoluteValue(-100.50);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing abs utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testSquareRoot() {
  float actual, expected;

  expected = 2.0;
  actual = squareRoot(4.0);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing squareRoots utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 5.656854;
  actual = squareRoot(32.0);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing squareRoots utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = -1;
  actual = squareRoot(-2.0);
  if (!floatComparison(expected, actual)) {
    fprintf(stderr, "Error in testing squareRoots utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  int expectedInt = 5;
  int actualInt = squareRoot(25);
  if (expectedInt != actualInt) {
    fprintf(stderr, "Error in testing squareRoots utility\n");
    printf("Expected: %d, received: %d\n", expectedInt, actualInt);
    exit(-1);
  }
}

void test() {
  quiet();
  testGcd();
  testAbs();
  testSquareRoot();
}
