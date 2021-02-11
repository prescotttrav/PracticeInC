#ifndef HEADER_POSITION
#define HEADER_POSITION

#include "board.h"

typedef struct {
  int col, row;
} Position;

#include "validateWinner.h"

Position convertDisplayValueToPosition(int displayValue);

Position advancePosition(enum Direction dir, Position p);

Position retractPosition(enum Direction dir, Position p);

_Bool positionEquality(Position p1, Position p2);

_Bool validPosition(int displayValue, char board[BOARD_SIZE][BOARD_SIZE]);

_Bool visitedPosition(Position cur, Position visited[]);

#endif
