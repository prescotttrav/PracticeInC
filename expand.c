#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 1000
#define TEST_ONE_RESULT "abcdefghijklmnopqrstuvwxyz"
#define TEST_TWO_RESULT "abc"
#define TEST_THREE_RESULT "0123456789"
#define TEST_FOUR_RESULT "abcdefghijklmnopqrstuvwxyz0123456789"
#define TEST_FIVE_RESULT "abcdefg456"

typedef struct ValueAndIndex {
  int val, index;
} ValueAndIndex;

ValueAndIndex getValueAndIndex(int i, char input[]) {
  ValueAndIndex s;
  s.val = input[i++];
  if (s.val == '-')
    s.val = input[i++];
  s.index = i;

  return s;
}

void expand(char input[], char output[]) {
  ValueAndIndex a, b;
  int i, j;
  i = j = 0;

  a = getValueAndIndex(i, input);
  while (a.val != '\0') {
    b = getValueAndIndex(a.index, input);
    while (a.val < b.val) 
      output[j++] = a.val++;
    output[j++] = a.val;
    a = getValueAndIndex(b.index, input);
  }
  output[j] = '\0';
}

void copyString(char from[], char to[]) {
  int c, i;
  for (i = 0; (c = from[i]) != '\0'; i++) {
    to[i] = c;
  }
  to[++i] = '\0';
}

int main() {
  char test[MAX_WIDTH], result[MAX_WIDTH];

  copyString("a-z", test);
  expand(test, result);
  if (strcmp(result, TEST_ONE_RESULT))
    printf("Test case one failed, %s\n", result);

  copyString("a-b-c", test);
  expand(test, result);
  if (strcmp(result, TEST_TWO_RESULT))
    printf("Test case two failed, %s\n", result);

  copyString("0-9", test);
  expand(test, result);
  if (strcmp(result, TEST_THREE_RESULT))
    printf("Test case three failed, %s\n", result);

  copyString("a-z0-9", test);
  expand(test, result);
  if (strcmp(result, TEST_FOUR_RESULT))
    printf("Test case four failed, %s\n", result);

  copyString("-a-g-4-6", test);
  expand(test, result);
  if (strcmp(result, TEST_FIVE_RESULT))
    printf("Test case five failed, %s\n", result);

  return 0;
}
