#include "board.h"
#include "position.h"
#include "validateWinner.h"

void initializeVisitedPositions(Position p, Position visited[]) {
  Position emptyP = {.row = -1, .col = -1};
  visited[0] = p;

  for (int i = 1; i < BOARD_SIZE * BOARD_SIZE; ++i) {
    visited[i] = emptyP;
  }
}

int adjacentSimilarElements(int count, enum Direction dir, char symbol,
                            Position p, int index, Position visited[],
                            char board[BOARD_SIZE][BOARD_SIZE]) {
  Position advancedPos, retractedPos;
  int advancedTotal, retractedTotal;
  advancedTotal = retractedTotal = 0;

  if (positionIsOutOfBoardBounds(p) || board[p.row][p.col] != symbol)
    return count;

  advancedPos = advancePosition(dir, p);
  if (!visitedPosition(advancedPos, visited)) {
    visited[index++] = advancedPos;
    advancedTotal = adjacentSimilarElements(count + 1, dir, symbol, advancedPos,
                                            index, visited, board);
  }

  retractedPos = retractPosition(dir, p);
  if (!visitedPosition(retractedPos, visited)) {
    visited[index++] = retractedPos;
    retractedTotal = adjacentSimilarElements(
        count + 1, dir, symbol, retractedPos, index, visited, board);
  }

  return advancedTotal + retractedTotal;
}

_Bool validateWinner(Position p, char symbol,
                     char board[BOARD_SIZE][BOARD_SIZE]) {
  Position visited[BOARD_SIZE * BOARD_SIZE];

  for (int i = HORIZONTAL; i <= BACKWARD_DIAG; ++i) {
    initializeVisitedPositions(p, visited);
    int count = adjacentSimilarElements(0, i, symbol, p, 1, visited, board);
    if (count - 1 == BOARD_SIZE)
      return 1;
  }
  return 0;
}
