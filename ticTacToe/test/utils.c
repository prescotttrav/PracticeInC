#include "../board.h"
#include <stdio.h>
#include <stdlib.h>

_Bool matrixEquality(char actual[BOARD_SIZE][BOARD_SIZE],
                     char expected[BOARD_SIZE][BOARD_SIZE], char *function) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (actual[i][j] != expected[i][j]) {
        fprintf(stderr, "Error in %s utility.\n", function);
        printf("Expected: %c, received: %c.\n", expected[i][j], actual[i][j]);
        return 0;
      }
    }
  }
  return 1;
}
