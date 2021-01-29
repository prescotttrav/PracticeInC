#include "main.h"
#include "test.h"
#include <stdio.h>

_Bool test() {
  DaysOfWeek actual, expected;

  expected = Sunday;
  actual = obtainDaysOfWeek(0);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Monday;
  actual = obtainDaysOfWeek(1);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Tuesday;
  actual = obtainDaysOfWeek(2);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Wednesday;
  actual = obtainDaysOfWeek(3);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Thursday;
  actual = obtainDaysOfWeek(4);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Friday;
  actual = obtainDaysOfWeek(5);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Saturday;
  actual = obtainDaysOfWeek(6);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  expected = Saturday;
  actual = obtainDaysOfWeek(10);
  if (actual != expected) {
    printf("Test case did not pass; expected: %d, received: %d\n", expected,
           actual);
    return 0;
  }

  return 1;
}
