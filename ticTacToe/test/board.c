#include "../board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testBlankSpace() {
  char *actual = blankSpace();
  char expected[4];

  strcpy(expected, "   ");
  if (strcmp(actual, expected) != 0) {
    fprintf(stderr, "Error in blankSpace utility.\n");
    printf("Expected: %s, received: %s.\n", expected, actual);
  }

  strcpy(expected, " ");
  if (strcmp(actual, expected) == 0) {
    fprintf(stderr, "Error in blankSpace utility.\n");
    printf("Expected: %s, received: %s.\n", expected, actual);
    exit(1);
  }
}

void testVerticalBoarder() {
  char actual;

  actual = verticalBoarder(0);
  if (actual != '|') {
    fprintf(stderr, "Error in verticalBoarder utility.\n");
    printf("Expected: %c, received: %c.\n", '|', actual);
    exit(-1);
  }

  actual = verticalBoarder(1);
  if (actual != '|') {
    fprintf(stderr, "Error in verticalBoarder utility.\n");
    printf("Expected: %c, received: %c.\n", '|', actual);
    exit(-1);
  }

  actual = verticalBoarder(2);
  if (actual != '\0') {
    fprintf(stderr, "Error in verticalBoarder utility.\n");
    printf("Expected: %c, received: %c.\n", '\0', actual);
    exit(-1);
  }

  actual = verticalBoarder(10);
  if (actual != '\0') {
    fprintf(stderr, "Error in verticalBoarder utility.\n");
    printf("Expected: %c, received: %c.\n", '\0', actual);
    exit(-1);
  }
}

void testInitializeBoard() {
}

void testBoardUtilities() {
  testBlankSpace();
  testVerticalBoarder();
  testInitializeBoard();
}
