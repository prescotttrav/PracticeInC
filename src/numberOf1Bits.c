/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/number-of-1-bits/
 *
 * Write a function that takes an unsigned integer and returns the number of '1'
 * bits it has (also known as the Hamming weight).
 *
 * Time: O(1)
 * Space: O(1)
 */
#include <inttypes.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

int hammingWeight(uint32_t n) {
  int bits = 0;
  while (n) {
    ++bits;
    n = n & (n - 1);
  }
  return bits;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  uint32_t input;
  int expected;
  int actual;
} testCase;

int main(void) {
  testCase test;

  // TEST CASE 1
  test.input = 11;
  test.expected = 3;
  test.actual = hammingWeight(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.input = 128;
  test.expected = 1;
  test.actual = hammingWeight(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.input = 4294967293;
  test.expected = 31;
  test.actual = hammingWeight(test.input);

  assert(test.expected == test.actual);

  return 0;
}
