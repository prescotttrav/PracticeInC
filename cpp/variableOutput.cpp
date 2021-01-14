#include <iostream>

int main() {
  int hour, minute;
  char colon = ':';

  hour = 8;
  minute = 33;

  // multi line
  std::cout << "The current times is ";
  std::cout << hour;
  std::cout << colon;
  std::cout << minute;
  std::cout << std::endl;
  // single line
  std::cout << "The current time is " << hour << colon << minute << std::endl;

  return 0;
}
