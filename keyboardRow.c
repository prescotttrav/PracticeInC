/* Author: Prescott J. Traversi
 * Source: https://leetcode.com/problems/keyboard-row/
 *
 * Given an array of strings words, return the words that can be typed using
 * letters of the alphabet on only one row of American keyboard like the image
 * below.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

/* --------------------------------- problem -------------------------------- */

#define INIT_ALPHA 97

static int indexof(char c) {
  return tolower(c) - INIT_ALPHA;
}

static void buildSet(_Bool **r, char *str) {
  int c;
  *r = calloc(26, sizeof(_Bool));
  for (int i = 0; (c = str[i]) != '\0'; i++) {
    int j = indexof(c);
    *(*r + j) = 1;
  }
}

static _Bool has(_Bool *r, char c) {
  int i = indexof(c);
  return r[i];
}

static int getrow(char c, _Bool *r1, _Bool *r2, _Bool *r3) {
  if (has(r1, c))
    return 1;
  if (has(r2, c))
    return 2;
  if (has(r3, c))
    return 3;
  return -1;
}

char **findWords(char **words, int wordsSize, int *returnSize) {
  char **res = NULL;
  int size = 0;
  _Bool *r1, *r2, *r3;
  buildSet(&r1, "qwertyuiop");
  buildSet(&r2, "asdfghjkl");
  buildSet(&r3, "zxcvbnm");

  for (int i = 0; i < wordsSize; i++) {
    char *word = words[i];
    int row = 0;
    int j = 0;
    int c;

    while ((c = word[j]) != '\0') {
      if (!row) {
        row = getrow(c, r1, r2, r3);
      } else if (row != getrow(c, r1, r2, r3)) {
        row = 0;
        break;
      }
      j++;
    }
    if (row) {
      res = realloc(res, sizeof(char *) * (size + 1));
      if (!res) {
        free(res);
        exit(-1);
      }
      res[size] = malloc(sizeof(char) * (strlen(word) + 1));
      res[size] = word;
      size++;
    }
  }

  free(r1);
  free(r2);
  free(r3);
  *returnSize = size;
  return res;
}

/* --------------------------------- testing -------------------------------- */

typedef struct testCase {
  char **input;
  char **expected;
  char **actual;
  int insize;
  int exsize;
  int actsize;
} testCase;

static void cleanup(testCase *test) {
  free(test->input);
  test->input = NULL;
  free(test->expected);
  test->expected = NULL;
  free(test->actual);
  test->actual = NULL;
  test->insize = 0;
  test->exsize = 0;
  test->actsize = 0;
}

static void assertlist(char **expected, char **actual, int n) {
  for (int i = 0; i < n; i++) {
    assert(strcmp(expected[i], actual[i]) == 0);
  }
}

static void assertFindWords(testCase test) {
  assert(test.exsize == test.actsize);
  assertlist(test.expected, test.actual, test.exsize);
}

static void addInput(testCase *test, char *s) {
  test->insize++;
  char **input = realloc(test->input, sizeof(char *) * test->insize);
  input[test->insize - 1] = s;
  test->input = input;
}

static void addExpected(testCase *test, char *s) {
  test->exsize++;
  char **expected = realloc(test->expected, sizeof(char *) * test->exsize);
  expected[test->exsize - 1] = s;
  test->expected = expected;
}

int main(void) {
  testCase test = {
      NULL,   // input
      NULL,   // expected
      NULL,   // actual
      0,      // insize
      0,      // exsize
      0       // actsize
  };

  // TEST CASE 1
  addInput(&test, "Hello");
  addInput(&test, "Alaska");
  addInput(&test, "Dad");
  addInput(&test, "Peace");

  addExpected(&test, "Alaska");
  addExpected(&test, "Dad");

  test.actual = findWords(test.input, test.insize, &test.actsize);
  assertFindWords(test);
  cleanup(&test);

  // TEST CASE 2
  addInput(&test, "omk");

  test.actual = findWords(test.input, test.insize, &test.actsize);
  assertFindWords(test);
  cleanup(&test);

  // TEST CASE 3
  addInput(&test, "adsdf");
  addInput(&test, "sfd");

  addExpected(&test, "adsdf");
  addExpected(&test, "sfd");

  test.actual = findWords(test.input, test.insize, &test.actsize);
  assertFindWords(test);
  cleanup(&test);

  return 1;
}
