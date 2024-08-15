/**
 * Consider this file a cookbook of some common bitwise operation patterns.
 * These functions are collected from various sources, mainly:
 * 1. open course exercises
 * 2. exercises from books I have read or am reading
 * 3. interesting stuff I run across online
 * 4. my school homework
 *
 * If anything in this file happens to be the same as your shcool homework,
 * it's your responsibility to make sure you have ruled out any risk of
 * plagiarism before actually using anything here.
 */

#include <stdio.h>
#include <assert.h>

/**
 * compute x ^ y using only ~ and &
 * legal ops: ~, &
 * max ops: 14
 * example: assert(bit_xor(4,5) == 1);
 */
int bit_xor(int x, int y) {
    /* filter out positions where both x and y have 1 */
    int z = x & y;
    z = ~z;

    /* find out positions where both x and y have 0 and
     * mark these positions with with0
     */
    int _z = ~((~x) & (~y));

    /* fix those 1s that are supposed to be 0 */
    z &= _z;
    return z;
}

/**
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
	return !(x ^ y);
}

/**
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	int result = !(x ^ y);
	return !result;
}

/**
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
	return !x;
}

/**
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	/*
	  C uses 2's complement to represent int values
	  it's ok to overflow in this procedure so long
	  as the bit representation is as expected
	*/

	/* set shift according to n; 1 ops */
	int shift = (n<<3);

	/* shift c to proper value; 1 op */
	int rc = c << shift;

	/* adjust mask according to shift; 2 ops */
	int mask = ~(0xFF << shift);

	/* mask x and replace target byte; 2 ops*/
	return (x & mask) | rc;
}

/**
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	/* 1 ops */
	int shift = (n << 3);

	/* 1 op */
	unsigned int mask = 0xFF << shift;

	/* 2 ops */
	return (x & mask) >> shift;
}

int main() {
	/* Fill in this main function to test your solutions! */

	/* Test isEqual */
	printf("1 for true/yes and 0 for false/no\n");
	printf("Is 5 equal to 5: %d\n", isEqual(5,5));
	printf("Is 5 equal to 4: %d\n", isEqual(5,4));

	/* Test isNotEqual */
	printf("1 for true/yes and 0 for false/no\n");
	printf("Is 5 not equal to 5: %d\n", isNotEqual(5,5));
	printf("Is 5 not equal to 4: %d\n", isNotEqual(5,4));

	/* Test isZero */
	int a = 0, b = 5;
	printf("1 for true/yes and 0 for false/no\n");
	printf("original: a = %d, b = %d\n", a, b);
	printf("Is a equal to 0: %d\n", isZero(a));
	printf("Is b equal to 0: %d\n", isZero(b));

	/* Test replaceByte */
	int x = 0x12345678;
	int x_ = replaceByte(x, 1, 0xab);
	printf("original x = 0x%x\n", x);
	printf("modified x = 0x%x\n", x_);
	assert(x_ == 0x1234ab78);

	int y = 0x7fffffff;
	int y_ = replaceByte(y, 3, 0xff);
	printf("original y = 0x%x\n", y);
	printf("modified y = 0x%x (hex)\n", y_);
	printf("modified y =  %d (decimal)\n", y_); /* expect overflow */
	assert(y_ == 0xffffffff);

	/* Test getByte */
	int n = 0x345678;
	int e = getByte(n,1);
	printf("original n = 0x%x\n", n);
	printf("extracted n = 0x%x\n", e);
	assert(0x56 == getByte(0x12345678,1));

	return 0;
}
