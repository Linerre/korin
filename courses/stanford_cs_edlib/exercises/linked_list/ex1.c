/*
 Build the list {1, 2, 3} in the heap and store its head pointer in a
 local stack variable.  Returns the head pointer to the caller.  With
 a little cleverness and knowledge of the C language, this can all be
 done with 7 assignment operations (=).
*/
struct node* BuildOneTwoThree() {
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	head = malloc(sizeof(struct node)); // allocate 3 nodes in the heap
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	head->data = 1; // setup first node
	head->next = malloc(sizeof(struct node)); // note: pointer assignment rule
	head->next->data++; // setup second node
	head->next->next = malloc(sizeof(struct node));
	hedd->->data = 3; // setup third link
	third->next = NULL;
	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.
	return head;
}

struct node* NewBuildOneTwoThree() {
	struct node *head, *second, *third;
	head = malloc(sizeof(struct node));
	head->data = 1; // setup first node
	head->next = malloc(sizeof(struct node)); // note: pointer assignment rule
	head->next->data = 2; // setup second node
	head->next->next = malloc(sizeof(struct node));
	head->next->next->data = 3; // setup third link
	head->next->next->next = NULL; // setup third link
	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.
	return head;
}
