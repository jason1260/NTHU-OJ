#include <stdio.h>
int main () {
    int i, t, a = 0, gap = 1;
    int count = 1;
    //char gray[100];
    scanf("%d", &t);
    for (i = 0; i < t; i++) count = count << 1;
    for (i = 0; i < count - 1; i++) {
        printf("%d\n", a);
        //for (i = 0; i < 100; i++) gray[i] = '0';
        if (!(i & 1)) {
            (a & 1) ? a-- : a++;
        }
        else {
            while (!(a & gap)) gap = gap << 1;
            gap = gap << 1;
            if (a & (gap)) a -= gap;
            else a += gap;
            gap = 1;
        }
    }
    printf("%d\n", a);

    return 0;
}