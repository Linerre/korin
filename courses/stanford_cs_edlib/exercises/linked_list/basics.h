/*
 * File: basics.h
 * ---------------
 * This file defines a few basic funtion utilities used for
 * linked list exercises.  They are explained in deital in
 * http://cslibrary.stanford.edu/103/
 */

#ifndef _basics_h
#define _basics_h

struct node {
	int data;
	struct node* next;
};

/*
 * Function: Length
 * ----------------
 * Usage: Length(&head);
 * Return the number of nodes in the list.
 */
int Length(struct node* head);

/*
 * Allocate and return the list {1, 2, 3}.  Use this to build lists to work on.
 */
struct node * BuildOneTwoThree();

void Push(struct node** head_ref, int new_data);

#endif
