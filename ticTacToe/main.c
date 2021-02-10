#include "board.h"
#include "main.h"
#include "test/main.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameTitle() {
  printf("\n__   __     _                             _______ _        _______ "
         "          _______         \n");
  printf(
      "\\ \\ / /    | |                           |__   __(_)      |__   __|  "
      "       |__   __|        \n");
  printf(" \\ V /_____| |_ _ __ ___ _ __ ___   ___     | |   _  ___     | | __ "
         "_  ___     | | ___   ___ \n");
  printf(
      "  > <______| __| '__/ _ \\ '_ ` _ \\ / _ \\    | |  | |/ __|    | |/ _` "
      "|/ __|    | |/ _ \\ / _ \\\n");
  printf(
      " / . \\     | |_| | |  __/ | | | | |  __/    | |  | | (__     | | (_| "
      "| (__     | | (_) |  __/\n");
  printf("/_/ \\_\\     \\__|_|  \\___|_| |_| |_|\\___|    |_|  |_|\\___|    "
         "|_|\\__,_|\\___|    |_|\\___/ \\___|\n\n");
  printf("Press any key to begin...\n");
}

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

  position = (int)rand() % (BOARD_SIZE * BOARD_SIZE + 1);
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

_Bool coordIsOutOfBounds(Coordinate coord) {
  return coord.row >= BOARD_SIZE || coord.row < 0 || coord.col >= BOARD_SIZE ||
         coord.col < 0;
}

Coordinate advanceCoordinate(enum Direction dir, Coordinate coord) {
  switch (dir) {
  case HORIZONTAL:
    coord.col += 1;
    break;
  case VERTICAL:
    coord.row += 1;
    break;
  case FORWARD_DIAG:
    coord.row -= 1;
    coord.col += 1;
    break;
  case BACKWARD_DIAG:
    coord.row += 1;
    coord.col += 1;
    break;
  }
  return coord;
}

Coordinate retractCoordinate(enum Direction dir, Coordinate coord) {
  switch (dir) {
  case HORIZONTAL:
    coord.col -= 1;
    break;
  case VERTICAL:
    coord.row -= 1;
    break;
  case FORWARD_DIAG:
    coord.row += 1;
    coord.col -= 1;
    break;
  case BACKWARD_DIAG:
    coord.row -= 1;
    coord.col -= 1;
    break;
  }
  return coord;
}

_Bool visitedCoordinate(Coordinate coord, Coordinate visited[]) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    if (coordinateEquality(coord, visited[i]))
      return 1;
  }
  return 0;
}

int traverseBoard(int count, enum Direction dir, char symbol, Coordinate coord,
                  int index, Coordinate visited[],
                  char board[BOARD_SIZE][BOARD_SIZE]) {
  Coordinate advanceCoord, retractCoord;
  int advancedTotal, retractedTotal;
  advancedTotal = retractedTotal = 0;

  if (board[coord.row][coord.col] != symbol || coordIsOutOfBounds(coord))
    return count;

  advanceCoord = advanceCoordinate(dir, coord);
  if (!visitedCoordinate(advanceCoord, visited)) {
    visited[index++] = advanceCoord;
    advancedTotal = traverseBoard(count + 1, dir, symbol, advanceCoord, index,
                                  visited, board);
  }

  retractCoord = retractCoordinate(dir, coord);
  if (!visitedCoordinate(retractCoord, visited)) {
    visited[index++] = retractCoord;
    retractedTotal = traverseBoard(count + 1, dir, symbol, retractCoord, index,
                                   visited, board);
  }

  return advancedTotal + retractedTotal;
}

_Bool validateIsWinner(Coordinate coord, char symbol,
                       char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = HORIZONTAL; i <= BACKWARD_DIAG; ++i) {
    Coordinate visited[BOARD_SIZE * BOARD_SIZE] = {
        [0] = coord, [1 ... BOARD_SIZE - 1] = {.row = -1, .col = -1}};
    int count = traverseBoard(0, i, symbol, coord, 1, visited, board);
    if (count - 1 == BOARD_SIZE)
      return 1;
  }
  return 0;
}

Coordinate takeTurn(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  Coordinate coord;
  if (symbol == 'X')
    coord = collectUserCoordinate(board);
  else
    coord = autoGenerateCoordinate(board);
  placeCoordinate(coord, symbol, board);
  system("clear");
  drawBoard(board);

  return coord;
}

int main() {
  test();
  _Bool winner;
  char board[BOARD_SIZE][BOARD_SIZE];
  int counter = 0;

  gameTitle();

  initializeBoard(board);
  drawBoard(board);

  while (counter < BOARD_SIZE * BOARD_SIZE) {
    char symbol = counter % 2 == 0 ? 'X' : 'O';
    Coordinate coord = takeTurn(symbol, board);
    if (validateIsWinner(coord, symbol, board)) {
      // TODO winner text!
      break;
    }
    ++counter;
  }

  return 0;
}
