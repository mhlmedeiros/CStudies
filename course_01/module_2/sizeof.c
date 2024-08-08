#include <stdio.h>

int main(){
    int a1=1;
    long int a2=1;
    float b1=0.0;
    double b2=0.0;
    long double b3=0.0;
    char ch='A';

    printf("On my system:\n\n");
    
    printf("int is %ld bytes long\n", sizeof(a1));
    printf("long int is %ld bytes long\n\n", sizeof(a2));

    printf("float is %ld bytes long\n", sizeof(b1));
    printf("double is %ld bytes long\n", sizeof(b2));
    printf("long double is %ld bytes long\n\n", sizeof(b3));

    printf("char is %ld bytes long\n", sizeof(ch));
    return 0;
}