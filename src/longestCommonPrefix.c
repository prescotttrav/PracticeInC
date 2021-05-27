/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/longest-common-prefix/
 *
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 * Time: O(n lg n)
 * Space: O(lg n)
 */
#include <stdlib.h>
#include <string.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

static int strCmp(const void *s1, const void *s2) {
  return strcmp(*(char **) s1, *(char **) s2);
}

static int getlen(char *s1, char *s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  return l1 < l2 ? l1 : l2;
}

static _Bool charcmp(char **strs, int low, int high, int k) {
  return strs[low][k] == strs[high][k];
}

char *longestCommonPrefix(char **strs, int strsSize) {
  int len, i;
  i = 0;
  char *res = NULL;

  qsort(strs, strsSize, sizeof(char *), strCmp);
  len = getlen(strs[0], strs[strsSize - 1]);
  res = malloc(sizeof(char) * len + 1);

  for (int j = 0; j < len; j++) {
    if (charcmp(strs, 0, strsSize - 1, j)) {
      res[i++] = strs[0][j];
    } else {
      break;
    }
  }
  res[i] = '\0';
  return res;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  char **input;
  int size;
  char *expected;
  char *actual;
} testCase;

static char **buildInput(char **strs, int strsSize) {
  char **s = NULL;
  s = malloc(sizeof(char *) * strsSize);
  assert(s);
  for (int i = 0; i < strsSize; i++) {
    int len = strlen(strs[i]);
    s[i] = malloc(sizeof(char) * (len + 1));
    assert(s[i]);
    strcpy(s[i], strs[i]);
  }
  return s;
}

static void freeTestCase(testCase t) {
  for (int i = 0; i < t.size; i++) {
    free(t.input[i]);
  }
  free(t.input);
}

int main(void) {
  testCase test;
  test.size = 3;
  test.input = buildInput((char *[]){"flower", "flow", "flight"}, test.size);
  test.expected = "fl";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  test.size = 3;
  test.input = buildInput((char *[]){"reflower", "flow", "flight"}, test.size);
  test.expected = "";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  test.size = 1;
  test.input = buildInput((char *[]){"a"}, test.size);
  test.expected = "a";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  return 0;
}
