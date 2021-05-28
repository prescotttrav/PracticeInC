/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 *
 * Time: O(n + m)
 * Space: O(1)
 */
#include <stdlib.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *p1 = headA;
  ListNode *p2 = headB;
  while (p1 != p2) {
    p1 = p1 ? p1->next : headB;
    p2 = p2 ? p2->next : headA;
  }
  return p1;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  ListNode *a;
  ListNode *b;
  ListNode *expected;
  ListNode *actual;
} testCase;

static ListNode *newNode(int val) {
  ListNode *n = malloc(sizeof(ListNode));
  assert(n);
  n->val = val;
  n->next = NULL;
  return n;
}

static ListNode *buildList(int vals[], int n) {
  ListNode *head = NULL;
  ListNode *cur = NULL;
  ListNode *prev = NULL;
  for (int i = 0; i < n; i++) {
    cur = newNode(vals[i]);
    if (!head)
      head = cur;
    if (prev)
      prev->next = cur;
    prev = cur;
  }
  return head;
}

static ListNode *listcat(ListNode *dest, ListNode *src) {
  ListNode *p = dest;
  while (p->next)
    p++;
  p->next = src;
  return dest;
}

static void freeList(ListNode *head, ListNode *final) {
  while (head && head != final) {
    ListNode *temp;
    temp = head;
    head = head->next;
    free(temp);
  }
}

static void freeTestCase(testCase t) {
  freeList(t.a, t.expected);
  freeList(t.b, t.expected);
  freeList(t.expected, NULL);
}

int main(void) {
  testCase test;

  // TEST CASE 1
  test.expected = buildList((int[]){8, 4, 5}, 3);
  test.a = buildList((int[]){4, 1}, 2);
  test.b = buildList((int[]){5, 6, 1}, 3);
  test.a = listcat(test.a, test.expected);
  test.b = listcat(test.b, test.expected);
  test.actual = getIntersectionNode(test.a, test.b);

  assert(test.actual == test.expected);
  freeTestCase(test);

  // TEST CASE 2
  test.expected = buildList((int[]){2, 4}, 2);
  test.a = buildList((int[]){1, 9, 1}, 3);
  test.b = buildList((int[]){3}, 1);
  listcat(test.a, test.expected);
  listcat(test.b, test.expected);
  test.actual = getIntersectionNode(test.a, test.b);

  assert(test.actual == test.expected);
  freeTestCase(test);

  // TEST CASE 3
  test.expected = NULL;
  test.a = buildList((int[]){2, 6, 4}, 3);
  test.b = buildList((int[]){1, 5}, 2);
  listcat(test.a, test.expected);
  listcat(test.b, test.expected);
  test.actual = getIntersectionNode(test.a, test.b);

  assert(test.actual == test.expected);
  freeTestCase(test);

  return 0;
}
