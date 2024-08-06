/*
Coursera Course 2
Module 2
Assignment on writing a program using enum function
Arunima
July 13,2024
*/

#include <stdio.h>
#include <ctype.h>
// typedefs
typedef enum month
{
    jan,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

typedef struct date
{
    enum month m;
    int d, y;
} date;

// printing month
void print_month(struct date date)
{ // simple function for displaying month and day
    switch (date.m)
    {
    case jan:
        printf("January day %d\n", date.d);
        break;
    case feb:
        printf("February day %d\n", date.d);
        break;
    case mar:
        printf("March day %d\n", date.d);
        break;
    case apr:
        printf("April day %d\n", date.d);
        break;
    case may:
        printf("May day %d\n", date.d);
        break;
    case jun:
        printf("June day %d\n", date.d);
        break;
    case jul:
        printf("July day %d\n", date.d);
        break;
    case aug:
        printf("August day %d\n", date.d);
        break;
    case sep:
        printf("September day %d\n", date.d);
        break;
    case oct:
        printf("October day %d\n", date.d);
        break;
    case nov:
        printf("November day %d\n", date.d);
        break;
    case dec:
        printf("December day %d\n", date.d);
        break;
    default:
        printf("Out of range!");
        break;
    }
}

date next_day(struct date next)
{ // next month|day function

    int last_day;
    switch (next.m)
    {
    case jan:
    case mar:
    case may:
    case jul:
    case aug:
    case oct:
    case dec:
        last_day = 31;
        break;
    case apr:
    case jun:
    case sep:
    case nov:
        last_day = 30;
        break;
    case feb:
        last_day = 28;
        break;
    default:
        return next;
    }
    if (next.d++ == last_day)
    {
        next.d = 1;
        if (next.m++ == dec)
        {
            next.m = jan;
            next.y++;
        }
    }
    return next;
}

int main(void)
{
    struct date date_0 = {jan, 1};
    struct date date_1 = {feb, 28};
    struct date date_2 = {mar, 14};
    struct date date_3 = {oct, 31};
    struct date date_4 = {dec, 31};

    print_month(date_0);
    print_month(date_1);
    print_month(date_2);
    print_month(date_3);
    print_month(date_4);
    printf("\n");

    print_month(next_day(date_0));
    print_month(next_day(date_1));
    print_month(next_day(date_2));
    print_month(next_day(date_3));
    print_month(next_day(date_4));
    printf("\n\n");

    return 0;
}