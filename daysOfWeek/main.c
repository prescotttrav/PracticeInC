#include "main.h"
#include "test.h"
#include <stdio.h>
#include <time.h>

DaysOfWeek obtainDaysOfWeek(int weekday) {
  switch (weekday) {
    case 0:
      return Sunday;
    case 1:
      return Monday;
    case 2:
      return Tuesday;
    case 3:
      return Wednesday;
    case 4:
      return Thursday;
    case 5:
      return Friday;
    case 6:
    default:
      return Saturday;
  }
}

void logDaysOfWeek(DaysOfWeek today) {
  switch (today) {
    case Sunday:
      printf("Today is sunday.\n");
      break;
    case Monday:
      printf("Today is monday.\n");
      break;
    case Tuesday:
      printf("Today is tuesday.\n");
      break;
    case Wednesday:
      printf("Today is wednesday.\n");
      break;
    case Thursday:
      printf("Today is thursday.\n");
      break;
    case Friday:
      printf("Today is friday.\n");
      break;
    case Saturday:
      printf("Today is saturday.\n");
      break;
  }
}

int main() {
  time_t now;
  DaysOfWeek today;

  time(&now);
  struct tm *local = localtime(&now);

  if (!test())
    return -1;

  today = obtainDaysOfWeek(local->tm_wday);
  logDaysOfWeek(today);

  return 0;
}
