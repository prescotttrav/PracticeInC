#ifndef HEADER_BOARD
#define HEADER_BOARD

#define BOARD_SIZE 3

#include "position.h"

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);

_Bool outOfBoardBounds(int displayValue);

void placeSymbolOnBoard(Position p, char symbol,
                        char board[BOARD_SIZE][BOARD_SIZE]);

_Bool positionIsOutOfBoardBounds(Position p);

#endif
