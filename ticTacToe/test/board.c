#include "board.h"
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
    exit(1);
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
  char expected[BOARD_SIZE][BOARD_SIZE] = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  char actual[BOARD_SIZE][BOARD_SIZE];

  initializeBoard(actual);
  if (!matrixEquality(actual, expected, "initializeBoard\0")) {
    exit(-1);
  }
}

void testBoardUtilities() {
  testBlankSpace();
  testVerticalBoarder();
  testInitializeBoard();
}
