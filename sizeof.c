#include <stdio.h>

int main() {
  int intValOne, intValTwo;
  float floatVal;
  double doubleVal;
  char charVal, charArr[3];
  _Bool boolean;
  unsigned short uShortVal;
  signed short sShortVal;
  long longVal;
  long double lDoubleVal;

  printf("sizeof unassigned int: %lu\n", sizeof(intValOne));
  intValTwo = 2;
  printf("sizeof assigned int: %lu\n", sizeof(intValTwo));
  intValOne = 600;
  printf("sizeof arithmetic int: %lu\n", sizeof(intValOne + intValTwo));

  printf("sizeof float: %lu\n", sizeof(floatVal));
  printf("sizeof double: %lu\n", sizeof(doubleVal));
  printf("sizeof char: %lu\n", sizeof(charVal));
  printf("sizeof char array of 3: %lu\n", sizeof(charArr));
  printf("sizeof boolean: %lu\n", sizeof(boolean));

  printf("sizeof unsigned short: %lu\n", sizeof(uShortVal));
  printf("sizeof signed short: %lu\n", sizeof(sShortVal));
  printf("sizeof long: %lu\n", sizeof(longVal));

  printf("sizeof long double: %lu\n", sizeof(lDoubleVal));

  return 0;
}
