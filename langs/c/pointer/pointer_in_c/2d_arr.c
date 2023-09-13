#include <stdio.h>

int main()
{
	int B[2][3];

	B[0][0] = 2;
	B[0][1] = 3;
	B[0][2] = 6;
	B[1][0] = 4;
	B[1][1] = 5;
	B[1][2] = 8;

	printf("%d\n", B[0][1]);
	/* A single pointer to int CANT point directly to B anymore */
	//int *ptr1 = B; 				/* wrong */
	int (*ptr2)[3] = B;			/* right, this is indeed what B returns */
	/* the results of the folowing are identical */
	printf("%p\n", B);			/* addr of 1st arr of the 2d arr */
	printf("%p\n", *B);			/* addr of 1st ele of 1st arr of the 2d arr  */
	printf("%p\n", B[0]);		/* addr of 1st arr of the 2d arr */
	printf("%p\n", &B[0]);		/* addr of 1st arr of the 2d arr */
	printf("%p\n", &B[0][0]);	/* addr of 1st ele of 1st arr of the 2d arr */

	/**
	 * `*B' returns the 1st array of B. It is identical to B[0]
	 * While array in C can be used as ptr to its 1st ele, so
	 * `*B' is indeed the ptr to B's 1st array's 1st ele, thus
	 * `*B' == &B[0][0]
	 */


	/* B+1 will move the ptr from beg of 1st arr to beg of 2nd */
	printf("%p\n", B+1);
	printf("%p\n", &B[1]);
	printf("%p\n", *(B+1));
	printf("%p\n", B[1]);
	printf("%p\n", &B[1][0]);


	/**
	 * B[i][j] == *(B[i]+j) == *(*(B+i)+j)
	 */



	return 0;
}
