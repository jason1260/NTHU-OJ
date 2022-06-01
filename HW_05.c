#include <stdio.h>
int n, m, i;
char x, y, s[200010], c[1000];
int main() {
    for (i = 'a'; i <= 'z'; ++i) c[i] = i;
    scanf("%d%d\n%s\n", &n, &m, s);
    while(m--){
        scanf("%c %c\n", &x, &y);
        for(i='a';i<='z';++i){
            if(c[i] == x) c[i] = y;
            else if(c[i] == y) c[i] = x;
        }
    }
    for (i = 0; i < n; ++i) printf("%c", c[s[i]]);
    printf("\n");
}