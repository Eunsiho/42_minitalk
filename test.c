#include <stdio.h>

int	main(void)
{
	int	c = 0;

	c |= 0;
	c <<= 1; //0000 0000

	c |= 1;
	c <<= 1; //0000 0010

	c |= 1;
	c <<= 1; //0000 0110

	c |= 0;
	c <<= 1; //0000 1100


	c |= 0;
	c <<= 1; //0001 1000

	c |= 0;
	c <<= 1; //0011 0000

	c |= 0;
	c <<= 1; //0110 0000

	c |= 1;   //0110 0001

	printf("%x\n", c);
	return (0);
}