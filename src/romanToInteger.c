/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/roman-to-integer/
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <stdlib.h>
#include <string.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

int getVal(int c) {
  switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
    default:
      return 1000;
  }
}

int romanToInt(char *s) {
  int c;
  int res = 0;
  for (int i = 0; (c = s[i]) != '\0'; i++) {
    if (s[i + 1] != '\0' && getVal(c) < getVal(s[i + 1]))
      res -= getVal(c);
    else
      res += getVal(c);
  }
  return res;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  char *input;
  int expected;
  int actual;
} testCase;

static void buildInput(testCase *t, char *str) {
  t->input = realloc(t->input, sizeof(char) * (strlen(str) + 1));
  assert(t->input);
  strcpy(t->input, str);
}

int main(void) {
  testCase test;

  // TEST CASE 1
  buildInput(&test, "III");
  test.expected = 3;
  test.actual = romanToInt(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 2
  buildInput(&test, "IX");
  test.expected = 9;
  test.actual = romanToInt(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 3
  buildInput(&test, "MCMXCIV");
  test.expected = 1994;
  test.actual = romanToInt(test.input);

  assert(test.expected == test.actual);

  free(test.input);
  return 0;
}
