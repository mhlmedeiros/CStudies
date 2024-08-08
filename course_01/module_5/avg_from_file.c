/*
    The executable of this code is supposed to be used
    as follows:

    a.out file_input

    where file_input is a text file with integers.
    In the context of the exercise: 
    
    file_input == elephant_seal_data.txt
*/
#include <stdio.h>

double average_from_array(int array[], int size){
    /*
    Receive an array of integers and its size;
    Returns the average.
    */
    int i, sum=0;
    
    for (i = 0; i < size; i++){
        sum += array[i];
    }
    return (double)sum / size;
}


double average_from_file(int size, char * file_name){
    /*
    Reads the content of a file with integers;
    Save its content into an array;
    Return the average of the numbers as a double.
    */
    int i, sum=0;
    int array[size];
    FILE * ifp;
    ifp = fopen(file_name,"r");
    for (i = 0; !feof(ifp); i++){
        fscanf(ifp, "%d", &array[i]);
    }
    fclose(ifp);
    return average_from_array(array, size);
}


int main(int argc, char * argv[]){
    int x, count;
    double avg;
    FILE * ifp; /*pointer to a file*/

    /* Test whether an argument was passed */
    if (argc != 2){
        printf("Please, pass a file with data as an argument!\n");
        return 0;
    }
    
    /* Open the file and count the numbers in it */
    ifp = fopen(argv[1], "r");
    for (count=0; !feof(ifp); count++){
        fscanf(ifp, "%d", &x);
    }
    fclose(ifp);

    /*Calculate the average saving the number into an array first*/
    avg = average_from_file(count, argv[1]);
    printf("avg = %.4lf\n", avg);

    return 0;
}