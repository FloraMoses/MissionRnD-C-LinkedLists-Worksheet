/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
void sort1(struct node*);
void swap1(struct node*, struct node*);
struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	if (head == NULL) {
		return head;
	}
	sort1(head);
	return head;
}
void sort1(struct node *start) {
	int swapped = 1, i;
	struct node *ptr1;
	struct node *lptr = NULL;
	while (swapped) {
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr) {
			if (ptr1->num > ptr1->next->num) {
				swap1(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}
void swap1(struct node *a, struct node *b) {
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}