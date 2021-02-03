#include "main.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_RECORDS 5

void queryData(AnnualRainfall res[]) {
  srand((unsigned int) time(NULL));
  int year = 2020;
  float a = 10.0;

  for (int i = 0; i < NUMBER_OF_RECORDS; ++i) {
    res[i].year = year - i;
    for (int j = 0; j < 12; ++j) {
      res[i].rainfall[j] = ((float) rand() / (float) RAND_MAX) * a;
    }
  }
}

void printMatrix(AnnualRainfall data[]) {
  for (int i = 0; i < NUMBER_OF_RECORDS; ++i) {
    printf("Year: %d\n", data[i].year);
    for (int j = 0; j < 12; ++j) {
      printf("%f ", data[i].rainfall[j]);
    }
    printf("\n");
  }
}

void printArr(float *arr, int n) {
  for (int i = 0; i < n; ++i)
    printf("%f ", *(arr + i));
  printf("\n");
}

void copyData(float from[], float to[], int n) {
  for (int i = 0; i < n; ++i)
    to[i] = from[i];
}

void filterAnnualData(int year, AnnualRainfall data[], float months[]) {
  for (int i = 0; i < NUMBER_OF_RECORDS; ++i) {
    if (year == data[i].year) {
      copyData(data[i].rainfall, months, 12);
      break;
    }
  }
}

float calculateAnnualRainfall(int year, AnnualRainfall data[]) {
  float annualRainfall = 0;
  float months[12] = {[0 ... 11] = -1};
  filterAnnualData(year, data, months);

  if (months[0] == -1)
    return 0;   // Need to think how we want to handle this officially
  for (int i = 0; i < 12; ++i) {
    annualRainfall += months[i];
  }
  return annualRainfall;
}

float calculateAnnualAverage(int year, int range, AnnualRainfall data[]) {
  float annualAverage = calculateAnnualRainfall(year, data);
  for (int i = 0; i < range; ++i) {
    annualAverage += calculateAnnualRainfall(year - i, data);
  }
  return annualAverage / range;
}

void accumulateMonthlyTotal(int year, AnnualRainfall data[],
                            float monthlyAverages[]) {
  float currentMonth[12];
  filterAnnualData(year, data, currentMonth);

  for (int i = 0; i < 12; ++i)
    monthlyAverages[i] += currentMonth[i];
}

void calculateMonthlyAverage(int year, int range, AnnualRainfall data[],
                             float monthlyAverages[]) {
  for (int i = 0; i < range; ++i)
    accumulateMonthlyTotal(year - i, data, monthlyAverages);

  for (int i = 0; i < 12; ++i)
    monthlyAverages[i] /= range;
}

char *getMonth(int val) {
  switch (val) {
    case 0:
      return "JAN";
    case 1:
      return "FEB";
    case 2:
      return "MAR";
    case 3:
      return "APR";
    case 4:
      return "MAY";
    case 5:
      return "JUN";
    case 6:
      return "JUL";
    case 7:
      return "AUG";
    case 8:
      return "SEP";
    case 9:
      return "OCT";
    case 10:
      return "NOV";
    case 11:
    default:
      return "DEC";
  }
}

void displayMonthlyAverages(float monthlyAverages[]) {
  for (int i = 0; i < 12; ++i)
    printf("%s\t%0.1f\n", getMonth(i), monthlyAverages[i]);
  printf("\n");
}

void displayAnnualRainfall(float annualRainfall[]) {
  int year = 2020;
  printf("YEAR\tRAINFALL (inches)\n\n");
  for (int i = NUMBER_OF_RECORDS - 1; i >= 0; --i)
    printf("%d:\t%0.1f\n", year - i, annualRainfall[i]);
}

int main() {
  test();
  float annualAverage, annualRainfall[NUMBER_OF_RECORDS],
      monthlyAverages[12] = {[0 ... 11] = 0};
  AnnualRainfall data[NUMBER_OF_RECORDS];
  queryData(data);

  for (int i = 0; i < NUMBER_OF_RECORDS; ++i)
    annualRainfall[i] = calculateAnnualRainfall(2020 - i, data);
  displayAnnualRainfall(annualRainfall);

  annualAverage = calculateAnnualAverage(2020, NUMBER_OF_RECORDS, data);
  printf("\nThe annual average is %.1f inches.\n\n", annualAverage);

  calculateMonthlyAverage(2020, NUMBER_OF_RECORDS, data, monthlyAverages);
  displayMonthlyAverages(monthlyAverages);

  return 0;
}
