#include <iostream>
#include <cmath>

int Displacement(int x0, int xf) {
  return xf - x0;
}

int Square(int val) {
  return val * val;
}

int PythagoreanTheorem(int a, int b) {
  int c;
  a = Square(a);
  b = Square(b);
  c = sqrt(a + b);

  return c;
}

int CalcDistance(int x1,int x2,int y1,int y2) {
  int dx, dy, distance;
  dx = Displacement(x1, x2);
  dy = Displacement(y1, y2);
  distance = PythagoreanTheorem(dx, dy);
  return distance;
}

int main() {
  int distance = CalcDistance(1, 6, 2, 3);
  std::cout << distance << std::endl;

  return 0;
}
