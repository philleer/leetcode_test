#include "bitops.h"

/*
 * @Description: Find rightmost of the given number
 * 		and return the result computed by removing
 * 		left ones from rightmost one
 * @Input params: 	signed int number, -2^32 <= num < 2^32-1
 * @Output params: 	signed int res contains only one 1 bit
 */
int findRightmostOne(signed int num)
{
	int res = 1;
	while((num&0x01)!=1)
	{
		num >>= 1;
		res <<= 1;
	}

	return res;
}