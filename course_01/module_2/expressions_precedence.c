#include <stdio.h>

int main(){
    int a=5, b=7, c=0, d=0; //initialize
    c = a - b;
    // a==5; b==7; c==-2; d==0;
    printf("a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
    c = a/b; 
    d = b/a; 
    //a==5; b==7; c==0; d==1
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    c = a%b; 
    d = b%a; 
    //a==5; b==7; c==5; d==2 
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    c = -a-b; 
    d = -b-a; 
    //a==5; b==7; c==-12; d==-12
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    c = ++a + b++; d += 5;
    // a==6; b==8; c==13; d==-7
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    return 0;
}