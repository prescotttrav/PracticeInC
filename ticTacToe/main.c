#include "board.h"
#include "main.h"
#include "test/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

Coordinate autoGenerateCoordinate(char board[BOARD_SIZE][BOARD_SIZE]) {
  Coordinate coord;
  int position;

  srand(time(NULL));

  position = (int) rand() % (BOARD_SIZE * BOARD_SIZE + 1);
  coord = convertPositionToCoordinate(position);

  while (!validateCoordinate(coord, board)) {
    position = (rand() % (BOARD_SIZE * BOARD_SIZE + 1));
    coord = convertPositionToCoordinate(position);
  }

  return coord;
}

void placeCoordinate(Coordinate coord, char symbol,
                     char board[BOARD_SIZE][BOARD_SIZE]) {
  board[coord.row][coord.col] = symbol;
}

// RE DO
_Bool validateIsWinner(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  return 0;
  /*
  Base case count == 3 || coord is out of range
  */
}

void takeTurn(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  Coordinate coord;
  if (symbol == 'X')
    coord = collectUserCoordinate(board);
  else
    coord = autoGenerateCoordinate(board);
  placeCoordinate(coord, symbol, board);
  system("clear");
  drawBoard(board);
}

int main() {
  test();
  _Bool winner;
  char symbol, board[BOARD_SIZE][BOARD_SIZE];
  int counter = 0;

  initializeBoard(board);
  drawBoard(board);

  while (counter < BOARD_SIZE * BOARD_SIZE) {
    symbol = counter % 2 == 0 ? 'X' : 'O';
    takeTurn(symbol, board);
    if (validateIsWinner(symbol, board))
      break;
    ++counter;
  }

  return 0;
}
