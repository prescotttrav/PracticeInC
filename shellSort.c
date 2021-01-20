#include <stdio.h>

void shellSort(int arr[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
	temp = arr[j];
	arr[j] = arr[j + gap];
	arr[j + gap] = temp;
      }
    }
  }
}

int main() {
  int testcase[] = {35, 33, 42, 10, 14, 19, 27, 44};
  shellSort(testcase, 8);
  for (int i = 0; i < 8; i++) {
    printf("%d ", testcase[i]);
  }
  printf("\n");
  
  return 0;
}

