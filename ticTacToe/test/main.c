#include "../main.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

_Bool coordinateEquality(Coordinate actual, Coordinate expected) {
  return actual.row == expected.row && actual.col == expected.col;
}

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
  /*
  testPlaceCoordinate();
  testValidateCoordinate();
  testCollectUserCoordinate();
  testAutoGenerateCoordinate();
  testValidateIsWinner();
  */
}
