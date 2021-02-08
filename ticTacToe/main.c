#include "main.h"
#include <stdio.h>

void placeCoordinate(Coordinate coord, char symbol, char board[]) {
  // Putting symbol in coord.row / col
}

_Bool validateCoordinate(Coordinate coord, char symbol, char board[]) {
  // Validating coordinate is not already on the board
}

Coordinate collectUserCoordinate(char board[]) {
  // Asking user for input & looping until input is valid
}

Coordinate autoGenerateCoordinate(char board[]) {
  // Auto generating the other player by randomly creating variables from 0 - 2
}

_Bool validateIsWinner(Coordinate coord, char symbol, char board[]) {
  // recursive / graph API validate winner
}

int main() {
  // define board
  return 0;
}
