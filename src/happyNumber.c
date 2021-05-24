/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/happy-number/
 *
 * Write an algorithm to determine if a number n is happy.
 *
 * n = summation of squared digits
 * Time: O(n)
 * Space: O(n)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <math.h>

/* --------------------------------- problem -------------------------------- */

static int repeated(int val, int *memo, int size) {
  for (int i = 0; i < size; i++) {
    if (memo[i] == val)
      return 1;
  }
  return 0;
}

static int happyHelper(int n, int *memo, int i) {
  int sum = 0;
  while (n != 0) {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }
  if (sum == 1)
    return 1;
  if (repeated(sum, memo, i))
    return 0;
  memo = realloc(memo, sizeof(int) * (i + 1));
  memo[i++] = sum;
  return happyHelper(sum, memo, i);
}

_Bool isHappy(int n) {
  int *memo = NULL;
  int i = 0;
  return happyHelper(n, memo, i);
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  int input;
  int expected;
  int actual;
} testCase;

int main(void) {
  testCase test;

  // TEST CASE 1
  test.input = 19;
  test.expected = 1;
  test.actual = isHappy(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.input = 2;
  test.expected = 0;
  test.actual = isHappy(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.input = 7;
  test.expected = 1;
  test.actual = isHappy(test.input);

  assert(test.expected == test.actual);

  return 1;
}
