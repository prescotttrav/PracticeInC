#include <stdio.h>

#define MAX_SIZE 100

typedef struct Stack {
  int index, items[MAX_SIZE];
} Stack;

void push(int val, Stack list) {
  list.items[list.index++] = val;
}

int pop(Stack stack) {
  int val = stack.items[stack.index--];
  return val;
}

int main() {
  Stack list = {0};
  int val;
  push(0, list);
  push(1, list);
/*  push(2, list);
  push(3, list);
  val = pop(list);
  if (val != 3) {
    printf("Expected 3, received %d", val);
    return 0;
  }
  val = pop(list);
  if (val != 2) {
    printf("Expected 2, received %d", val);
    return 0;
  }
*/
  val = pop(list);
  if (val != 1) {
    printf("Expected 1, received %d", val);
    return 0;
  }
  val = pop(list);
  if (val != 0) {
    printf("Expected 0, received %d", val);
    return 0;
  }
/*
  val = pop(list);
  if (val != NULL) {
    printf("Expected NULL, received %d", val);
    return 0;
  }
  */

  return 1;
}
