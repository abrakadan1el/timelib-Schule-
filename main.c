/**
 *  Author: philipp luersen
 *  version: 1.0
 *  date:03.05.2022
 *  A short Program to determine the number of days before a given date.
 *
 **/

#include <stdlib.h>

#include <stdio.h>

int schalt(int jahr){
    if(jahr%4==0){
        if(jahr%100==0){
            if(jahr%400==0){
                return 1;
            }
           return 0;
        }
        return 1;
    }
    return 0;
}


int main()
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int tag,monat,jahr,erg=0;
    
    printf(" *** Tag des Jahres *** \n");
    do{
        printf("Geben Sie das Jahr ein: ");
        scanf("%d",&jahr);
    }while(jahr<1000 || jahr>9999);
    
    if(schalt(jahr)){
        tage_pro_monat[1]++;
    }
    
    do{
        printf("Geben Sie den Monat ein: ");
        scanf("%d",&monat);
    }while(monat<1 || monat>12);

    do{
        printf("Geben Sie den Tag ein: ");
        scanf("%d",&tag);
    }while(tage_pro_monat[monat-1]<tag || tag<1);

    if(monat==1){
        printf("Heute ist der %d. Tag dieses Jahres.",tag);
        return 0;
    }
    
    for (int i = 0; i <= monat-2; i++) {
        erg+=tage_pro_monat[i];
    }
    erg+=tag;
    printf("Heute ist der %d. Tag dieses Jahres.",erg);
    
    return 0;
}
