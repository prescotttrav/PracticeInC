#include <stdio.h>

#define TO_NUM 49
#define TO_CHAR 97

int main() {
  int alpha[26];
  int num[10];
  int i, j, c, white;

  white = 0;
  for (i = 0; i < 26; i++) {
    if (i < 10)
      num[i] = 0;
    alpha[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++num[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++white;
    else if (c >= 'a' && c <= 'z')
      ++alpha[c - '0' - TO_NUM];
  }
  // Print nums
  for (i = 0; i < 10; i++) {
    printf("%d\t", i);
    for (j = 0; j < num[i]; j++) {
      printf(".");
    }
    printf("\n");
  }
  // Print alpha
  for (i = 0; i < 26; i++) {
    printf("%c\t", (char) (i + TO_CHAR));
    for (j = 0; j < alpha[i]; j++) {
      printf(".");
    }
    printf("\n");
  }
  // Print white
  printf("white\t");
  for (i = 0; i < white; i++) {
    printf(".");
  }
  printf("\n");

  return 0;
}
