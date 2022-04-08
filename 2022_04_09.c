#include <stdio.h>
#include <assert.h>

int BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}

	return -1;
}

