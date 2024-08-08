#include <stdio.h>

void swap(int*, int*);


int main(){
    int a, b;
    printf("\nEnter two integers: ");
    scanf("%d %d", &a, &b);
    printf("\nThe intial values are a=%d and b=%d\n", a, b);
    swap(&a,&b);
    printf("\nThe final values are a=%d and b=%d\n\n", a, b);
    return 0;
}

void swap(int *i, int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}