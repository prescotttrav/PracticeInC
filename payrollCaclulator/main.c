#include "test.h"
#include <stdio.h>

#define PAY_RATE 12
#define STANDARD_WEEK_HOURS 40

typedef struct {
  float regular, overtime;
} HoursWorked;

float calculateOvertime(float totalHours) {
  float overtime = totalHours - STANDARD_WEEK_HOURS;

  return overtime > 0 ? overtime : 0.0;
}

HoursWorked collectHoursWorked() {
  HoursWorked hours;
  printf("Enter total hours worked this week: \n");
  scanf("%f", &hours.regular);

  hours.overtime = calculateOvertime(hours.regular);
  hours.regular -= hours.overtime;

  return hours;
}

float calculateGrossPay(HoursWorked hours) {
  float grossPay, overtimeHourlyRate;
  overtimeHourlyRate = PAY_RATE + (PAY_RATE / 2);
  grossPay = 0;

  grossPay += hours.regular * PAY_RATE;
  grossPay += hours.overtime * overtimeHourlyRate;
  return grossPay;
}

float determineTaxCost(float value, float rate) {
  return value * rate;
}

float calculateTaxes(float grossPay) {
  float value, rate, taxes = 0;

  for (int i = 0; i < 3 && grossPay > 0; i++) {
    switch (i) {
      case 0:
        value = grossPay > 300 ? 300 : grossPay;
        rate = 0.15;
        break;
      case 1:
        value = grossPay > 150 ? 150 : grossPay;
        rate = 0.20;
        break;
      case 2:
        value = grossPay;
        rate = 0.25;
        break;
    }
    taxes += determineTaxCost(value, rate);
    grossPay -= value;
  }
  return taxes;
}

int main() {
  HoursWorked payPeriod;
  float grossPay, taxes, netPay;

  // TODO unit test utilities
  //  if (!test())
  //    return -1;

  payPeriod = collectHoursWorked();
  grossPay = calculateGrossPay(payPeriod);
  taxes = calculateTaxes(grossPay);
  netPay = grossPay - taxes;

  printf(
      "Gross pay for this week: %.2f\nTaxes for this week: %.2f\nNet pay for "
      "this week: %.2f\n",
      grossPay, taxes, netPay);

  return 0;
}
