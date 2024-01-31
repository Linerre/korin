#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "basics.h"

int Count(struct node * head, int search)
{
	struct node * current = head;
	int count = 0;
	while(current->next != NULL) {
		if (current->data == search)
			count++;

		current = current->next;
	}
	return count;
}

int main()
{
	struct node * head = BuildOneTwoThree();
	assert(Length(head) == 3);
	printf("List lenght is: %d\n", Length(head));

	int cnt2 = Count(head, 2);
	assert(cnt2 == 1);
	printf("The number of value 2 is: %d\n", cnt2);

	return 0;
}
