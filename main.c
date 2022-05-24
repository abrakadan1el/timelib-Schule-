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

static int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


struct date {
    int day;
    int month;
    int year;
};

/*
Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 
Übergabeparameter:
year: int
Rückgabewert:
1, wenn übergebenes Jahr ein
Schaltjahr ist
0, wenn übergebenes Jahr kein
Schaltjahr ist
-1, wenn ein ungültiges Jahr
übergeben wurde
*/
int is_leapyear(int year){
    if(year<1582) return -1;
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

/*
Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
Übergabeparameter:
day: Zeiger auf int
month: Zeiger auf int
year: Zeiger auf int
Rückgabewert:
kein Rückgabewert
*/
void input_date(int *day, int *month, int *year){
    char datum[10];
    printf(" *** Tag des Jahres *** \n");
    printf("Bitte geben Sie ein Datum ein: ");
    scanf("%10s",datum);
    char *token=strtok(datum,".");
    *day=atoi(token);
    token=strtok(NULL,".");
    *month=atoi(token);
    token=strtok(NULL,".");
    *year=atoi(token);
}

/*
Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
Übergabeparameter:
month: int
year: int
Rückgabewert:
Anzahl von Tagen: int
1-31, wenn ein gültiger Monar
eingegeben wurde
-1, wenn ein ungültiger Monat oder
Jahr übergeben wurde
*/
int get_days_for_month(int month, int year){
    tage_pro_monat[1]=28;
    if((month<1 || month>12) || (year<1582 || year>2400)) return -1;
    if(is_leapyear(year)) tage_pro_monat[1]++;
    return tage_pro_monat[month-1];
}


/*
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.
Übergabeparameter:
day: int
month: int
year: int
Rückgabewert:
1, wenn das übergebene Datum
gültig ist
0, wenn das Datum nicht gültig ist 
*/
int exists_date(struct date d){
    if (d.year<1582 || d.year>2400) return 0;
    if(d.month<1 || d.month>12) return 0;
    if(is_leapyear(d.year)) tage_pro_monat[1]++;
    if(tage_pro_monat[d.month-1]<d.day || d.day<1) return 0;
    tage_pro_monat[1]--;
    return 1;
}


/*
Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
Übergabeparameter:
day: int
month: int
year: int
Rückgabewert:
Nummer des Tages: int
*/
int day_of_the_year(struct date d){
    if(!exists_date(d)) return -1;
    int erg=1;
    if(d.month==1){
        return d.day;
    }
    for (int i = 0; i <= d.month-1; i++) {
        erg+=get_days_for_month(i,d.year);
    }  
    erg+=d.day;
    return erg;
}

/*
Berechnet den Wochentag eines Datums.
Übergabeparameter:
day:int
month:int
year:int
Rückgabewert:
Tag der Woche:int
*/
int day_of_the_week(struct date d){
    return (d.day+=d.month<3?d.year--:d.year-2,23*d.month/9+d.day+4+d.year/4-d.year/100+d.year/400)%7;
}


/*
Berechnet die Wochennummer des Datums.
Übergabeparameter:
day:int
month:int
year:int
Rückgabewert:
Nummer der Woche:int
*/
int week_of_the_year(struct date d){
    int doy=day_of_the_year(d);
    int dow=day_of_the_week(d);
    d.day=1;
    d.month=1;
    int dowjan1=day_of_the_week(d);
    int week=((doy+6)/7);
    if(dow<dowjan1) week++;
    return week;
}

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
