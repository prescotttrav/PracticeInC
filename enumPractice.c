#include <stdio.h>
#include <string.h>

typedef enum
{
  GOOGLE,
  FACEBOOK,
  XEROX,
  YAHOO,
  EBAY,
  MICROSOFT
} Company;

typedef struct {
  char name[25];
  Company company;
} Employee;

int main() {
  Employee prescott, colby, scotty;

  prescott = (Employee){.name = "Prescott", .company = GOOGLE};
  colby = (Employee){.name = "Colby", .company = YAHOO};

  strcpy(scotty.name, "Scotty");
  scotty.company = FACEBOOK;

  if (colby.company == scotty.company) {
    printf("Unexpected equality, %d %d", colby.company, scotty.company);
    return -1;
  } else if (prescott.company == colby.company) {
    printf("Unexpected equality, %d %d", prescott.company, colby.company);
    return -1;
  } else if (scotty.name == prescott.name) {
    printf("Unexpected equality, %s %s", scotty.name, prescott.name);
    return -1;
  } else {
    return 0;
  }
}
