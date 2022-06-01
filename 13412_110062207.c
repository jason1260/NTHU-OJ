#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int val;
    struct _Node *next;
}Node;
Node* Solver(Node* head, int k) {
	if (k == 1) {
		return head;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	node->val = -1;
	node->next = head;
	Node* hd = node;
	Node* bk = head;
	Node* index = head;
	Node* hh = head->next;
	int count = k, flag = 1;
	while (flag) {
		while (--count) {
            if (!index) return node->next;
			if (index->next) {
			    //printf("bk = %d, index = %d\n", bk->val, index->val);
				bk = index->next;
				index = index->next;
			}
			else {
                return node->next;
			}
        }
		count = k;
		if (!hd->next || !hd->next->next) break;
		Node* tmp = hd->next, *tmpNext = hd->next->next, *tmpNextNext;
		tmp->next = bk->next;
		hd->next = bk;
		//printf("b  head = %d, hd = %d, hdnext = %d, bk = %d\n", head->val, hd->val, hd->next->val, bk->val);
		while (tmpNext->next != bk->next) {
			tmpNextNext = tmpNext->next;
			tmpNext->next = tmp;
			tmp = tmpNext;
			tmpNext = tmpNextNext;
		}
		tmpNext->next = tmp;
		hd = head;
		if (hd) head = hd->next;
		if (hd) index = hd->next;   
		if (hd) bk = hd->next;
		//printf("a  head = %d, hd = %d, hdnext = %d, bk = %d\n", head->val, hd->val, hd->next->val, bk->val);
		//break;
	}
	//printf("hd = %d, hdnext = %d, index = %d\n", hd->val, hd->next->val, index->val);
	return node->next;
}