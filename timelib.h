#define TIMELIB_H_
int is_leapyear(int year);
void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int day_of_the_year(int day, int month, int year);
int day_of_the_week(int day, int month, int year);
int week_of_the_year(int day, int month, int year);