/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/longest-common-prefix/
 *
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <stdlib.h>
#include <string.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

static char *getmin(char **strs, int strsSize) {
  char *min = strs[0];
  for (int i = 1; i < strsSize; i++) {
    if (strcmp(min, strs[i]) > 0)
      min = strs[i];
  }
  return min;
}

static char *getmax(char **strs, int strsSize) {
  char *max = strs[0];
  for (int i = 1; i < strsSize; i++) {
    if (strcmp(max, strs[i]) < 0)
      max = strs[i];
  }
  return max;
}

static int getlen(char *s1, char *s2) {
  int i = 0;
  while (*s1++ && *s2++) {
    i++;
  }
  return i;
}

char *longestCommonPrefix(char **strs, int strsSize) {
  int i;
  char *res = NULL;
  char *min = getmin(strs, strsSize);
  char *max = getmax(strs, strsSize);
  int len = getlen(min, max);
  res = malloc(sizeof(char) * (len + 1));
  assert(res);

  for (i = 0; i < len; i++) {
    if (min[i] == max[i]) {
      res[i] = min[i];
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
  free(t.actual);
}

int main(void) {
  testCase test;

  // TEST CASE 1
  test.size = 3;
  test.input = buildInput((char *[]){"flower", "flow", "flight"}, test.size);
  test.expected = "fl";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  // TEST CASE 2
  test.size = 3;
  test.input = buildInput((char *[]){"reflower", "flow", "flight"}, test.size);
  test.expected = "";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  // TEST CASE 3
  test.size = 1;
  test.input = buildInput((char *[]){"a"}, test.size);
  test.expected = "a";
  test.actual = longestCommonPrefix(test.input, test.size);

  assert(strcmp(test.actual, test.expected) == 0);
  freeTestCase(test);

  return 0;
}
