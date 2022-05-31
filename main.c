/**
 *  Author: philipp luersen
 *  version: 1.0
 *  date:03.05.2022
 *  A short Program to determine the number of days before a given date.
 *
 **/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "timelib.h"


struct date {
    int day;
    int month;
    int year;
};

int main()
{
    struct date d;
    input_date(&d.day,&d.month,&d.year);
    if(!exists_date(d)){
        printf("Datum existiert nicht.");
        return 0;
    }
    printf("Das Datum ist der %d. Tag des Jahres %d \n",day_of_the_year(d),d.year);
    printf("und der %d. Tag der %d. Woche",day_of_the_week(d),week_of_the_year(d));
    
    
    return 0;
}
