#include "board.h"
#include <stdio.h>

char *blankSpace() {
  return "   ";
}

void boardBuffer() {
  printf("%s", blankSpace());
}

void boardBreakLine() {
  printf("\n %s%s| %s%s|\n", blankSpace(), blankSpace(), blankSpace(),
         blankSpace());
}

char verticalBoarder(int col) {
  return col < BOARD_SIZE - 1 ? '|' : '\0';
}

void horizontalBoarder(int row) {
  if (row < BOARD_SIZE - 1) {
    printf("-------|-------|-------");
  } else {
    printf("\n");
  }
}

void formattedBoardElement(char element, int col) {
  printf("%c%s%c%s", element, blankSpace(), verticalBoarder(col), blankSpace());
}

void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    boardBreakLine();
    boardBuffer();
    for (int j = 0; j < BOARD_SIZE; ++j) {
      formattedBoardElement(board[i][j], j);
    }
    boardBuffer();
    boardBreakLine();
    horizontalBoarder(i);
  }
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  int counter = 0;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = ++counter + '0';
    }
  }
}
