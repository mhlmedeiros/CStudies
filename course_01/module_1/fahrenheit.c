/*
    C for Eveyone
    Convertion of Fahrenheit to Celsius
*/

#include <stdio.h>

int main(void){
    int fahrenheit, celsius;

    printf("Please enter fahrenheit as an integer: ");
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit-32)/1.8;
    printf("%d Fahrenheit is %d in Celsius\n", fahrenheit, celsius);
    return 0;
}

