/*
 * A risk modeling system uses a scaling computing system that implements an
 * autoscale policy depending on the current load or utilization of the
 * computing system. The system starts with a number of computing instances
 * given by instances. The system polls the instances every second to see the
 * average utilization at that second, and performs scaling as described below.
 * Once any action is taken, the system will stop polling for 10 seconds. During
 * that time, the number of instances does not change. Average utilization >
 * 60%: Double the number of instances if the doubled value does not exceed 2 *
 * 10^8. This is an action. If the number of instances exceeds this limit on
 * doubling, perform no action. Average utilization < 25%: Halve the number of
 * instances if the number of instances is greater than 1 (take ceil if the
 * number is not an integer). This is also an action. If the number of instances
 * is 1, take no action. 25% <= Average utilization <= 60%: No action. Given an
 * array of the values of the average utilization at each second for this
 * system, determine the number of instances at the end of the time frame.
 *
 * Time: O(n)
 * Space: O(1)
 */
#include <assert.h>
#include <math.h>

#define MAX_SIZE 100000
#define MAX_INSTANCE 200000000
#define MIN_INSTANCE 1

_Bool inUtilRange(int arr[], int i) {
  return 1 <= arr[i] && arr[i] <= 100;
}

int ceilingHalf(int val) {
  return val / 2 + (val % 2 != 0);
}

int autoscaleInstances(int instance, int averageUtil[], int n) {
  for (int i = 0; i < n && inUtilRange(averageUtil, i); ++i) {
    if (averageUtil[i] > 60 && instance * 2 < MAX_INSTANCE) {
      instance *= 2;
      i += 9;
    } else if (averageUtil[i] < 25 && instance > MIN_INSTANCE) {
      instance = ceilingHalf(instance);
      i += 9;
    }
  }

  return instance < MIN_INSTANCE ? MIN_INSTANCE : instance;
}

int main() {
  int instance;

  instance = autoscaleInstances(
      2, (int[]){25, 23, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80}, 12);
  assert(instance == 2);

  instance = autoscaleInstances(1, (int[]){5, 10, 80}, 3);
  assert(instance == 2);

  instance = autoscaleInstances(5, (int[]){30, 5, 4, 8, 19, 89}, 6);
  assert(instance == 3);

  return 0;
}
