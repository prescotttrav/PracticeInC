#include "board.h"
#include "main.h"
#include "test/main.h"
#include <stdio.h>

Coordinate convertPositionToCoordinate(int position) {
  Coordinate coord;

  if (position < 1 || position > BOARD_SIZE * BOARD_SIZE) {
    coord.row = -1;
    coord.col = -1;
  } else {
    coord.row = (position - 1) / BOARD_SIZE;
    coord.col = (position - 1) % BOARD_SIZE;
  }

  return coord;
}

_Bool invalidCoordinate(Coordinate coord) {
  int row = coord.row;
  int col = coord.col;

  if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE)
    return 1;
  else
    return 0;
}

_Bool validateCoordinate(Coordinate coord, char board[BOARD_SIZE][BOARD_SIZE]) {
  if (invalidCoordinate(coord))
    return 0;

  char element = board[coord.row][coord.col];
  if (element == 'O' || element == 'X')
    return 0;
  else
    return 1;
}

Coordinate collectUserCoordinate(char board[BOARD_SIZE][BOARD_SIZE]) {
  Coordinate coord;
  int position;
  printf(
      "Enter the corresponding number to where you want to place your mark: ");
  scanf("%d", &position);

  coord = convertPositionToCoordinate(position);
  while (!validateCoordinate(coord, board)) {
    printf("Invalid input, try entering a different number: ");
    scanf("%d", &position);
    coord = convertPositionToCoordinate(position);
  }

  return coord;
}

/*
void placeCoordinate(Coordinate coord, char symbol, char board[]) {
  // Putting symbol in coord.row / col
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
  // retain counter
  // define board
  char board[BOARD_SIZE][BOARD_SIZE];
  initializeBoard(board);
  drawBoard(board);

  collectUserCoordinate(board);

  return 0;
}
