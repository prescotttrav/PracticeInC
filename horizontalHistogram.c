#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, j, cur;
  int count[argc - 1];

  i = 0;
  while (i < argc - 1) {
    cur = 0;
    char *word = argv[i + 1];
    for (j = 0; word[j] != '\0'; j++) {
      ++cur;
    }
    count[i] = cur;
    i++;
  }
  printf("Histogram\n");
  for (i = 0; i < argc - 1; i++) {
    printf("%s\t", argv[i + 1]);
    for (j = 0; j < count[i]; j++) {
      printf(".");
    }
    printf("\n");
  }

  return 0;
}
