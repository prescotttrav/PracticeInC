#ifndef HEADER_BOARD
#define HEADER_BOARD

#define BOARD_SIZE 3

enum Direction
{
  HORIZONTAL,
  VERTICAL,
  FORWARD_DIAG,
  BACKWARD_DIAG
};

char *blankSpace();

char verticalBoarder(int col);

void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]);

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);

#endif
