/**
 * Function pointers are functions used to store pointers
 * 1. What would be the addr of a fn?
 */

#include <stdio.h>

/**
 * In memory a fn is one continuous block with some instrutions;
 * The addr of this fn will be the addr of its 1st instruction, i.e.
 * its entry point.
 */

int Add(int a, int b)
{
	return a+b;
}

void print_hello()
{
	printf("Hello\n");
}

void print_name(char *name)
{
	printf("Hello %s\n", name);
}


int main()
{
	/* create a ptr to a fn that takes (int, int) as arg/para and return it */
	int (*p)(int, int);			/* fn ptr declaration */

	/* This syntax however declares a fn that returns a int ptr */
	int *fn_ret_int(int, int);

	int c;
	p = &Add;					/* point to fn Add; ALTERNATIVE: p = Add; */
	c = (*p)(2,3);				/* call fn using ptr, c = p(2,3) if ALT */
	printf("%d\n", c);


	/**
	 * ALTERNATIVELY, and more popular indeed
	 * p = Add;
	 * c = p(2,4)
	 */
	void (*ptr)();
	ptr = print_hello;
	ptr();


	void (*ptr2)(char*);
	ptr2 = print_name;
	ptr2("Stupid");
	return 0;
}
