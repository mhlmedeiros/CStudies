/* This code uses the sin() and cos() functions in the math library and print out theirs
 * correspoding values in terminal view with input values between 0 and 1.
 *
 * Code modifyed from Coursera course on C of Module 3.
 *
 * Jully 2th, 2024
 */

#include <stdio.h>
#include <math.h> // has sin(), abs(), ans fabs()

int main(void)
{
	double interval; 
	int i;
	int n;
	
	printf("Please, insert here how many input values you want between 0 and 1\n");
	scanf("%d", &n);
		
	printf("\n  ____________________________________________________\n");
	printf("\n    Table of values of Sine and Cossine Functions");
	printf("\n  ____________________________________________________\n");


	for(i = 0; i < n; i++)
	{
		interval = i/(n-1.);
		printf("\n | sin(%lf) = %lf, cos(%lf) = %lf | \t", interval, sin(interval), interval, cos(interval));
	}

	printf("\n  ----------------------------------------------------\n");

	return 0;
}
