typedef struct {
  int col, row;
} Coordinate;

void placeCoordinate(Coordinate coord, char symbol, char board[]);

_Bool validateCoordinate(Coordinate coord, char symbol, char board[]);

Coordinate collectUserCoordinate(char board[]);

Coordinate autoGenerateCoordinate(char board[]);

_Bool validateIsWinner(Coordinate coord, char symbol, char board[]);