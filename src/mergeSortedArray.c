/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/merge-sorted-array/
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Time: O(m + n)
 * Space: O(1)
 */
#include <stdlib.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j])
      nums1[k--] = nums1[i--];
    else
      nums1[k--] = nums2[j--];
  }
  while (j >= 0)
    nums1[k--] = nums2[j--];
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  int *nums1;
  int m;
  int *nums2;
  int n;
  int *expected;
} testCase;

static void buildArr(int **to, int *from, int n) {
  *to = malloc(sizeof(int) * n);
  assert(to);
  for (int i = 0; i < n; i++)
    (*to)[i] = from[i];
}

static void assertarr(int *actual, int *expected, int n) {
  for (int i = 0; i < n; i++) {
    assert(actual[i] == expected[i]);
  }
}

int main(void) {
  testCase test;

  // TEST CASE 1
  buildArr(&test.nums1, (int[]){1, 2, 3, 0, 0, 0}, 6);
  test.m = 3;
  buildArr(&test.nums2, (int[]){2, 5, 6}, 3);
  test.n = 3;
  buildArr(&test.expected, (int[]){1, 2, 2, 3, 5, 6}, 6);
  merge(test.nums1, test.m, test.m, test.nums2, test.n, test.n);

  assertarr(test.nums1, test.expected, 6);

  // TEST CASE 2
  buildArr(&test.nums1, (int[]){1}, 1);
  test.m = 1;
  buildArr(&test.nums2, (int[]){}, 0);
  test.n = 0;
  buildArr(&test.expected, (int[]){1}, 1);
  merge(test.nums1, test.m, test.m, test.nums2, test.n, test.n);

  assertarr(test.nums1, test.expected, 1);

  return 0;
}
