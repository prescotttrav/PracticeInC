#ifndef HEADER_PLAYER_MOVE
#define HEADER_PLAYER_MOVE

#include "board.h"
#include "position.h"

Position playerMove(char symbol, char board[BOARD_SIZE][BOARD_SIZE]);

Position playerTurn(char symbol, char board[BOARD_SIZE][BOARD_SIZE]);

#endif
