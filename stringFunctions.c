#include <assert.h>
#include <stdio.h>
#include <string.h>

int strlength(char str[]) {
  int i;
  for (i = 0; str[i] != '\0'; ++i)
    ;

  return i;
}

void strconcat(char init[], char end[]) {
  int i;
  for (i = 0; init[i] != '\0'; ++i)
    ;

  for (int j = 0; end[j] != '\0'; ++j)
    init[i++] = end[j];

  init[i] = '\0';
}

_Bool strequality(char str1[], char str2[]) {
  int i;
  for (i = 0; str1[i] != '\0' || str2[i] != '\0'; ++i) {
    if (str1[i] != str2[i])
      return 0;
  }
  if (str1[i] == '\0' && str2[i] == '\0')
    return 1;
  else
    return 0;
}

void reverseString(char str[], char rev[]) {
  int i;
  int length = strlen(str);

  for (i = 0; i < length; ++i) {
    rev[i] = str[length - i - 1];
  }
  rev[i] = '\0';
}

int main() {
  char str[] = "Hello";
  assert(strlength(str) == 5);

  char init[100] = "This is the beginning";
  char end[20] = "This is the end";
  strconcat(init, end);
  assert(strcmp(init, "This is the beginningThis is the end") == 0);

  char str1[] = "this is number one";
  char str2[] = "this is number o";
  assert(strequality(str1, str2) == 0);

  char rev[6];
  reverseString(str, rev);
  assert(strcmp(rev, "olleH") == 0);
  return 0;
}
