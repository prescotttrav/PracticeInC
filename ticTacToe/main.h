#ifndef HEADER_MAIN
#define HEADER_MAIN

#include "board.h"

#endif

typedef struct {
  int col, row;
} Coordinate;

Coordinate convertPositionToCoordinate(int position);

void placeCoordinate(Coordinate coord, char symbol, char board[]);

_Bool invalidCoordinate(Coordinate coord);

_Bool validateCoordinate(Coordinate coord, char board[BOARD_SIZE][BOARD_SIZE]);

Coordinate collectUserCoordinate(char board[BOARD_SIZE][BOARD_SIZE]);

Coordinate autoGenerateCoordinate(char board[]);

_Bool validateIsWinner(Coordinate coord, char symbol, char board[]);
