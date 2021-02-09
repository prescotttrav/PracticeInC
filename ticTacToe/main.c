#include "board.h"
#include "main.h"
#include "test/main.h"
#include <stdio.h>

Coordinate convertPositionToCoordinate(int position) {
  Coordinate coord;
  coord.row = (position - 1) / BOARD_SIZE;
  coord.col = (position - 1) % BOARD_SIZE;

  return coord;
}
/*
void placeCoordinate(Coordinate coord, char symbol, char board[]) {
  // Putting symbol in coord.row / col
}

_Bool validateCoordinate(Coordinate coord, char symbol, char board[]) {
  // Validating coordinate is not already on the board
}

Coordinate collectUserCoordinate(char board[]) {
  // Asking user for input & looping until input is valid
}

Coordinate autoGenerateCoordinate(char board[]) {
  // Auto generating the other player by randomly creating variables from 0 - 2
}

_Bool validateIsWinner(Coordinate coord, char symbol, char board[]) {
  // recursive / graph API validate winner
}
*/
int main() {
  test();
  // define board
  /*
  char board[BOARD_SIZE][BOARD_SIZE];
  initializeBoard(board);
  drawBoard(board);
  */
  // retain counter

  convertPositionToCoordinate(9);

  return 0;
}
