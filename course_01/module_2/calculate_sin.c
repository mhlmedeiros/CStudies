/*
    This program asks for a float input x
    and returns the sine of x.

    To compile this code use:

        gcc -o calculate_sin.exe calculate_sin.c -lm
    
    then the math library will be correctly included.

*/

#include <stdio.h>
#include <math.h>

int main(void){
    
    float  x=0.0, sin_x=0.0; //initialize the variables

    printf("Please enter a real number (angle in rads): ");
    scanf("%f", &x); // input

    sin_x = sin(x);
    printf("\nsin(%f) = %f\n\n", x, sin_x); // result
    
    return 0;
}