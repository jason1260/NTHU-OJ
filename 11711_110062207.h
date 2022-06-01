#include <stdlib.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k);
void delete_3d_array(unsigned ***arr);

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    int i;
    unsigned ***arr = (unsigned ***)malloc(n * sizeof(unsigned **));
    unsigned **row = (unsigned **)malloc(n * m * sizeof(unsigned *));
    unsigned *col = (unsigned *)malloc(n * m * k * sizeof(unsigned));
    for (i = 0; i < n; i++) arr[i] = &row[i*m];
    for (i = 0; i < n * m; i++) row[i] = &col[i*k];
    for (i = 0; i < n * m * k; i++) col[i] = 0;
    return arr;
}

void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
	free(arr[0]);
	free(arr);
}