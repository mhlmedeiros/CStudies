/*
Generate a table of absolute values of sine and cosine 
    values between (0,1);
  
The range of the table is  from 0 to 2*PI with "n" 
equal steps;
*/

#include <stdio.h>
#include <math.h>

/*value of pi*/
#define PI 3.141592 

int main(){
    int i, n=20;
    float x=0.0;

    /*print the header of the table*/
    printf(
        "%5s%15s%15s%15s\n%5s%15s%15s%15s\n\n",
        "index", "  x  ", "|sin(x)|", "|cos(x)|",
        "_____", "________", "_________", "_________");

    /*print each row of the table*/
    for (i=0;i<=n;i++){
        x = i * 2*PI/n;
        printf(
            "%5d%15f%15f%15f\n", 
            i, x, fabs(sin(x)), fabs(cos(x))
        );
    }
    return 0;
}