#include "board.h"
#include "display.h"
#include "main.h"
#include "playerMove.h"
#include "position.h"
#include "validateWinner.h"
//#include "test/main.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeGame(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  gameTitle();
  initializeBoard(board);
  drawBoard(symbol, board);
}

int main() {
  // test();
  char board[BOARD_SIZE][BOARD_SIZE];
  int counter = 0;

  initializeGame('O', board);

  while (counter < BOARD_SIZE * BOARD_SIZE) {
    char symbol = counter % 2 == 0 ? 'X' : 'O';
    Position p = playerTurn(symbol, board);

    if (validateWinner(p, symbol, board)) {
      displayWinner(symbol);
      break;
    }
    ++counter;
  }

  if (counter == BOARD_SIZE * BOARD_SIZE)
    displayDraw();

  return 0;
}
