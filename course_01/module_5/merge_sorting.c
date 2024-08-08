#include <stdio.h>

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


int main(){
    int len1=4, array1[4]={3, 5, 7, 8};
    int len2=3, array2[3]={1, 2, 9};
    int i, len3, array3[7];

    /*
    printf("Please enter your the size of your array: ");
    scanf("%d", &n);
    */
    len3 = len2 + len1;
    merge(array1, array2, array3, len1, len2);

    for (i=0; i<len3; i++){
        printf("%5d", array3[i]);
    }

    printf("\n");
    return 0;
}