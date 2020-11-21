#include <stdio.h>

#define COLUMN_WIDTH 25
#define MAX_LINE 1000

int countWords(int c[], char w[], char s[]) {
  // 1 array for word lengths & 1 array for words; interpreted from line[]
  // returns final index
}

void foldline(int start, int end, int c[], char w[]) {
  // Recursive
  // Adds counts that are >= COLUMN_WIDTH (these make up the final line to be printed)
  // If count is drastically greater or lesser, breaks word with '-'
}

int getLine(char s[]) {
  // Builds line by line array from input
}

int main() {
  int len, i, count[MAX_LINE];
  char line[MAX_LINE], words[MAX_LINE];

  while ((len = getLine(line)) > 0) {
    i = countWords(count, words, line);
    foldline(0, i, count, words);
  }

  return 0;
}
