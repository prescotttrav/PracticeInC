#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void test() {
  signed short actual, expected;

  expected = 0;
  actual = evaluateUserGuess(5, 5);
  if (actual != expected) {
    fprintf(stderr, "Error in testing evaluateUserGuess utility.\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }

  expected = 1;
  actual = evaluateUserGuess(5, 0);
  if (actual != expected) {
    fprintf(stderr, "Error in testing evaluateUserGuess utility.\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }

  expected = -1;
  actual = evaluateUserGuess(0, 5);
  if (actual != expected) {
    fprintf(stderr, "Error in testing evaluateUserGuess utility.\n");
    printf("Expected: %d, received: %d\n", expected, actual);
    exit(-1);
  }
}
