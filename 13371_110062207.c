#include <stdio.h>
#include <stdlib.h>

#include "13371_110062207.h"

void mergeSort(int*, int, int);

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main()
{   
    int size;

    scanf("%d", &size);

    int *arr = (int*)malloc(sizeof(int)*size);
    
    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    mergeSort(arr, 0, size - 1);
    
    printArray(arr, size);
    return 0;
}

void mergeSort(int* arg, int st, int ed) {
    if (st >= ed)
        return;
    int arr[ed];
    int mid = ((ed - st) >> 1) + st;
    int st1 = st, ed1 = mid;
    int st2 = mid + 1, ed2 = ed;
    mergeSort(arg, st1, ed1);
    mergeSort(arg, st2, ed2);
    int k = st;
    while (st1 <= ed1 && st2 <= ed2)
        arr[k++] = arg[st1] < arg[st2] ? arg[st1++] : arg[st2++];
    while (st1 <= ed1)
        arr[k++] = arg[st1++];
    while (st2 <= ed2)
        arr[k++] = arg[st2++];
    for (k = st; k <= ed; k++) {
        arg[k] = arr[k];
    }
}