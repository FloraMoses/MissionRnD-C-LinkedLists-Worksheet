/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	typedef struct node NODE;
	NODE *head, *first = 0, *cur = 0;
	if (N == 0) {
		head = (NODE *)malloc(sizeof(NODE));
		head->num = 0;
		head->next = NULL;
		return head;
	}
	if (N < 0)
		N = -N;
	int remainder = 0;
	while (N != 0)
	{
		head = (NODE *)malloc(sizeof(NODE));
		remainder = N % 10;
		head->num = remainder;
		N = N / 10;
		if (first != 0)	{
			cur->next = head;
			cur = head;
		}
		else {
			first = head;
			cur = head;
		}
	}
	cur->next = NULL;
	cur = first;
	NODE *previous = NULL, *next;
	while (cur != NULL) {
		next = cur->next;
		cur->next = previous;
		previous = cur;
		cur = next;
	}
	cur = previous;
	return cur;
}