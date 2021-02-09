#include "../main.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

_Bool coordinateEquality(Coordinate actual, Coordinate expected) {
  return actual.row == expected.row && actual.col == expected.col;
}

void testConvertPositionToCoordinate() {
  Coordinate actual, expected;

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
}

/*
void testPlaceCoordinate() {
}

void testValidateCoordinate() {
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
  /*
  testPlaceCoordinate();
  testValidateCoordinate();
  testCollectUserCoordinate();
  testAutoGenerateCoordinate();
  testValidateIsWinner();
  */
}
