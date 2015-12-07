/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>
void sort(struct node*);
void swap(struct node*, struct node*);
struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	sort(head);
}
void sort(struct node *start) {
	int swapped = 1, i;
	struct node *ptr1;
	struct node *lptr = NULL;
	while (swapped) {
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr) {
			if (ptr1->data > ptr1->next->data) {
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} 
}
void swap(struct node *a, struct node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}