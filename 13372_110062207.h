#include <stdio.h>
void Swap(int*, int*);
void Replace(int*, int*);
void Switch(int**, int**);

void Swap(int *a, int *b) {
    char x, y;
    int m, n, temp;
    fflush(stdin);
    scanf("%c %c %d %d", &x, &y, &m, &n);
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
    fflush(stdin);
    scanf("%c %lld %lld", &t, &m, &n);
    if (t == 'A') *(a + m) = n;
    else if (t == 'B') *(b + m) = n;
}

void Switch(int **a, int **b) {
    int *m;
    m = *a;
    *a = *b;
    *b = m;
}