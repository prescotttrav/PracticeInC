/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/linked-list-cycle/
 *
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <stdlib.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

static ListNode *advance(ListNode *node, int n) {
  for (int i = 0; i < n; i++) {
    if (node) {
      node = node->next;
    } else {
      return NULL;
    }
  }
  return node;
}

_Bool hasCycle(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && slow) {
    slow = advance(slow, 1);
    fast = advance(fast, 2);
    if (slow && fast && slow == fast)
      return 1;
  }
  return 0;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  ListNode *input;
  int expected;
  int actual;
} testCase;

static ListNode *newNode(int val) {
  ListNode *n = NULL;
  n = malloc(sizeof(ListNode));
  n->val = val;
  n->next = NULL;
  return n;
}

static ListNode *buildInput(int list[], int pos, int n) {
  ListNode *head, *cur, *prev;
  prev = NULL;
  for (int i = 0; i < n; i++) {
    cur = newNode(list[i]);
    if (i == 0)
      head = cur;
    if (prev)
      prev->next = cur;
    prev = cur;
  }
  if (pos >= 0) {
    cur = head;
    for (int i = 0; i < pos; i++)
      cur = cur->next;
    prev->next = cur;
  }
  return head;
}

int main(void) {
  testCase test;

  // TEST CASE 1
  test.input = buildInput((int[]){3, 2, 0, -4}, 1, 4);
  test.expected = 1;
  test.actual = hasCycle(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.input = buildInput((int[]){1, 2}, 0, 2);
  test.expected = 1;
  test.actual = hasCycle(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.input = buildInput((int[]){1}, -1, 1);
  test.expected = 0;
  test.actual = hasCycle(test.input);

  assert(test.expected == test.actual);

  return 1;
}
