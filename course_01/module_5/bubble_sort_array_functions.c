/*
Implements the algorithm of bubble sorting.

1. Asks the user to type in 5 integers;
2. Calculates the sum on the go;
3. Sorts using the bubble sorting algorithm;
4. Prints out the sequece sorted

Example of the "A book on C" pag. 37

*/

#include <stdio.h>
#define CLASS_SIZE 5

void swap(int *a, int *b);
void bubble_sort(int how_many, int data[]);
void print_array(int how_many, int data[], char str[]);

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int how_many, int data[]){
    /* Bubble sort: */
    int i, j, go_on;

    for (i = 0; i < CLASS_SIZE-1; i++){
        go_on = 0;
        for (j = CLASS_SIZE-1; j>i; j--){
            if (data[j] > data[j - 1]){
                swap(&data[j], &data[j-1]);
                go_on++;
            }
        }
        if (go_on == 0){
            printf("\nfinished\n");
            break;
        }
        else {
            print_array(CLASS_SIZE, data, "  inside bubble\n");
        }
    }
}

void print_array(int how_many, int data[], char str[]){
    int i;
    
    for(i=0; i<how_many; i++){
        printf("%5d", data[i]);
    }
    printf("%s", str);
}

int main(){
    int score[CLASS_SIZE];
    int i, j, sum = 0;

    printf("Input %d scores: ", CLASS_SIZE);
    for (i=0; i<CLASS_SIZE;i++){
        scanf("%d", &score[i]);
        sum += score[i];
    }

    print_array(CLASS_SIZE, score, "  initial state\n");
    bubble_sort(CLASS_SIZE, score);
    print_array(CLASS_SIZE, score, "  final state\n");

    printf("\nOrdered scores:\n\n");
    for (i=0; i<CLASS_SIZE; i++)
        printf("   score[%d]=%5d\n", i, score[i]);
    printf(
        "\n%18d%s\n%18.1f%s\n\n",
        sum,
        " is the sum of all the scores",
        (double) sum/CLASS_SIZE,
        " is the class average"
    );
    return 0;
}