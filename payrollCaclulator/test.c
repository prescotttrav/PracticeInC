#include "main.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool floatComparison(float x, float y) {
  char strX[PRECISION], strY[PRECISION];

  gcvt(x, PRECISION, strX);
  gcvt(y, PRECISION, strY);

  return strcmp(strX, strY) == 0 ? 1 : 0;
}

void testCalculateOvertime() {
  float expected, actual;
  expected = 0.0;
  actual = calculateOvertime(40.0);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 5.0;
  actual = calculateOvertime(45.0);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = .50;
  actual = calculateOvertime(40.50);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 460.0;
  actual = calculateOvertime(500.0);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testCalculateGrossPay() {
  HoursWorked hours;
  float expected, actual;
  expected = 0.0;
  hours = (HoursWorked){0.0, 0.0};
  actual = calculateGrossPay(hours);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 480.0;
  hours = (HoursWorked){40.0, 0.0};
  actual = calculateGrossPay(hours);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 489.0;
  hours = (HoursWorked){40.0, 0.50};
  actual = calculateGrossPay(hours);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 570.0;
  hours = (HoursWorked){40.0, 5.0};
  actual = calculateGrossPay(hours);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 8760.0;
  hours = (HoursWorked){40.0, 460.0};
  actual = calculateGrossPay(hours);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testDetermineTaxCost() {
  float expected, actual;
  expected = 45.0;
  actual = determineTaxCost(300, 0.15);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 30.0;
  actual = determineTaxCost(150, .2);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 125.0;
  actual = determineTaxCost(500, .25);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 4818.0;
  actual = determineTaxCost(8760, .55);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testCalculateTaxes() {
  float expected, actual;
  expected = 82.50;
  actual = calculateTaxes(480);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 105.0;
  actual = calculateTaxes(570);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 150.0;
  actual = calculateTaxes(750);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 2152.50;
  actual = calculateTaxes(8760);
  if (!floatComparison(actual, expected)) {
    fprintf(stderr, "Error in testing calculate overtime utility.\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

_Bool test() {
  testCalculateOvertime();
  testCalculateGrossPay();
  testDetermineTaxCost();
  testCalculateTaxes();

  return 1;
}
