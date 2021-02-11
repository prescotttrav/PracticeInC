#ifndef HEADER_VALIDATE_WINNER
#define HEADER_VALIDATE_WINNER

#include "board.h"
#include "position.h"

enum Direction
{
  HORIZONTAL,
  VERTICAL,
  FORWARD_DIAG,
  BACKWARD_DIAG
};

_Bool validateWinner(Position p, char symbol,
                     char board[BOARD_SIZE][BOARD_SIZE]);

#endif
