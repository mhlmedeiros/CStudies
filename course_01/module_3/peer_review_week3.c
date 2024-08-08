#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main(void){
    double interval;
    int i;

    for (i=0;i<=30;i++){
        interval = i * 2*PI/30;
        printf("%d sin(%lf) = %lf\n", i, interval, fabs(sin(interval)));
    }
    printf("\n+++++++\n");
    return 0;
}