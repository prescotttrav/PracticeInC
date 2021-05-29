/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 *
 * You need to help them find out their common interest with the least list
 * index sum. If there is a choice tie between answers, output all of them with
 * no order requirement. You could assume there always exists an answer.
 *
 * Time: O(n1 + n2)
 * Space: O(n1)
 */
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <limits.h>

/* ---------------------------- hashmap functions  -------------------------- */

typedef struct MapNode {
  char *key;
  int val;
  struct MapNode *next;
} MapNode;

typedef struct Map {
  int size;
  MapNode **table;
} Map;

static Map initMap(int size) {
  Map m = {.size = size};
  m.table = (MapNode **) malloc(sizeof(MapNode *) * size);
  assert(m.table);
  for (int i = 0; i < size; i++)
    m.table[i] = NULL;
  return m;
}

static void destroyMap(Map *m) {
  for (int i = 0; i < m->size; i++) {
    MapNode *n = m->table[i];
    while (n != NULL) {
      MapNode *temp = n;
      n = n->next;
      free(temp);
    }
  }
}

static int hash(Map *m, char *key) {
  int c;
  int sum = 0;
  for (int i = 0; (c = key[i]) != '\0'; i++)
    sum += c;
  return sum % m->size;
}

static MapNode *newNode(char *key, int val) {
  MapNode *n = malloc(sizeof(MapNode));
  assert(n);
  n->key = key;
  n->val = val;
  return n;
}

static MapNode *get(Map *m, char *key) {
  int idx = hash(m, key);
  MapNode *n = m->table[idx];
  while (n != NULL && strcmp(key, n->key) != 0)
    n = n->next;
  if (n == NULL || strcmp(key, n->key) != 0)
    return NULL;
  return n;
}

static void add(Map *m, char *key, int val) {
  MapNode *n = newNode(key, val);
  int idx = hash(m, key);
  n->next = m->table[idx];
  m->table[idx] = n;
}

/* --------------------------------- problem -------------------------------- */

static int getCount(MapNode *n, int i) {
  if (n == NULL)
    return INT_MAX;
  return n->val + i;
}

char **findRestaurant(char **list1, int list1Size, char **list2, int list2Size,
                      int *returnSize) {
  Map map = initMap(list1Size);
  char **res = NULL;
  int min = INT_MAX - 1;
  int size = 0;

  for (int i = 0; i < list1Size; i++) {
    add(&map, list1[i], i);
  }

  for (int i = 0; i < list2Size; i++) {
    int count;
    MapNode *n = get(&map, list2[i]);
    if ((count = getCount(n, i)) > min)
      continue;
    if (count < min) {
      size = 0;
      min = count;
    }
    res = realloc(res, sizeof(char *) * (size + 1));
    if (res == NULL) {
      free(res);
      exit(-1);
    }
    res[size++] = n->key;
  }
  destroyMap(&map);
  *returnSize = size;
  return res;
}

/* --------------------------------- testing -------------------------------- */

typedef struct {
  char **s1;
  char **s2;
  int s1Size;
  int s2Size;
  char **expected;
  int expSize;
  char **actual;
  int actualSize;
} testCase;

static void assertlist(testCase t) {
  assert(t.expSize == t.actualSize);
  for (int i = 0; i < t.expSize; i++)
    assert(strcmp(t.actual[i], t.expected[i]) == 0);
}

static void freeTestCase(testCase t) {
  free(t.actual);
}

int main(void) {
  testCase test;

  // TEST CASE 1
  test.s1 = (char *[]){"Shogun", "Tapioca Express", "Burger King", "KFC"};
  test.s1Size = 4;
  test.s2 = (char *[]){"Piatti", "The Grill at Torrey Pines",
                       "Hungry Hunter Steakhouse", "Shogun"};
  test.s2Size = 4;
  test.expected = (char *[]){"Shogun"};
  test.expSize = 1;
  test.actual = findRestaurant(test.s1, test.s1Size, test.s2, test.s2Size,
                               &test.actualSize);

  assertlist(test);
  freeTestCase(test);

  // TEST CASE 2
  test.s1 = (char *[]){"Shogun", "Tapioca Express", "Burger King", "KFC"};
  test.s1Size = 4;
  test.s2 = (char *[]){"KFC", "Shogun", "Burger King"};
  test.s2Size = 3;
  test.expected = (char *[]){"Shogun"};
  test.expSize = 1;
  test.actual = findRestaurant(test.s1, test.s1Size, test.s2, test.s2Size,
                               &test.actualSize);

  assertlist(test);
  freeTestCase(test);

  // TEST CASE 3
  test.s1 = (char *[]){"Shogun", "Tapioca Express", "Burger King", "KFC"};
  test.s1Size = 4;
  test.s2 =
      (char *[]){"KNN", "KFC", "Burger King", "Tapioca Express", "Shogun"};
  test.s2Size = 5;
  test.expected = (char *[]){"KFC", "Burger King", "Tapioca Express", "Shogun"};
  test.expSize = 4;
  test.actual = findRestaurant(test.s1, test.s1Size, test.s2, test.s2Size,
                               &test.actualSize);

  assertlist(test);
  freeTestCase(test);

  return 0;
}
