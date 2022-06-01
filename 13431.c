#include "13431.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef putchar_unlocked
#define putchar putchar_unlocked
#endif

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        node *head = malloc(sizeof(node)), *cur = head;
        while (n--)
        {
            scanf("%d", &(cur->val));
            if (n)
                cur = cur->next = malloc(sizeof(node));
            else
                cur->next = NULL;
        }
        putchar(is_palindrome(head) ? 'T' : 'F');
        while (head)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    putchar('\n');
    return 0;
}
