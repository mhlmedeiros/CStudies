#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS 1000 /* number of fct calls */
#define NCOLS 7 /* number of columns */
#define NLINES 7 /* number of lines */

int main(void){
    int i,val;
    long begin, diff, end;

    begin = time(NULL);
    srand(time(NULL));
    printf("\nTIMING TEST: %d calls to rand()\n\n", NCALLS);

    for(i=1; i<=NCALLS; ++i){
        val = rand();
        if (i<=NCOLS*NLINES){
            printf("%15d ", val);
            if (i%NCOLS==0)
                printf("\n");
        }
        else if(i == NCOLS * NLINES +1)
            printf("%15s\n\n", "......");
    }
    end = time(NULL);
    diff = end-begin;

    printf(
        "%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
        "          end time: ", end,
        "        begin time: ", begin,
        "      elapsed time: ", diff,
        "time for each call: ", (double) diff/NCALLS
    );

    return 0;
}