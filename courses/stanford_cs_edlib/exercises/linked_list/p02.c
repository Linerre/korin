#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "basics.h"

int GetNth(struct node * head, int n)
{
	assert(n >= 0);

	int count = 0;
	struct node * current = head;
	// NOTE: current, not current->next
	while(current != NULL) {
		count++;

		if (n == count - 1)
			return current->data;

		current = current->next;
	}

	// Will fail if n is invalid
	assert(n <= count - 1);
	return -1;
}

int main()
{
	struct node * my_list = BuildOneTwoThree();
	int last_ndata = GetNth(my_list, 2);

	assert(last_ndata == 3);

	return 0;
}
