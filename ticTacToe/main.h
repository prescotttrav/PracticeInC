#ifndef HEADER_BOARD
#define HEADER_BOARD

#include "board.h"

#endif

typedef struct {
  int col, row;
} Coordinate;

Coordinate convertPositionToCoordinate(int position);

void placeCoordinate(Coordinate coord, char symbol,
                     char board[BOARD_SIZE][BOARD_SIZE]);

_Bool invalidCoordinate(Coordinate coord);

_Bool validateCoordinate(Coordinate coord, char board[BOARD_SIZE][BOARD_SIZE]);

Coordinate collectUserCoordinate(char board[BOARD_SIZE][BOARD_SIZE]);

Coordinate autoGenerateCoordinate(char board[BOARD_SIZE][BOARD_SIZE]);

_Bool validateIsWinner(Coordinate coord, char symbol,
                       char board[BOARD_SIZE][BOARD_SIZE]);

Coordinate advanceCoordinate(enum Direction dir, Coordinate coord);

Coordinate retractCoordinate(enum Direction dir, Coordinate coord);

_Bool coordIsOutOfBounds(Coordinate coord);
