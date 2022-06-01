#include <stdio.h>
#include <string.h>
#include "13391_110062207.h"

int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int num;
        
        if (!strcmp(str, "AddFront")) {
            scanf("%d", &num);
            AddFront(&head, &back, num);
        }
        else if (!strcmp(str, "AddBack")) {
            scanf("%d", &num);
            AddBack(&head, &back, num);
        }
        else if (!strcmp(str, "DeleteFront")) {
            DeleteFront(&head, &back);
        }
        else if (!strcmp(str, "Delete")) {
            scanf("%d", &num);
            Delete(&head, &back, num);
        }
        else if (!strcmp(str, "Swap")) {
            Swap(&head, &back);
        }
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;
    
    if (head->next == NULL) printf("empty\n");

    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}