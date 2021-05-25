/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
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

static ListNode *cycleIntersect(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast && slow) {
    fast = advance(fast, 2);
    slow = advance(slow, 1);
    if (fast && slow && fast == slow) {
      return fast;
    }
  }
  return NULL;
}

static ListNode *cycleStart(ListNode *head, ListNode *intersect) {
  while (head != intersect) {
    head = head->next;
    intersect = intersect->next;
  }
  return head;
}

ListNode *detectCycle(ListNode *head) {
  ListNode *intersect = cycleIntersect(head);
  if (!intersect)
    return NULL;
  ListNode *start = cycleStart(head, intersect);
  return start;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  ListNode *input;
  ListNode *expected;
  ListNode *actual;
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

static ListNode *getNode(ListNode *head, int pos) {
  if (pos < 0)
    return NULL;
  for (int i = 0; i < pos; i++) {
    head = head->next;
  }
  return head;
}

int main(void) {
  testCase test;

  // TEST CASE 1
  test.input = buildInput((int[]){3, 2, 0, -4}, 1, 4);
  test.expected = getNode(test.input, 1);
  test.actual = detectCycle(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 2
  test.input = buildInput((int[]){1, 2}, 0, 2);
  test.expected = getNode(test.input, 0);
  test.actual = detectCycle(test.input);

  assert(test.expected == test.actual);

  // TEST CASE 3
  test.input = buildInput((int[]){1}, -1, 1);
  test.expected = getNode(test.input, -1);
  test.actual = detectCycle(test.input);

  assert(test.expected == test.actual);

  return 1;
}
