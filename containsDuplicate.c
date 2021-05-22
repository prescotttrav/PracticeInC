/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/contains-duplicate/
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 * Time: O(n)
 * Space: O(n)
 */
#include <math.h>
#include <stdlib.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

typedef struct node {
  int val;
  struct node *next;
} node;

typedef struct set {
  node **t;
  int size;
} set;

static int hash(set *s, int val) {
  return abs(val % s->size);
}

static _Bool has(set *s, int val) {
  int i = hash(s, val);
  node *n = s->t[i];
  while (n) {
    if (n->val == val)
      return 1;
    n = n->next;
  }
  return 0;
}

static node *newNode(int val) {
  node *n = NULL;
  n = malloc(sizeof(node));

  n->val = val;
  n->next = NULL;
  return n;
}

static void add(set *s, int val) {
  int i = hash(s, val);
  if (has(s, val))
    return;

  node *n = newNode(val);
  n->next = s->t[i];
  s->t[i] = n;
}

static void initSet(set *s, int n) {
  s->size = n;
  s->t = NULL;
  s->t = (node **) malloc(sizeof(node) * n);

  for (int i = 0; i < n; i++) {
    s->t[i] = NULL;
  }
}

_Bool containsDuplicate(int *nums, int numsSize) {
  set s;
  initSet(&s, numsSize);

  for (int i = 0; i < numsSize; i++) {
    if (has(&s, nums[i]))
      return 1;
    else
      (add(&s, nums[i]));
  }
  return 0;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  int input[10];
  int numSize;
  _Bool expected;
  _Bool actual;
} testCase;

static void cpyarr(int to[], int from[], int n) {
  for (int i = 0; i < n; i++)
    to[i] = from[i];
}

int main(void) {
  testCase test = {
      {0},   // input
      0,     // numSize
      0,     // expected
      0,     // actual
  };

  // TEST CASE 1
  test.numSize = 4;
  cpyarr(test.input, (int[]){1, 2, 3, 1}, test.numSize);
  test.expected = 1;
  test.actual = containsDuplicate(test.input, test.numSize);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.numSize = 4;
  cpyarr(test.input, (int[]){1, 2, 3, 4}, test.numSize);
  test.expected = 0;
  test.actual = containsDuplicate(test.input, test.numSize);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.numSize = 4;
  cpyarr(test.input, (int[]){1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, test.numSize);
  test.expected = 1;
  test.actual = containsDuplicate(test.input, test.numSize);

  assert(test.expected == test.actual);

  return 0;
}
