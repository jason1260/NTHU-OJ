#include<stdio.h>
#include <stdlib.h>

#include "13372_110062207.h"

void Swap(int*, int*);

void Replace(int*, int*);

void Switch(int**, int**);

void PrintArrays(int *A, int *B, int size){
    for(int i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    for(int j = 0; j < size; j++){
        if(j != 0) printf(" ");
        printf("%d", B[j]);
    }
    printf("\n");
    return;
}

int main(){
    char str[10];
    int size;
    scanf("%d", &size);

    int *A = (int*)malloc(sizeof(int)*size);
    int *B = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        A[i] = num;
    }

    for(int j = 0; j < size; j++){
        int num;
        scanf("%d", &num);
        B[j] = num;
    }

    while(1){
        scanf("%s", str);
        if(str[2] == 'A') Swap(A, B);//Swap
        else if(str[2] == 'I') Switch(&A, &B);//Switch
        else if(str[2] == 'P') Replace(A, B);//Replace
        else if(str[2] == 'O') break;//Stop
    }

    PrintArrays(A, B, size);

    return 0;
}

void Swap(int *a, int *b) {
    char x, y;
    int m, n, temp;
    scanf(" \n%c %c %d %d", &x, &y, &m, &n);
    if (x == 'A') {
        temp = *(a + m);
        *(a + m) = *(b + n);
        *(b + n) = temp;
    }
    else if (x == 'B'){
        temp = *(b + m);
        *(b + m) = *(a + n);
        *(a + n) = temp;
    }
}

void Replace(int *a, int *b) {
    char t;
    long long int m, n;
    scanf(" \n%c %lld %lld", &t, &m, &n);
    if (t == 'A') *(a + m) = n;
    else if (t == 'B') *(b + m) = n;
}

void Switch(int **a, int **b) {
    int *m;
    m = *a;
    *a = *b;
    *b = m;
}