#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Range 100 // range of random increase in salary.
#define Randomarray rand() % Range

#define FIll1                 \
    for (i = 0; i < 100; i++) \
        a[i] = Randomarray;

void bubble_sort(int a[], int size)
{
    int i;
    int j;
    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf(" a[%d] = %d ", i, a[i]);
    }
}

int main()
{
    int i;
    int a[100];
    srand(time(0));
    FIll1;
    bubble_sort(a, 100);
    return 0;
};