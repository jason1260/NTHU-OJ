#include <stdio.h>
char key[7] = "BANANA";
char input;
int main () {
    int i, j;
    int index = 0, count = 0, wrong = 0;
    while (scanf("%c", &input) == 1) {
        if (input == '0') {
            printf("No potassium.\n");
            break;
        }
        if (input != key[index] || wrong > 0) {
            if (input == '/') {
                if (wrong > 0) {
                    wrong -= 1;
                    //wrong > 0 ? printf("-1\n") : printf("%d\n", count);
                }
                else {
                    if (index > 0) {
                        count--;
                        index--;
                    }
                    //printf("-1\n");
                    wrong = 0;
                }
                wrong > 0 ? printf("-1\n") : printf("%d\n", count);
            }
            else {
                wrong += 1;
                printf("-1\n");
            }
            //wrong > 0 ? printf("-1\n") : printf("%d\n", count);
        }
        else {
            count++;
            index++;
            printf("%d\n", count);
        }
        if (count == 6) {
            printf("Potassium!\n");
            break;
        }
    }
    //if (wrong > 0) printf("No potassium.\n");

    return 0;
}