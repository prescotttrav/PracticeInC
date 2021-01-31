#define PAY_RATE 12
#define STANDARD_WEEK_HOURS 40

typedef struct {
  float regular, overtime;
} HoursWorked;

float calculateOvertime(float totalHours);

float calculateGrossPay(HoursWorked hours);

float determineTaxCost(float value, float rate);

float calculateTaxes(float grossPay);
