#include <stdio.h>

/* Array is passed by reference however. Compiler changes C[] to *C */
void my_print(char *C)
{
	while(*C != '\0')
	{
		printf("%c", *C);
		/**
		 * Increasing a pointer by 1 increases the address by 1 sizeof the
		 * type the pointer points to.
		 * C++ here means to increase 1 byte to the current address
		*/
		C++;
	}
	printf("\n");
}

int main()
{
	/**
	 * char C[20] = "hello"; string gets stored in the stack and
	 * C[10] = 'b'; is valid
	 */
	char C[20] = "hellp";
	char *C = "Hello";			/* stored as compile-time const */
	C[0] = 'A';					/* not allowed and get segmentation fault */
	my_print(C);
	return 0;
}
