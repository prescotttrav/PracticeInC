#include <stdio.h>

int atoi(char s[]) {
  int n, i;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  
  return n;
}

int main() {
  int res;
  printf("Expected: 12345, Actual: %d\n", atoi("12345"));
  printf("Expected: 888, Actual: %d\n", atoi("888"));
  printf("Expected: 0, Actual: %d\n", atoi("0000"));
  printf("Expected: 0, Actual: %d\n", atoi("abcd"));
  printf("Expected: 1, Actual: %d\n", atoi("1abcd"));

  return 0;
}
