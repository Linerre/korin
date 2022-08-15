#include <stdio.h>

int main()
{
	int C[3][2][2] = {
		{{2,5}, {7,9}},
		{{3,4}, {6,1}},
		{{0,8}, {11,13}}
	};
	/**
	 * [
	 *   [[int, int], [int, int]],
	 *   [[int, int], [int, int]],
	 *   [[int, int], [int, int]]
	 * ]
	 */
	/* C == int (*p)[2][2] , an arr of 2 arrs with each having 2 ints */
	return 0;
}
