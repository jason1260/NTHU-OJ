#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ans[5000];
int ans_index = 0;
int main () {
    char in[1010];
    char last = '\0';
    int count = 0;
    scanf("%s", in);
    char tmp = in[0];
    int len = strlen(in);
    while(len--) {
        tmp = in[strlen(in) - len - 1];
        //printf("tmp = %c, last = %c\n", tmp, last);
        if (tmp != last && len != (strlen(in) - 1)) {
            if (last <= '9') {
                //printf("case 1\n");
                if (count >= 2) {
                    int a, b, c;
                    if (count == 1000) {
                        ans[ans_index++] = '1';
                        ans[ans_index++] = '0';
                        ans[ans_index++] = '0';
                        ans[ans_index++] = '0';
                    }
                    else if (count >= 100) {
                        c = count % 10;
                        //printf("%d\n", c);
                        count /= 10;
                        b = count % 10;
                        //printf("%d\n", b);
                        count /= 10;
                        a = count % 10;
                        //printf("%d\n", a);
                        count /= 10;
                        ans[ans_index++] = '0' + a;
                        ans[ans_index++] = '0' + b;
                        ans[ans_index++] = '0' + c;
                    }
                    else if (count >= 10) {
                        b = count % 10;
                        count /= 10;
                        a = count % 10;
                        count /= 10;
                        ans[ans_index++] = '0' + a;
                        ans[ans_index++] = '0' + b;
                    }
                    else ans[ans_index++] = count + 48;
                }
                ans[ans_index++] = '\'';
                ans[ans_index++] = last;
                ans[ans_index++] = '\'';
            }
            else if (count > 2 && last >= 'A') {
                //printf("case 2\n");
                int a, b, c;
                if (count == 1000) {
                    ans[ans_index++] = '1';
                    ans[ans_index++] = '0';
                    ans[ans_index++] = '0';
                    ans[ans_index++] = '0';
                }
                else if (count >= 100) {
                    c = count % 10;
                    //printf("%d\n", c);
                    count /= 10;
                    b = count % 10;
                    //printf("%d\n", b);
                    count /= 10;
                    a = count % 10;
                    //printf("%d\n", a);
                    count = 0;
                    ans[ans_index++] = '0' + a;
                    ans[ans_index++] = '0' + b;
                    ans[ans_index++] = '0' + c;
                }
                else if (count >= 10) {
                    b = count % 10;
                    count /= 10;
                    a = count % 10;
                    count /= 10;
                    ans[ans_index++] = '0' + a;
                    ans[ans_index++] = '0' + b;
                }
                else ans[ans_index++] = count + 48;
                ans[ans_index++] = last;
            }
            else {
                //printf("case 3\n");
                for (int i = 0; i < count; i++)
                    ans[ans_index++] = last;
            }
            count = 1;
        }
        else 
            count++;
        last = tmp;
        //printf("count = %d\n", count);
    }
    if (last <= '9') {
        //printf("case 1\n");
        if (count >= 2) {
            int a, b, c;
            if (count == 1000) {
                ans[ans_index++] = '1';
                ans[ans_index++] = '0';
                ans[ans_index++] = '0';
                ans[ans_index++] = '0';
            }
            else if (count >= 100) {
                c = count % 10;
                //printf("%d\n", c);
                count /= 10;
                b = count % 10;
                //printf("%d\n", b);
                count /= 10;
                a = count % 10;
                //printf("%d\n", a);
                count = 0;
                ans[ans_index++] = '0' + a;
                ans[ans_index++] = '0' + b;
                ans[ans_index++] = '0' + c;
            }
            else if (count >= 10) {
                b = count % 10;
                count /= 10;
                a = count % 10;
                ans[ans_index++] = '0' + a;
                ans[ans_index++] = '0' + b;
            }
            else ans[ans_index++] = count + 48;
        }
        ans[ans_index++] = '\'';
        ans[ans_index++] = last;
        ans[ans_index++] = '\'';
    }
    else if (count > 2 && last >= 'A') {
        //printf("case 2\n");
        int a, b, c;
        if (count == 1000) {
            ans[ans_index++] = '1';
            ans[ans_index++] = '0';
            ans[ans_index++] = '0';
            ans[ans_index++] = '0';
        }
        else if (count >= 100) {
            c = count % 10;
            //printf("%d\n", c);
            count /= 10;
            b = count % 10;
            //printf("%d\n", b);
            count /= 10;
            a = count % 10;
            //printf("%d\n", a);
            count = 0;
            ans[ans_index++] = '0' + a;
            ans[ans_index++] = '0' + b;
            ans[ans_index++] = '0' + c;
        }
        else if (count >= 10) {
            b = count % 10;
            count /= 10;
            a = count % 10;
            ans[ans_index++] = '0' + a;
            ans[ans_index++] = '0' + b;
        }
        else ans[ans_index++] = count + 48;
        ans[ans_index++] = last;
    }
    else {
        //printf("case 3\n");
        for (int i = 0; i < count; i++)
            ans[ans_index++] = last;
    }
    printf("%s\n", ans);
    double l_ans = strlen(ans);
    double l_in = strlen(in);
    double rate = l_ans / l_in;
    (rate >= 1.0) ? printf("The string can't zip\n") :printf("Compress rate: %.3f\n", rate);

    return 0;
}