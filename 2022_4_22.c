#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, d;
	a = c = 0;
	b = 1;
	d = 20;
	if (a)
	{
		d = d - 10;

	}
	else if (!b)
	{
		if (!c)
		{
			d = 25;
		}
	
	}
	else
	{
		d = 15;
	}
	printf("%d", d);
	return 0;
}