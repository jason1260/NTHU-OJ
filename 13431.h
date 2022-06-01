#include <stdbool.h>

typedef struct _node
{
    int val;
    struct _node *next;
} node;

bool is_palindrome(node *head) {
    int list[50010] = {0};
    int count = 0, i;
    node *index = head;
    for (; index; index = index->next) count++;
    for (i = 0, index = head; i < count >> 1; i++, index = index->next) list[i] = index->val;
    index = (count & 1) ? index->next : index;
    for (i -= 1; index; index = index->next, i--) 
        if (list[i] != index->val) return false;
    return true;
}