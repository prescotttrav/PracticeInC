#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Not ideal way to compare doubles; simply a lazy hack.
_Bool doubleEquality(double actual, double expected) {
  int comparedResult;
  char first[50], second[50];
  sprintf(first, "%f", actual);
  sprintf(second, "%f", expected);
  comparedResult = strcmp(first, second);
  return comparedResult == 0;
}

_Bool test() {
  double days, years, expected;

  days = calculateDays(1440);
  expected = 1.000000;
  if (!doubleEquality(days, expected)) {
    printf("Failed calculateDays; expected %lf, received %lf\n", expected,
           days);
    return 0;
  }
  days = calculateDays(525600);
  expected = 365.000000;
  if (!doubleEquality(days, expected)) {
    printf("Failed calculateDays; expected %lf, received %lf\n", expected,
           days);
    return 0;
  }
  days = calculateDays(479);
  expected = 0.332639;
  if (!doubleEquality(days, expected)) {
    printf("Failed calculateDays; expected %lf, received %lf\n", expected,
           days);
    return 0;
  }
  days = calculateDays(1);
  expected = .000694;
  if (!doubleEquality(days, expected)) {
    printf("Failed calculateDays; expected %lf, received %lf\n", expected,
           days);
    return 0;
  }

  years = calculateYears(1);
  expected = 1.9026e-6;
  if (!doubleEquality(years, expected)) {
    printf("Failed calculateYears; expected %lf, received %lf\n", expected,
           years);
    return 0;
  }
  years = calculateYears(525600);
  expected = 1.0;
  if (!doubleEquality(years, expected)) {
    printf("Failed calculateYears; expected %lf, received %lf\n", expected,
           years);
    return 0;
  }
  years = calculateYears(262800);
  expected = .5;
  if (!doubleEquality(years, expected)) {
    printf("Failed calculateYears; expected %lf, received %lf\n", expected,
           years);
    return 0;
  }
  years = calculateYears(1.918e+8);
  expected = 364.916286;
  if (!doubleEquality(years, expected)) {
    printf("Failed calculateYears; expected %lf, received %lf\n", expected,
           years);
    return 0;
  }

  return 1;
}
