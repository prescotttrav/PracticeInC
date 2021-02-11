#ifndef HEADER_DISPLAY
#define HEADER_DISPLAY

#include "board.h"

void gameTitle();

void drawBoard(char symbol, char board[BOARD_SIZE][BOARD_SIZE]);

void displayPlayerTurn(char symbol);

void displayWinner(char symbol);

void displayDraw();

#endif
