#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void gameTitle() {
  system("clear");
  printf("\n__   __     _                             _______ _        _______ "
         "          _______         \n");
  printf(
      "\\ \\ / /    | |                           |__   __(_)      |__   __|  "
      "       |__   __|        \n");
  printf(" \\ V /_____| |_ _ __ ___ _ __ ___   ___     | |   _  ___     | | __ "
         "_  ___     | | ___   ___ \n");
  printf(
      "  > <______| __| '__/ _ \\ '_ ` _ \\ / _ \\    | |  | |/ __|    | |/ _` "
      "|/ __|    | |/ _ \\ / _ \\\n");
  printf(
      " / . \\     | |_| | |  __/ | | | | |  __/    | |  | | (__     | | (_| "
      "| (__     | | (_) |  __/\n");
  printf("/_/ \\_\\     \\__|_|  \\___|_| |_| |_|\\___|    |_|  |_|\\___|    "
         "|_|\\__,_|\\___|    |_|\\___/ \\___|\n\n");
  printf("Press Enter to begin...");
  while (getchar() != '\n')
    ;
}

char *padding() {
  return "   ";
}

void displayPlayerTurn(char symbol) {
  if (symbol == 'O')
    printf("\n%sPlayer One Turn\n", padding());
  else
    printf("\n%sPlayer Two Turn\n", padding());
}

void boardInteriorPadding() {
  printf("%s", padding());
}

void verticalFormattedBoarder() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE - 1; ++i) {
    printf(" %s%s|", padding(), padding());
  }
  printf("\n");
}

char verticalBoarderChar(int col) {
  return col < BOARD_SIZE - 1 ? '|' : '\0';
}

void horizontalBoarderFormattedSize() {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    printf("-------%c", verticalBoarderChar(i));
  }
}

void horizontalFormatedBoarder(int row) {
  if (row < BOARD_SIZE - 1)
    horizontalBoarderFormattedSize();
  else
    printf("\n");
}

void formattedCellElement(char element, int col) {
  printf("%c%s%c%s", element, padding(), verticalBoarderChar(col), padding());
}

void drawBoard(char symbol, char board[BOARD_SIZE][BOARD_SIZE]) {
  system("clear");
  displayPlayerTurn(symbol);
  for (int i = 0; i < BOARD_SIZE; ++i) {
    verticalFormattedBoarder();
    boardInteriorPadding();
    for (int j = 0; j < BOARD_SIZE; ++j) {
      formattedCellElement(board[i][j], j);
    }
    boardInteriorPadding();
    verticalFormattedBoarder();
    horizontalFormatedBoarder(i);
  }
}

void displayWinner(char symbol) {
  if (symbol == 'X') {
    printf("__     ______  _    _  __          _______ _   _ _ _ _ \n");
    printf("\\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | | | |\n");
    printf(" \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | | | |\n");
    printf("  \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | | | |\n");
    printf("   | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |_|_|_|\n");
    printf(
        "   |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_(_|_|_)\n\n\n");
  } else {
    printf("__     ______  _    _   _      ____   _____ ______       \n");
    printf("\\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|      \n");
    printf(" \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__         \n");
    printf("  \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|        \n");
    printf("   | | | |__| | |__| | | |___| |__| |____) | |____ _ _ _ \n");
    printf(
        "   |_|  \\____/ \\____/  |______\\____/|_____/|______(_|_|_)\n\n\n");
  }
}

void displayDraw() {
  printf(" _____  _____       __          ___ \n");
  printf("|  __ \\|  __ \\     /\\ \\        / / |\n");
  printf("| |  | | |__) |   /  \\ \\  /\\  / /| |\n");
  printf("| |  | |  _  /   / /\\ \\ \\/  \\/ / | |\n");
  printf("| |__| | | \\ \\  / ____ \\  /\\  /  |_|\n");
  printf("|_____/|_|  \\_\\/_/    \\_\\/  \\/   (_)\n\n\n");
}
