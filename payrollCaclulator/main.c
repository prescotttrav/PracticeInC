#include "test.h"
#include <stdio.h>

#define PAY_RATE 12

float collectHours() {
  float hours;
  printf("Enter hours worked this week: \n");
  scanf("%f", &hours);

  return hours;
}

float determineOvertime(float totalHours) {
  float overtime = totalHours - 40;

  return overtime > 0 ? overtime : 0.0;
}

float calculateCostBeforeTaxes(float regularHours, float overtime) {
  float cost = regularHours * PAY_RATE;
  if (overtime > 0)
    cost += overtime * (PAY_RATE + (PAY_RATE / 2));

  return cost;
}

float calculateCostAfterTaxes(float cost) {
  float fifteen, twenty, twentyFive, value;
  fifteen = twenty = twentyFive = 0;

  value = cost > 300 ? 300 : cost;
  fifteen = value * 0.15;

  if (cost > 300) {
    value = cost - 300 > 150 ? 150 : cost - 150;
    twenty = value * 0.2;
  }
  if (cost > 450) {
    value = cost - 450;
    twentyFive = value * 0.25;
  }
  return cost - fifteen - twenty - twentyFive;
}

int main() {
  float hoursWorked, overtime, regularHours, cost;

  // TODO unit test utilities
  //  if (!test())
  //    return -1;

  // TODO return struct of regular hours & overtime
  hoursWorked = collectHours();
  overtime = determineOvertime(hoursWorked);
  regularHours = hoursWorked - overtime;

  cost = calculateCostBeforeTaxes(regularHours, overtime);
  // TODO condense into one calculate cost utility
  cost = calculateCostAfterTaxes(cost);

  printf("cost: %.2f\n", cost);
}
