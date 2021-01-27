#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convertF(int degree) {
  return (5.0 / 9.0) * (degree - 32);
}

int convertC(float degree) {
  return degree * (9.0 / 5.0) + 32;
}

int main() {
  printf("Fahrenheit to Celsius\n");
  for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d\t%6.1f\n", fahr, convertF(fahr));
  }
  printf("Celsius to Fahrenheit\n");
  for (float celsius = convertF(LOWER); celsius <= convertF(UPPER);
       celsius -= convertF(STEP - 10)) {
    printf("%6.1f\t%3d\n", celsius, convertC(celsius));
  }
  return 0;
}
