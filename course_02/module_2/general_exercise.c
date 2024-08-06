/*
    Implementation of a program that prints
    the next day and calculate the next day
    of a given date.
*/

#include <stdio.h>

typedef enum month{jan, feb, mar, apr, may, jun, jul, ago, sep, oct, nov, dec} month;
typedef struct date{month m; int d;} date;

/*Function to update the month after updating the day*/
void update_month(date *dt){
    switch (dt->d)
    {
    case 29:
        if (dt->m == feb){
            dt->m++;
            dt->d = 1;
        }
        break;
    case 31:
        switch (dt->m)
        {
        case apr: dt->m++; dt->d = 1; break;
        case jun: dt->m++; dt->d = 1; break;
        case sep: dt->m++; dt->d = 1; break;
        case nov: dt->m++; dt->d = 1; break;
        default: break;
        }
    default:
        if (dt->d > 31){
            dt->m++;
            dt->m = dt->m % 12;
            dt->d = dt->d % 31;
        }
        break;
    }
}

/*Function to update the day to the next day*/
void next_day(date *dt){
    dt->d++;
    update_month(dt);
}

/*Function to print the date in formatted way*/
void print_date(const date *dt){
    char *month;
    switch (dt->m){
        case jan: month = "Jan"; break;
        case feb: month = "Feb"; break;
        case mar: month = "Mar"; break;
        case apr: month = "Apr"; break;
        case may: month = "May"; break;
        case jun: month = "Jun"; break;
        case jul: month = "Jul"; break;
        case ago: month = "Ago"; break;
        case sep: month = "Sep"; break;
        case oct: month = "Oct"; break;
        case nov: month = "Nov"; break;
        case dec: month = "Dec"; break;
    }
    printf("%s %2d", month, dt->d);
}

int main(void){
    /*
    Defining an array of dates to 
    organize the code; in this way 
    one can use a loop to apply the 
    functions. 
    */
    int i;
    date dates[4] = {
        {feb,28}, 
        {mar,14}, 
        {oct,31}, 
        {dec,31}
    };

    /*
    assuming each entry of the array as the current date,
    print out the date and the next date in a fomatted way
    */
    for (i=0; i<4; i++){
        printf("%20s","Current date: ");
        print_date(dates + i);
        next_day(dates + i);
        printf("%20s", "Next date: ");
        print_date(dates + i);
        putchar('\n');
    }
    return 0;
}

