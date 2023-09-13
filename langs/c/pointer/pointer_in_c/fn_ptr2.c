/**
 * Function pointers are functions used to store pointers
 * 2. Use cases: fn ptrs can be passed as args to other fns
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* this lib now provides abs, qsort also comes here */

void A()
{
	printf("Hello");
}

void B(void (*ptr)())			/* fn ptr as arg */
{
	ptr();						/* call-back fn that ptr points to */
}

void my_sort(int *arr, int n)
{
	int i,j,tmp;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(arr[j] < arr[j+1]) /* swap two values if elej > elej+1 */
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

/**
 * callback fn will compare two ints and return:
 * 1 if 1st is higher
 * 0 if two are equal
 * -1 if 2nd is higher
 */
int compare(int a, int b)
{
	/* equality logic is missing since it doesnt matter in this case */
	if(a>b) return -1;
	else return 1;
}

// void type used because the fn is to be used with qsort, which
// accepts any kind of arrays: int, char, etc.
int new_compare(const void *a, const void *b)
{
	int A = *((int*)a);			/* typecasting to int* and getting value */
	int B = *((int*)b);
	return A-B; 				/* increasing order */
	/**
	 * Decreasing order: return B-A;
	 * Absolute order: return abs(A)-abs(B);
	 */
}

int abs_compare(int a, int b)
{
	if(abs(a) > abs(b)) return 1;
	else return -1;
}


void my_new_sort(int *arr, int n, int (*compare)(int, int))
{
	int i,j,tmp;
	for(i=0; i<n; i++) {
		for(j=0; j<n-1; j++) {
			if(compare(arr[j], arr[j+1]) > 0) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main()
{
	int i, C[] = {3,2,1,4,6,5};
	int D[] = {-31,22,-1,50,-6,4}; /* => {-1,4,-6,22,-31,50} */
	my_new_sort(D,6,abs_compare);
	for(i=0; i<6; i++)
		printf("%d ", D[i]);

	void (*p)() = A;
	B(p);

	/**
	 * Alternatively:
	 * B(A);
	 */
	return 0;
}
