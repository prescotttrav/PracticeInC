#include "board.h"
#include "position.h"
#include "validateWinner.h"

_Bool positionEquality(Position p1, Position p2) {
  return p1.row == p2.row && p1.col == p2.col;
}

_Bool emptyPosition(Position p) {
  Position emptyPos = {.row = -1, .col = -1};
  return positionEquality(emptyPos, p);
}

Position convertDisplayValueToPosition(int displayValue) {
  Position p;
  p.row = (displayValue - 1) / BOARD_SIZE;
  p.col = (displayValue - 1) % BOARD_SIZE;

  return p;
}

_Bool occupiedDisplayValue(int displayValue,
                           char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = convertDisplayValueToPosition(displayValue);

  return board[p.row][p.col] == 'X' || board[p.row][p.col] == 'O';
}

_Bool validPosition(int displayValue, char board[BOARD_SIZE][BOARD_SIZE]) {
  if (outOfBoardBounds(displayValue) ||
      occupiedDisplayValue(displayValue, board))
    return 0;
  else
    return 1;
}

_Bool visitedPosition(Position cur, Position visited[]) {
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
    if (emptyPosition(visited[i]))
      break;
    else if (positionEquality(cur, visited[i]))
      return 1;
  }
  return 0;
}

Position advancePosition(enum Direction dir, Position p) {
  switch (dir) {
    case HORIZONTAL:
      p.col += 1;
      break;
    case VERTICAL:
      p.row += 1;
      break;
    case FORWARD_DIAG:
      p.row -= 1;
      p.col += 1;
      break;
    case BACKWARD_DIAG:
      p.row += 1;
      p.col += 1;
      break;
  }
  return p;
}

Position retractPosition(enum Direction dir, Position p) {
  switch (dir) {
    case HORIZONTAL:
      p.col -= 1;
      break;
    case VERTICAL:
      p.row -= 1;
      break;
    case FORWARD_DIAG:
      p.row += 1;
      p.col -= 1;
      break;
    case BACKWARD_DIAG:
      p.row -= 1;
      p.col -= 1;
      break;
  }
  return p;
}
