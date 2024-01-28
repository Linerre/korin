/*
 * File: basics.c
 * ---------------
 * This file implements functions in basics.h
 */

#include <stdlib.h>
#include "basics.h"

// Using the while approach
int Length(struct node * head)
{
	struct node * current = head;
	int count = 0;
	while(current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

struct node * BuildOneTwoThree()
{
	struct node * head		= NULL;
	struct node * second	= NULL;
	struct node * third		= NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}

// Use the local pointer to modify the head
void Push(struct node ** head_ref, int new_data)
{
	// Init the new head
	struct node * new_head = malloc(sizeof(struct node));
	new_head->data = new_data;
	new_head->next = *head_ref;

	// Now make the original head pointer point to the new head
	*head_ref = new_head;
}
