#include <stdio.h>
#include <stdlib.h>



typedef struct rational {
    int numerator;
    int denominator;
} rational;

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

        printf("%d: %d/%d\n", i, num, den);
    }
}

void print_fraction(rational fraction)
{
    printf("%d/%d\n",fraction.numerator, fraction.denominator);
}


rational* build_array(FILE* ifp, int *size)
{
    int i;
    fscanf(ifp, "%d", size);

    printf("%d\n\n", *size);
    rational *fractions = malloc(*size * sizeof(rational));
    
    for (i=0; i < *size; i++)
    {
        fscanf(ifp, "%d", &((fractions+i)->numerator));
        fscanf(ifp, "%d", &((fractions+i)->denominator));
    }
    return fractions;
}


rational* sum(rational a, rational b)
{   
    rational *ans = malloc(sizeof(rational));
    ans->numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    ans->denominator = a.denominator * b.denominator;
    return ans;
}

rational* multiplication(rational a, rational b)
{   
    rational *ans = malloc(sizeof(rational));
    ans->numerator = a.numerator * b.numerator;
    ans->denominator = a.denominator * b.denominator;
    return ans;
}

rational* division(rational a, rational b)
{   
    rational b_inv;
    b_inv.numerator = b.denominator;
    b_inv.denominator = b.numerator;
    return multiplication(a, b_inv);
}

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
    //FILE *ofp;
    rational* fractions;
    rational* s;
    rational* average;
    rational* size_inv=malloc(sizeof(rational));

    ifp = fopen(argv[1], "r+");
    //ofp = fopen(argv[2], "w");
    
    
    fractions = build_array(ifp, &size);
    
    printf("OK\n");
    printf("%d\n\n", size);

    
    s = sum(fractions[0], fractions[1]);
    print_fraction(*s);

    s = multiplication(fractions[0], fractions[1]);
    print_fraction(*s);

    s = division(fractions[0], fractions[1]);
    print_fraction(*s);

    s = sum_all(fractions, size);
    print_fraction(*s);

    size_inv->numerator = 1;
    size_inv->denominator = size;

    average = multiplication(*s, *size_inv);

    print_fraction(*average);

    fclose(ifp);
    //fclose(ofp);

    return 0;
}