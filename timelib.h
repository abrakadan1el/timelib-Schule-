#define TIMELIB_H_
int is_leapyear(int year);
void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(struct date d);
int day_of_the_year(struct date d);
int day_of_the_week(struct date d);
int week_of_the_year(struct date d);