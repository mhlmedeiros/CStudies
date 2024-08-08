#include "merge_sort.h"

void merge(int a[], int b[], int c[], int m, int n){
    int i=0,j=0,k=0;

    while (i<m && j<n){
        if (a[i]<b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i<m)
        c[k++] = a[i++];
    while (j<n)
        c[k++] = b[j++];
}

void mergesort_power2(int a[], int n){
    int k, i, *w, count = 0;
    w = calloc(n, sizeof(int)); // free here

    for (k = 1; k < n; k *= 2){
        for (i = 0; i < n; i += 2 * k){
            merge(a + i, a + i + k, w + i, k, k);
        }
        for (i = 0; i < n; ++i){
            a[i] = w[i];
        }
        ++count;
        //printf("\tt = %d: ", count);
        //print_array(a, n);
    }
    free(w);
}

void print_array(int a[], int n){
    int i;
    printf("[");
    for( i=0; i<n; ++i){
        printf("%4d%s", a[i], (i==n-1)? "]\n": ",");
    }
}

int maxpower2(int N, int *exponent){
    int m, count=0;

    for (m=1; m<N; m*=2){
        if (N<2*m){ 
            break;
        }
        ++count;
    }
    *exponent = count;
    return m;
}


void decompose(int N, int *powers){
    
    int exponent, power = 0, sum = 0, count = 0;

    for (sum=0; sum!=N; sum += power){
        power = maxpower2(N-sum, &exponent);
        powers[count] = power;
        ++count;
    }

}