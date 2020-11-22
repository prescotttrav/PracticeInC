#include <stdio.h>

#define COLUMN_WIDTH 25
#define MAX_LINE 1000
#define THREASHOLD 5


int getLine(char s[]) {
  printf("getLine");
  int c, i;
  for (i = 0; i < MAX_LINE && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  printf("Will return");
  return i;
}

int insertTab(char s[], int i) {
  printf("insertTab");
  while(i % 8 != 0) {
    s[i++] = ' ';
  }
  return i;
}

int nextWord(char s[], char w[], int i) {
  printf("nextWord");
  int j = 0;
  while (s[i] != ' ' || s[i] != '\0' || s[i] != '\n' || s[i] != '\t') {
    w[j++] = s[i++];
  }
  if (s[i] == ' ') {
    w[j++] = s[i];
  } else if (s[i] == '\n') {
    w[j++] = '\n';
  } else if (s[i] == '\t') {
    j = insertTab(w, j);
  }
  w[j] = '\0';
  return j;
}

int breakWord(char to[], char from[], int i, int start, int end) {
  printf("breakWord");
  int j;
  for (j = start; j < end; ++j) {
    to[j] = from[i++];
  }
  to[j++] = '\n';
  to[j] = '\0';
  return j;
}

void foldLine(char s[]) {
  printf("foldLine");
  int total = 0;
  int i = 0;
  int k = 0;
  int bufferSize = 0;
  int remaining;
  char newLine[COLUMN_WIDTH];
  char bufferWord[COLUMN_WIDTH];
  
  while (s[i] != '\0') {
    bufferSize = nextWord(s, bufferWord, i);
    if (total + bufferSize <= COLUMN_WIDTH) {
      for (int j = 0; j < bufferSize; ++j) {
        newLine[k++] = bufferWord[j];
      }
      i += bufferSize;
    } else if (COLUMN_WIDTH - total + bufferSize > 0 && COLUMN_WIDTH - total + bufferSize <= THREASHOLD) {
      for (int j = 0; j < bufferSize; ++j) {
        newLine[k++] = bufferWord[j];
      }
      i += bufferSize;
      newLine[k++] = '\n';
      total = 0;
    } else if (total + bufferSize - COLUMN_WIDTH > 0 && total + bufferSize - COLUMN_WIDTH <= THREASHOLD) {
      newLine[k++] = '\n';
      total += 0;
    } else {
      remaining = breakWord(newLine, bufferWord, 0, k, COLUMN_WIDTH - total - 1);
      k += bufferSize - remaining;
      i += k;
      newLine[k++] = '\n';
      total += 0;
    }
  }
  printf("%s", newLine);
}

int main() {
  int len;
  char line[MAX_LINE];

  while ((len = getLine(line)) > 0) {
    printf("here");
    foldLine(line);
  }

  return 0;
}
