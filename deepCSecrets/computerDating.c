#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

typedef struct date_t {
  int years, months, weeks, days, hours, minutes;
} date_t;

const int SEC_TO_MIN = 60;
const int MIN_TO_HR = 60;
const int HR_TO_DAY = 24;
const int DAY_TO_WK = 7;
const float WK_TO_MO = 4.34524;
const int MO_TO_YR = 12;

int sec_to_min(double sec) {
  return sec / SEC_TO_MIN;
}

int sec_to_hr(double sec) {
  return sec_to_min(sec) / MIN_TO_HR;
}

int sec_to_day(double sec) {
  return sec_to_hr(sec) / HR_TO_DAY;
}

int sec_to_wk(double sec) {
  return sec_to_day(sec) / DAY_TO_WK;
}

int sec_to_mo(double sec) {
  return sec_to_wk(sec) / WK_TO_MO;
}

int sec_to_year(double sec) {
  return sec_to_mo(sec) / MO_TO_YR;
}

double min_to_sec(int min) {
  return min * SEC_TO_MIN;
}

double hr_to_sec(int hr) {
  return min_to_sec(hr) * MIN_TO_HR;
}

double day_to_sec(int day) {
  return hr_to_sec(day) * HR_TO_DAY;
}

double wk_to_sec(int wk) {
  return day_to_sec(wk) * DAY_TO_WK;
}

double mo_to_sec(int mo) {
  return wk_to_sec(mo) * WK_TO_MO;
}

double year_to_sec(int yr) {
  return mo_to_sec(yr) * MO_TO_YR;
}

time_t get_time_wrap(void) {
  char *str = NULL;
  time_t mac_os_time_max = UINT_MAX;

  str = ctime(&mac_os_time_max);

  if (!str) {
    fprintf(stderr, "ctime failed.\n");
  } else {
    printf("wrap around time: %s\n", str);
  }

  return mac_os_time_max;
}

date_t remaining_time_dogged(time_t final) {
  date_t d;
  time_t now;
  double sec, diff;

  time(&now);

  sec = difftime(final, now);

  d.years = sec_to_year(sec);
  sec -= year_to_sec(d.years);

  d.months = sec_to_mo(sec);
  sec -= mo_to_sec(d.months);

  d.weeks = sec_to_wk(sec);
  sec -= wk_to_sec(d.weeks);

  d.days = sec_to_day(sec);
  sec -= day_to_sec(d.days);

  d.hours = sec_to_hr(sec);
  sec -= hr_to_sec(d.hours);

  d.minutes = sec_to_min(sec);

  return d;
}

void print_remaining_time(date_t d) {
  printf("Remaining time dogged by UNIX deamon:\n");
  printf("Years: \t\t%d\n", d.years);
  printf("Months: \t%d\n", d.months);
  printf("Weeks: \t\t%d\n", d.weeks);
  printf("Days: \t\t%d\n", d.days);
  printf("Hours: \t\t%d\n", d.hours);
  printf("Minutes: \t%d\n", d.minutes);
}

int main(void) {
  date_t d;
  time_t wrap;

  wrap = get_time_wrap();
  d = remaining_time_dogged(wrap);

  print_remaining_time(d);

  return 0;
}
