/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/majority-element/
 *
 * Given an array nums of size n, return the majority element.
 *
 * Time: O(n)
 * Space: O(n)
 */
#include <stdlib.h>

#include <assert.h>
#include <math.h>

/* ---------------------------- hashmap functions  -------------------------- */

typedef struct HashNode {
  int key;
  int val;
  struct HashNode *next;
} HashNode;

typedef struct Hashmap {
  int size;
  HashNode **table;
} Hashmap;

static void initMap(Hashmap *m, int size) {
  m->size = size;
  m->table = malloc(sizeof(HashNode *) * size);
  assert(m->table);
  for (int i = 0; i < size; i++)
    m->table[i] = NULL;
}

static void destroyMap(Hashmap *m) {
  for (int i = 0; i < m->size; i++) {
    HashNode *n = m->table[i];
    while (n != NULL) {
      HashNode *temp = n;
      n = n->next;
      free(temp);
    }
  }
  free(m->table);
}

static int hash(Hashmap *m, int key) {
  return abs(key % m->size);
}

static HashNode *get(Hashmap *m, int key) {
  int idx = hash(m, key);
  HashNode *n = m->table[idx];
  while (n != NULL && n->key != key) {
    n = n->next;
  }
  return n;
}

static HashNode *newNode(int key, int val) {
  HashNode *n = malloc(sizeof(HashNode));
  assert(n);
  n->key = key;
  n->val = val;
  n->next = NULL;
  return n;
}

static HashNode *add(Hashmap *m, int key, int val) {
  int idx = hash(m, key);
  HashNode *n = newNode(key, val);
  n->next = m->table[idx];
  m->table[idx] = n;
  return n;
}

/* --------------------------------- problem -------------------------------- */

static int majorityElement(int *nums, int numsSize) {
  Hashmap m;
  initMap(&m, numsSize);
  int res = -1;
  int majority = numsSize / 2 + 1;
  for (int i = 0; i < numsSize; i++) {
    HashNode *n = get(&m, nums[i]);
    if (n == NULL) {
      n = add(&m, nums[i], 0);
    }
    n->val += 1;
    if (n->val >= majority) {
      res = n->key;
      break;
    }
  }
  destroyMap(&m);
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
