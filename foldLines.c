#include <stdio.h>

#define COLUMN_LENGTH 25
#define MAX_LINE 1000
#define THREASHOLD 5

int getLine(char s[]) {
  int c, i;
  
  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';

  return i;
}

int getWordLength(char s[], int i) {
  int len = 0;

  while (s[i] != '\0') {
    ++len;
    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      break;
    }
    ++i;
  }

  return len;
}

int breakLine(char from[], char to[], int i, int j, int n) {
  int x;
  for (x = n; x > 2; --x)
    to[j++] = from[i++];
  to[j] = '-';
  return n - 2;
}

void foldLine(char s[]) {
  int i, j, total, wordLength, removedLength;
  char newLine[COLUMN_LENGTH];
  i = j = total = 0;

  while (s[i] != '\0') {
    wordLength = getWordLength(s, i);
    if (total + wordLength <= COLUMN_LENGTH) {
      for (int x = 0; x < wordLength; ++x) {
        newLine[j++] = s[i + x];
      }
      i += wordLength;
      total += wordLength;
    } else {
      if (COLUMN_LENGTH - total > THREASHOLD) {
        removedLength = breakLine(s, newLine, i, j, COLUMN_LENGTH - total);
        i += removedLength;
        j += removedLength + 1;
      }
      newLine[j++] = '\n';
      newLine[j] = '\0';
      printf("%s", newLine);
      j = 0;
      total = 0;
    }
  }
  if (newLine[j] != '\0')
    newLine[j] = '\0';
  printf("%s", newLine);
}

int main() {
  int len;
  char line[MAX_LINE];
  
  while ((len = getLine(line)) > 0) {
    foldLine(line);
  }

  return 0;
}
