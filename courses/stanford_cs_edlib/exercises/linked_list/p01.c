#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "basics.h"

int main()
{
	struct node * head = BuildOneTwoThree();
	assert(Length(head) == 3);
	printf("List lenght is: %d\n", Length(head));
	return 0;
}
