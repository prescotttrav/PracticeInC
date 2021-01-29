#include "test.h"
#include <stdio.h>
#include <stdlib.h>

long obtainMinutes(int count, char *values[]) {
  long minutes;
  if (count > 1) {
    minutes = strtol(values[1], NULL, 10);
  } else {
    printf("Enter minutes: \n");
    scanf("%ld", &minutes);
  }
  return minutes;
}

double calculateDays(long minutes) {
  return minutes / 60.0 / 24.0;
}

double calculateYears(long minutes) {
  double days = calculateDays(minutes);
  return days / 365.0;
}

int main(int argc, char *argv[]) {
  if (!test())
    return -1;
  long minutes;
  double days, years;

  minutes = obtainMinutes(argc, argv);
  days = calculateDays(minutes);
  years = calculateYears(minutes);

  printf("Minutes: %ld, days: %lf, years: %lf\n", minutes, days, years);

  return 0;
}
