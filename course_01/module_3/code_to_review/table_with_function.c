#include <stdio.h>
#include <math.h>

//void printSineCosineTable();

// Function to print a table of sine and cosine values between 0 and 1
void printSineCosineTable()
{
    double interval = 0.1; // Step size for the table
    double angle, sine_val, cosine_val;

    // Print table header
    printf("Angle\tSine\tCosine\n");

    // Loop through angles from 0 to 1 with step size of 0.1
    for (angle = 0.0; angle <= 1.0; angle += interval)
    {
        sine_val = sin(angle);
        cosine_val = cos(angle);
        printf("%.2f\t%.4f\t%.4f\n", angle, sine_val, cosine_val);
    }
}

// Main function to demonstrate the table printing
int main()
{
    printSineCosineTable();
    return 0;
}