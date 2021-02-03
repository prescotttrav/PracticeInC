#include "main.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool floatEquality(float expected, float actual) {
  int precision = 6;
  char exptectedStr[precision], acutalStr[precision];

  gcvt(expected, precision, exptectedStr);
  gcvt(actual, precision, acutalStr);

  return strcmp(exptectedStr, acutalStr) == 0 ? 1 : 0;
}

_Bool arrayEquality(float expected[], float actual[], int n) {
  float expectedVal, actualVal;

  for (int i = 0; i < n; ++i) {
    expectedVal = expected[i];
    actualVal = actual[i];
    if (!floatEquality(expectedVal, actualVal)) {
      fprintf(stderr, "Error in testing filterAnnualData utility\n");
      printf("Expected: %f, received: %f\n", expectedVal, actualVal);
      return 0;
    }
  }
  return 1;
}

void testFilterAnnualData(AnnualRainfall data[],
                          AnnualRainfall TWENTY_TWENTY_TEST_DATA,
                          AnnualRainfall TWENTY_EIGHTEEN_TEST_DATA) {
  float actual[12], expected[12] = {[0 ... 11] = -1};

  filterAnnualData(2020, data, actual);
  if (!arrayEquality(TWENTY_TWENTY_TEST_DATA.rainfall, actual, 12))
    exit(-1);

  filterAnnualData(2018, data, actual);
  if (!arrayEquality(TWENTY_EIGHTEEN_TEST_DATA.rainfall, actual, 12))
    exit(-1);

  filterAnnualData(1965, data, actual);
  if (!arrayEquality(expected, actual, 12))
    exit(-1);
}

/*
void testAnnualRainfall() {
  float annualExpected, annualActual;

  annualExpected = ;
  annualActual = calculateAnnualRainfall(2019);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }

  annualExpected = ;
  annualActual = calculateAnnualRainfall(2016);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }

  annualExpected = ;
  annualActual = calculateAnnualRainfall(1995);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }
}

void testAnnualAverage() {
  float expected, actual;

  expected = ;
  actual = calculateAnnualAverage(2019, 2);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = ;
  actual = calculateAnnualAverage(2020, 5);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = ;
  actual = calculateAnnualAverage(1948, 3);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testMonthlyAverage() {
  float expected[12], actual[12];

  expected = ;
  actual = calculateMonthlyAverage(2016, 3);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateMonthlyAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = ;
  actual = calculateMonthlyAverage(2020, 5);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateMonthlyAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = ;
  actual = calculateMonthlyAverage(2000, 2);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateMonthlyAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}
*/
void test() {
  AnnualRainfall TWENTY_TWENTY_TEST_DATA = {
      .year = 2020,
      .rainfall = {1.170643, 5.001214, 5.395714, 5.764346, 1.359773, 3.710046,
                   4.739877, 3.113551, 9.445971, 8.423777, 8.416020, 8.054144}};

  AnnualRainfall TWENTY_EIGHTEEN_TEST_DATA = {
      .year = 2018,
      .rainfall = {2.855701, 5.766173, 2.070837, 4.567609, 7.804437, 9.163725,
                   4.723938, 5.218887, 3.842277, 7.146372, 9.062814, 8.709334}};

  AnnualRainfall data[] = {
      TWENTY_TWENTY_TEST_DATA,   TWENTY_NINETEEN_TEST_DATA,
      TWENTY_EIGHTEEN_TEST_DATA, TWENTY_SEVENTEEN_TEST_DATA,
      TWENTY_SIXTEEN_TEST_DATA,
  };

  testFilterAnnualData(data, TWENTY_TWENTY_TEST_DATA,
                       TWENTY_EIGHTEEN_TEST_DATA);
  /*
    testAnnualRainfall();
    testAnnualAverage();
    testMonthlyAverage();
  */
}
