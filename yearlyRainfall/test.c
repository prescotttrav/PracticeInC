#include "main.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool floatEquality(float expected, float actual) {
  int precision = 5;
  char exptectedStr[precision], acutalStr[precision];

  gcvt(expected, precision, exptectedStr);
  gcvt(actual, precision, acutalStr);

  return strcmp(exptectedStr, acutalStr) == 0 ? 1 : 0;
}

_Bool arrayEquality(float expected[], float actual[], int n) {
  for (int i = 0; i < n; ++i) {
    float expectedVal = expected[i];
    float actualVal = actual[i];
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
  float actual[12] = {[0 ... 11] = -1};
  float expected[12] = {[0 ... 11] = -1};

  filterAnnualData(1965, data, actual);
  if (!arrayEquality(expected, actual, 12))
    exit(-1);

  filterAnnualData(2018, data, actual);
  if (!arrayEquality(TWENTY_EIGHTEEN_TEST_DATA.rainfall, actual, 12))
    exit(-1);

  filterAnnualData(2020, data, actual);
  if (!arrayEquality(TWENTY_TWENTY_TEST_DATA.rainfall, actual, 12))
    exit(-1);
}

void testAnnualRainfall(AnnualRainfall data[]) {
  float annualExpected, annualActual;

  annualExpected = 0.0;
  annualActual = calculateAnnualRainfall(1995, data);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }

  annualExpected = 62.403717;
  annualActual = calculateAnnualRainfall(2019, data);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }

  annualExpected = 65.110863;
  annualActual = calculateAnnualRainfall(2016, data);
  if (!floatEquality(annualExpected, annualActual)) {
    fprintf(stderr, "Error in testing calculateAnnualRainfall utility\n");
    printf("Expected: %f, received: %f\n", annualExpected, annualActual);
    exit(-1);
  }
}

void testAnnualAverage(AnnualRainfall data[]) {
  float expected, actual;

  expected = 0.0;
  actual = calculateAnnualAverage(1948, 3, data);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 97.869766;
  actual = calculateAnnualAverage(2019, 2, data);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }

  expected = 78.751190;
  actual = calculateAnnualAverage(2020, 5, data);
  if (!floatEquality(expected, actual)) {
    fprintf(stderr, "Error in testing calculateAnnualAverage utility\n");
    printf("Expected: %f, received: %f\n", expected, actual);
    exit(-1);
  }
}

void testMonthlyAverage(AnnualRainfall data[]) {
  float actual[12] = {[0 ... 11] = 0};

  float expected_one[] = {5.866240, 3.894746, 8.991137, 4.033412,
                          9.553514, 5.922896, 6.118527, 4.098502,
                          3.517697, 1.926963, 6.463065, 4.724165};
  calculateMonthlyAverage(2016, 3, data, actual);
  if (!arrayEquality(expected_one, actual, 12)) {
    exit(-1);
  }

  float expected_two[] = {5.910718, 5.441410, 7.767761, 6.763953,
                          7.766268, 7.675056, 6.657271, 4.760959,
                          5.433166, 5.221194, 8.597064, 6.859529};
  calculateMonthlyAverage(2020, 5, data, actual);
  if (!arrayEquality(expected_two, actual, 12)) {
    exit(-1);
  }
}

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
  testAnnualRainfall(data);
  testAnnualAverage(data);
  testMonthlyAverage(data);
}
