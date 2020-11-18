#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, j, max, cur;
  int count[argc - 1];
  char *word;

  i = 0;
  while (i < argc - 1) {
    cur = 0;
    word = argv[i + 1];
    for (j = 0; word[j] != '\0'; j++) {
      ++cur;
      if (cur > max)
        max = cur;
    }
    count[i] = cur;
    i++;
  }
  printf("Vertical Historgram\n");
  for (j = max; j > 0; j--) {
    for (i = 0; i < argc - 1; i++) {
      if (count[i] >= j) 
        printf(".\t");
      else
        printf("\t");
    }
    printf("\n");
  }
  for (i = 1; i < argc; i++) {
    printf("%s\t", argv[i]);
  }
  printf("\n");

  return 0;
}
