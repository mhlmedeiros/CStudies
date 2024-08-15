#include <stdio.h>
#include <stdlib.h>

/* Definition of the struct that holds the rational numbers*/
typedef struct rational {
    int numerator;
    int denominator;
} rational;

/*Function to print the content of a file*/
void print_file(FILE *ifp)
{
    char c;
    rewind(ifp);

    fscanf(ifp, "%c", &c);
    while ((c=getc(ifp))!=EOF)
    {
        putchar(c);
    }
    putchar('\n');
}

/*Function to print out the pairs */
void print_pairs(FILE *ifp)
{
    int i, n;
    int num, den;
    rewind(ifp);

    fscanf(ifp, "%d", &n);
    for (i=0; i<n; i++)
    {
        fscanf(ifp, "%d", &num);
        fscanf(ifp, "%d", &den);

        printf("%d: (%d,%d)\n", i, num, den);
    }
}

/*Function to print out the a fraction */
void print_fraction(rational fraction)
{
    printf("%d/%d\n",fraction.numerator, fraction.denominator);
}

/*Builder function to generate the array of rationals*/
rational* build_array(FILE* ifp, int *size)
{
    int i;
    fscanf(ifp, "%d", size);

    rational *fractions = malloc(*size * sizeof(rational));
    
    for (i=0; i < *size; i++)
    {
        fscanf(ifp, "%d", &((fractions+i)->numerator));
        fscanf(ifp, "%d", &((fractions+i)->denominator));
    }
    return fractions;
}

/*Rotine to calculate the sum of 2 rational numbers*/
rational* sum(rational a, rational b)
{   
    rational *ans = malloc(sizeof(rational));
    ans->numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    ans->denominator = a.denominator * b.denominator;
    return ans;
}

/*Rotine to calculate the product of 2 rational numbers*/
rational* multiplication(rational a, rational b)
{   
    rational *ans = malloc(sizeof(rational));
    ans->numerator = a.numerator * b.numerator;
    ans->denominator = a.denominator * b.denominator;
    return ans;
}

/*Rotine to calculate the division of 2 rational numbers*/
rational* division(rational a, rational b)
{   
    rational b_inv;
    b_inv.numerator = b.denominator;
    b_inv.denominator = b.numerator;
    return multiplication(a, b_inv);
}

/*Rotine to calculate the sum all rational numbers in a array*/
rational* sum_all(rational* fractions, int size)
{
    rational *summation=malloc(sizeof(rational));
    rational *n_inv=malloc(sizeof(rational));
    int i;

    summation->numerator = 0;
    summation->denominator = 1;

    n_inv->numerator = 1;
    n_inv->denominator = size;

    for (i=0; i<size; i++)
    {
        summation = sum(*summation, fractions[i]);
    }

    return summation;
}


int main(int argc, char *argv[])
{
    int size;
    FILE *ifp;
    rational* fractions;
    rational* summation;
    rational* average;
    rational* size_inv=malloc(sizeof(rational));

    if (argc != 2){
        printf("You have to pass an input file.\n");
        exit(1);
    }
    ifp = fopen(argv[1], "r+");
    fractions = build_array(ifp, &size);
    summation = sum_all(fractions, size);
    size_inv->numerator = 1;
    size_inv->denominator = size;
    average = multiplication(*summation, *size_inv);

    printf("The sum of all rationals is: ");
    print_fraction(*summation);
    printf("The average of the ratioals is: ");
    print_fraction(*average);
    fclose(ifp);

    return 0;
}