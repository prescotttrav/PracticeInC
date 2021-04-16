#include <ctype.h>
#include <stdio.h>

#define EXPRESSION_ERROR (-1)

int peekChar(void) {
  int c = getchar();

  if (c != EOF)
    ungetc(c, stdin);

  return c;
}

int readNumber(void) {
  int c;
  int acc = 0;

  while ((c = peekChar()) != EOF && isdigit(c)) {
    c = getchar();
    acc *= 10;
    acc += (c - '0');
  }

  return acc;
}

int performOperation(int exp1, int exp2, int op) {
  switch (op) {
    case '*':
      return exp1 * exp2;
    case '+':
      return exp1 + exp2;
    default:
      return EXPRESSION_ERROR;
  }
}

int readExpression(void) {
  int c, exp1, exp2, op;

  c = peekChar();

  if (c == '(') {
    c = getchar();

    exp1 = readExpression();
    op = getchar();
    exp2 = readExpression();

    c = getchar();
    if (c != ')')
      return EXPRESSION_ERROR;

    return performOperation(exp1, exp2, op);

  } else if (isdigit(c)) {
    return readNumber();
  } else {
    return EXPRESSION_ERROR;
  }
}

int main() {
  int ans = readExpression();

  return 0;
}
