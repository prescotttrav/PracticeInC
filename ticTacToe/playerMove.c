#include "board.h"
#include "display.h"
#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void waitFor(int secs) {
  int retTime = time(0) + secs;
  while (time(0) < retTime)
    ;
}

int autoGenerateMove(char board[BOARD_SIZE][BOARD_SIZE]) {
  int displayValue;

  srand(time(NULL));
  displayValue = (int) rand() % (BOARD_SIZE * BOARD_SIZE + 1);

  while (!validPosition(displayValue, board)) {
    displayValue = (int) rand() % (BOARD_SIZE * BOARD_SIZE + 1);
  }

  waitFor(2);
  return displayValue;
}

// TODO breaks on float & char
int collectUserMove(char board[BOARD_SIZE][BOARD_SIZE]) {
  int displayValue;

  printf(
      "Enter the corresponding number to where you want to place your mark: ");
  scanf("%d", &displayValue);

  while (!validPosition(displayValue, board)) {
    printf("Invalid input, try entering a different number: ");
    scanf("%d", &displayValue);
  }

  return displayValue;
}

Position playerMove(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p;
  int displayValue;

  if (symbol == 'X')   // TODO allow selecting of char
    displayValue = collectUserMove(board);
  else
    displayValue = autoGenerateMove(board);   // TODO allow two players

  p = convertDisplayValueToPosition(displayValue);
  return p;
}

Position playerTurn(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = playerMove(symbol, board);
  placeSymbolOnBoard(p, symbol, board);
  drawBoard(symbol, board);

  return p;
}
