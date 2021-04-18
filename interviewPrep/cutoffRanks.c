/*
 * Each year, employees of an organization are rated based on their performance.
 * The employees are then ranked based on the ratings. Enployees with the same
 * ratings will have the same rankings, but the next employee with the next
 * lowest score will be rated based on the position within the list of all
 * rankings. Employees below the cutoff rank are placed in a layoff list. Give
 * the ratings each employee receives and the cutoff rank, return the number of
 * employees who are not in the layoff list.
 *
 * Time: O(n lg n)
 * Space: O(lg n)
 */
#include <assert.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return (*(int *) b - *(int *) a);
}

int getAboveCutOffRankCount(int scores[], int cutOffRank, int n) {
  int i, count, equal;
  count = 1;
  equal = 0;

  qsort(scores, n, sizeof(int), cmp);

  for (i = 1; i < n; ++i) {
    if (scores[i] == scores[i - 1])
      ++equal;
    else if (scores[i] != scores[i - 1]) {
      count += equal + 1;
      equal = 0;
    }

    if (count > cutOffRank) {
      break;
    }
  }

  return i;
}

int main() {
  int remainingEmployees;

  remainingEmployees =
      getAboveCutOffRankCount((int[]){100, 90, 80, 70, 60}, 2, 5);

  assert(remainingEmployees == 2);

  remainingEmployees =
      getAboveCutOffRankCount((int[]){100, 100, 80, 70, 60}, 4, 5);

  assert(remainingEmployees == 4);

  remainingEmployees = getAboveCutOffRankCount((int[]){100, 50, 50, 25}, 3, 4);

  assert(remainingEmployees == 3);

  remainingEmployees = getAboveCutOffRankCount((int[]){2, 2, 3, 4, 5}, 4, 5);

  assert(remainingEmployees == 5);

  return 0;
}
