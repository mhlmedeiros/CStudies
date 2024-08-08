#include <stdio.h>

int main(){
    int i, size;

    printf("Enter the number of values: ");
    scanf("%d", &size);

    int array[size];

    for (i=0; i<size; i++){
        scanf("%d", &array[i]);
    }
    return 0;
}