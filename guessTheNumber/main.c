#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

short generateValue() {
  srand(time(0));
  return rand() % 21;
}

short collectUserGuess() {
  short guess;

  printf("Enter your guess, values can be whole numbers 0 - 20: ");
  scanf("%hi", &guess);

  return guess;
}

short evaluateUserGuess(short guess, short actual) {
  if (guess == actual)
    return 0;
  else if (guess > actual)
    return 1;
  else
    return -1;
}

int main() {
  test();
  short value, count, guessValue, guessResult;
  char indicator[5];

  value = generateValue();

  for (count = 0; count < 5; count++) {
    guessValue = collectUserGuess();
    guessResult = evaluateUserGuess(guessValue, value);
    if (guessResult == 0) {
      printf("You guessed the correct value!\n");
      break;
    }
    guessResult > 0 ? strcpy(indicator, "high") : strcpy(indicator, "low");
    printf("Your guess was too %s\n", indicator);
  }

  return 0;
}
