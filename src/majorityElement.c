/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/majority-element/
 *
 * Given an array nums of size n, return the majority element.
 *
 * Time: O(nlgn)
 * Space: O(1)
 */
#include <stdlib.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

static int countRange(int *nums, int lo, int hi, int val) {
  int count = 0;
  for (int i = lo; i <= hi; i++) {
    if (nums[i] == val)
      ++count;
  }
  return count;
}

static int majorityHelper(int *nums, int lo, int hi) {
  if (lo == hi)
    return nums[lo];
  int mid = (lo + hi) / 2;
  int left = majorityHelper(nums, lo, mid);
  int right = majorityHelper(nums, mid + 1, hi);
  if (left == right)
    return left;
  int leftCount = countRange(nums, lo, hi, left);
  int rightCount = countRange(nums, lo, hi, right);
  return leftCount > rightCount ? left : right;
}

int majorityElement(int *nums, int numsSize) {
  return majorityHelper(nums, 0, numsSize - 1);
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
