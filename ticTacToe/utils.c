#include "utils.h"

_Bool coordinateEquality(Coordinate coord1, Coordinate coord2) {
  return coord1.row == coord2.row && coord1.col == coord2.col;
}
