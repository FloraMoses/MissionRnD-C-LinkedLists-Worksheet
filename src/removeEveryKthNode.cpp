/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K <= 0 || head == NULL || K == 1) {
		return NULL;
	}
	struct node *cur = head;
	int count = 1;
	while (cur != NULL) {
		count++;
		if (count == K) {
			count = 1;
			if (cur->next == NULL)
				continue;
			else
				cur->next = cur->next->next;
		}
		cur = cur->next;
	}
	return head;
}