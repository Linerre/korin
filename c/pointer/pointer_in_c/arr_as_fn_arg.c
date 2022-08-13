#include <stdio.h>

/* Array is passed by reference however. Compiler changes C[] to *C[] */
void my_print(char C[])
{
	int i = 0;
	/* while(*C != '\0') ALTERNATIVE */
	while(C[i] != '\0')
	{
		printf("%c", C[i]);
		/* C++; ALTERNATIVE */
		i++;
	}
	printf("\n");
}

int main()
{
	char C[20] = "Hello";
	return 0;
}
