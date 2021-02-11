#include "board.h"
#include "position.h"
#include <stdio.h>

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  int counter = 0;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = ++counter + '0';
    }
  }
}

void placeSymbolOnBoard(Position p, char symbol,
                        char board[BOARD_SIZE][BOARD_SIZE]) {
  board[p.row][p.col] = symbol;
}

_Bool outOfBoardBounds(int displayValue) {
  return displayValue < 1 || displayValue > BOARD_SIZE * BOARD_SIZE;
}

_Bool positionIsOutOfBoardBounds(Position p) {
  return p.row < 0 || p.row >= BOARD_SIZE || p.col < 0 || p.col >= BOARD_SIZE;
}
