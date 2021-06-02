/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/majority-element/
 *
 * Given an array nums of size n, return the majority element.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <assert.h>

/* --------------------------------- problem -------------------------------- */

int majorityElement(int *nums, int numsSize) {
  int res = -1;
  int count = 0;
  for (int i = 0; i < numsSize; i++) {
    if (count == 0)
      res = nums[i];
    count += nums[i] == res ? 1 : -1;
  }
  return res;
}

/* --------------------------------- testing -------------------------------- */

typedef struct TestCase {
  int input[7];
  int size;
  int expected;
  int actual;
} TestCase;

static void arrcpy(int *to, int *from, int n) {
  for (int i = 0; i < n; i++)
    to[i] = from[i];
}

int main(void) {
  TestCase test;

  // TEST CASE 1
  test.size = 7;
  arrcpy(test.input, (int[]){2, 2, 1, 1, 1, 2, 2}, test.size);
  test.expected = 2;
  test.actual = majorityElement(test.input, test.size);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.size = 1;
  arrcpy(test.input, (int[]){1}, test.size);
  test.expected = 1;
  test.actual = majorityElement(test.input, test.size);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.size = 6;
  arrcpy(test.input, (int[]){-1, 1, 1, 1, 2, 1}, test.size);
  test.expected = 1;
  test.actual = majorityElement(test.input, test.size);

  assert(test.expected == test.actual);

  return 0;
}
