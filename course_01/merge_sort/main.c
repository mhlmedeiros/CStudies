/*
    MERGE SORTING FOR AN ARRAY 
    WITH AN ARBITRARY NUMBER OF
    ELEMENTS
*/


#include "merge_sort.h"
#define N 13

int main(void){
    int m=N, a[N] = {7,6,1,2,8,9,5,4,1,4,2,3,10};
    int max_exp, *decomp, *temp;
    int i, j, k;

    maxpower2(m, &max_exp);
    decomp = calloc(max_exp+1, sizeof(int));
    temp = calloc(m, sizeof(int));

    decompose(m, decomp);
    print_array(a, m);
    //print_array(decomp, max_exp+1);

    j = 0;
    for (i=0; decomp[i] != 0; ++i)
    {
        mergesort_power2(a + j, decomp[i]);
        j += decomp[i];
    }

    //print_array(a, m);

    j = 0;
    for (i = 0; decomp[i] != 0; ++i)
    {
        j += decomp[i];
        merge(a, a + j, temp, j, decomp[i+1]);
        for (k = 0; k < j+decomp[i+1]; ++k)
        {
            a[k] = temp[k];
        }
    }

    

    print_array(a, m);

    free(temp);
    free(decomp);

    return 0;
}