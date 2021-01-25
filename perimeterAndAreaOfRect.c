#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
  double height, width, area, perimeter;
};

struct Rectangle filterRectangleProperties(char *argv[]) {
  struct Rectangle rect;
  double height, width;
  height = strtod(argv[1], NULL);
  width = strtod(argv[2], NULL);

  rect.height = height;
  rect.width = width;

  return rect;
}

struct Rectangle askForRectangleProperties() {
  struct Rectangle rect;
  double height, width;
  printf("Enter rectangle height: \n");
  scanf("%lf", &height);
  printf("Enter rectangle width: \n");
  scanf("%lf", &width);

  rect.height = height;
  rect.width = width;
  return rect;
}

double calculatePerimeter(struct Rectangle rect) {
  return 2 * (rect.height + rect.width);
}

double calculateArea(struct Rectangle rect) {
  return rect.height * rect.width;
}

_Bool rectEquality(struct Rectangle x, struct Rectangle y) {
  if (x.height != y.height)
    return 0; 
  else if (x.width != y.width)
    return 0;
  else if (x.perimeter != y.perimeter)
    return 0;
  else if (x.area != y.area)
    return 0;
  else
    return 1;
}

_Bool testcase() {
  struct Rectangle testRect;
  struct Rectangle expectedRect = {5.0, 3.0, 15.0, 16.0};

  testRect.height = 5;
  testRect.width = 3;
  testRect.perimeter = calculatePerimeter(testRect);
  testRect.area = calculateArea(testRect);
  if (!rectEquality(testRect, expectedRect)) {
    printf("Failed test case, received height: %lf, width: %lf, perimeter: %lf, area: %lf", testRect.height, testRect.width, testRect.perimeter, testRect.area);
    printf("Expected height: %lf, width: %lf, perimeter: %lf, area: %lf", expectedRect.height, expectedRect.width, expectedRect.perimeter, expectedRect.area);
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  if (!testcase())
    return -1;

  struct Rectangle curRect;

  if (argc == 3)
    curRect = filterRectangleProperties(argv);
  else
    curRect = askForRectangleProperties();

  curRect.perimeter = calculatePerimeter(curRect);
  curRect.area = calculateArea(curRect);

  return 0;
}
