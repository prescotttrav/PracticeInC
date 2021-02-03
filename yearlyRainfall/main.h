typedef struct annual_rainfall {
  int year;
  float rainfall[12];
} AnnualRainfall;

typedef enum month
{
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
} Month;

void filterAnnualData(int year, AnnualRainfall data[], float months[]);

float calculateAnnualRainfall(int year, AnnualRainfall data[]);

float calculateAnnualAverage(int year, int range, AnnualRainfall data[]);

void calculateMonthlyAverage(int year, int range, AnnualRainfall data[],
                             float monthlyAverage[]);
