#include "../board.h"
#include "../main.h"
#include "../utils.h"
#include "board.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void testConvertPositionToCoordinate() {
  Coordinate actual, expected;

  expected.row = -1;
  expected.col = -1;
  actual = convertPositionToCoordinate(0);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 0;
  actual = convertPositionToCoordinate(1);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 1;
  actual = convertPositionToCoordinate(2);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 2;
  actual = convertPositionToCoordinate(3);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = 0;
  actual = convertPositionToCoordinate(4);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = 1;
  actual = convertPositionToCoordinate(5);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = 2;
  actual = convertPositionToCoordinate(6);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 0;
  actual = convertPositionToCoordinate(7);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 1;
  actual = convertPositionToCoordinate(8);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 2;
  actual = convertPositionToCoordinate(9);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = -1;
  expected.col = -1;
  actual = convertPositionToCoordinate(10);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in convertPositionToCoordinate util.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d }",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }
}

void testInvalidCoordinate() {
  Coordinate coord;
  _Bool actual, expected;

  coord.row = -1;
  coord.col = -1;
  expected = 1;
  actual = invalidCoordinate(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in invalidCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 10;
  coord.col = 5;
  expected = 1;
  actual = invalidCoordinate(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in invalidCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 0;
  expected = 0;
  actual = invalidCoordinate(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in invalidCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }
}

void testValidateCoordinate() {
  Coordinate coord;
  _Bool actual, expected;
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'1', 'O', '3'}, {'X', 'O', 'X'}, {'7', '8', 'X'}};

  coord.row = 0;
  coord.col = 0;
  expected = 1;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 2;
  coord.col = 1;
  expected = 1;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 2;
  expected = 1;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 1;
  expected = 0;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 1;
  coord.col = 1;
  expected = 0;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 2;
  coord.col = 2;
  expected = 0;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 1;
  coord.col = 0;
  expected = 0;
  actual = validateCoordinate(coord, board);
  if (actual != expected) {
    fprintf(stderr, "Error in validateCoordinate utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }
}

void testAdvanceCoordinate() {
  Coordinate actual, expected, original;

  original.row = 1;
  original.col = 1;

  expected.row = 1;
  expected.col = 2;
  actual = advanceCoordinate(HORIZONTAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 1;
  actual = advanceCoordinate(VERTICAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 2;
  actual = advanceCoordinate(FORWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 2;
  actual = advanceCoordinate(BACKWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  original.row = 0;
  original.col = 0;

  expected.row = 0;
  expected.col = 1;
  actual = advanceCoordinate(HORIZONTAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = 0;
  actual = advanceCoordinate(VERTICAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = -1;
  expected.col = 1;
  actual = advanceCoordinate(FORWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = 1;
  actual = advanceCoordinate(BACKWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }
}

void testRetractCoordinate() {
  Coordinate actual, expected, original;

  original.row = 1;
  original.col = 1;

  expected.row = 1;
  expected.col = 0;
  actual = retractCoordinate(HORIZONTAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 1;
  actual = retractCoordinate(VERTICAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 2;
  expected.col = 0;
  actual = retractCoordinate(FORWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 0;
  expected.col = 0;
  actual = retractCoordinate(BACKWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  original.row = 0;
  original.col = 0;

  expected.row = 0;
  expected.col = -1;
  actual = retractCoordinate(HORIZONTAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = -1;
  expected.col = 0;
  actual = retractCoordinate(VERTICAL, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = 1;
  expected.col = -1;
  actual = retractCoordinate(FORWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }

  expected.row = -1;
  expected.col = -1;
  actual = retractCoordinate(BACKWARD_DIAG, original);
  if (!coordinateEquality(actual, expected)) {
    fprintf(stderr, "Error in advanceCoordinate utility.\n");
    printf("Expected: { row: %d, col: %d }, received: { row: %d, col: %d}.\n",
           expected.row, expected.col, actual.row, actual.col);
    exit(-1);
  }
}

void testCoordIsOutOfBounds() {
  _Bool actual, expected;
  Coordinate coord;

  coord.row = 1;
  coord.col = 1;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 1;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 0;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 1;
  coord.col = 0;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 2;
  coord.col = 0;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 2;
  coord.col = 1;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 2;
  coord.col = 2;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 2;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 1;
  coord.col = 2;
  expected = 0;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = -1;
  coord.col = 2;
  expected = 1;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 1;
  coord.col = -1;
  expected = 1;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 3;
  coord.col = 1;
  expected = 1;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 0;
  coord.col = 3;
  expected = 1;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }

  coord.row = 3;
  coord.col = 3;
  expected = 1;
  actual = coordIsOutOfBounds(coord);
  if (actual != expected) {
    fprintf(stderr, "Error in coordIsOutOfBounds utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(-1);
  }
}

void testValidateIsWinner() {
  _Bool actual, expected;
  Coordinate coord;
  char symbol;

  coord.row = 1;
  coord.col = 1;
  symbol = 'X';
  char boardTestOne[BOARD_SIZE][BOARD_SIZE] = {
      {'X', 'O', 'O'}, {'4', 'X', 'O'}, {'O', '8', 'X'}};
  expected = 1;
  actual = validateIsWinner(coord, symbol, boardTestOne);
  if (actual != expected) {
    fprintf(stderr, "Error in validateIsWinner utility.\n");
    printf("Expected: %d, received: %d.\n", expected, actual);
    exit(1);
  }
}

/*
void testPlaceCoordinate() {
}

void testCollectUserCoordinate() {
}

void testAutoGenerateCoordinate() {
}

void testValidateIsWinner() {
}
*/

void test() {
  testBoardUtilities();
  testConvertPositionToCoordinate();
  testInvalidCoordinate();
  testValidateCoordinate();
  testAdvanceCoordinate();
  testRetractCoordinate();
  testCoordIsOutOfBounds();
  testValidateIsWinner();
  /*
  testPlaceCoordinate();
  testValidateCoordinate();
  testCollectUserCoordinate();
  testAutoGenerateCoordinate();
  testValidateIsWinner();
  */
}
