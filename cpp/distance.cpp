#include <iostream>
#include <cmath>

int Displacement(int x0, int xf) {
  return xf - x0;
}

int ValidateDisplacement() {
  int res = Displacement(0, 5);
  if (res != 5) {
    return 0;
  }
  res = Displacement(6, 0);
  if (res != -6) {
    return 0;
  }
  res = Displacement(3, 3);
  if (res != 0) {
    return 0;
  }
  return 1;
}

int Square(int val) {
  return val * val;
}

int ValidateSquare() {
  int res = Square(1);
  if (res != 1) {
    return 0;
  }
  res = Square(2);
  if (res != 4) {
    return 0;
  }
  res = Square(-6);
  if (res != 36) {
    return 0;
  }
  return 1;
}

int PythagoreanTheorem(int a, int b) {
  int c;
  a = Square(a);
  b = Square(b);
  c = sqrt(a + b);

  return c;
}

int ValidatePythagoreanTheorem() {
  int res = PythagoreanTheorem(3, 4);
  if (res != 5) {
    return 0;
  }
  res = PythagoreanTheorem(4, -4);
  if (res != 5) {
    return 0;
  }
  res = PythagoreanTheorem(1, 4);
  if (res != 4) {
    return 0;
  }
  return 1;
}

int CalcDistance(int x1,int x2,int y1,int y2) {
  int dx, dy, distance;
  dx = Displacement(x1, x2);
  dy = Displacement(y1, y2);
  distance = PythagoreanTheorem(dx, dy);
  return distance;
}

int main() {
  int d, sq, pt;
  d = ValidateDisplacement();
  sq =ValidateSquare();
  pt =ValidatePythagoreanTheorem();

  if (d && sq && pt) {
    int distance = CalcDistance(1, 6, 2, 3);
    std::cout << distance << std::endl;
  }
  return 0;
}
