#include <iostream>
#include <cmath>

double area(double radians) {
  double pi = acos(-1.0);
  return pi * radians * radians;
}

int main() {
  double radians = 12.6;
  double result = area(radians);
  std::cout << result << std::endl;

  return 0;
}
